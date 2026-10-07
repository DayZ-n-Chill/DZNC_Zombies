// Every zombie gets its eye color from the admin menu settings at runtime, so it works on any map.
// DZNC_ config classes follow the setting of the vanilla type they inherit from.
modded class ZombieBase
{
	static ref TStringArray DZNC_BLOCKED_SLOTS = {"Headgear", "Mask", "Eyewear"};
	// Every zombie the mod manages, on both server and client.
	static ref array<ZombieBase> s_DZNC_All = new array<ZombieBase>;

	// Client only. One shared ticker cycles every crazy zombie in step, so the server sends nothing per color.
	// Milliseconds each crazy color stays on screen.
	static const int DZNC_CRAZY_TICK_MS = 200;
	static int s_DZNC_CrazyStep;
	static bool s_DZNC_CrazyTicking;

	// Client only. Dead zombies step their eyes down to vanilla over DZNC_FADE_MS, driven by one shared ticker.
	static const int DZNC_FADE_MS = 5000;
	static const int DZNC_FADE_TICK_MS = 100;
	static const int DZNC_EYES_ALIVE = 0;
	static const int DZNC_EYES_FADING = 1;
	static const int DZNC_EYES_FADED = 2;
	static bool s_DZNC_FadeTicking;

	protected int m_DZNC_EyeColor;
	protected int m_DZNC_EyeIntensity = DZNC_Eyes.INTENSITY_DEFAULT;
	protected bool m_DZNC_Crazy;
	protected bool m_DZNC_FadeOnDeath;
	// Set by the server when the zombie dies, so every client gets one guaranteed sync for it.
	protected bool m_DZNC_Dead;
	protected int m_DZNC_DeathEyes = DZNC_EYES_ALIVE;
	protected int m_DZNC_FadeColor;
	protected int m_DZNC_FadeIntensity;
	protected int m_DZNC_FadeStart;
	// -1 means the material on the model is unknown (DZNC_ classes bake a glow rvmat), so the first apply always runs.
	protected int m_DZNC_AppliedEyeColor = -1;
	protected int m_DZNC_AppliedEyeIntensity = -1;
	protected string m_DZNC_SettingsKey;
	protected bool m_DZNC_SettingsKeyResolved;
	// Server only. Preview and lineup zombies stand still in the calm upright idle instead of reacting to players.
	protected bool m_DZNC_HoldUpright;

	static const int DZNC_UPRIGHT_STANCE = 0;
	static const int DZNC_CALM_IDLE = 0;

	override void Init()
	{
		super.Init();
		RegisterNetSyncVariableInt("m_DZNC_EyeColor", 0, DZNC_Eyes.COLOR_NAMES.Count() - 1);
		RegisterNetSyncVariableInt("m_DZNC_EyeIntensity", DZNC_Eyes.INTENSITY_MIN, DZNC_Eyes.INTENSITY_MAX);
		RegisterNetSyncVariableBool("m_DZNC_Crazy");
		RegisterNetSyncVariableBool("m_DZNC_FadeOnDeath");
		RegisterNetSyncVariableBool("m_DZNC_Dead");
	}

	override void EEInit()
	{
		super.EEInit();

		if (DZNC_GetSettingsKey() == "")
			return;

		s_DZNC_All.Insert(this);
		if (GetGame().IsServer())
		{
			m_DZNC_EyeIntensity = DZNC_EyeSettings.Get().GetIntensity();
			m_DZNC_Crazy = DZNC_EyeSettings.Get().GetCrazyMode();
			m_DZNC_FadeOnDeath = DZNC_EyeSettings.Get().GetFadeOnDeath();
			DZNC_SetEyeColor(DZNC_EyeSettings.Get().GetColor(DZNC_GetSettingsKey()));
		}
		else
		{
			// A zombie that was already dead when it streamed in shows vanilla eyes straight away.
			if (m_DZNC_FadeOnDeath && DZNC_IsDead())
				m_DZNC_DeathEyes = DZNC_EYES_FADED;
			// Covers zombies whose synced color never changes from its initial value, so OnVariablesSynchronized may not fire.
			DZNC_ApplyEyes();
		}
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		s_DZNC_All.RemoveItem(this);
	}

	// Vanilla only calls this on the server, see EntityAI.EEKilled.
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);

		if (DZNC_GetSettingsKey() == "")
			return;

		m_DZNC_Dead = true;
		SetSynchDirty();
	}

	bool DZNC_IsDead()
	{
		return m_DZNC_Dead || !IsAlive();
	}

	// The vanilla type whose admin setting this zombie follows, or "" if it is not covered by the menu.
	string DZNC_GetSettingsKey()
	{
		if (m_DZNC_SettingsKeyResolved)
			return m_DZNC_SettingsKey;

		m_DZNC_SettingsKeyResolved = true;
		string type = GetType();
		if (DZNC_Eyes.ZOMBIE_TYPES.Find(type) != -1)
		{
			m_DZNC_SettingsKey = type;
			return m_DZNC_SettingsKey;
		}

		if (type.IndexOf("DZNC_") != 0)
			return m_DZNC_SettingsKey;

		string child = type;
		string parent;
		while (GetGame().ConfigGetBaseName("CfgVehicles " + child, parent) && parent != "")
		{
			if (DZNC_Eyes.ZOMBIE_TYPES.Find(parent) != -1)
			{
				m_DZNC_SettingsKey = parent;
				break;
			}
			child = parent;
		}
		return m_DZNC_SettingsKey;
	}

	// Called by the admin menu so zombies already in the world change straight away.
	static void DZNC_ApplyToType(string type, int color)
	{
		foreach (ZombieBase zombie : s_DZNC_All)
		{
			if (zombie && zombie.DZNC_GetSettingsKey() == type)
				zombie.DZNC_SetEyeColor(color);
		}
	}

	// Called by the admin menu when the global eye brightness changes.
	static void DZNC_ApplyIntensity(int intensity)
	{
		foreach (ZombieBase zombie : s_DZNC_All)
		{
			if (zombie)
				zombie.DZNC_SetEyeIntensity(intensity);
		}
	}

	void DZNC_SetEyeIntensity(int intensity)
	{
		m_DZNC_EyeIntensity = DZNC_Eyes.ClampIntensity(intensity);
		DZNC_ApplyEyes();
		SetSynchDirty();
	}

	void DZNC_SetEyeColor(int color)
	{
		m_DZNC_EyeColor = color;
		DZNC_ApplyEyes();
		SetSynchDirty();
		DZNC_StripHeadgear();
	}

	// Called by the admin menu when crazy mode is switched on or off.
	static void DZNC_ApplyCrazy(bool crazy)
	{
		foreach (ZombieBase zombie : s_DZNC_All)
		{
			if (zombie)
				zombie.DZNC_SetCrazy(crazy);
		}
	}

	void DZNC_SetCrazy(bool crazy)
	{
		m_DZNC_Crazy = crazy;
		DZNC_ApplyEyes();
		SetSynchDirty();
		DZNC_StripHeadgear();
	}

	// Called by the admin menu when fade on death is switched on or off.
	static void DZNC_ApplyFade(bool fade)
	{
		foreach (ZombieBase zombie : s_DZNC_All)
		{
			if (zombie)
				zombie.DZNC_SetFadeOnDeath(fade);
		}
	}

	void DZNC_SetFadeOnDeath(bool fade)
	{
		m_DZNC_FadeOnDeath = fade;
		SetSynchDirty();
	}

	// Starts the fade from whatever the eyes show right now, including a crazy cycle color.
	protected void DZNC_StartFade()
	{
		if (!DZNC_Eyes.IsColor(m_DZNC_AppliedEyeColor))
		{
			m_DZNC_DeathEyes = DZNC_EYES_FADED;
			return;
		}

		m_DZNC_DeathEyes = DZNC_EYES_FADING;
		m_DZNC_FadeColor = m_DZNC_AppliedEyeColor;
		m_DZNC_FadeIntensity = m_DZNC_AppliedEyeIntensity;
		m_DZNC_FadeStart = GetGame().GetTime();

		if (s_DZNC_FadeTicking)
			return;

		s_DZNC_FadeTicking = true;
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DZNC_FadeTick, DZNC_FADE_TICK_MS, true);
	}

	protected static void DZNC_FadeTick()
	{
		bool anyFading;
		foreach (ZombieBase zombie : s_DZNC_All)
		{
			if (zombie && zombie.m_DZNC_DeathEyes == DZNC_EYES_FADING)
			{
				zombie.DZNC_UpdateFade();
				if (zombie.m_DZNC_DeathEyes == DZNC_EYES_FADING)
					anyFading = true;
			}
		}

		if (!anyFading)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(DZNC_FadeTick);
			s_DZNC_FadeTicking = false;
		}
	}

	// Each brightness step gets an equal share of the fade, then the vanilla material.
	protected void DZNC_UpdateFade()
	{
		int elapsed = GetGame().GetTime() - m_DZNC_FadeStart;
		int intensity = m_DZNC_FadeIntensity - elapsed * m_DZNC_FadeIntensity / DZNC_FADE_MS;
		if (intensity < DZNC_Eyes.INTENSITY_MIN)
		{
			m_DZNC_DeathEyes = DZNC_EYES_FADED;
			DZNC_ApplyMaterial(0, m_DZNC_EyeIntensity);
			return;
		}

		DZNC_ApplyMaterial(m_DZNC_FadeColor, intensity);
	}

	protected void DZNC_StripHeadgear()
	{
		if (!DZNC_StripsHeadgear())
			return;

		foreach (string slot : DZNC_BLOCKED_SLOTS)
		{
			EntityAI worn = FindAttachmentBySlotName(slot);
			if (worn)
				GetGame().ObjectDelete(worn);
		}
	}

	protected static void DZNC_StartCrazyTicker()
	{
		if (s_DZNC_CrazyTicking)
			return;

		s_DZNC_CrazyTicking = true;
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DZNC_CrazyTick, DZNC_CRAZY_TICK_MS, true);
	}

	// Advances every crazy zombie to the next color and stops itself once none are left.
	protected static void DZNC_CrazyTick()
	{
		s_DZNC_CrazyStep = (s_DZNC_CrazyStep + 1) % DZNC_Eyes.CRAZY_COLORS.Count();

		bool anyCrazy;
		foreach (ZombieBase zombie : s_DZNC_All)
		{
			if (zombie && zombie.m_DZNC_Crazy && zombie.m_DZNC_DeathEyes == DZNC_EYES_ALIVE)
			{
				zombie.DZNC_ApplyMaterial(DZNC_Eyes.CRAZY_COLORS[s_DZNC_CrazyStep], zombie.m_DZNC_EyeIntensity);
				anyCrazy = true;
			}
		}

		if (!anyCrazy)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(DZNC_CrazyTick);
			s_DZNC_CrazyTicking = false;
		}
	}

	// Freezes the zombie in place in its calm standing idle. Move command values replicate from the server.
	void DZNC_HoldUpright()
	{
		m_DZNC_HoldUpright = true;
		m_StanceVariation = DZNC_UPRIGHT_STANCE;
		GetAIAgent().SetKeepInIdle(true);
	}

	// Runs before the vanilla mind state, vault and fight handling, which would otherwise switch to the alerted idle.
	override bool ModCommandHandlerInside(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		if (!m_DZNC_HoldUpright)
			return super.ModCommandHandlerInside(pDt, pCurrentCommandID, pCurrentCommandFinished);

		DayZInfectedCommandMove moveCommand = GetCommand_Move();
		if (moveCommand && !moveCommand.IsTurning())
		{
			moveCommand.SetStanceVariation(DZNC_UPRIGHT_STANCE);
			moveCommand.SetIdleState(DZNC_CALM_IDLE);
		}
		return true;
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if (DZNC_GetSettingsKey() != "")
			DZNC_ApplyEyes();
	}

	// Crazy cycling and the death fade only run on clients. The dedicated server keeps the saved color.
	protected void DZNC_ApplyEyes()
	{
		if (!GetGame().IsDedicatedServer())
		{
			if (m_DZNC_DeathEyes == DZNC_EYES_ALIVE && m_DZNC_FadeOnDeath && DZNC_IsDead())
				DZNC_StartFade();

			if (m_DZNC_DeathEyes == DZNC_EYES_FADING)
				return;

			if (m_DZNC_DeathEyes == DZNC_EYES_FADED)
			{
				DZNC_ApplyMaterial(0, m_DZNC_EyeIntensity);
				return;
			}

			if (m_DZNC_Crazy)
			{
				DZNC_ApplyMaterial(DZNC_Eyes.CRAZY_COLORS[s_DZNC_CrazyStep], m_DZNC_EyeIntensity);
				DZNC_StartCrazyTicker();
				return;
			}
		}

		DZNC_ApplyMaterial(m_DZNC_EyeColor, m_DZNC_EyeIntensity);
	}

	protected void DZNC_ApplyMaterial(int color, int intensity)
	{
		string key = DZNC_GetSettingsKey();

		// Vanilla types spawn wearing the vanilla rvmat, so there is nothing to undo for them.
		if (m_DZNC_AppliedEyeColor == -1 && key == GetType())
			m_DZNC_AppliedEyeColor = 0;

		if (color == m_DZNC_AppliedEyeColor)
		{
			// Vanilla eyes ignore brightness, so only a glow color needs re-applying for a new step.
			if (!DZNC_Eyes.IsColor(color) || intensity == m_DZNC_AppliedEyeIntensity)
				return;
		}

		m_DZNC_AppliedEyeColor = color;
		m_DZNC_AppliedEyeIntensity = intensity;
		SetObjectMaterial(0, DZNC_Eyes.GetMaterial(key, color, intensity));
	}

	// Debug only: with DebugLineup on, the server keeps glowing zombies bare-headed so the eyes are easy to judge.
	// Otherwise, and always on clients, attachments behave exactly like vanilla.
	bool DZNC_StripsHeadgear()
	{
		if (!GetGame().IsServer() || !DZNC_EyeSettings.Get().m_Admins.DebugLineup)
			return false;

		string key = DZNC_GetSettingsKey();
		if (key == "")
			return GetType().IndexOf("DZNC_") == 0;
		return DZNC_EyeSettings.Get().GetCrazyMode() || DZNC_Eyes.IsColor(DZNC_EyeSettings.Get().GetColor(key));
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (DZNC_StripsHeadgear() && DZNC_BLOCKED_SLOTS.Find(InventorySlots.GetSlotName(slotId)) != -1)
			return false;

		return super.CanReceiveAttachment(attachment, slotId);
	}

	// The Central Economy can attach spawn gear without asking CanReceiveAttachment, so strip anything that lands anyway.
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		if (DZNC_StripsHeadgear() && DZNC_BLOCKED_SLOTS.Find(slot_name) != -1)
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(GetGame().ObjectDelete, item);
	}
}
