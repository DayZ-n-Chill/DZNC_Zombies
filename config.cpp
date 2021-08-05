class CfgPatches
{
	class DZNC_Zombie_E
	{
		units[] = {"Hermit_NewAI"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters","DZ_Characters_Zombies","DZ_Scripts","DZ_Data","DZ_Surfaces","DZ_Structures_Furniture"};
	};
};

class CfgMods
{
	class DZNC_Zombie_E
	{
		dir = "DZNC_Zombies";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "DZNC_Zombies";
		author = "DayZ n' Chill";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";

		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"DZNC_Zombies/WorldScripts"};
			};
		};

		dependencies[] = {
			"Game",
			"World",
			"Mission"
		};
	};
	
};

class CfgVehicles
{
	class ZmbM_HermitSkinny_Beige;
	class ZmbM_HermitSkinny_Black;
	class ZmbM_HermitSkinny_Green;
	class ZmbM_HermitSkinny_Red;
	class ZmbM_FarmerFat_Beige;
	class ZmbM_FarmerFat_Blue;
	class ZmbM_FarmerFat_Brown;
	class ZmbM_FarmerFat_Green;
	class ZmbF_CitizenANormal_Beige;
	class ZmbF_CitizenANormal_Brown;
	class ZmbF_CitizenANormal_Blue;
	class ZmbM_CitizenASkinny_Blue;
	class ZmbM_CitizenASkinny_Brown;
	class ZmbM_CitizenASkinny_Grey;
	class ZmbM_CitizenASkinny_Red;
	class ZmbM_CitizenBFat_Blue;
	class ZmbM_CitizenBFat_Red;
	class ZmbM_CitizenBFat_Green;
	class ZmbF_CitizenBSkinny;
	class ZmbM_PrisonerSkinny;
	class ZmbM_FirefighterNormal;
	class ZmbM_FishermanOld_Blue;
	class ZmbM_FishermanOld_Green;
	class ZmbM_FishermanOld_Grey;
	class ZmbM_FishermanOld_Red;
	class ZmbM_JournalistSkinny;
	class ZmbF_JournalistNormal_Blue;
	class ZmbF_JournalistNormal_Green;
	class ZmbF_JournalistNormal_Red;
	class ZmbF_JournalistNormal_White;
	class ZmbM_ParamedicNormal_Blue;
	class ZmbM_ParamedicNormal_Green;
	class ZmbM_ParamedicNormal_Red;
	class ZmbM_ParamedicNormal_Black;
	class ZmbF_ParamedicNormal_Blue;
	class ZmbF_ParamedicNormal_Green;
	class ZmbF_ParamedicNormal_Red;
	class ZmbM_HikerSkinny_Blue;
	class ZmbM_HikerSkinny_Green;
	class ZmbM_HikerSkinny_Yellow;
	class ZmbF_HikerSkinny_Blue;
	class ZmbF_HikerSkinny_Grey;
	class ZmbF_HikerSkinny_Green;
	class ZmbF_HikerSkinny_Red;
	class ZmbM_HunterOld_Autumn;
	class ZmbM_HunterOld_Spring;
	class ZmbM_HunterOld_Summer;
	class ZmbM_HunterOld_Winter;
	class ZmbF_SurvivorNormal_Blue;
	class ZmbF_SurvivorNormal_Orange;
	class ZmbF_SurvivorNormal_Red;
	class ZmbF_SurvivorNormal_White;
	class ZmbM_PolicemanFat;
	class ZmbF_PoliceWomanNormal;
	class ZmbM_PolicemanSpecForce;
	class ZmbM_SoldierNormal;
	class ZmbM_usSoldier_normal_Woodland;
	class ZmbM_usSoldier_normal_Desert;
	class ZmbM_CommercialPilotOld_Blue;
	class ZmbM_CommercialPilotOld_Olive;
	class ZmbM_CommercialPilotOld_Brown;
	class ZmbM_CommercialPilotOld_Grey;
	class ZmbM_PatrolNormal_PautRev;
	class ZmbM_PatrolNormal_Autumn;
	class ZmbM_PatrolNormal_Flat;
	class ZmbM_PatrolNormal_Summer;
	class ZmbM_JoggerSkinny_Blue;
	class ZmbM_JoggerSkinny_Green;
	class ZmbM_JoggerSkinny_Red;
	class ZmbF_JoggerSkinny_Blue;
	class ZmbF_JoggerSkinny_Brown;
	class ZmbF_JoggerSkinny_Green;
	class ZmbF_JoggerSkinny_Red;
	class ZmbM_MotobikerFat_Beige;
	class ZmbM_MotobikerFat_Black;
	class ZmbM_MotobikerFat_Blue;
	class ZmbM_VillagerOld_Blue;
	class ZmbM_VillagerOld_Green;
	class ZmbM_VillagerOld_White;
	class ZmbM_SkaterYoung_Blue;
	class ZmbM_SkaterYoung_Brown;
	class ZmbM_SkaterYoung_Green;
	class ZmbM_SkaterYoung_Grey;
	class ZmbF_SkaterYoung_Brown;
	class ZmbF_SkaterYoung_Striped;
	class ZmbF_SkaterYoung_Violet;
	class ZmbF_DoctorSkinny;
	class ZmbF_BlueCollarFat_Blue;
	class ZmbF_BlueCollarFat_Green;
	class ZmbF_BlueCollarFat_Red;
	class ZmbF_BlueCollarFat_White;
	class ZmbF_MechanicNormal_Beige;
	class ZmbF_MechanicNormal_Green;
	class ZmbF_MechanicNormal_Grey;
	class ZmbF_MechanicNormal_Orange;
	class ZmbM_MechanicSkinny_Blue;
	class ZmbM_MechanicSkinny_Grey;
	class ZmbM_MechanicSkinny_Green;
	class ZmbM_MechanicSkinny_Red;
	class ZmbM_ConstrWorkerNormal_Beige;
	class ZmbM_ConstrWorkerNormal_Black;
	class ZmbM_ConstrWorkerNormal_Green;
	class ZmbM_ConstrWorkerNormal_Grey;
	class ZmbM_HeavyIndustryWorker;
	class ZmbM_OffshoreWorker_Green;
	class ZmbM_OffshoreWorker_Orange;
	class ZmbM_OffshoreWorker_Red;
	class ZmbM_OffshoreWorker_Yellow;
	class ZmbF_NurseFat;
	class ZmbM_HandymanNormal_Beige;
	class ZmbM_HandymanNormal_Blue;
	class ZmbM_HandymanNormal_Green;
	class ZmbM_HandymanNormal_Grey;
	class ZmbM_HandymanNormal_White;
	class ZmbM_DoctorFat;
	class ZmbM_Jacket_beige;
	class ZmbM_Jacket_black;
	class ZmbM_Jacket_blue;
	class ZmbM_Jacket_bluechecks;
	class ZmbM_Jacket_brown;
	class ZmbM_Jacket_greenchecks;
	class ZmbM_Jacket_grey;
	class ZmbM_Jacket_khaki;
	class ZmbM_Jacket_magenta;
	class ZmbM_Jacket_stripes;
	class ZmbF_PatientOld;
	class ZmbM_PatientSkinny;
	class ZmbF_ShortSkirt_beige;
	class ZmbF_ShortSkirt_black;
	class ZmbF_ShortSkirt_brown;
	class ZmbF_ShortSkirt_green;
	class ZmbF_ShortSkirt_grey;
	class ZmbF_ShortSkirt_checks;
	class ZmbF_ShortSkirt_red;
	class ZmbF_ShortSkirt_stripes;
	class ZmbF_ShortSkirt_white;
	class ZmbF_ShortSkirt_yellow;
	class ZmbF_VillagerOld_Blue;
	class ZmbF_VillagerOld_Green;
	class ZmbF_VillagerOld_Red;
	class ZmbF_VillagerOld_White;
	class ZmbF_MilkMaidOld_Beige;
	class ZmbF_MilkMaidOld_Black;
	class ZmbF_MilkMaidOld_Green;
	class ZmbF_MilkMaidOld_Grey;
	class ZmbM_priestPopSkinny;
	class ZmbM_ClerkFat_Brown;
	class ZmbM_ClerkFat_Grey;
	class ZmbM_ClerkFat_Khaki;
	class ZmbM_ClerkFat_White;
	class ZmbF_Clerk_Normal_Blue;
	class ZmbF_Clerk_Normal_White;
	class ZmbF_Clerk_Normal_Green;
	class ZmbF_Clerk_Normal_Red;
	class ZmbF_ClerkFat_Black;
	class ZmbF_ClerkFat_GreyPattern;
	class ZmbF_ClerkFat_BluePattern;
	class ZmbF_ClerkFat_White;
	
