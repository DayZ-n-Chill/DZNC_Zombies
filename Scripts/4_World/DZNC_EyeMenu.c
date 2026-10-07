// Admin menu: a searchable list of zombie types with a live preview of the selected one,
// setting eye colors one by one, per outfit family, or for every zombie at once.
// Every change is sent to the server right away and saved there.
class DZNC_EyeMenu extends UIScriptedMenu
{
	static const int MENU_ID = 0x445A4E;
	static const int TAB_ON = 0xFFC8102E;
	static const int TAB_OFF = 0xFF3A3A3A;
	static const int SELECTOR_TEXT_ON = 0xFFFFFFFF;
	static const int SELECTOR_TEXT_OFF = 0xFF808080;
	static const int SELECTOR_SWATCH_OFF_ALPHA = 0x50000000;
	static const float CONFIRM_SECONDS = 3;
	static const float DRAG_DEGREES_PER_PIXEL = 0.5;
	static const float ROTATE_SEND_INTERVAL = 0.05;
	// Preview placement: zombie height in meters, how near and far it may stand from the camera,
	// and the part of the screen height (top and bottom, as fractions) it must fit in.
	static const float PREVIEW_HEIGHT = 1.85;
	static const float PREVIEW_MIN_DISTANCE = 1.0;
	static const float PREVIEW_MAX_DISTANCE = 12;
	static const float PREVIEW_DISTANCE_STEP = 1.05;
	static const float PREVIEW_TOP = 0.26;
	static const float PREVIEW_BOTTOM = 0.93;
	static const float PREVIEW_MAX_ANGLE = 1.4;
	// Half the zombie's on-screen width as a share of its on-screen height, plus a gap, used to keep it clear of the menu.
	static const float PREVIEW_HALF_WIDTH = 0.2;
	static const float PREVIEW_PANEL_GAP = 20;
	// The menu opens on the left, this share of the screen width from the edge, vertically centred.
	static const float PANEL_LEFT = 0.05;
	static const int INTENSITY_MIN = 1;
	static const int INTENSITY_MAX = 10;

	protected ref array<int> m_Colors;
	protected ref array<int> m_ListTypes = new array<int>;	// list row -> zombie index
	protected int m_Index;
	protected int m_LastGlowColor = 1;
	protected int m_BulkColor = 1;
	protected int m_Intensity = 5;
	protected bool m_ChangedOnly;
	protected float m_ResetConfirmTimer;
	protected bool m_FillingList;
	protected bool m_MouseWasHeld;
	protected bool m_Dragging;
	protected int m_DragLastX;
	protected bool m_MovingMenu;
	protected float m_MoveOffsetX;
	protected float m_MoveOffsetY;
	protected float m_Yaw;
	protected float m_SentYaw;
	protected float m_RotateSendTimer;
	protected bool m_PreviewPending;

	protected ButtonWidget m_FilterChanged;
	protected EditBoxWidget m_SearchBox;
	protected Widget m_SearchHint;
	protected TextListboxWidget m_ZombieList;
	protected ButtonWidget m_ListModeVanilla;
	protected ButtonWidget m_ListModeGlow;
	protected TextWidget m_ListColorName;
	protected Widget m_ListColorSwatch;
	protected ButtonWidget m_ListApplyFamily;
	protected Widget m_Header;
	protected Widget m_Close;
	protected TextWidget m_BulkColorName;
	protected Widget m_BulkColorSwatch;
	protected ButtonWidget m_SetAll;
	protected ButtonWidget m_ResetAll;
	protected CheckBoxWidget m_CrazyMode;
	protected Widget m_CrazyHint;
	protected CheckBoxWidget m_FadeOnDeath;
	protected Widget m_FadeHint;
	protected SliderWidget m_BrightnessSlider;
	protected TextWidget m_BrightnessValue;
	protected TextWidget m_Summary;

	static void Open(array<int> colors, int intensity, int crazy, int fade)
	{
		DZNC_EyeMenu menu = DZNC_EyeMenu.Cast(GetGame().GetUIManager().FindMenu(MENU_ID));
		if (!menu)
			menu = DZNC_EyeMenu.Cast(GetGame().GetUIManager().EnterScriptedMenu(MENU_ID, null));
		if (menu)
			menu.SetColors(colors, intensity, crazy, fade);
	}

