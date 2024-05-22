class DayZTool: WorkbenchPlugin
{
	void RunDayZBat(string filepath, bool wait = false)
	{
		if (filepath.Length() < 2) return;
		
		filepath.Replace("\\", "/");
		
		if (filepath[1] != ":")
		{
			string cwd;
			Workbench.GetCwd(cwd);
			filepath = cwd + "/" + filepath;
		}
		
		int index = filepath.IndexOf("/");
		int last_index = index;
		
		while(index != -1)
		{
			last_index = index;
			index = filepath.IndexOfFrom(last_index + 1, "/");
		}
		
		if (last_index == -1) return;
		
		string path = filepath.Substring(0, last_index);
		string bat = filepath.Substring(last_index + 1, filepath.Length() - last_index - 1);
		/*Print(filepath);
		Print(path);
		Print(bat);*/
		// Made it so that you can access other drives. 
		Workbench.RunCmd("cmd /c \"chdir /D " + path + " & call " + bat + "\"", wait);
	}
	
	override void Configure() 
	{
		Workbench.ScriptDialog("Mission directory","", this);
	}
	
	[ButtonAttribute("OK")]
	void DialogOk()
	{
	}
};


[WorkbenchPluginAttribute("Kill: Dayz ", "Shutdown All Diag64 Tasks", "ctrl+3", "", {"ResourceManager","ScriptEditor"})]
class KillModTool: DayZTool
{
    string BatchFile;

    void KillModTool()

    {
		 BatchFile = "P:/Mod-Name/Workbench/ToolAddons/Batch/Sysops/Kill_DayZ-Diag64.bat";
    }

    override void Run()
    {
        RunDayZBat(BatchFile, true);
    }
}

// [WorkbenchPluginAttribute("Restart DayZ", "Just for testing", "ctrl+1", "", {"ScriptEditor"})]
// class RestartDayzTool: DayZTool
// {
// 	[Attribute("day_z_data_missions/killDayZ.bat", "fileeditbox", "Path to missions dir", "")]
// 	string KillBatPath;
	
// 	[Attribute("day_z_data_missions/_default_single/default_SampleMap3_Empty.bat", "fileeditbox", "Path to missions dir", "")]
// 	string MissionBatPath;
	
// 	override void Run()
// 	{
// 		RunDayZBat(KillBatPath, true);
// 		RunDayZBat(MissionBatPath);
// 	}
// }

// [WorkbenchPluginAttribute("Run DayZ ", "Just for testing", "ctrl+2", "", {"ScriptEditor"})]
// class RunDayzTool: DayZTool
// {
// 	[Attribute("day_z_data_missions/_default_single/default_SampleMap3_Empty.bat", "fileeditbox", "Path to missions dir", "")]
// 	string MissionBatPath;
	
// 	override void Run()
// 	{
// 		RunDayZBat(MissionBatPath);
// 	}
// }



// [WorkbenchPluginAttribute("Wrap Mod", "Just for testing", "ctrl+4", "", {"ScriptEditor"})]
// class WrapModTool: DayZTool
// {
// 	[Attribute("day_z_data_missions/killDayZ.bat", "fileeditbox", "Path to missions dir", "")]
// 	string KillBatPath;
	
// 	override void Run()
// 	{
// 		RunDayZBat(KillBatPath);
// 	}
// }

// [WorkbenchPluginAttribute("Wrap DayZ", "Just for testing", "ctrl+5", "", {"ScriptEditor"})]
// class WrapDayZTool: DayZTool
// {
// 	[Attribute("day_z_data_missions/killDayZ.bat", "fileeditbox", "Path to missions dir", "")]
// 	string KillBatPath;
	
// 	override void Run()
// 	{
// 		RunDayZBat(KillBatPath);
// 	}
// }

// [WorkbenchPluginAttribute("Build Mod: Mikeros Tool", "Just for testing", "ctrl+6", "", {"ScriptEditor"})]
// class BuildModMikTool: DayZTool
// {
// 	[Attribute("day_z_data_missions/killDayZ.bat", "fileeditbox", "Path to missions dir", "")]
// 	string KillBatPath;
	
// 	override void Run()
// 	{
// 		RunDayZBat(KillBatPath);
// 	}
// }

// [WorkbenchPluginAttribute("Build Mod: Addon Builder", "Just for testing", "ctrl+7", "", {"ScriptEditor"})]
// class BuildModAOBTool: DayZTool
// {
// 	[Attribute("day_z_data_missions/killDayZ.bat", "fileeditbox", "Path to missions dir", "")]
// 	string KillBatPath;
	
// 	override void Run()
// 	{
// 		RunDayZBat(KillBatPath);
// 	}
// }