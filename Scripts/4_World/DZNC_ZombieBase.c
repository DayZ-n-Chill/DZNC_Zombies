// Glowing eye zombies never wear anything on their heads, so the eyes stay visible.
// Every zombie gets its eye color from the admin menu settings at runtime, so it works on any map.
// DZNC_ config classes follow the setting of the vanilla type they inherit from.
modded class ZombieBase
{
	static ref TStringArray DZNC_BLOCKED_SLOTS = {"Headgear", "Mask", "Eyewear"};
	static ref array<ZombieBase> s_DZNC_All = new array<ZombieBase>;

	protected int m_DZNC_EyeColor;
	// -1 means the material on the model is unknown (DZNC_ classes bake a glow rvmat), so the first apply always runs.
	protected int m_DZNC_AppliedEyeColor = -1;
	protected string m_DZNC_SettingsKey;
	protected bool m_DZNC_SettingsKeyResolved;

	override void Init()
	{
		super.Init();
		RegisterNetSyncVariableInt("m_DZNC_EyeColor", 0, DZNC_Eyes.COLOR_NAMES.Count() - 1);
	}

	override void EEInit()
	{
		super.EEInit();

		if (DZNC_GetSettingsKey() == "")
			return;

		if (GetGame().IsServer())
		{
			s_DZNC_All.Insert(this);
			DZNC_SetEyeColor(DZNC_EyeSettings.Get().GetColor(DZNC_GetSettingsKey()));
		}
		else
		{
			// Covers zombies whose synced color never changes from its initial value, so OnVariablesSynchronized may not fire.
			DZNC_ApplyEyes();
		}
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		s_DZNC_All.RemoveItem(this);
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

	void DZNC_SetEyeColor(int color)
	{
		m_DZNC_EyeColor = color;
		DZNC_ApplyEyes();
		SetSynchDirty();

		if (DZNC_IsGlowZombie())
		{
			foreach (string slot : DZNC_BLOCKED_SLOTS)
			{
				EntityAI worn = FindAttachmentBySlotName(slot);
				if (worn)
					GetGame().ObjectDelete(worn);
			}
		}
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if (DZNC_GetSettingsKey() != "")
			DZNC_ApplyEyes();
	}

	protected void DZNC_ApplyEyes()
	{
		string key = DZNC_GetSettingsKey();

		// Vanilla types spawn wearing the vanilla rvmat, so there is nothing to undo for them.
		if (m_DZNC_AppliedEyeColor == -1 && key == GetType())
			m_DZNC_AppliedEyeColor = 0;

		if (m_DZNC_EyeColor == m_DZNC_AppliedEyeColor)
			return;

		m_DZNC_AppliedEyeColor = m_DZNC_EyeColor;
		SetObjectMaterial(0, DZNC_Eyes.GetMaterial(key, m_DZNC_EyeColor));
	}

	bool DZNC_IsGlowZombie()
	{
		string key = DZNC_GetSettingsKey();
		if (key == "")
			return GetType().IndexOf("DZNC_") == 0;
		if (GetGame().IsServer())
			return DZNC_Eyes.IsColor(DZNC_EyeSettings.Get().GetColor(key));
		return DZNC_Eyes.IsColor(m_DZNC_EyeColor);
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (DZNC_IsGlowZombie() && DZNC_BLOCKED_SLOTS.Find(InventorySlots.GetSlotName(slotId)) != -1)
			return false;

		return super.CanReceiveAttachment(attachment, slotId);
	}

	// The Central Economy can attach spawn gear without asking CanReceiveAttachment, so strip anything that lands anyway.
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		if (GetGame().IsServer() && DZNC_IsGlowZombie() && DZNC_BLOCKED_SLOTS.Find(slot_name) != -1)
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(GetGame().ObjectDelete, item);
	}
}
