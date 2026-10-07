// Shared eye color definitions, server settings storage and RPC ids.

enum DZNC_EyeRPC
{
	REQUEST_MENU = 0x445A4E00,	// client -> server: open the admin menu
	MENU_DATA,					// server -> client: admin settings
	SET_EYES,					// client -> server: change one zombie type
	NOT_ADMIN,					// server -> client: request refused
	SHOW_PREVIEW,				// client -> server: spawn a preview zombie at a given spot and yaw near the admin
	CLOSE_PREVIEW,				// client -> server: remove it
	SET_MANY,					// client -> server: change a batch of zombie types at once
	ROTATE_PREVIEW				// client -> server: spin the preview zombie
}

class DZNC_Eyes
{
	// Index 0 leaves the zombie looking vanilla.
	static ref TStringArray COLOR_NAMES = {"Vanilla", "Yellow", "Red", "Blue", "Green", "Orange"};
	static ref array<int> COLOR_ARGB = {0xFF808080, 0xFFFFE000, 0xFFFF2020, 0xFF2080FF, 0xFF20FF40, 0xFFFF8000};

	// Every vanilla infected class the glowing eye materials were made for.
	static ref TStringArray ZOMBIE_TYPES = {
		"ZmbM_HermitSkinny_Beige",
		"ZmbF_BlueCollarFat_Blue",
		"ZmbF_BlueCollarFat_Green",
		"ZmbM_HermitSkinny_Black",
		"ZmbM_HermitSkinny_Green",
		"ZmbM_HermitSkinny_Red",
		"ZmbM_FarmerFat_Beige",
		"ZmbM_FarmerFat_Blue",
		"ZmbM_FarmerFat_Brown",
		"ZmbM_FarmerFat_Green",
		"ZmbF_CitizenANormal_Beige",
		"ZmbF_CitizenANormal_Brown",
		"ZmbF_CitizenANormal_Blue",
		"ZmbM_CitizenASkinny_Blue",
		"ZmbM_CitizenASkinny_Brown",
		"ZmbM_CitizenASkinny_Grey",
		"ZmbM_CitizenASkinny_Red",
		"ZmbM_CitizenBFat_Blue",
		"ZmbM_CitizenBFat_Red",
		"ZmbM_CitizenBFat_Green",
		"ZmbF_CitizenBSkinny",
		"ZmbM_PrisonerSkinny",
		"ZmbM_FirefighterNormal",
		"ZmbM_FishermanOld_Blue",
		"ZmbM_FishermanOld_Green",
		"ZmbM_FishermanOld_Grey",
		"ZmbM_FishermanOld_Red",
		"ZmbM_JournalistSkinny",
		"ZmbF_JournalistNormal_Blue",
		"ZmbF_JournalistNormal_Green",
		"ZmbF_JournalistNormal_Red",
		"ZmbF_JournalistNormal_White",
		"ZmbM_ParamedicNormal_Black",
		"ZmbF_ParamedicNormal_Blue",
		"ZmbF_ParamedicNormal_Green",
		"ZmbF_ParamedicNormal_Red",
		"ZmbM_HikerSkinny_Blue",
		"ZmbM_HikerSkinny_Green",
		"ZmbM_HikerSkinny_Yellow",
		"ZmbF_HikerSkinny_Grey",
		"ZmbF_HikerSkinny_Red",
		"ZmbM_HunterOld_Autumn",
		"ZmbM_HunterOld_Spring",
		"ZmbM_HunterOld_Summer",
		"ZmbM_HunterOld_Winter",
		"ZmbF_SurvivorNormal_Blue",
		"ZmbF_SurvivorNormal_Orange",
		"ZmbF_SurvivorNormal_Red",
		"ZmbF_SurvivorNormal_White",
		"ZmbM_PolicemanFat",
		"ZmbF_PoliceWomanNormal",
		"ZmbM_PolicemanSpecForce",
		"ZmbM_SoldierNormal",
		"ZmbM_usSoldier_normal_Woodland",
		"ZmbM_usSoldier_normal_Desert",
		"ZmbM_CommercialPilotOld_Blue",
		"ZmbM_CommercialPilotOld_Olive",
		"ZmbM_CommercialPilotOld_Brown",
		"ZmbM_CommercialPilotOld_Grey",
		"ZmbM_PatrolNormal_PautRev",
		"ZmbM_PatrolNormal_Autumn",
		"ZmbM_PatrolNormal_Flat",
		"ZmbM_PatrolNormal_Summer",
		"ZmbM_JoggerSkinny_Blue",
		"ZmbM_JoggerSkinny_Green",
		"ZmbM_JoggerSkinny_Red",
		"ZmbF_JoggerSkinny_Brown",
		"ZmbM_MotobikerFat_Beige",
		"ZmbM_MotobikerFat_Black",
		"ZmbM_MotobikerFat_Blue",
		"ZmbM_VillagerOld_Blue",
		"ZmbM_VillagerOld_Green",
		"ZmbM_VillagerOld_White",
		"ZmbM_SkaterYoung_Blue",
		"ZmbM_SkaterYoung_Brown",
		"ZmbM_SkaterYoung_Green",
		"ZmbM_SkaterYoung_Grey",
		"ZmbF_SkaterYoung_Striped",
		"ZmbF_SkaterYoung_Violet",
		"ZmbF_DoctorSkinny",
		"ZmbF_BlueCollarFat_Red",
		"ZmbF_BlueCollarFat_White",
		"ZmbF_MechanicNormal_Beige",
		"ZmbF_MechanicNormal_Green",
		"ZmbF_MechanicNormal_Grey",
		"ZmbF_MechanicNormal_Orange",
		"ZmbM_MechanicSkinny_Blue",
		"ZmbM_MechanicSkinny_Grey",
		"ZmbM_MechanicSkinny_Green",
		"ZmbM_MechanicSkinny_Red",
		"ZmbM_ConstrWorkerNormal_Beige",
		"ZmbM_ConstrWorkerNormal_Black",
		"ZmbM_ConstrWorkerNormal_Green",
		"ZmbM_ConstrWorkerNormal_Grey",
		"ZmbM_HeavyIndustryWorker",
		"ZmbM_OffshoreWorker_Green",
		"ZmbM_OffshoreWorker_Orange",
		"ZmbM_OffshoreWorker_Red",
		"ZmbM_OffshoreWorker_Yellow",
		"ZmbF_NurseFat",
		"ZmbM_HandymanNormal_Beige",
		"ZmbM_HandymanNormal_Blue",
		"ZmbM_HandymanNormal_Green",
		"ZmbM_HandymanNormal_Grey",
		"ZmbM_HandymanNormal_White",
		"ZmbM_DoctorFat",
		"ZmbM_Jacket_beige",
		"ZmbM_Jacket_black",
		"ZmbM_Jacket_blue",
		"ZmbM_Jacket_bluechecks",
		"ZmbM_Jacket_brown",
		"ZmbM_Jacket_greenchecks",
		"ZmbM_Jacket_grey",
		"ZmbM_Jacket_khaki",
		"ZmbM_Jacket_magenta",
		"ZmbM_Jacket_stripes",
		"ZmbF_PatientOld",
		"ZmbM_PatientSkinny",
		"ZmbF_ShortSkirt_beige",
		"ZmbF_ShortSkirt_black",
		"ZmbF_ShortSkirt_brown",
		"ZmbF_ShortSkirt_green",
		"ZmbF_ShortSkirt_grey",
		"ZmbF_ShortSkirt_checks",
		"ZmbF_ShortSkirt_red",
		"ZmbF_ShortSkirt_stripes",
		"ZmbF_ShortSkirt_white",
		"ZmbF_ShortSkirt_yellow",
		"ZmbF_VillagerOld_Red",
		"ZmbF_MilkMaidOld_Beige",
		"ZmbF_MilkMaidOld_Black",
		"ZmbF_MilkMaidOld_Green",
		"ZmbF_MilkMaidOld_Grey",
		"ZmbM_priestPopSkinny",
		"ZmbM_ClerkFat_Brown",
		"ZmbM_ClerkFat_Grey",
		"ZmbM_ClerkFat_Khaki",
		"ZmbM_ClerkFat_White",
		"ZmbF_Clerk_Normal_Blue",
		"ZmbF_Clerk_Normal_White",
		"ZmbF_Clerk_Normal_Green",
		"ZmbF_Clerk_Normal_Red",
		"ZmbF_ClerkFat_Black",
		"ZmbF_ClerkFat_GreyPattern",
		"ZmbF_ClerkFat_BluePattern"
	};