	class DZNC_HermitSkinny_Beige: ZmbM_HermitSkinny_Beige
	{  
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_BlueCollarFat_Blue: ZmbF_BlueCollarFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_BlueCollarFat_Green: ZmbF_BlueCollarFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_HermitSkinny_Black: ZmbM_HermitSkinny_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_HermitSkinny_Green: ZmbM_HermitSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_HermitSkinny_Red: ZmbM_HermitSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_FarmerFat_Beige: ZmbM_FarmerFat_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_FarmerFat_Blue: ZmbM_FarmerFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_FarmerFat_Brown: ZmbM_FarmerFat_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_FarmerFat_Green: ZmbM_FarmerFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CitizenANormal_Beige: ZmbF_CitizenANormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CitizenANormal_Brown: ZmbF_CitizenANormal_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CitizenANormal_Blue: ZmbF_CitizenANormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CitizenASkinny_Blue: ZmbM_CitizenASkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CitizenASkinny_Brown: ZmbM_CitizenASkinny_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CitizenASkinny_Grey: ZmbM_CitizenASkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CitizenASkinny_Red: ZmbM_CitizenASkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CitizenBFat_Blue: ZmbM_CitizenBFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CitizenBFat_Red: ZmbM_CitizenBFat_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CitizenBFat_Green: ZmbM_CitizenBFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CitizenBSkinny: ZmbF_CitizenBSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_PrisonerSkinny: ZmbM_PrisonerSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_FirefighterNormal: ZmbM_FirefighterNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_FishermanOld_Blue: ZmbM_FishermanOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_FishermanOld_Green: ZmbM_FishermanOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_FishermanOld_Grey: ZmbM_FishermanOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_FishermanOld_Red: ZmbM_FishermanOld_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_JournalistSkinny: ZmbM_JournalistSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_JournalistNormal_Blue: ZmbF_JournalistNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_JournalistNormal_Green: ZmbF_JournalistNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_JournalistNormal_Red: ZmbF_JournalistNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_JournalistNormal_White: ZmbF_JournalistNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ParamedicNormal_Black: ZmbM_ParamedicNormal_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ParamedicNormal_Blue: ZmbF_ParamedicNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ParamedicNormal_Green: ZmbF_ParamedicNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ParamedicNormal_Red: ZmbF_ParamedicNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_HikerSkinny_Blue: ZmbM_HikerSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_HikerSkinny_Green: ZmbM_HikerSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_HikerSkinny_Yellow: ZmbM_HikerSkinny_Yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_HikerSkinny_Grey: ZmbF_HikerSkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_HikerSkinny_Red: ZmbF_HikerSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_HunterOld_Autumn: ZmbM_HunterOld_Autumn
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_HunterOld_Spring: ZmbM_HunterOld_Spring
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_HunterOld_Summer: ZmbM_HunterOld_Summer
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_HunterOld_Winter: ZmbM_HunterOld_Winter
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_SurvivorNormal_Blue: ZmbF_SurvivorNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_SurvivorNormal_Orange: ZmbF_SurvivorNormal_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_SurvivorNormal_Red: ZmbF_SurvivorNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_SurvivorNormal_White: ZmbF_SurvivorNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_PolicemanFat: ZmbM_PolicemanFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_PoliceWomanNormal: ZmbF_PoliceWomanNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_PolicemanSpecForce: ZmbM_PolicemanSpecForce
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_SoldierNormal: ZmbM_SoldierNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_usSoldier_normal_Woodland: ZmbM_usSoldier_normal_Woodland
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_usSoldier_normal_Desert: ZmbM_usSoldier_normal_Desert
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CommercialPilotOld_Blue: ZmbM_CommercialPilotOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CommercialPilotOld_Olive: ZmbM_CommercialPilotOld_Olive
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CommercialPilotOld_Brown: ZmbM_CommercialPilotOld_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_CommercialPilotOld_Grey: ZmbM_CommercialPilotOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_PatrolNormal_PautRev: ZmbM_PatrolNormal_PautRev
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_PatrolNormal_Autumn: ZmbM_PatrolNormal_Autumn
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_PatrolNormal_Flat: ZmbM_PatrolNormal_Flat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_PatrolNormal_Summer: ZmbM_PatrolNormal_Summer
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_JoggerSkinny_Blue: ZmbM_JoggerSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_JoggerSkinny_Green: ZmbM_JoggerSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_JoggerSkinny_Red: ZmbM_JoggerSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_JoggerSkinny_Brown: ZmbF_JoggerSkinny_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MotobikerFat_Beige: ZmbM_MotobikerFat_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MotobikerFat_Black: ZmbM_MotobikerFat_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MotobikerFat_Blue: ZmbM_MotobikerFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_VillagerOld_Blue: ZmbM_VillagerOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_VillagerOld_Green: ZmbM_VillagerOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_VillagerOld_White: ZmbM_VillagerOld_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_SkaterYoung_Blue: ZmbM_SkaterYoung_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_SkaterYoung_Brown: ZmbM_SkaterYoung_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_SkaterYoung_Green: ZmbM_SkaterYoung_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_SkaterYoung_Grey: ZmbM_SkaterYoung_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_SkaterYoung_Striped: ZmbF_SkaterYoung_Striped
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_SkaterYoung_Violet: ZmbF_SkaterYoung_Violet
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_DoctorSkinny: ZmbF_DoctorSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_BlueCollarFat_Red: ZmbF_BlueCollarFat_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_BlueCollarFat_White: ZmbF_BlueCollarFat_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MechanicNormal_Beige: ZmbF_MechanicNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MechanicNormal_Green: ZmbF_MechanicNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MechanicNormal_Grey: ZmbF_MechanicNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MechanicNormal_Orange: ZmbF_MechanicNormal_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MechanicSkinny_Blue: ZmbM_MechanicSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MechanicSkinny_Grey: ZmbM_MechanicSkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MechanicSkinny_Green: ZmbM_MechanicSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MechanicSkinny_Red: ZmbM_MechanicSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ConstrWorkerNormal_Beige: ZmbM_ConstrWorkerNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ConstrWorkerNormal_Black: ZmbM_ConstrWorkerNormal_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ConstrWorkerNormal_Green: ZmbM_ConstrWorkerNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ConstrWorkerNormal_Grey: ZmbM_ConstrWorkerNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_HeavyIndustryWorker: ZmbM_HeavyIndustryWorker
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_OffshoreWorker_Green: ZmbM_OffshoreWorker_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_OffshoreWorker_Orange: ZmbM_OffshoreWorker_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_OffshoreWorker_Red: ZmbM_OffshoreWorker_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_OffshoreWorker_Yellow: ZmbM_OffshoreWorker_Yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_NurseFat: ZmbF_NurseFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_HandymanNormal_Beige: ZmbM_HandymanNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.rvmat"};
	};
	class DZNC_HandymanNormal_Blue: ZmbM_HandymanNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.rvmat"};
	};
	class DZNC_HandymanNormal_Green: ZmbM_HandymanNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.rvmat"};
	};
	class DZNC_HandymanNormal_Grey: ZmbM_HandymanNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.rvmat"};
	};
	class DZNC_HandymanNormal_White: ZmbM_HandymanNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.rvmat"};
	};
	class DZNC_DoctorFat: ZmbM_DoctorFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_Jacket_beige: ZmbM_Jacket_beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_Jacket_black: ZmbM_Jacket_black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_Jacket_blue: ZmbM_Jacket_blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_Jacket_bluechecks: ZmbM_Jacket_bluechecks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_Jacket_brown: ZmbM_Jacket_brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_Jacket_greenchecks: ZmbM_Jacket_greenchecks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_Jacket_grey: ZmbM_Jacket_grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_Jacket_khaki: ZmbM_Jacket_khaki
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_Jacket_magenta: ZmbM_Jacket_magenta
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_Jacket_stripes: ZmbM_Jacket_stripes
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_PatientOld: ZmbF_PatientOld
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_PatientSkinny: ZmbM_PatientSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ShortSkirt_beige: ZmbF_ShortSkirt_beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.rvmat"};
	};
	class DZNC_ShortSkirt_black: ZmbF_ShortSkirt_black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.rvmat"};
	};
	class DZNC_ShortSkirt_brown: ZmbF_ShortSkirt_brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.rvmat"};
	};
	class DZNC_ShortSkirt_green: ZmbF_ShortSkirt_green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.rvmat"};
	};
	class DZNC_ShortSkirt_grey: ZmbF_ShortSkirt_grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.rvmat"};
	};
	class DZNC_ShortSkirt_checks: ZmbF_ShortSkirt_checks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.rvmat"};
	};
	class DZNC_ShortSkirt_red: ZmbF_ShortSkirt_red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.rvmat"};
	};
	class DZNC_ShortSkirt_stripes: ZmbF_ShortSkirt_stripes
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.rvmat"};
	};
	class DZNC_ShortSkirt_white: ZmbF_ShortSkirt_white
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.rvmat"};
	};
	class DZNC_ShortSkirt_yellow: ZmbF_ShortSkirt_yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.rvmat"};
	};
	class DZNC_VillagerOld_Red: ZmbF_VillagerOld_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MilkMaidOld_Beige: ZmbF_MilkMaidOld_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MilkMaidOld_Black: ZmbF_MilkMaidOld_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MilkMaidOld_Green: ZmbF_MilkMaidOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_MilkMaidOld_Grey: ZmbF_MilkMaidOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_priestPopSkinny: ZmbM_priestPopSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ClerkFat_Brown: ZmbM_ClerkFat_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ClerkFat_Grey: ZmbM_ClerkFat_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ClerkFat_Khaki: ZmbM_ClerkFat_Khaki
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ClerkFat_White: ZmbM_ClerkFat_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_Clerk_Normal_Blue: ZmbF_Clerk_Normal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_Clerk_Normal_White: ZmbF_Clerk_Normal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_Clerk_Normal_Green: ZmbF_Clerk_Normal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_Clerk_Normal_Red: ZmbF_Clerk_Normal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ClerkFat_Black: ZmbF_ClerkFat_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ClerkFat_GreyPattern: ZmbF_ClerkFat_GreyPattern
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
	class DZNC_ClerkFat_BluePattern: ZmbF_ClerkFat_BluePattern
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\eyes.rvmat"};
	};
