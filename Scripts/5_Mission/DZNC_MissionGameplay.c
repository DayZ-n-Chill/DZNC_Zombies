// The hotkey toggles the zombie eye admin menu. The server decides whether this player may open it.
modded class MissionGameplay
{
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		if (id != DZNC_EyeMenu.MENU_ID)
			return super.CreateScriptedMenu(id);

		UIScriptedMenu menu = new DZNC_EyeMenu;
		menu.SetID(id);
		return menu;
	}

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		if (!GetUApi().GetInputByName("UADZNCZombieEyeMenu").LocalPress())
			return;

		UIScriptedMenu menu = GetGame().GetUIManager().GetMenu();
		if (DZNC_EyeMenu.IsOpen())
		{
			menu.Close();
			return;
		}

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!menu && player)
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Send(player, DZNC_EyeRPC.REQUEST_MENU, true);
		}
	}
}