	static bool IsOpen()
	{
		return GetGame().GetUIManager().FindMenu(MENU_ID) != null;
	}

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("DZNC_Zombies/Scripts/GUI/eye_menu.layout");
		m_FilterChanged = ButtonWidget.Cast(layoutRoot.FindAnyWidget("FilterChanged"));
		m_SearchBox = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("SearchBox"));
		m_SearchHint = layoutRoot.FindAnyWidget("SearchHint");
		m_ZombieList = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("ZombieList"));
		m_ListModeVanilla = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ListModeVanilla"));
		m_ListModeGlow = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ListModeGlow"));
		m_ListColorName = TextWidget.Cast(layoutRoot.FindAnyWidget("ListColorName"));
		m_ListColorSwatch = layoutRoot.FindAnyWidget("ListColorSwatch");
		m_ListApplyFamily = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ListApplyFamily"));
		m_Header = layoutRoot.FindAnyWidget("Header");
		m_Close = layoutRoot.FindAnyWidget("Close");
		m_BulkColorName = TextWidget.Cast(layoutRoot.FindAnyWidget("BulkColorName"));
		m_BulkColorSwatch = layoutRoot.FindAnyWidget("BulkColorSwatch");
		m_SetAll = ButtonWidget.Cast(layoutRoot.FindAnyWidget("SetAll"));
		m_ResetAll = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ResetAll"));
		m_Summary = TextWidget.Cast(layoutRoot.FindAnyWidget("Summary"));
		m_CrazyMode = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("CrazyMode"));
		m_CrazyHint = layoutRoot.FindAnyWidget("CrazyHint");
		m_FadeOnDeath = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("FadeOnDeath"));
		m_FadeHint = layoutRoot.FindAnyWidget("FadeHint");
		m_BrightnessSlider = SliderWidget.Cast(layoutRoot.FindAnyWidget("BrightnessSlider"));
		m_BrightnessValue = TextWidget.Cast(layoutRoot.FindAnyWidget("BrightnessValue"));
		m_BrightnessSlider.SetMinMax(INTENSITY_MIN, INTENSITY_MAX);
		m_BrightnessSlider.SetStep(1);

		int screenW, screenH;
		GetScreenSize(screenW, screenH);
		float panelW, panelH;
		layoutRoot.GetSize(panelW, panelH);
		layoutRoot.SetPos(screenW * PANEL_LEFT, Math.Max(0, (screenH - panelH) * 0.5));
		return layoutRoot;
	}

	override void OnShow()
	{
		super.OnShow();
		GetGame().GetMission().AddActiveInputExcludes({"menu"});
		GetGame().GetUIManager().ShowUICursor(true);
	}

	override void OnHide()
	{
		super.OnHide();
		GetGame().GetMission().RemoveActiveInputExcludes({"menu"}, true);
		GetGame().GetUIManager().ShowUICursor(false);

		// The server removes the preview zombie it spawned for us.
		ScriptRPC rpc = new ScriptRPC();
		rpc.Send(GetGame().GetPlayer(), DZNC_EyeRPC.CLOSE_PREVIEW, true);
	}

	void SetColors(array<int> colors, int intensity, int crazy, int fade)
	{
		m_Colors = colors;
		m_Intensity = Math.Clamp(intensity, INTENSITY_MIN, INTENSITY_MAX);
		m_BrightnessSlider.SetCurrent(m_Intensity);
		m_CrazyMode.SetChecked(crazy != 0);
		m_FadeOnDeath.SetChecked(fade != 0);
		ShowPreview();
		RefreshList();
		RefreshAll();
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		int color = m_Colors[m_Index];

		switch (w.GetName())
		{
			// The eye controls under the list act on the selected zombie.
			case "ListModeVanilla":
				SetCurrent(0);
				return true;
			case "ListModeGlow":
				if (!DZNC_Eyes.IsColor(color))
					SetCurrent(ShownColor());
				return true;
			// The arrows always step one color from the one shown and switch the zombie to glowing.
			case "ListPrevColor":
				SetCurrent(CycleGlow(ShownColor(), -1));
				return true;
			case "ListNextColor":
				SetCurrent(CycleGlow(ShownColor(), 1));
				return true;
			case "ListApplyFamily":
				SetTypes(FamilyTypes(DZNC_Eyes.ZOMBIE_TYPES[m_Index]), color);
				return true;
			case "FilterChanged":
				m_ChangedOnly = !m_ChangedOnly;
				RefreshList();
				return true;
			case "BulkPrevColor":
				m_BulkColor = CycleGlow(m_BulkColor, -1);
				RefreshAll();
				return true;
			case "BulkNextColor":
				m_BulkColor = CycleGlow(m_BulkColor, 1);
				RefreshAll();
				return true;
			case "SetAll":
				SetTypes(DZNC_Eyes.ZOMBIE_TYPES, m_BulkColor);
				return true;
			case "RandomizeAll":
				RandomizeAll();
				return true;
			case "CrazyMode":
				SendToggle(m_CrazyMode, DZNC_EyeRPC.SET_CRAZY);
				return true;
			case "FadeOnDeath":
				SendToggle(m_FadeOnDeath, DZNC_EyeRPC.SET_FADE);
				return true;
			case "ResetAll":
				// Wiping every setting takes a second click so it can't happen by accident.
				if (m_ResetConfirmTimer > 0)
				{
					m_ResetConfirmTimer = 0;
					SetTypes(DZNC_Eyes.ZOMBIE_TYPES, 0);
				}
				else
				{
					m_ResetConfirmTimer = CONFIRM_SECONDS;
					RefreshAll();
				}
				return true;
			case "Close":
				Close();
				return true;
		}
		return false;
	}

	override bool OnChange(Widget w, int x, int y, bool finished)
	{
		// The list narrows down with every key typed into the search box.
		if (w == m_SearchBox)
		{
			RefreshList();
			return true;
		}

		// The brightness slider snaps to whole steps; the server hears about each new step once.
		if (w == m_BrightnessSlider)
		{
			int step = Math.Round(m_BrightnessSlider.GetCurrent());
			step = Math.Clamp(step, INTENSITY_MIN, INTENSITY_MAX);
			m_BrightnessSlider.SetCurrent(step);
			if (step != m_Intensity)
			{
				m_Intensity = step;
				ScriptRPC rpc = new ScriptRPC();
				rpc.Write(m_Intensity);
				rpc.Send(GetGame().GetPlayer(), DZNC_EyeRPC.SET_INTENSITY, true);
				RefreshAll();
			}
			return true;
		}

		return super.OnChange(w, x, y, finished);
	}

	override bool OnItemSelected(Widget w, int x, int y, int row, int column, int oldRow, int oldColumn)
	{
		if (w != m_ZombieList || m_FillingList || row < 0 || row >= m_ListTypes.Count())
			return false;

		// Picking a row swaps the preview zombie and points the eye controls under the list at it.
		SelectZombie(m_ListTypes[row]);
		return true;
	}

	// The checkbox has already flipped by the time the click arrives, like vanilla's script console.
	protected void SendToggle(CheckBoxWidget box, int rpcType)
	{
		int value = 0;
		if (box.IsChecked())
			value = 1;
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(value);
		rpc.Send(GetGame().GetPlayer(), rpcType, true);
		RefreshAll();
	}

	protected void SelectZombie(int index)
	{
		m_Index = index;
		ShowPreview();
		RefreshAll();
	}

	// The selected zombie's glow color, or on vanilla the last glow color the admin used.
	protected int ShownColor()
	{
		int color = m_Colors[m_Index];
		if (DZNC_Eyes.IsColor(color))
			return color;
		return m_LastGlowColor;
	}

	protected int CycleGlow(int color, int step)
	{
		int glowCount = DZNC_Eyes.COLOR_NAMES.Count() - 1;
		return (color - 1 + step + glowCount) % glowCount + 1;
	}

	protected TStringArray FamilyTypes(string type)
	{
		string family = DZNC_Eyes.FamilyOf(type);
		TStringArray types = new TStringArray;
		foreach (string other : DZNC_Eyes.ZOMBIE_TYPES)
		{
			if (DZNC_Eyes.FamilyOf(other) == family)
				types.Insert(other);
		}
		return types;
	}

	protected void SetCurrent(int color)
	{
		TStringArray types = new TStringArray;
		types.Insert(DZNC_Eyes.ZOMBIE_TYPES[m_Index]);
		SetTypes(types, color);
	}

	// Every zombie type gets a random glow color, never vanilla. Types are grouped by the color they drew
	// so each color goes out as one ordinary batch change.
	protected void RandomizeAll()
	{
		int glowCount = DZNC_Eyes.COLOR_NAMES.Count() - 1;
		array<ref TStringArray> groups = new array<ref TStringArray>;
		for (int i = 0; i <= glowCount; i++)
			groups.Insert(new TStringArray);

		foreach (string type : DZNC_Eyes.ZOMBIE_TYPES)
			groups[Math.RandomIntInclusive(1, glowCount)].Insert(type);

		for (int color = 1; color <= glowCount; color++)
		{
			if (groups[color].Count() > 0)
				SetTypes(groups[color], color);
		}
	}

	protected void SetTypes(TStringArray types, int color)
	{
		foreach (string type : types)
			m_Colors[DZNC_Eyes.ZOMBIE_TYPES.Find(type)] = color;
		if (DZNC_Eyes.IsColor(color))
			m_LastGlowColor = color;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(types);
		rpc.Write(color);
		rpc.Send(GetGame().GetPlayer(), DZNC_EyeRPC.SET_MANY, true);
		RefreshAll();
	}

	// The server spawns the real zombie in front of the camera, centred on screen; eye changes reach it
	// like any other zombie of that type. Placement waits one frame so the camera has settled.
	protected void ShowPreview()
	{
		m_Yaw = 0;
		m_SentYaw = 0;
		m_PreviewPending = true;
	}

	protected void SendPreview()
	{
		vector camPos = GetGame().GetCurrentCameraPosition();
		vector camDir = GetGame().GetCurrentCameraDirection();
		vector flat = camDir;
		flat[1] = 0;
		flat.Normalize();
		float camYaw = Math.Atan2(flat[0], flat[2]);

		int screenW, screenH;
		GetScreenSize(screenW, screenH);
		float topY = screenH * PREVIEW_TOP;
		float bottomY = screenH * PREVIEW_BOTTOM;

		// Screen centre, unless that would put the zombie under the menu; then just right of it.
		float panelX, panelY, panelW, panelH;
		layoutRoot.GetScreenPos(panelX, panelY);
		layoutRoot.GetScreenSize(panelW, panelH);
		float clearX = panelX + panelW + PREVIEW_PANEL_GAP + (bottomY - topY) * PREVIEW_HALF_WIDTH;
		float targetX = Math.Max(screenW * 0.5, clearX);

		// Walk outward from the camera until the whole zombie fits the screen: the first fit is the biggest one.
		// Projecting with the engine's own camera covers field of view, aspect ratio, pitch and third person alike.
		float distance = PREVIEW_MIN_DISTANCE;
		float angle = 0;
		vector pos;
		while (true)
		{
			angle = CenterAngle(camPos, camYaw, distance, angle, targetX);
			pos = GroundPoint(camPos, camYaw + angle, distance);
			if (distance >= PREVIEW_MAX_DISTANCE || FitsFrame(pos, camPos, camDir, topY, bottomY))
				break;
			distance = distance * PREVIEW_DISTANCE_STEP;
		}

		vector toCamera = camPos - pos;
		toCamera[1] = 0;
		vector facing = toCamera.VectorToAngles();

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(DZNC_Eyes.ZOMBIE_TYPES[m_Index]);
		rpc.Write(pos);
		rpc.Write(facing[0]);
		rpc.Send(GetGame().GetPlayer(), DZNC_EyeRPC.SHOW_PREVIEW, true);
	}

	// Yaw in radians, 0 = north, growing clockwise like the camera heading.
	protected vector GroundPoint(vector camPos, float yaw, float distance)
	{
		vector pos = camPos + Vector(Math.Sin(yaw), 0, Math.Cos(yaw)) * distance;
		pos[1] = GetGame().SurfaceY(pos[0], pos[2]);
		return pos;
	}

	protected float ScreenXAt(vector camPos, float yaw, float distance)
	{
		vector screen = GetGame().GetScreenPos(GroundPoint(camPos, yaw, distance) + Vector(0, PREVIEW_HEIGHT * 0.5, 0));
		return screen[0];
	}

	// Finds the turn away from the camera heading that puts the zombie's middle on the screen's centre line.
	protected float CenterAngle(vector camPos, float camYaw, float distance, float angle, float targetX)
	{
		float a0 = angle;
		float x0 = ScreenXAt(camPos, camYaw + a0, distance);
		float a1 = a0 + 0.05;
		for (int i = 0; i < 4; i++)
		{
			float x1 = ScreenXAt(camPos, camYaw + a1, distance);
			if (x1 == x0)
				break;
			float a2 = a1 + (targetX - x1) * (a1 - a0) / (x1 - x0);
			a0 = a1;
			x0 = x1;
			a1 = Math.Clamp(a2, -PREVIEW_MAX_ANGLE, PREVIEW_MAX_ANGLE);
		}
		return a1;
	}

	protected bool FitsFrame(vector pos, vector camPos, vector camDir, float topY, float bottomY)
	{
		vector headPos = pos + Vector(0, PREVIEW_HEIGHT, 0);
		// Points behind the camera project to meaningless screen positions.
		if (vector.Dot(pos - camPos, camDir) <= 0 || vector.Dot(headPos - camPos, camDir) <= 0)
			return false;

		vector feet = GetGame().GetScreenPos(pos);
		vector head = GetGame().GetScreenPos(headPos);
		return head[1] >= topY && feet[1] <= bottomY;
	}

	protected void RefreshAll()
	{
		int color = m_Colors[m_Index];
		bool glow = DZNC_Eyes.IsColor(color);
		Paint(m_ListModeVanilla, TabColor(!glow));
		Paint(m_ListModeGlow, TabColor(glow));

		// The selector always shows a color; on vanilla it is the one glowing would use, greyed out.
		int shown = ShownColor();
		m_ListColorName.SetText(DZNC_Eyes.COLOR_NAMES[shown]);
		if (glow)
		{
			m_ListColorName.SetColor(SELECTOR_TEXT_ON);
			m_ListColorSwatch.SetColor(DZNC_Eyes.COLOR_ARGB[shown]);
		}
		else
		{
			m_ListColorName.SetColor(SELECTOR_TEXT_OFF);
			m_ListColorSwatch.SetColor((DZNC_Eyes.COLOR_ARGB[shown] & 0x00FFFFFF) | SELECTOR_SWATCH_OFF_ALPHA);
		}
		m_ListApplyFamily.Show(FamilyTypes(DZNC_Eyes.ZOMBIE_TYPES[m_Index]).Count() > 1);

		m_BulkColorName.SetText(DZNC_Eyes.COLOR_NAMES[m_BulkColor]);
		m_BulkColorSwatch.SetColor(DZNC_Eyes.COLOR_ARGB[m_BulkColor]);
		string setAll = "SET ALL TO " + EyeLabel(m_BulkColor);
		setAll.ToUpper();
		Label(m_SetAll, setAll);
		if (m_ResetConfirmTimer > 0)
			Label(m_ResetAll, "CLICK AGAIN TO CONFIRM");
		else
			Label(m_ResetAll, "RESET ALL TO VANILLA");
		m_CrazyHint.Show(m_CrazyMode.IsChecked());
		m_FadeHint.Show(m_FadeOnDeath.IsChecked());
		m_BrightnessValue.SetText(m_Intensity.ToString() + " / " + INTENSITY_MAX);

		int glowing;
		foreach (int c : m_Colors)
		{
			if (DZNC_Eyes.IsColor(c))
				glowing++;
		}
		m_Summary.SetText(glowing.ToString() + " of " + m_Colors.Count() + " zombie types have glowing eyes");

		RefreshListColors();
	}

	// Rewrites the eye column in place so the list keeps its rows, scroll and selection after a change.
	// Rows only come and go when the filter or the search changes.
	protected void RefreshListColors()
	{
		for (int row = 0; row < m_ListTypes.Count(); row++)
		{
			int color = m_Colors[m_ListTypes[row]];
			m_ZombieList.SetItem(row, DZNC_Eyes.COLOR_NAMES[color], null, 1);
			m_ZombieList.SetItemColor(row, 1, DZNC_Eyes.COLOR_ARGB[color]);
		}
	}

	protected void RefreshList()
	{
		if (m_ChangedOnly)
			Label(m_FilterChanged, "SHOWING GLOWING ONLY  -  CLICK TO SHOW ALL");
		else
			Label(m_FilterChanged, "SHOWING ALL ZOMBIES  -  CLICK TO SHOW GLOWING ONLY");

		// Matches the readable name or the class name, ignoring case.
		string search = m_SearchBox.GetText();
		search.TrimInPlace();
		search.ToLower();
		m_SearchHint.Show(search == "");

		m_FillingList = true;
		m_ZombieList.ClearItems();
		m_ListTypes.Clear();
		for (int i = 0; i < DZNC_Eyes.ZOMBIE_TYPES.Count(); i++)
		{
			int color = m_Colors[i];
			if (m_ChangedOnly && !DZNC_Eyes.IsColor(color))
				continue;

			string type = DZNC_Eyes.ZOMBIE_TYPES[i];
			string pretty = DZNC_Eyes.PrettyName(type);
			if (search != "")
			{
				string haystack = pretty + " " + type;
				haystack.ToLower();
				if (!haystack.Contains(search))
					continue;
			}

			int row = m_ZombieList.AddItem(pretty, null, 0);
			m_ZombieList.SetItem(row, DZNC_Eyes.COLOR_NAMES[color], null, 1);
			m_ZombieList.SetItemColor(row, 1, DZNC_Eyes.COLOR_ARGB[color]);
			m_ListTypes.Insert(i);
			if (i == m_Index)
				m_ZombieList.SelectRow(row);
		}
		m_FillingList = false;
	}

	// Buttons are a background panel plus a fixed size label, so text never scales with the button.
	protected void Paint(Widget button, int color)
	{
		button.FindAnyWidget(button.GetName() + "_bg").SetColor(color);
	}

	protected void Label(Widget button, string text)
	{
		TextWidget.Cast(button.FindAnyWidget(button.GetName() + "_label")).SetText(text);
	}

	protected string EyeLabel(int color)
	{
		if (DZNC_Eyes.IsColor(color))
			return DZNC_Eyes.COLOR_NAMES[color] + " eyes";
		return "vanilla eyes";
	}

	// A left press on the header (not the close button) drags the menu around; a press anywhere outside
	// the menu spins the preview zombie, like the inventory character. The press decides which, until release.
	protected void UpdateMouseDrag(float timeslice)
	{
		int mouseX, mouseY;
		GetMousePos(mouseX, mouseY);
		bool held = GetMouseState(MouseState.LEFT) & MB_PRESSED_MASK;

		if (!held)
		{
			m_Dragging = false;
			m_MovingMenu = false;
		}
		else if (!m_MouseWasHeld)
		{
			if (IsOver(m_Header, mouseX, mouseY) && !IsOver(m_Close, mouseX, mouseY))
			{
				// Same offset-then-SetPos pattern as the vanilla item diagnostic window.
				float menuX, menuY;
				layoutRoot.GetScreenPos(menuX, menuY);
				m_MoveOffsetX = menuX - mouseX;
				m_MoveOffsetY = menuY - mouseY;
				m_MovingMenu = true;
			}
			else if (!IsOver(layoutRoot, mouseX, mouseY))
			{
				m_Dragging = true;
				m_DragLastX = mouseX;
			}
		}
		m_MouseWasHeld = held;

		if (m_MovingMenu)
			layoutRoot.SetPos(mouseX + m_MoveOffsetX, mouseY + m_MoveOffsetY);

		if (m_Dragging)
		{
			m_Yaw -= (mouseX - m_DragLastX) * DRAG_DEGREES_PER_PIXEL;
			m_DragLastX = mouseX;
		}

		m_RotateSendTimer -= timeslice;
		if (m_Yaw != m_SentYaw && m_RotateSendTimer <= 0)
		{
			m_RotateSendTimer = ROTATE_SEND_INTERVAL;
			m_SentYaw = m_Yaw;
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(m_Yaw);
			rpc.Send(GetGame().GetPlayer(), DZNC_EyeRPC.ROTATE_PREVIEW, false);
		}
	}

	protected bool IsOver(Widget w, int x, int y)
	{
		float wx, wy, ww, wh;
		w.GetScreenPos(wx, wy);
		w.GetScreenSize(ww, wh);
		return x >= wx && x <= wx + ww && y >= wy && y <= wy + wh;
	}

	protected int TabColor(bool selected)
	{
		if (selected)
			return TAB_ON;
		return TAB_OFF;
	}

	override void Update(float timeslice)
	{
		super.Update(timeslice);

		if (m_ResetConfirmTimer > 0)
		{
			m_ResetConfirmTimer -= timeslice;
			if (m_ResetConfirmTimer <= 0)
				RefreshAll();
		}

		if (m_PreviewPending)
		{
			m_PreviewPending = false;
			SendPreview();
		}

		UpdateMouseDrag(timeslice);

		if (GetUApi().GetInputByID(UAUIBack).LocalPress())
			Close();
	}
}