class DZNC_RED_HermitSkinny_Beige: ZmbM_HermitSkinny_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_BlueCollarFat_Blue: ZmbF_BlueCollarFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_BlueCollarFat_Green: ZmbF_BlueCollarFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_HermitSkinny_Black: ZmbM_HermitSkinny_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_HermitSkinny_Green: ZmbM_HermitSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_HermitSkinny_Red: ZmbM_HermitSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_FarmerFat_Beige: ZmbM_FarmerFat_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_FarmerFat_Blue: ZmbM_FarmerFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_FarmerFat_Brown: ZmbM_FarmerFat_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_FarmerFat_Green: ZmbM_FarmerFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CitizenANormal_Beige: ZmbF_CitizenANormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CitizenANormal_Brown: ZmbF_CitizenANormal_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CitizenANormal_Blue: ZmbF_CitizenANormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CitizenASkinny_Blue: ZmbM_CitizenASkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CitizenASkinny_Brown: ZmbM_CitizenASkinny_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CitizenASkinny_Grey: ZmbM_CitizenASkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CitizenASkinny_Red: ZmbM_CitizenASkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CitizenBFat_Blue: ZmbM_CitizenBFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CitizenBFat_Red: ZmbM_CitizenBFat_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CitizenBFat_Green: ZmbM_CitizenBFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CitizenBSkinny: ZmbF_CitizenBSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_PrisonerSkinny: ZmbM_PrisonerSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_FirefighterNormal: ZmbM_FirefighterNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_FishermanOld_Blue: ZmbM_FishermanOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_FishermanOld_Green: ZmbM_FishermanOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_FishermanOld_Grey: ZmbM_FishermanOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_FishermanOld_Red: ZmbM_FishermanOld_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_JournalistSkinny: ZmbM_JournalistSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_JournalistNormal_Blue: ZmbF_JournalistNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_JournalistNormal_Green: ZmbF_JournalistNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_JournalistNormal_Red: ZmbF_JournalistNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_JournalistNormal_White: ZmbF_JournalistNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ParamedicNormal_Black: ZmbM_ParamedicNormal_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ParamedicNormal_Blue: ZmbF_ParamedicNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ParamedicNormal_Green: ZmbF_ParamedicNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ParamedicNormal_Red: ZmbF_ParamedicNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_HikerSkinny_Blue: ZmbM_HikerSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_HikerSkinny_Green: ZmbM_HikerSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_HikerSkinny_Yellow: ZmbM_HikerSkinny_Yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_HikerSkinny_Grey: ZmbF_HikerSkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_HikerSkinny_Red: ZmbF_HikerSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_HunterOld_Autumn: ZmbM_HunterOld_Autumn
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_HunterOld_Spring: ZmbM_HunterOld_Spring
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_HunterOld_Summer: ZmbM_HunterOld_Summer
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_HunterOld_Winter: ZmbM_HunterOld_Winter
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_SurvivorNormal_Blue: ZmbF_SurvivorNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_SurvivorNormal_Orange: ZmbF_SurvivorNormal_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_SurvivorNormal_Red: ZmbF_SurvivorNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_SurvivorNormal_White: ZmbF_SurvivorNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_PolicemanFat: ZmbM_PolicemanFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_PoliceWomanNormal: ZmbF_PoliceWomanNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_PolicemanSpecForce: ZmbM_PolicemanSpecForce
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_SoldierNormal: ZmbM_SoldierNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_usSoldier_normal_Woodland: ZmbM_usSoldier_normal_Woodland
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_usSoldier_normal_Desert: ZmbM_usSoldier_normal_Desert
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CommercialPilotOld_Blue: ZmbM_CommercialPilotOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CommercialPilotOld_Olive: ZmbM_CommercialPilotOld_Olive
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CommercialPilotOld_Brown: ZmbM_CommercialPilotOld_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_CommercialPilotOld_Grey: ZmbM_CommercialPilotOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_PatrolNormal_PautRev: ZmbM_PatrolNormal_PautRev
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_PatrolNormal_Autumn: ZmbM_PatrolNormal_Autumn
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_PatrolNormal_Flat: ZmbM_PatrolNormal_Flat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_PatrolNormal_Summer: ZmbM_PatrolNormal_Summer
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_JoggerSkinny_Blue: ZmbM_JoggerSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_JoggerSkinny_Green: ZmbM_JoggerSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_JoggerSkinny_Red: ZmbM_JoggerSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_JoggerSkinny_Brown: ZmbF_JoggerSkinny_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MotobikerFat_Beige: ZmbM_MotobikerFat_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MotobikerFat_Black: ZmbM_MotobikerFat_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MotobikerFat_Blue: ZmbM_MotobikerFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_VillagerOld_Blue: ZmbM_VillagerOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_VillagerOld_Green: ZmbM_VillagerOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_VillagerOld_White: ZmbM_VillagerOld_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_SkaterYoung_Blue: ZmbM_SkaterYoung_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_SkaterYoung_Brown: ZmbM_SkaterYoung_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_SkaterYoung_Green: ZmbM_SkaterYoung_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_SkaterYoung_Grey: ZmbM_SkaterYoung_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_SkaterYoung_Striped: ZmbF_SkaterYoung_Striped
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_SkaterYoung_Violet: ZmbF_SkaterYoung_Violet
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_DoctorSkinny: ZmbF_DoctorSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_BlueCollarFat_Red: ZmbF_BlueCollarFat_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_BlueCollarFat_White: ZmbF_BlueCollarFat_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MechanicNormal_Beige: ZmbF_MechanicNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MechanicNormal_Green: ZmbF_MechanicNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MechanicNormal_Grey: ZmbF_MechanicNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MechanicNormal_Orange: ZmbF_MechanicNormal_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MechanicSkinny_Blue: ZmbM_MechanicSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MechanicSkinny_Grey: ZmbM_MechanicSkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MechanicSkinny_Green: ZmbM_MechanicSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MechanicSkinny_Red: ZmbM_MechanicSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ConstrWorkerNormal_Beige: ZmbM_ConstrWorkerNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ConstrWorkerNormal_Black: ZmbM_ConstrWorkerNormal_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ConstrWorkerNormal_Green: ZmbM_ConstrWorkerNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ConstrWorkerNormal_Grey: ZmbM_ConstrWorkerNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_HeavyIndustryWorker: ZmbM_HeavyIndustryWorker
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_OffshoreWorker_Green: ZmbM_OffshoreWorker_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_OffshoreWorker_Orange: ZmbM_OffshoreWorker_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_OffshoreWorker_Red: ZmbM_OffshoreWorker_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_OffshoreWorker_Yellow: ZmbM_OffshoreWorker_Yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_NurseFat: ZmbF_NurseFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_HandymanNormal_Beige: ZmbM_HandymanNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Red.rvmat"};
	};
	class DZNC_RED_HandymanNormal_Blue: ZmbM_HandymanNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Red.rvmat"};
	};
	class DZNC_RED_HandymanNormal_Green: ZmbM_HandymanNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Red.rvmat"};
	};
	class DZNC_RED_HandymanNormal_Grey: ZmbM_HandymanNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Red.rvmat"};
	};
	class DZNC_RED_HandymanNormal_White: ZmbM_HandymanNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Red.rvmat"};
	};
	class DZNC_RED_DoctorFat: ZmbM_DoctorFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_Jacket_beige: ZmbM_Jacket_beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_Jacket_black: ZmbM_Jacket_black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_Jacket_blue: ZmbM_Jacket_blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_Jacket_bluechecks: ZmbM_Jacket_bluechecks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_Jacket_brown: ZmbM_Jacket_brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_Jacket_greenchecks: ZmbM_Jacket_greenchecks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_Jacket_grey: ZmbM_Jacket_grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_Jacket_khaki: ZmbM_Jacket_khaki
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_Jacket_magenta: ZmbM_Jacket_magenta
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_Jacket_stripes: ZmbM_Jacket_stripes
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_PatientOld: ZmbF_PatientOld
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_PatientSkinny: ZmbM_PatientSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ShortSkirt_beige: ZmbF_ShortSkirt_beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Red.rvmat"};
	};
	class DZNC_RED_ShortSkirt_black: ZmbF_ShortSkirt_black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Red.rvmat"};
	};
	class DZNC_RED_ShortSkirt_brown: ZmbF_ShortSkirt_brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Red.rvmat"};
	};
	class DZNC_RED_ShortSkirt_green: ZmbF_ShortSkirt_green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Red.rvmat"};
	};
	class DZNC_RED_ShortSkirt_grey: ZmbF_ShortSkirt_grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Red.rvmat"};
	};
	class DZNC_RED_ShortSkirt_checks: ZmbF_ShortSkirt_checks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Red.rvmat"};
	};
	class DZNC_RED_ShortSkirt_red: ZmbF_ShortSkirt_red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Red.rvmat"};
	};
	class DZNC_RED_ShortSkirt_stripes: ZmbF_ShortSkirt_stripes
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Red.rvmat"};
	};
	class DZNC_RED_ShortSkirt_white: ZmbF_ShortSkirt_white
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Red.rvmat"};
	};
	class DZNC_RED_ShortSkirt_yellow: ZmbF_ShortSkirt_yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Red.rvmat"};
	};
	class DZNC_RED_VillagerOld_Red: ZmbF_VillagerOld_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MilkMaidOld_Beige: ZmbF_MilkMaidOld_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MilkMaidOld_Black: ZmbF_MilkMaidOld_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MilkMaidOld_Green: ZmbF_MilkMaidOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_MilkMaidOld_Grey: ZmbF_MilkMaidOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_priestPopSkinny: ZmbM_priestPopSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ClerkFat_Brown: ZmbM_ClerkFat_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ClerkFat_Grey: ZmbM_ClerkFat_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ClerkFat_Khaki: ZmbM_ClerkFat_Khaki
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ClerkFat_White: ZmbM_ClerkFat_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_Clerk_Normal_Blue: ZmbF_Clerk_Normal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_Clerk_Normal_White: ZmbF_Clerk_Normal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_Clerk_Normal_Green: ZmbF_Clerk_Normal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_Clerk_Normal_Red: ZmbF_Clerk_Normal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ClerkFat_Black: ZmbF_ClerkFat_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ClerkFat_GreyPattern: ZmbF_ClerkFat_GreyPattern
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
	class DZNC_RED_ClerkFat_BluePattern: ZmbF_ClerkFat_BluePattern
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\red-eyes.rvmat"};
	};
