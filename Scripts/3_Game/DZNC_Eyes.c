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
	ROTATE_PREVIEW,				// client -> server: spin the preview zombie
	SET_INTENSITY,				// client -> server: change the global eye brightness step
	SET_CRAZY,					// client -> server: turn crazy mode on (1) or off (0)
	SET_FADE					// client -> server: turn fade on death on (1) or off (0)
}

class DZNC_Eyes
{
	// Brightness steps. Each glow material exists once per step, 5 is the original brightness.
	static const int INTENSITY_MIN = 1;
	static const int INTENSITY_MAX = 10;
	static const int INTENSITY_DEFAULT = 5;

	// Crazy mode cycles every zombie through these colors in order: Red, Orange, Yellow, Green, Blue, Indigo, Violet.
	// The time per color is ZombieBase.DZNC_CRAZY_TICK_MS.
	static ref array<int> CRAZY_COLORS = {2, 5, 1, 4, 3, 6, 7};

	// Index 0 leaves the zombie looking vanilla. Only append new colors, saved settings store these indices.
	static ref TStringArray COLOR_NAMES = {"Vanilla", "Yellow", "Red", "Blue", "Green", "Orange", "Indigo", "Violet"};
	static ref array<int> COLOR_ARGB = {0xFF808080, 0xFFFFE000, 0xFFFF2020, 0xFF2080FF, 0xFF20FF40, 0xFFFF8000, 0xFF4B2BFF, 0xFFB040FF};

	// Vanilla body materials that have glow copies in data\bodies, named <body>_<color>_<step>.rvmat.
	// To support a new body, add its rvmat file name here (lowercase, no extension).
	static ref TStringArray SUPPORTED_BODIES = {
		"hermit", "bluecollar_fat_f", "farmer", "citizena_normal_f", "citizena_skinny_m",
		"citizenb_fat_m", "citizenb_skinny_f", "prisoner_skinny_m", "firefighter_normal_m", "fisherman_old_m",
		"journalist_skinny_m", "journalist_normal_f", "paramedic_normal_m", "paramedic_normal_f", "hiker_skinny_m",
		"hiker_skinny_f", "hunter_old_m", "survivor_normal_f", "policeman_fat_m", "policewoman_normal_f",
		"policemanspecialforce_normal_m", "soldier_normal_m", "ussoldier_normal_m", "commercialpilot_old_m", "patrol_normal_m",
		"jogger_skinny_m", "jogger_skinny_f", "motobiker_fat_m", "villager_old_m", "skater_young_m",
		"skater_young_f", "doctor_skinny_f", "mechanic_normal_f", "mechanic_skinny_m", "constructionworker_normal_m",
		"heavyindustryworker_normal_m", "offshoreworker_normal_m", "nurse_fat_f", "coveralls", "doctor_fat_m",
		"jacket", "patient_old_f", "patient_skinny_m", "shortskirt", "villager_old_f",
		"milkmaid_old_f", "priestpop_skinny_m", "clerk_fat_m", "clerka_normal_f", "clerkb_fat_f",
		"gamedev_m", "santa", "armyofficer_fat_m"
	};

	// Every infected class in CfgVehicles whose body has glow materials, sorted. Filled once by Discover()
	// when the game is created, so server and client build the same list from the same config.
	static ref TStringArray ZOMBIE_TYPES = new TStringArray;

	// Infected type -> file name of its vanilla body material, e.g. "hermit".
	private static ref map<string, string> s_BodyBases = new map<string, string>;

	static void Discover(CGame game)
	{
		ZOMBIE_TYPES.Clear();
		s_BodyBases.Clear();

		TStringArray infected = new TStringArray;
		TStringArray fullPath = new TStringArray;
		int count = game.ConfigGetChildrenCount("CfgVehicles");
		for (int i = 0; i < count; i++)
		{
			string name;
			if (!game.ConfigGetChildName("CfgVehicles", i, name) || name.IndexOf("DZNC_") == 0)
				continue;
			if (game.ConfigGetInt("CfgVehicles " + name + " scope") != 2 || !IsInfected(game, name, fullPath))
				continue;

			infected.Insert(name);
			s_BodyBases.Set(name, ReadBodyBase(game, name));
		}

		foreach (string type : infected)
		{
			string body = s_BodyBases.Get(type);
			if (body == "")
			{
				body = FamilyBodyBase(type, infected);
				s_BodyBases.Set(type, body);
			}
			if (SUPPORTED_BODIES.Find(body) != -1)
				ZOMBIE_TYPES.Insert(type);
		}
		ZOMBIE_TYPES.Sort();
	}

	// Script class ZombieMaleBase and ZombieFemaleBase both extend ZombieBase, so any of the three in the config chain counts.
	protected static bool IsInfected(CGame game, string name, TStringArray fullPath)
	{
		fullPath.Clear();
		game.ConfigGetFullPath("CfgVehicles " + name, fullPath);
		foreach (string parent : fullPath)
		{
			parent.ToLower();
			if (parent == "zombiebase" || parent == "zombiemalebase" || parent == "zombiefemalebase")
				return true;
		}
		return false;
	}

