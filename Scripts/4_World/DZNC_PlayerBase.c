// Admin menu traffic rides on the player entity. The server checks the admin list on every request.
modded class PlayerBase
{
	static const float DZNC_PREVIEW_MAX_RANGE = 15;

	protected ZombieBase m_DZNC_PreviewZombie;
	protected float m_DZNC_PreviewBaseYaw;

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		switch (rpc_type)
		{
			case DZNC_EyeRPC.REQUEST_MENU:
				DZNC_OnMenuRequest(sender);
				break;
			case DZNC_EyeRPC.SET_EYES:
				DZNC_OnSetEyes(sender, ctx);
				break;
			case DZNC_EyeRPC.SET_MANY:
				DZNC_OnSetMany(sender, ctx);
				break;
			case DZNC_EyeRPC.SET_INTENSITY:
				DZNC_OnSetIntensity(sender, ctx);
				break;
			case DZNC_EyeRPC.SHOW_PREVIEW:
				DZNC_OnShowPreview(sender, ctx);
				break;
			case DZNC_EyeRPC.ROTATE_PREVIEW:
				DZNC_OnRotatePreview(sender, ctx);
				break;
			case DZNC_EyeRPC.CLOSE_PREVIEW:
				DZNC_DeletePreview();
				break;
			case DZNC_EyeRPC.MENU_DATA:
				DZNC_OnMenuData(ctx);
				break;
			case DZNC_EyeRPC.NOT_ADMIN:
				NotificationSystem.AddNotificationExtended(4, "Zombie Eyes", "You are not on the DZNC_Zombies admin list.");
				break;
		}
	}

	protected void DZNC_OnMenuRequest(PlayerIdentity sender)
	{
		if (!GetGame().IsServer())
			return;

		DZNC_EyeSettings settings = DZNC_EyeSettings.Get();
		ScriptRPC rpc = new ScriptRPC();
		if (!settings.IsAdmin(sender))
		{
			Print("[DZNC_Zombies] Refused menu for non-admin " + sender.GetPlainId());
			rpc.Send(this, DZNC_EyeRPC.NOT_ADMIN, true, sender);
			return;
		}

		array<int> colors = new array<int>;
		foreach (string type : DZNC_Eyes.ZOMBIE_TYPES)
			colors.Insert(settings.GetColor(type));
		rpc.Write(colors);
		rpc.Write(settings.GetIntensity());
		rpc.Send(this, DZNC_EyeRPC.MENU_DATA, true, sender);
		Print("[DZNC_Zombies] Opened eye menu for admin " + sender.GetPlainId());
	}

	protected void DZNC_OnSetEyes(PlayerIdentity sender, ParamsReadContext ctx)
	{
		if (!GetGame().IsServer() || !DZNC_EyeSettings.Get().IsAdmin(sender))
			return;

		string type;
		int color;
		if (!ctx.Read(type) || !ctx.Read(color))
			return;
		if (DZNC_Eyes.ZOMBIE_TYPES.Find(type) == -1 || color < 0 || color >= DZNC_Eyes.COLOR_NAMES.Count())
			return;

		DZNC_EyeSettings.Get().SetColor(type, color);
		DZNC_EyeSettings.Get().Save();
		ZombieBase.DZNC_ApplyToType(type, color);
		Print("[DZNC_Zombies] " + sender.GetPlainId() + " set " + type + " eyes to " + DZNC_Eyes.COLOR_NAMES[color]);
	}

	protected void DZNC_OnSetMany(PlayerIdentity sender, ParamsReadContext ctx)
	{
		if (!GetGame().IsServer() || !DZNC_EyeSettings.Get().IsAdmin(sender))
			return;

		TStringArray types = new TStringArray;
		int color;
		if (!ctx.Read(types) || !ctx.Read(color) || color < 0 || color >= DZNC_Eyes.COLOR_NAMES.Count())
			return;

		int changed;
		foreach (string type : types)
		{
			if (DZNC_Eyes.ZOMBIE_TYPES.Find(type) == -1)
				continue;
			DZNC_EyeSettings.Get().SetColor(type, color);
			ZombieBase.DZNC_ApplyToType(type, color);
			changed++;
		}
		DZNC_EyeSettings.Get().Save();
		Print("[DZNC_Zombies] " + sender.GetPlainId() + " set " + changed + " zombie types to " + DZNC_Eyes.COLOR_NAMES[color] + " eyes");
	}

	protected void DZNC_OnSetIntensity(PlayerIdentity sender, ParamsReadContext ctx)
	{
		if (!GetGame().IsServer() || !DZNC_EyeSettings.Get().IsAdmin(sender))
			return;

		int intensity;
		if (!ctx.Read(intensity))
			return;

		DZNC_EyeSettings settings = DZNC_EyeSettings.Get();
		settings.SetIntensity(intensity);
		settings.Save();
		ZombieBase.DZNC_ApplyIntensity(settings.GetIntensity());
		Print("[DZNC_Zombies] " + sender.GetPlainId() + " set eye brightness to " + settings.GetIntensity());
	}

	// Spawns a frozen zombie where the admin's menu shows it inside the preview frame, so the eyes can be
	// judged in the real world. The client works out the spot and the yaw that faces its camera.
	protected void DZNC_OnShowPreview(PlayerIdentity sender, ParamsReadContext ctx)
	{
		if (!GetGame().IsServer() || !DZNC_EyeSettings.Get().IsAdmin(sender))
			return;

		string type;
		vector pos;
		float yaw;
		if (!ctx.Read(type) || !ctx.Read(pos) || !ctx.Read(yaw) || DZNC_Eyes.ZOMBIE_TYPES.Find(type) == -1)
			return;

		DZNC_DeletePreview();

		pos[1] = GetGame().SurfaceY(pos[0], pos[2]);
		if (vector.Distance(pos, GetPosition()) > DZNC_PREVIEW_MAX_RANGE)
			return;

		m_DZNC_PreviewZombie = ZombieBase.Cast(GetGame().CreateObjectEx(type, pos, ECE_PLACE_ON_SURFACE | ECE_INITAI | ECE_NOLIFETIME));
		if (!m_DZNC_PreviewZombie)
			return;

		m_DZNC_PreviewBaseYaw = yaw;
		m_DZNC_PreviewZombie.SetOrientation(Vector(m_DZNC_PreviewBaseYaw, 0, 0));
		m_DZNC_PreviewZombie.GetAIAgent().SetKeepInIdle(true);
	}

	// Yaw is relative to facing the admin's camera, so 0 always means "looking at me".
	protected void DZNC_OnRotatePreview(PlayerIdentity sender, ParamsReadContext ctx)
	{
		if (!GetGame().IsServer() || !m_DZNC_PreviewZombie || !DZNC_EyeSettings.Get().IsAdmin(sender))
			return;

		float yaw;
		if (!ctx.Read(yaw))
			return;

		m_DZNC_PreviewZombie.SetOrientation(Vector(m_DZNC_PreviewBaseYaw + yaw, 0, 0));
	}

	protected void DZNC_DeletePreview()
	{
		if (m_DZNC_PreviewZombie)
			GetGame().ObjectDelete(m_DZNC_PreviewZombie);
		m_DZNC_PreviewZombie = null;
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		if (GetGame().IsServer())
			DZNC_DeletePreview();
	}

	protected void DZNC_OnMenuData(ParamsReadContext ctx)
	{
		array<int> colors = new array<int>;
		int intensity;
		if (!ctx.Read(colors) || !ctx.Read(intensity))
		{
			Print("[DZNC_Zombies] Could not read eye menu data");
			return;
		}

		Print("[DZNC_Zombies] Eye menu data received for " + colors.Count() + " zombie types");
		DZNC_EyeMenu.Open(colors, intensity);
	}
}