class DZNC_BLUE_HermitSkinny_Beige: ZmbM_HermitSkinny_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_BlueCollarFat_Blue: ZmbF_BlueCollarFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_BlueCollarFat_Green: ZmbF_BlueCollarFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HermitSkinny_Black: ZmbM_HermitSkinny_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HermitSkinny_Green: ZmbM_HermitSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HermitSkinny_Red: ZmbM_HermitSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_FarmerFat_Beige: ZmbM_FarmerFat_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_FarmerFat_Blue: ZmbM_FarmerFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_FarmerFat_Brown: ZmbM_FarmerFat_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_FarmerFat_Green: ZmbM_FarmerFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CitizenANormal_Beige: ZmbF_CitizenANormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CitizenANormal_Brown: ZmbF_CitizenANormal_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CitizenANormal_Blue: ZmbF_CitizenANormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CitizenASkinny_Blue: ZmbM_CitizenASkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CitizenASkinny_Brown: ZmbM_CitizenASkinny_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CitizenASkinny_Grey: ZmbM_CitizenASkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CitizenASkinny_Red: ZmbM_CitizenASkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CitizenBFat_Blue: ZmbM_CitizenBFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CitizenBFat_Red: ZmbM_CitizenBFat_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CitizenBFat_Green: ZmbM_CitizenBFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CitizenBSkinny: ZmbF_CitizenBSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_PrisonerSkinny: ZmbM_PrisonerSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_FirefighterNormal: ZmbM_FirefighterNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_FishermanOld_Blue: ZmbM_FishermanOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_FishermanOld_Green: ZmbM_FishermanOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_FishermanOld_Grey: ZmbM_FishermanOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_FishermanOld_Red: ZmbM_FishermanOld_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_JournalistSkinny: ZmbM_JournalistSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_JournalistNormal_Blue: ZmbF_JournalistNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_JournalistNormal_Green: ZmbF_JournalistNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_JournalistNormal_Red: ZmbF_JournalistNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_JournalistNormal_White: ZmbF_JournalistNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ParamedicNormal_Black: ZmbM_ParamedicNormal_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ParamedicNormal_Blue: ZmbF_ParamedicNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ParamedicNormal_Green: ZmbF_ParamedicNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ParamedicNormal_Red: ZmbF_ParamedicNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HikerSkinny_Blue: ZmbM_HikerSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HikerSkinny_Green: ZmbM_HikerSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HikerSkinny_Yellow: ZmbM_HikerSkinny_Yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HikerSkinny_Grey: ZmbF_HikerSkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HikerSkinny_Red: ZmbF_HikerSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HunterOld_Autumn: ZmbM_HunterOld_Autumn
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HunterOld_Spring: ZmbM_HunterOld_Spring
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HunterOld_Summer: ZmbM_HunterOld_Summer
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HunterOld_Winter: ZmbM_HunterOld_Winter
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_SurvivorNormal_Blue: ZmbF_SurvivorNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_SurvivorNormal_Orange: ZmbF_SurvivorNormal_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_SurvivorNormal_Red: ZmbF_SurvivorNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_SurvivorNormal_White: ZmbF_SurvivorNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_PolicemanFat: ZmbM_PolicemanFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_PoliceWomanNormal: ZmbF_PoliceWomanNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_PolicemanSpecForce: ZmbM_PolicemanSpecForce
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_SoldierNormal: ZmbM_SoldierNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_usSoldier_normal_Woodland: ZmbM_usSoldier_normal_Woodland
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_usSoldier_normal_Desert: ZmbM_usSoldier_normal_Desert
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CommercialPilotOld_Blue: ZmbM_CommercialPilotOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CommercialPilotOld_Olive: ZmbM_CommercialPilotOld_Olive
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CommercialPilotOld_Brown: ZmbM_CommercialPilotOld_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_CommercialPilotOld_Grey: ZmbM_CommercialPilotOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_PatrolNormal_PautRev: ZmbM_PatrolNormal_PautRev
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_PatrolNormal_Autumn: ZmbM_PatrolNormal_Autumn
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_PatrolNormal_Flat: ZmbM_PatrolNormal_Flat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_PatrolNormal_Summer: ZmbM_PatrolNormal_Summer
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_JoggerSkinny_Blue: ZmbM_JoggerSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_JoggerSkinny_Green: ZmbM_JoggerSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_JoggerSkinny_Red: ZmbM_JoggerSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_JoggerSkinny_Brown: ZmbF_JoggerSkinny_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MotobikerFat_Beige: ZmbM_MotobikerFat_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MotobikerFat_Black: ZmbM_MotobikerFat_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MotobikerFat_Blue: ZmbM_MotobikerFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_VillagerOld_Blue: ZmbM_VillagerOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_VillagerOld_Green: ZmbM_VillagerOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_VillagerOld_White: ZmbM_VillagerOld_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_SkaterYoung_Blue: ZmbM_SkaterYoung_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_SkaterYoung_Brown: ZmbM_SkaterYoung_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_SkaterYoung_Green: ZmbM_SkaterYoung_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_SkaterYoung_Grey: ZmbM_SkaterYoung_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_SkaterYoung_Striped: ZmbF_SkaterYoung_Striped
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_SkaterYoung_Violet: ZmbF_SkaterYoung_Violet
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_DoctorSkinny: ZmbF_DoctorSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_BlueCollarFat_Red: ZmbF_BlueCollarFat_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_BlueCollarFat_White: ZmbF_BlueCollarFat_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MechanicNormal_Beige: ZmbF_MechanicNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MechanicNormal_Green: ZmbF_MechanicNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MechanicNormal_Grey: ZmbF_MechanicNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MechanicNormal_Orange: ZmbF_MechanicNormal_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MechanicSkinny_Blue: ZmbM_MechanicSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MechanicSkinny_Grey: ZmbM_MechanicSkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MechanicSkinny_Green: ZmbM_MechanicSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MechanicSkinny_Red: ZmbM_MechanicSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ConstrWorkerNormal_Beige: ZmbM_ConstrWorkerNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ConstrWorkerNormal_Black: ZmbM_ConstrWorkerNormal_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ConstrWorkerNormal_Green: ZmbM_ConstrWorkerNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ConstrWorkerNormal_Grey: ZmbM_ConstrWorkerNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HeavyIndustryWorker: ZmbM_HeavyIndustryWorker
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_OffshoreWorker_Green: ZmbM_OffshoreWorker_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_OffshoreWorker_Orange: ZmbM_OffshoreWorker_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_OffshoreWorker_Red: ZmbM_OffshoreWorker_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_OffshoreWorker_Yellow: ZmbM_OffshoreWorker_Yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_NurseFat: ZmbF_NurseFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HandymanNormal_Beige: ZmbM_HandymanNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_HandymanNormal_Blue: ZmbM_HandymanNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Blue.rvmat"};
	};
	class DZNC_BLUE_HandymanNormal_Green: ZmbM_HandymanNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Blue.rvmat"};
	};
	class DZNC_BLUE_HandymanNormal_Grey: ZmbM_HandymanNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Blue.rvmat"};
	};
	class DZNC_BLUE_HandymanNormal_White: ZmbM_HandymanNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Blue.rvmat"};
	};
	class DZNC_BLUE_DoctorFat: ZmbM_DoctorFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_Jacket_beige: ZmbM_Jacket_beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_Jacket_black: ZmbM_Jacket_black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_Jacket_blue: ZmbM_Jacket_blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_Jacket_bluechecks: ZmbM_Jacket_bluechecks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_Jacket_brown: ZmbM_Jacket_brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_Jacket_greenchecks: ZmbM_Jacket_greenchecks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_Jacket_grey: ZmbM_Jacket_grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_Jacket_khaki: ZmbM_Jacket_khaki
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_Jacket_magenta: ZmbM_Jacket_magenta
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_Jacket_stripes: ZmbM_Jacket_stripes
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_PatientOld: ZmbF_PatientOld
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_PatientSkinny: ZmbM_PatientSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ShortSkirt_beige: ZmbF_ShortSkirt_beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Blue.rvmat"};
	};
	class DZNC_BLUE_ShortSkirt_black: ZmbF_ShortSkirt_black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Blue.rvmat"};
	};
	class DZNC_BLUE_ShortSkirt_brown: ZmbF_ShortSkirt_brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Blue.rvmat"};
	};
	class DZNC_BLUE_ShortSkirt_green: ZmbF_ShortSkirt_green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Blue.rvmat"};
	};
	class DZNC_BLUE_ShortSkirt_grey: ZmbF_ShortSkirt_grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Blue.rvmat"};
	};
	class DZNC_BLUE_ShortSkirt_checks: ZmbF_ShortSkirt_checks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Blue.rvmat"};
	};
	class DZNC_BLUE_ShortSkirt_red: ZmbF_ShortSkirt_red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Blue.rvmat"};
	};
	class DZNC_BLUE_ShortSkirt_stripes: ZmbF_ShortSkirt_stripes
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Blue.rvmat"};
	};
	class DZNC_BLUE_ShortSkirt_white: ZmbF_ShortSkirt_white
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Blue.rvmat"};
	};
	class DZNC_BLUE_ShortSkirt_yellow: ZmbF_ShortSkirt_yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Blue.rvmat"};
	};
	class DZNC_BLUE_VillagerOld_Red: ZmbF_VillagerOld_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MilkMaidOld_Beige: ZmbF_MilkMaidOld_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MilkMaidOld_Black: ZmbF_MilkMaidOld_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MilkMaidOld_Green: ZmbF_MilkMaidOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_MilkMaidOld_Grey: ZmbF_MilkMaidOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_priestPopSkinny: ZmbM_priestPopSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ClerkFat_Brown: ZmbM_ClerkFat_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ClerkFat_Grey: ZmbM_ClerkFat_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ClerkFat_Khaki: ZmbM_ClerkFat_Khaki
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ClerkFat_White: ZmbM_ClerkFat_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_Clerk_Normal_Blue: ZmbF_Clerk_Normal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_Clerk_Normal_White: ZmbF_Clerk_Normal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_Clerk_Normal_Green: ZmbF_Clerk_Normal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_Clerk_Normal_Red: ZmbF_Clerk_Normal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ClerkFat_Black: ZmbF_ClerkFat_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ClerkFat_GreyPattern: ZmbF_ClerkFat_GreyPattern
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_BLUE_ClerkFat_BluePattern: ZmbF_ClerkFat_BluePattern
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\blue-eyes.rvmat"};
	};
	class DZNC_GREEN_HermitSkinny_Beige: ZmbM_HermitSkinny_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_BlueCollarFat_Blue: ZmbF_BlueCollarFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_BlueCollarFat_Green: ZmbF_BlueCollarFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_HermitSkinny_Black: ZmbM_HermitSkinny_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_HermitSkinny_Green: ZmbM_HermitSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_HermitSkinny_Red: ZmbM_HermitSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_FarmerFat_Beige: ZmbM_FarmerFat_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_FarmerFat_Blue: ZmbM_FarmerFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_FarmerFat_Brown: ZmbM_FarmerFat_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_FarmerFat_Green: ZmbM_FarmerFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CitizenANormal_Beige: ZmbF_CitizenANormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CitizenANormal_Brown: ZmbF_CitizenANormal_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CitizenANormal_Blue: ZmbF_CitizenANormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CitizenASkinny_Blue: ZmbM_CitizenASkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CitizenASkinny_Brown: ZmbM_CitizenASkinny_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CitizenASkinny_Grey: ZmbM_CitizenASkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CitizenASkinny_Red: ZmbM_CitizenASkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CitizenBFat_Blue: ZmbM_CitizenBFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CitizenBFat_Red: ZmbM_CitizenBFat_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CitizenBFat_Green: ZmbM_CitizenBFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CitizenBSkinny: ZmbF_CitizenBSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_PrisonerSkinny: ZmbM_PrisonerSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_FirefighterNormal: ZmbM_FirefighterNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_FishermanOld_Blue: ZmbM_FishermanOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_FishermanOld_Green: ZmbM_FishermanOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_FishermanOld_Grey: ZmbM_FishermanOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_FishermanOld_Red: ZmbM_FishermanOld_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_JournalistSkinny: ZmbM_JournalistSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_JournalistNormal_Blue: ZmbF_JournalistNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_JournalistNormal_Green: ZmbF_JournalistNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_JournalistNormal_Red: ZmbF_JournalistNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_JournalistNormal_White: ZmbF_JournalistNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ParamedicNormal_Black: ZmbM_ParamedicNormal_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ParamedicNormal_Blue: ZmbF_ParamedicNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ParamedicNormal_Green: ZmbF_ParamedicNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ParamedicNormal_Red: ZmbF_ParamedicNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_HikerSkinny_Blue: ZmbM_HikerSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_HikerSkinny_Green: ZmbM_HikerSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_HikerSkinny_Yellow: ZmbM_HikerSkinny_Yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_HikerSkinny_Grey: ZmbF_HikerSkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_HikerSkinny_Red: ZmbF_HikerSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_HunterOld_Autumn: ZmbM_HunterOld_Autumn
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_HunterOld_Spring: ZmbM_HunterOld_Spring
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_HunterOld_Summer: ZmbM_HunterOld_Summer
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_HunterOld_Winter: ZmbM_HunterOld_Winter
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_SurvivorNormal_Blue: ZmbF_SurvivorNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_SurvivorNormal_Orange: ZmbF_SurvivorNormal_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_SurvivorNormal_Red: ZmbF_SurvivorNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_SurvivorNormal_White: ZmbF_SurvivorNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_PolicemanFat: ZmbM_PolicemanFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_PoliceWomanNormal: ZmbF_PoliceWomanNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_PolicemanSpecForce: ZmbM_PolicemanSpecForce
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_SoldierNormal: ZmbM_SoldierNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_usSoldier_normal_Woodland: ZmbM_usSoldier_normal_Woodland
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_usSoldier_normal_Desert: ZmbM_usSoldier_normal_Desert
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CommercialPilotOld_Blue: ZmbM_CommercialPilotOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CommercialPilotOld_Olive: ZmbM_CommercialPilotOld_Olive
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CommercialPilotOld_Brown: ZmbM_CommercialPilotOld_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_CommercialPilotOld_Grey: ZmbM_CommercialPilotOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_PatrolNormal_PautRev: ZmbM_PatrolNormal_PautRev
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_PatrolNormal_Autumn: ZmbM_PatrolNormal_Autumn
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_PatrolNormal_Flat: ZmbM_PatrolNormal_Flat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_PatrolNormal_Summer: ZmbM_PatrolNormal_Summer
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_JoggerSkinny_Blue: ZmbM_JoggerSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_JoggerSkinny_Green: ZmbM_JoggerSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_JoggerSkinny_Red: ZmbM_JoggerSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_JoggerSkinny_Brown: ZmbF_JoggerSkinny_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MotobikerFat_Beige: ZmbM_MotobikerFat_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MotobikerFat_Black: ZmbM_MotobikerFat_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MotobikerFat_Blue: ZmbM_MotobikerFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_VillagerOld_Blue: ZmbM_VillagerOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_VillagerOld_Green: ZmbM_VillagerOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_VillagerOld_White: ZmbM_VillagerOld_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_SkaterYoung_Blue: ZmbM_SkaterYoung_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_SkaterYoung_Brown: ZmbM_SkaterYoung_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_SkaterYoung_Green: ZmbM_SkaterYoung_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_SkaterYoung_Grey: ZmbM_SkaterYoung_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_SkaterYoung_Striped: ZmbF_SkaterYoung_Striped
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_SkaterYoung_Violet: ZmbF_SkaterYoung_Violet
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_DoctorSkinny: ZmbF_DoctorSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_BlueCollarFat_Red: ZmbF_BlueCollarFat_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_BlueCollarFat_White: ZmbF_BlueCollarFat_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MechanicNormal_Beige: ZmbF_MechanicNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MechanicNormal_Green: ZmbF_MechanicNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MechanicNormal_Grey: ZmbF_MechanicNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MechanicNormal_Orange: ZmbF_MechanicNormal_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MechanicSkinny_Blue: ZmbM_MechanicSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MechanicSkinny_Grey: ZmbM_MechanicSkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MechanicSkinny_Green: ZmbM_MechanicSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MechanicSkinny_Red: ZmbM_MechanicSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ConstrWorkerNormal_Beige: ZmbM_ConstrWorkerNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ConstrWorkerNormal_Black: ZmbM_ConstrWorkerNormal_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ConstrWorkerNormal_Green: ZmbM_ConstrWorkerNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ConstrWorkerNormal_Grey: ZmbM_ConstrWorkerNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_HeavyIndustryWorker: ZmbM_HeavyIndustryWorker
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_OffshoreWorker_Green: ZmbM_OffshoreWorker_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_OffshoreWorker_Orange: ZmbM_OffshoreWorker_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_OffshoreWorker_Red: ZmbM_OffshoreWorker_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_OffshoreWorker_Yellow: ZmbM_OffshoreWorker_Yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_NurseFat: ZmbF_NurseFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_HandymanNormal_Beige: ZmbM_HandymanNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Green.rvmat"};
	};
	class DZNC_GREEN_HandymanNormal_Blue: ZmbM_HandymanNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Green.rvmat"};
	};
	class DZNC_GREEN_HandymanNormal_Green: ZmbM_HandymanNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Green.rvmat"};
	};
	class DZNC_GREEN_HandymanNormal_Grey: ZmbM_HandymanNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Green.rvmat"};
	};
	class DZNC_GREEN_HandymanNormal_White: ZmbM_HandymanNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Green.rvmat"};
	};
	class DZNC_GREEN_DoctorFat: ZmbM_DoctorFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_Jacket_beige: ZmbM_Jacket_beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_Jacket_black: ZmbM_Jacket_black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_Jacket_blue: ZmbM_Jacket_blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_Jacket_bluechecks: ZmbM_Jacket_bluechecks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_Jacket_brown: ZmbM_Jacket_brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_Jacket_greenchecks: ZmbM_Jacket_greenchecks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_Jacket_grey: ZmbM_Jacket_grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_Jacket_khaki: ZmbM_Jacket_khaki
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_Jacket_magenta: ZmbM_Jacket_magenta
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_Jacket_stripes: ZmbM_Jacket_stripes
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_PatientOld: ZmbF_PatientOld
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_PatientSkinny: ZmbM_PatientSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ShortSkirt_beige: ZmbF_ShortSkirt_beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Green.rvmat"};
	};
	class DZNC_GREEN_ShortSkirt_black: ZmbF_ShortSkirt_black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Green.rvmat"};
	};
	class DZNC_GREEN_ShortSkirt_brown: ZmbF_ShortSkirt_brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Green.rvmat"};
	};
	class DZNC_GREEN_ShortSkirt_green: ZmbF_ShortSkirt_green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Green.rvmat"};
	};
	class DZNC_GREEN_ShortSkirt_grey: ZmbF_ShortSkirt_grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Green.rvmat"};
	};
	class DZNC_GREEN_ShortSkirt_checks: ZmbF_ShortSkirt_checks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Green.rvmat"};
	};
	class DZNC_GREEN_ShortSkirt_red: ZmbF_ShortSkirt_red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Green.rvmat"};
	};
	class DZNC_GREEN_ShortSkirt_stripes: ZmbF_ShortSkirt_stripes
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Green.rvmat"};
	};
	class DZNC_GREEN_ShortSkirt_white: ZmbF_ShortSkirt_white
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Green.rvmat"};
	};
	class DZNC_GREEN_ShortSkirt_yellow: ZmbF_ShortSkirt_yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Green.rvmat"};
	};
	class DZNC_GREEN_VillagerOld_Red: ZmbF_VillagerOld_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MilkMaidOld_Beige: ZmbF_MilkMaidOld_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MilkMaidOld_Black: ZmbF_MilkMaidOld_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MilkMaidOld_Green: ZmbF_MilkMaidOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_MilkMaidOld_Grey: ZmbF_MilkMaidOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_priestPopSkinny: ZmbM_priestPopSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ClerkFat_Brown: ZmbM_ClerkFat_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ClerkFat_Grey: ZmbM_ClerkFat_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ClerkFat_Khaki: ZmbM_ClerkFat_Khaki
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ClerkFat_White: ZmbM_ClerkFat_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_Clerk_Normal_Blue: ZmbF_Clerk_Normal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_Clerk_Normal_White: ZmbF_Clerk_Normal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_Clerk_Normal_Green: ZmbF_Clerk_Normal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_Clerk_Normal_Red: ZmbF_Clerk_Normal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ClerkFat_Black: ZmbF_ClerkFat_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ClerkFat_GreyPattern: ZmbF_ClerkFat_GreyPattern
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
	class DZNC_GREEN_ClerkFat_BluePattern: ZmbF_ClerkFat_BluePattern
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\green-eyes.rvmat"};
	};