	// First non-empty hiddenSelectionsMaterials entry, walking up the parent chain in case a child overrides it with blanks.
	protected static string ReadBodyBase(CGame game, string name)
	{
		TStringArray mats = new TStringArray;
		string cls = name;
		while (cls != "")
		{
			mats.Clear();
			game.ConfigGetTextArray("CfgVehicles " + cls + " hiddenSelectionsMaterials", mats);
			foreach (string mat : mats)
			{
				string base = FileBaseName(mat);
				if (base != "")
					return base;
			}

			string parent;
			if (!game.ConfigGetBaseName("CfgVehicles " + cls, parent))
				break;
			cls = parent;
		}
		return "";
	}

	// Types with no material anywhere in their chain borrow the body of another outfit of the same family.
	protected static string FamilyBodyBase(string type, TStringArray infected)
	{
		string family = FamilyOf(type);
		foreach (string other : infected)
		{
			string body = s_BodyBases.Get(other);
			if (body != "" && FamilyOf(other) == family)
				return body;
		}
		// ZmbF_ShortSkirt_Black has no hiddenSelectionsMaterials anywhere in its chain.
		if (family == "ZmbF_ShortSkirt")
			return "shortskirt";
		return "";
	}

	// "dz\characters\zombies\data\hermit.rvmat" -> "hermit"
	protected static string FileBaseName(string path)
	{
		string base = path;
		base.Replace("/", "\\");
		int slash = base.LastIndexOf("\\");
		if (slash != -1)
			base = base.Substring(slash + 1, base.Length() - slash - 1);
		int dot = base.LastIndexOf(".");
		if (dot != -1)
			base = base.Substring(0, dot);
		base.TrimInPlace();
		base.ToLower();
		return base;
	}

	// The discovered type matching a name regardless of case, or the name itself if none does.
	static string MatchType(string name)
	{
		if (ZOMBIE_TYPES.Find(name) != -1)
			return name;

		string lower = name;
		lower.ToLower();
		foreach (string type : ZOMBIE_TYPES)
		{
			string typeLower = type;
			typeLower.ToLower();
			if (typeLower == lower)
				return type;
		}
		return name;
	}

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

	static int ClampIntensity(int intensity)
	{
		if (intensity < INTENSITY_MIN)
			return INTENSITY_MIN;
		if (intensity > INTENSITY_MAX)
			return INTENSITY_MAX;
		return intensity;
	}

	static string GetVanillaMaterial(string type)
	{
		TStringArray mats = new TStringArray;
		GetGame().ConfigGetTextArray("CfgVehicles " + type + " hiddenSelectionsMaterials", mats);
		if (mats.Count() > 0)
			return mats[0];
		return "";
	}

	// Resolved by Discover() for every infected type, e.g. "ZmbM_HermitSkinny_Beige" -> "hermit".
	static string GetBodyBase(string type)
	{
		return s_BodyBases.Get(type);
	}

	// Each vanilla body has its own copy of its material per glow color and brightness step in data\bodies.
	static string GetMaterial(string type, int color, int intensity)
	{
		if (!IsColor(color))
			return GetVanillaMaterial(type);

		string colorName = COLOR_NAMES[color];
		colorName.ToLower();
		return "DZNC_Zombies\\data\\bodies\\" + GetBodyBase(type) + "_" + colorName + "_" + ClampIntensity(intensity) + ".rvmat";
	}
}

class DZNC_EyeSettingsData
{
	ref map<string, int> ZombieEyes = new map<string, int>;
	int Intensity = DZNC_Eyes.INTENSITY_DEFAULT;
	bool CrazyMode = false;
	bool FadeOnDeath = false;
}

class DZNC_AdminData
{
	ref TStringArray SteamIDs = new TStringArray;
	// Spawns every menu zombie type in front of the first admin to join after a server start.
	bool DebugLineup = false;
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
		// Files written before brightness existed have no Intensity field and keep the default.
		m_Data.Intensity = DZNC_Eyes.ClampIntensity(m_Data.Intensity);
		MatchSavedTypes();
		if (!FileExist(ADMINS_FILE))
			JsonFileLoader<DZNC_AdminData>.SaveFile(ADMINS_FILE, m_Admins, error);
		else if (!JsonFileLoader<DZNC_AdminData>.LoadFile(ADMINS_FILE, m_Admins, error))
			Print("[DZNC_Zombies] " + error);
	}

	// Older files used the hand written type list, which had some names in the wrong case (ZmbF_ShortSkirt_black).
	// An exact key always wins over a case-only match.
	protected void MatchSavedTypes()
	{
		map<string, int> matched = new map<string, int>;
		foreach (string key, int color : m_Data.ZombieEyes)
		{
			string type = DZNC_Eyes.MatchType(key);
			if (type == key || !matched.Contains(type))
				matched.Set(type, color);
		}
		m_Data.ZombieEyes = matched;
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

	int GetIntensity()
	{
		return m_Data.Intensity;
	}

	void SetIntensity(int intensity)
	{
		m_Data.Intensity = DZNC_Eyes.ClampIntensity(intensity);
	}

	bool GetCrazyMode()
	{
		return m_Data.CrazyMode;
	}

	void SetCrazyMode(bool crazy)
	{
		m_Data.CrazyMode = crazy;
	}

	bool GetFadeOnDeath()
	{
		return m_Data.FadeOnDeath;
	}

	void SetFadeOnDeath(bool fade)
	{
		m_Data.FadeOnDeath = fade;
	}
}

// Same place vanilla walks CfgVehicles for its character list. GetGame() is not set yet inside this constructor.
modded class DayZGame
{
	void DayZGame()
	{
		DZNC_Eyes.Discover(this);
	}
}