	// "ZmbM_HermitSkinny_Beige" -> "Hermit Skinny Beige (M)"
	static string PrettyName(string type)
	{
		string gender = type.Substring(3, 1);
		string body = type.Substring(5, type.Length() - 5);
		string pretty;
		for (int i = 0; i < body.Length(); i++)
		{
			string ch = body.Get(i);
			if (ch == "_")
			{
				pretty += " ";
				continue;
			}
			string upper = ch;
			upper.ToUpper();
			if (i > 0 && ch == upper && body.Get(i - 1) != "_")
				pretty += " ";
			if (i == 0 || body.Get(i - 1) == "_")
				ch = upper;
			pretty += ch;
		}
		return pretty + " (" + gender + ")";
	}

	// Outfit variants share everything before the last underscore, e.g. ZmbM_HermitSkinny_*.
	static string FamilyOf(string type)
	{
		int cut = type.LastIndexOf("_");
		if (cut <= 4)
			return type;
		return type.Substring(0, cut);
	}

	static bool IsColor(int color)
	{
		return color > 0 && color < COLOR_NAMES.Count();
	}

	// Handyman and short skirt models have their eyes in a different UV spot, so they use their own masks.
	static string GetMaterial(string type, int color)
	{
		if (!IsColor(color))
		{
			TStringArray mats = new TStringArray;
			GetGame().ConfigGetTextArray("CfgVehicles " + type + " hiddenSelectionsMaterials", mats);
			if (mats.Count() > 0)
				return mats[0];
			return "";
		}

		string colorName = COLOR_NAMES[color];
		string family;
		if (type.Contains("HandymanNormal"))
			family = "HandyEyes";
		else if (type.Contains("ShortSkirt"))
			family = "SkirtEyes";

		if (family != "")
		{
			if (colorName == "Yellow")
				return "DZNC_Zombies\\data\\" + family + ".rvmat";
			return "DZNC_Zombies\\data\\" + family + "." + colorName + ".rvmat";
		}

		if (colorName == "Yellow")
			return "DZNC_Zombies\\data\\eyes.rvmat";
		colorName.ToLower();
		return "DZNC_Zombies\\data\\" + colorName + "-eyes.rvmat";
	}
}