class DZNC_ORANGE_HermitSkinny_Beige: ZmbM_HermitSkinny_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_BlueCollarFat_Blue: ZmbF_BlueCollarFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_BlueCollarFat_Green: ZmbF_BlueCollarFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_HermitSkinny_Black: ZmbM_HermitSkinny_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_HermitSkinny_Green: ZmbM_HermitSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_HermitSkinny_Red: ZmbM_HermitSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_FarmerFat_Beige: ZmbM_FarmerFat_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_FarmerFat_Blue: ZmbM_FarmerFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_FarmerFat_Brown: ZmbM_FarmerFat_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_FarmerFat_Green: ZmbM_FarmerFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CitizenANormal_Beige: ZmbF_CitizenANormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CitizenANormal_Brown: ZmbF_CitizenANormal_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CitizenANormal_Blue: ZmbF_CitizenANormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CitizenASkinny_Blue: ZmbM_CitizenASkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CitizenASkinny_Brown: ZmbM_CitizenASkinny_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CitizenASkinny_Grey: ZmbM_CitizenASkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CitizenASkinny_Red: ZmbM_CitizenASkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CitizenBFat_Blue: ZmbM_CitizenBFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CitizenBFat_Red: ZmbM_CitizenBFat_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CitizenBFat_Green: ZmbM_CitizenBFat_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CitizenBSkinny: ZmbF_CitizenBSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_PrisonerSkinny: ZmbM_PrisonerSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_FirefighterNormal: ZmbM_FirefighterNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_FishermanOld_Blue: ZmbM_FishermanOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_FishermanOld_Green: ZmbM_FishermanOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_FishermanOld_Grey: ZmbM_FishermanOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_FishermanOld_Red: ZmbM_FishermanOld_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_JournalistSkinny: ZmbM_JournalistSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_JournalistNormal_Blue: ZmbF_JournalistNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_JournalistNormal_Green: ZmbF_JournalistNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_JournalistNormal_Red: ZmbF_JournalistNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_JournalistNormal_White: ZmbF_JournalistNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ParamedicNormal_Black: ZmbM_ParamedicNormal_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ParamedicNormal_Blue: ZmbF_ParamedicNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ParamedicNormal_Green: ZmbF_ParamedicNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ParamedicNormal_Red: ZmbF_ParamedicNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_HikerSkinny_Blue: ZmbM_HikerSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_HikerSkinny_Green: ZmbM_HikerSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_HikerSkinny_Yellow: ZmbM_HikerSkinny_Yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_HikerSkinny_Grey: ZmbF_HikerSkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_HikerSkinny_Red: ZmbF_HikerSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_HunterOld_Autumn: ZmbM_HunterOld_Autumn
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_HunterOld_Spring: ZmbM_HunterOld_Spring
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_HunterOld_Summer: ZmbM_HunterOld_Summer
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_HunterOld_Winter: ZmbM_HunterOld_Winter
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_SurvivorNormal_Blue: ZmbF_SurvivorNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_SurvivorNormal_Orange: ZmbF_SurvivorNormal_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_SurvivorNormal_Red: ZmbF_SurvivorNormal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_SurvivorNormal_White: ZmbF_SurvivorNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_PolicemanFat: ZmbM_PolicemanFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_PoliceWomanNormal: ZmbF_PoliceWomanNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_PolicemanSpecForce: ZmbM_PolicemanSpecForce
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_SoldierNormal: ZmbM_SoldierNormal
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_usSoldier_normal_Woodland: ZmbM_usSoldier_normal_Woodland
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_usSoldier_normal_Desert: ZmbM_usSoldier_normal_Desert
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CommercialPilotOld_Blue: ZmbM_CommercialPilotOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CommercialPilotOld_Olive: ZmbM_CommercialPilotOld_Olive
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CommercialPilotOld_Brown: ZmbM_CommercialPilotOld_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_CommercialPilotOld_Grey: ZmbM_CommercialPilotOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_PatrolNormal_PautRev: ZmbM_PatrolNormal_PautRev
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_PatrolNormal_Autumn: ZmbM_PatrolNormal_Autumn
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_PatrolNormal_Flat: ZmbM_PatrolNormal_Flat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_PatrolNormal_Summer: ZmbM_PatrolNormal_Summer
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_JoggerSkinny_Blue: ZmbM_JoggerSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_JoggerSkinny_Green: ZmbM_JoggerSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_JoggerSkinny_Red: ZmbM_JoggerSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_JoggerSkinny_Brown: ZmbF_JoggerSkinny_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MotobikerFat_Beige: ZmbM_MotobikerFat_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MotobikerFat_Black: ZmbM_MotobikerFat_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MotobikerFat_Blue: ZmbM_MotobikerFat_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_VillagerOld_Blue: ZmbM_VillagerOld_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_VillagerOld_Green: ZmbM_VillagerOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_VillagerOld_White: ZmbM_VillagerOld_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_SkaterYoung_Blue: ZmbM_SkaterYoung_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_SkaterYoung_Brown: ZmbM_SkaterYoung_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_SkaterYoung_Green: ZmbM_SkaterYoung_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_SkaterYoung_Grey: ZmbM_SkaterYoung_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_SkaterYoung_Striped: ZmbF_SkaterYoung_Striped
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_SkaterYoung_Violet: ZmbF_SkaterYoung_Violet
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_DoctorSkinny: ZmbF_DoctorSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_BlueCollarFat_Red: ZmbF_BlueCollarFat_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_BlueCollarFat_White: ZmbF_BlueCollarFat_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MechanicNormal_Beige: ZmbF_MechanicNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MechanicNormal_Green: ZmbF_MechanicNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MechanicNormal_Grey: ZmbF_MechanicNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MechanicNormal_Orange: ZmbF_MechanicNormal_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MechanicSkinny_Blue: ZmbM_MechanicSkinny_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MechanicSkinny_Grey: ZmbM_MechanicSkinny_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MechanicSkinny_Green: ZmbM_MechanicSkinny_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MechanicSkinny_Red: ZmbM_MechanicSkinny_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ConstrWorkerNormal_Beige: ZmbM_ConstrWorkerNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ConstrWorkerNormal_Black: ZmbM_ConstrWorkerNormal_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ConstrWorkerNormal_Green: ZmbM_ConstrWorkerNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ConstrWorkerNormal_Grey: ZmbM_ConstrWorkerNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_HeavyIndustryWorker: ZmbM_HeavyIndustryWorker
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_OffshoreWorker_Green: ZmbM_OffshoreWorker_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_OffshoreWorker_Orange: ZmbM_OffshoreWorker_Orange
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_OffshoreWorker_Red: ZmbM_OffshoreWorker_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_OffshoreWorker_Yellow: ZmbM_OffshoreWorker_Yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_NurseFat: ZmbF_NurseFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_HandymanNormal_Beige: ZmbM_HandymanNormal_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_HandymanNormal_Blue: ZmbM_HandymanNormal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_HandymanNormal_Green: ZmbM_HandymanNormal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_HandymanNormal_Grey: ZmbM_HandymanNormal_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_HandymanNormal_White: ZmbM_HandymanNormal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\HandyEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_DoctorFat: ZmbM_DoctorFat
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_Jacket_beige: ZmbM_Jacket_beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_Jacket_black: ZmbM_Jacket_black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_Jacket_blue: ZmbM_Jacket_blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_Jacket_bluechecks: ZmbM_Jacket_bluechecks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_Jacket_brown: ZmbM_Jacket_brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_Jacket_greenchecks: ZmbM_Jacket_greenchecks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_Jacket_grey: ZmbM_Jacket_grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_Jacket_khaki: ZmbM_Jacket_khaki
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_Jacket_magenta: ZmbM_Jacket_magenta
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_Jacket_stripes: ZmbM_Jacket_stripes
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_PatientOld: ZmbF_PatientOld
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_PatientSkinny: ZmbM_PatientSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ShortSkirt_beige: ZmbF_ShortSkirt_beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_ShortSkirt_black: ZmbF_ShortSkirt_black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_ShortSkirt_brown: ZmbF_ShortSkirt_brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_ShortSkirt_green: ZmbF_ShortSkirt_green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_ShortSkirt_grey: ZmbF_ShortSkirt_grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_ShortSkirt_checks: ZmbF_ShortSkirt_checks
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_ShortSkirt_red: ZmbF_ShortSkirt_red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_ShortSkirt_stripes: ZmbF_ShortSkirt_stripes
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_ShortSkirt_white: ZmbF_ShortSkirt_white
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_ShortSkirt_yellow: ZmbF_ShortSkirt_yellow
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\SkirtEyes.Orange.rvmat"};
	};
	class DZNC_ORANGE_VillagerOld_Red: ZmbF_VillagerOld_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MilkMaidOld_Beige: ZmbF_MilkMaidOld_Beige
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MilkMaidOld_Black: ZmbF_MilkMaidOld_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MilkMaidOld_Green: ZmbF_MilkMaidOld_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_MilkMaidOld_Grey: ZmbF_MilkMaidOld_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_priestPopSkinny: ZmbM_priestPopSkinny
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ClerkFat_Brown: ZmbM_ClerkFat_Brown
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ClerkFat_Grey: ZmbM_ClerkFat_Grey
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ClerkFat_Khaki: ZmbM_ClerkFat_Khaki
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ClerkFat_White: ZmbM_ClerkFat_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_Clerk_Normal_Blue: ZmbF_Clerk_Normal_Blue
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_Clerk_Normal_White: ZmbF_Clerk_Normal_White
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_Clerk_Normal_Green: ZmbF_Clerk_Normal_Green
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_Clerk_Normal_Red: ZmbF_Clerk_Normal_Red
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ClerkFat_Black: ZmbF_ClerkFat_Black
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ClerkFat_GreyPattern: ZmbF_ClerkFat_GreyPattern
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
	class DZNC_ORANGE_ClerkFat_BluePattern: ZmbF_ClerkFat_BluePattern
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"DZNC_Zombies\data\orange-eyes.rvmat"};
	};
};