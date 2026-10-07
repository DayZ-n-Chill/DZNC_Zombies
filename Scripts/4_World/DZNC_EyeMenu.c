// Admin menu: a searchable list of zombie types with a live preview of the selected one,
// setting eye colors one by one, per outfit family, or for every zombie at once.
// Every change is sent to the server right away and saved there.
class DZNC_EyeMenu extends UIScriptedMenu
{
	static const int MENU_ID = 0x445A4E;
	static const int TAB_ON = 0xFFA8102A;
	static const int TAB_OFF = 0xFF212124;
	static const int SWITCH_ON = 0xFFC8142E;
	static const int SWITCH_OFF = 0xFF4C4C52;
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
	// Layout sizes for the hand-built slider and switches, in layout pixels.
	static const float SLIDER_WIDTH = 528;
	static const float SLIDER_KNOB = 18;
	static const float SWITCH_KNOB_OFF_X = 481;
	static const float SWITCH_KNOB_ON_X = 505;
	static const float SWITCH_KNOB_Y = 7;
	static const int POPUP_SELECTED = 0;
	static const int POPUP_BULK = 1;

	protected ref array<int> m_Colors;
	protected ref array<int> m_ListTypes = new array<int>;	// list row -> zombie index
	protected int m_Index;
	protected int m_LastGlowColor = 1;
	protected int m_BulkColor = 1;
	protected int m_Intensity = 5;
	protected bool m_Crazy;
	protected bool m_Fade;
	protected bool m_ChangedOnly;
	protected float m_ResetConfirmTimer;
	protected bool m_FillingList;
	protected bool m_MouseWasHeld;
	protected bool m_Dragging;
	protected int m_DragLastX;
	protected bool m_MovingMenu;
	protected bool m_DraggingSlider;
	protected float m_MoveOffsetX;
	protected float m_MoveOffsetY;
	protected float m_Yaw;
	protected float m_SentYaw;
	protected float m_RotateSendTimer;
	protected bool m_PreviewPending;
	protected int m_PopupTarget;

	protected ButtonWidget m_FilterAll;
	protected ButtonWidget m_FilterGlowing;
	protected EditBoxWidget m_SearchBox;
	protected Widget m_SearchHint;
	protected TextListboxWidget m_ZombieList;
	protected ButtonWidget m_ListModeVanilla;
	protected ButtonWidget m_ListModeGlow;
	protected Widget m_ListColorPicker;
	protected TextWidget m_ListColorName;
	protected Widget m_ListColorSwatch;
	protected ButtonWidget m_ListApplyFamily;
	protected Widget m_Header;
	protected Widget m_Close;
	protected Widget m_BulkColorPicker;
	protected TextWidget m_BulkColorName;
	protected Widget m_BulkColorSwatch;
	protected ButtonWidget m_SetAll;
	protected ButtonWidget m_ResetAll;
	protected Widget m_CrazyMode;
	protected Widget m_FadeOnDeath;
	protected Widget m_BrightnessSlider;
	protected Widget m_BrightnessFill;
	protected Widget m_BrightnessKnob;
	protected TextWidget m_BrightnessValue;
	protected Widget m_ColorPopup;
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
		m_FilterAll = ButtonWidget.Cast(layoutRoot.FindAnyWidget("FilterAll"));
		m_FilterGlowing = ButtonWidget.Cast(layoutRoot.FindAnyWidget("FilterGlowing"));
		m_SearchBox = EditBoxWidget.Cast(layoutRoot.FindAnyWidget("SearchBox"));
		m_SearchHint = layoutRoot.FindAnyWidget("SearchHint");
		m_ZombieList = TextListboxWidget.Cast(layoutRoot.FindAnyWidget("ZombieList"));
		m_ListModeVanilla = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ListModeVanilla"));
		m_ListModeGlow = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ListModeGlow"));
		m_ListColorPicker = layoutRoot.FindAnyWidget("ListColorPicker");
		m_ListColorName = TextWidget.Cast(layoutRoot.FindAnyWidget("ListColorName"));
		m_ListColorSwatch = layoutRoot.FindAnyWidget("ListColorSwatch");
		m_ListApplyFamily = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ListApplyFamily"));
		m_Header = layoutRoot.FindAnyWidget("Header");
		m_Close = layoutRoot.FindAnyWidget("Close");
		m_BulkColorPicker = layoutRoot.FindAnyWidget("BulkColorPicker");
		m_BulkColorName = TextWidget.Cast(layoutRoot.FindAnyWidget("BulkColorName"));
		m_BulkColorSwatch = layoutRoot.FindAnyWidget("BulkColorSwatch");
		m_SetAll = ButtonWidget.Cast(layoutRoot.FindAnyWidget("SetAll"));
		m_ResetAll = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ResetAll"));
		m_CrazyMode = layoutRoot.FindAnyWidget("CrazyMode");
		m_FadeOnDeath = layoutRoot.FindAnyWidget("FadeOnDeath");
		m_BrightnessSlider = layoutRoot.FindAnyWidget("BrightnessSlider");
		m_BrightnessFill = layoutRoot.FindAnyWidget("BrightnessFill");
		m_BrightnessKnob = layoutRoot.FindAnyWidget("BrightnessKnob");
		m_BrightnessValue = TextWidget.Cast(layoutRoot.FindAnyWidget("BrightnessValue"));
		m_ColorPopup = layoutRoot.FindAnyWidget("ColorPopup");
		m_Summary = TextWidget.Cast(layoutRoot.FindAnyWidget("Summary"));