class DZNC_EyeSettingsData
{
	ref map<string, int> ZombieEyes = new map<string, int>;
}

class DZNC_AdminData
{
	ref TStringArray SteamIDs = new TStringArray;
}

// Server only. Lives in $profile:DZNC_Zombies so it works the same on every map.
class DZNC_EyeSettings
{
	static const string DIR = "$profile:DZNC_Zombies";
	static const string SETTINGS_FILE = DIR + "/EyeSettings.json";
	static const string ADMINS_FILE = DIR + "/Admins.json";

	private static ref DZNC_EyeSettings s_Instance;

	ref DZNC_EyeSettingsData m_Data = new DZNC_EyeSettingsData;
	ref DZNC_AdminData m_Admins = new DZNC_AdminData;

	static DZNC_EyeSettings Get()
	{
		if (!s_Instance)
		{
			s_Instance = new DZNC_EyeSettings;
			s_Instance.Load();
		}
		return s_Instance;
	}

	void Load()
	{
		if (!FileExist(DIR))
			MakeDirectory(DIR);

		string error;
		if (FileExist(SETTINGS_FILE) && !JsonFileLoader<DZNC_EyeSettingsData>.LoadFile(SETTINGS_FILE, m_Data, error))
			Print("[DZNC_Zombies] " + error);
		if (!FileExist(ADMINS_FILE))
			JsonFileLoader<DZNC_AdminData>.SaveFile(ADMINS_FILE, m_Admins, error);
		else if (!JsonFileLoader<DZNC_AdminData>.LoadFile(ADMINS_FILE, m_Admins, error))
			Print("[DZNC_Zombies] " + error);
	}

	void Save()
	{
		string error;
		if (!JsonFileLoader<DZNC_EyeSettingsData>.SaveFile(SETTINGS_FILE, m_Data, error))
			Print("[DZNC_Zombies] " + error);
	}

	bool IsAdmin(PlayerIdentity identity)
	{
		return identity && m_Admins.SteamIDs.Find(identity.GetPlainId()) != -1;
	}

	int GetColor(string type)
	{
		return m_Data.ZombieEyes.Get(type);
	}

	void SetColor(string type, int color)
	{
		if (DZNC_Eyes.IsColor(color))
			m_Data.ZombieEyes.Set(type, color);
		else
			m_Data.ZombieEyes.Remove(type);
	}
}
