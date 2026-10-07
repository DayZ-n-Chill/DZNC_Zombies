// Debug lineup: with DebugLineup set in Admins.json, the first admin to join after a server start
// gets one frozen zombie of every menu type lined up in front of them to compare eyes side by side.
modded class MissionServer
{
	static const int DZNC_LINEUP_COLUMNS = 15;
	static const int DZNC_LINEUP_BATCH = 25;
	static const int DZNC_LINEUP_BATCH_DELAY = 100;
	static const float DZNC_LINEUP_COLUMN_SPACING = 1.5;
	static const float DZNC_LINEUP_ROW_SPACING = 4;
	static const float DZNC_LINEUP_START_DISTANCE = 6;

	protected bool m_DZNC_LineupSpawned;

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);

		if (m_DZNC_LineupSpawned || !player)
			return;

		DZNC_EyeSettings settings = DZNC_EyeSettings.Get();
		if (!settings.m_Admins.DebugLineup || !settings.IsAdmin(identity))
			return;

		m_DZNC_LineupSpawned = true;

		vector forward = player.GetDirection();
		forward[1] = 0;
		forward = forward.Normalized();

		Print("[DZNC_Zombies] Spawning debug lineup of " + DZNC_Eyes.ZOMBIE_TYPES.Count() + " zombies for admin " + identity.GetPlainId());
		DZNC_SpawnLineupBatch(player.GetPosition(), forward, 0);
	}

	protected void DZNC_SpawnLineupBatch(vector origin, vector forward, int start)
	{
		vector right = Vector(forward[2], 0, -forward[0]);
		int total = DZNC_Eyes.ZOMBIE_TYPES.Count();
		int end = start + DZNC_LINEUP_BATCH;
		if (end > total)
			end = total;

		for (int i = start; i < end; i++)
		{
			int row = i / DZNC_LINEUP_COLUMNS;
			int column = i % DZNC_LINEUP_COLUMNS;
			float side = (column - (DZNC_LINEUP_COLUMNS - 1) * 0.5) * DZNC_LINEUP_COLUMN_SPACING;
			float ahead = DZNC_LINEUP_START_DISTANCE + row * DZNC_LINEUP_ROW_SPACING;

			vector pos = origin + forward * ahead + right * side;
			pos[1] = GetGame().SurfaceY(pos[0], pos[2]);

			ZombieBase zombie = ZombieBase.Cast(GetGame().CreateObjectEx(DZNC_Eyes.ZOMBIE_TYPES[i], pos, ECE_PLACE_ON_SURFACE | ECE_INITAI));
			if (!zombie)
				continue;

			vector toAdmin = origin - pos;
			toAdmin[1] = 0;
			zombie.SetOrientation(Vector(toAdmin.VectorToAngles()[0], 0, 0));
			zombie.GetAIAgent().SetKeepInIdle(true);
		}

		if (end < total)
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DZNC_SpawnLineupBatch, DZNC_LINEUP_BATCH_DELAY, false, origin, forward, end);
	}
}