		// The color popup lists every glow color, in the same order as the color table.
		for (int color = 1; color < DZNC_Eyes.COLOR_NAMES.Count(); color++)
		{
			Widget pick = layoutRoot.FindAnyWidget("Pick" + color);
			if (!pick)
				continue;
			TextWidget.Cast(pick.FindAnyWidget(pick.GetName() + "_label")).SetText(DZNC_Eyes.COLOR_NAMES[color]);
			pick.FindAnyWidget(pick.GetName() + "_swatch").SetColor(DZNC_Eyes.COLOR_ARGB[color]);
		}

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
		m_Crazy = crazy != 0;
		m_Fade = fade != 0;
		ShowPreview();
		RefreshList();
		RefreshAll();
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		int color = m_Colors[m_Index];
		string name = w.GetName();

		// Picking a color from the popup: the selected zombie starts glowing in it, or the bulk color changes.
		if (name.IndexOf("Pick") == 0)
		{
			int picked = name.Substring(4, name.Length() - 4).ToInt();
			m_ColorPopup.Show(false);
			if (m_PopupTarget == POPUP_SELECTED)
			{
				SetCurrent(picked);
			}
			else
			{
				m_BulkColor = picked;
				RefreshAll();
			}
			return true;
		}

		switch (name)
		{
			case "FilterAll":
				m_ChangedOnly = false;
				RefreshList();
				return true;
			case "FilterGlowing":
				m_ChangedOnly = true;
				RefreshList();
				return true;
			// The eye controls under the list act on the selected zombie.
			case "ListModeVanilla":
				SetCurrent(0);
				return true;
			case "ListModeGlow":
				if (!DZNC_Eyes.IsColor(color))
					SetCurrent(ShownColor());
				return true;
			case "ListColorPicker":
				ToggleColorPopup(POPUP_SELECTED, m_ListColorPicker);
				return true;
			case "ListApplyFamily":
				SetTypes(FamilyTypes(DZNC_Eyes.ZOMBIE_TYPES[m_Index]), color);
				return true;
			case "BulkColorPicker":
				ToggleColorPopup(POPUP_BULK, m_BulkColorPicker);
				return true;
			case "SetAll":
				SetTypes(DZNC_Eyes.ZOMBIE_TYPES, m_BulkColor);
				return true;
			case "RandomizeAll":
				RandomizeAll();
				return true;
			case "CrazyMode":
				m_Crazy = !m_Crazy;
				SendToggle(m_Crazy, DZNC_EyeRPC.SET_CRAZY);
				return true;
			case "FadeOnDeath":
				m_Fade = !m_Fade;
				SendToggle(m_Fade, DZNC_EyeRPC.SET_FADE);
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

	// The list narrows down with every key typed into the search box.
	override bool OnChange(Widget w, int x, int y, bool finished)
	{
		if (w != m_SearchBox)
			return super.OnChange(w, x, y, finished);

		RefreshList();
		return true;
	}

	override bool OnItemSelected(Widget w, int x, int y, int row, int column, int oldRow, int oldColumn)
	{
		if (w != m_ZombieList || m_FillingList || row < 0 || row >= m_ListTypes.Count())
			return false;

		// Picking a row swaps the preview zombie and points the eye controls under the list at it.
		SelectZombie(m_ListTypes[row]);
		return true;
	}

	protected void SendToggle(bool on, int rpcType)
	{
		int value = 0;
		if (on)
			value = 1;
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(value);
		rpc.Send(GetGame().GetPlayer(), rpcType, true);
		RefreshAll();
	}

	// Opens the color list under the selector that was clicked, or closes it when clicked again.
	protected void ToggleColorPopup(int target, Widget opener)
	{
		if (m_ColorPopup.IsVisible() && m_PopupTarget == target)
		{
			m_ColorPopup.Show(false);
			return;
		}

		m_PopupTarget = target;
		float x, y, w, h;
		opener.GetPos(x, y);
		opener.GetSize(w, h);
		m_ColorPopup.SetPos(x, y + h + 2);
		m_ColorPopup.Show(true);
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
		string bulkName = DZNC_Eyes.COLOR_NAMES[m_BulkColor];
		bulkName.ToLower();
		Label(m_SetAll, "Set all to " + bulkName);
		if (m_ResetConfirmTimer > 0)
			Label(m_ResetAll, "Click again to confirm");
		else
			Label(m_ResetAll, "Reset to vanilla");
		// The refresh icon would overlap the longer confirm text.
		m_ResetAll.FindAnyWidget("ResetAll_icon").Show(m_ResetConfirmTimer <= 0);

		PaintSwitch(m_CrazyMode, m_Crazy);
		PaintSwitch(m_FadeOnDeath, m_Fade);
		PaintSlider();

		int glowing;
		foreach (int c : m_Colors)
		{
			if (DZNC_Eyes.IsColor(c))
				glowing++;
		}
		m_Summary.SetText(glowing.ToString() + " of " + m_Colors.Count() + " zombie types glowing");

		RefreshListColors();
	}

	// Switches are a pill of two circles and a bar, with a white knob that sits left when off and right when on.
	protected void PaintSwitch(Widget row, bool on)
	{
		string prefix = row.GetName();
		int trackColor = SWITCH_OFF;
		float knobX = SWITCH_KNOB_OFF_X;
		if (on)
		{
			trackColor = SWITCH_ON;
			knobX = SWITCH_KNOB_ON_X;
		}
		row.FindAnyWidget(prefix + "_trackL").SetColor(trackColor);
		row.FindAnyWidget(prefix + "_trackR").SetColor(trackColor);
		row.FindAnyWidget(prefix + "_trackC").SetColor(trackColor);
		row.FindAnyWidget(prefix + "_knob").SetPos(knobX, SWITCH_KNOB_Y);
	}

	protected void PaintSlider()
	{
		float fill = SLIDER_WIDTH * (m_Intensity - INTENSITY_MIN) / (INTENSITY_MAX - INTENSITY_MIN);
		float fillW, fillH;
		m_BrightnessFill.GetSize(fillW, fillH);
		m_BrightnessFill.SetSize(fill, fillH);
		float knobX = Math.Clamp(fill - SLIDER_KNOB * 0.5, 0, SLIDER_WIDTH - SLIDER_KNOB);
		float knobOldX, knobY;
		m_BrightnessKnob.GetPos(knobOldX, knobY);
		m_BrightnessKnob.SetPos(knobX, knobY);
		m_BrightnessValue.SetText(m_Intensity.ToString() + " / " + INTENSITY_MAX);
	}

	// The slider snaps to whole steps under the mouse; the server hears about each new step once.
	protected void UpdateSliderFromMouse(int mouseX)
	{
		float sliderX, sliderY, sliderW, sliderH;
		m_BrightnessSlider.GetScreenPos(sliderX, sliderY);
		m_BrightnessSlider.GetScreenSize(sliderW, sliderH);
		float t = Math.Clamp((mouseX - sliderX) / sliderW, 0, 1);
		int step = Math.Round(INTENSITY_MIN + t * (INTENSITY_MAX - INTENSITY_MIN));
		if (step == m_Intensity)
			return;

		m_Intensity = step;
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(m_Intensity);
		rpc.Send(GetGame().GetPlayer(), DZNC_EyeRPC.SET_INTENSITY, true);
		PaintSlider();
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
		Paint(m_FilterAll, TabColor(!m_ChangedOnly));
		Paint(m_FilterGlowing, TabColor(m_ChangedOnly));

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

	// What a left press does is decided when it starts, until release: the header (not the close button)
	// drags the menu, the brightness slider follows the mouse, and anywhere outside the menu spins the
	// preview zombie like the inventory character. A press outside the open color list closes it.
	protected void UpdateMouseDrag(float timeslice)
	{
		int mouseX, mouseY;
		GetMousePos(mouseX, mouseY);
		bool held = GetMouseState(MouseState.LEFT) & MB_PRESSED_MASK;

		if (!held)
		{
			m_Dragging = false;
			m_MovingMenu = false;
			m_DraggingSlider = false;
		}
		else if (!m_MouseWasHeld)
		{
			if (m_ColorPopup.IsVisible() && !IsOver(m_ColorPopup, mouseX, mouseY) && !IsOver(m_ListColorPicker, mouseX, mouseY) && !IsOver(m_BulkColorPicker, mouseX, mouseY))
				m_ColorPopup.Show(false);

			if (IsOver(m_Header, mouseX, mouseY) && !IsOver(m_Close, mouseX, mouseY))
			{
				// Same offset-then-SetPos pattern as the vanilla item diagnostic window.
				float menuX, menuY;
				layoutRoot.GetScreenPos(menuX, menuY);
				m_MoveOffsetX = menuX - mouseX;
				m_MoveOffsetY = menuY - mouseY;
				m_MovingMenu = true;
			}
			else if (IsOver(m_BrightnessSlider, mouseX, mouseY) && !m_ColorPopup.IsVisible())
			{
				m_DraggingSlider = true;
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

		if (m_DraggingSlider)
			UpdateSliderFromMouse(mouseX);

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
