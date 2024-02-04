![Header Image](https://cdn.discordapp.com/attachments/787056181784477777/1202646357362614342/dayznchill_A_logo_for_the_dayz_ui_system_called_face_the_camera_cb5670ce-be43-44ed-890d-2125c6da2674.png?ex=65ce36b3&is=65bbc1b3&hm=d54893d7e230abe6e996a6f08e83ff903918a7c2af466ba4a6b3dfe0fdc9af68&)

# Colorful UI - Community Edition Template

## Features
- Fully Responsive Design (UHD & Ultrawide Supported)
- Loading Screen with Synced BG Images, & Tips
- Main Menu with Static BG Image and Custom Music.
- Moddified layout on all Default Layouts. 
- Easily Editiably Layout Files with Prefab Elements.
- Simple Configuration
- Customize EVERY ELEMENT INDIVIDUALLY!
- NO MOD DEPENDANCIES!

## Coming Soon
- Server Panel
- Multiple Prefab, & Custom Theme Colors.
- Customizable Stamina Colors
- Customizable Status Icon Colors
- Death Screen with Random BG Images, & Death Quotes
- MultiLanguage
- Player Stats
- Leaderboards
- Killfeed

## Open Source:  
Lets build together. This project is open source under MIT Licsence. If you have things you would like to see improve on this template base. Send me a pull request on GITHUB.

### Artistic Freedom:  
In addition to the Source Code, there are also some art files. Here is the original PSD file Used to create this layout. Use it to learn more about how I put these layouts together.

# Installation Guide:  
A Comprehensive Mod Template for DayZ. Optimized with Workbench for Advanced Scripting and pboProject for Efficient Building.
This is my personal template, that I ues for all projects

# Repository Setup

Follow these steps to clone the DayZ Mod Template, set up your project environment, and initialize your own Git repository.

#### Creating Your Project from a Template

1. **Use the Template Repository**:
   - Navigate to the DayZ Mod Template repository on GitHub: `[https://github.com/DayZ-n-Chill/DayZ-Colorful-UI/](https://github.com/DayZ-n-Chill/DayZ-Colorful-UI/)`
   - Click on the "Use this template" button near the top of the repository page.

2. **Set Up Your New Repository**:
   - Enter a name for your new repository, like `DayZ-MyServerName-UI`.
   - Optionally, provide a description.
   - Choose the repository visibility (public or private).
   - Click on "Create repository from template" to generate your new repository.

#### Cloning Your New Repository

3. **Clone Your New Repository**:
   - Once your repository is created, clone it to your local machine:
     ```bash
     git clone https://github.com/yourusername/DayZ-Mod-Name.git
     ```
   - Replace `yourusername` with your actual GitHub username.

4. **Navigate to the Cloned Directory**:
   - Change your directory to the one you just cloned:
     ```bash
     cd DayZ-Mod-Name
     ```
# Workbench

#### Mounting to the Workdrive

1. **Run the Batch File to Mount**:
   - Navigate to the `SetupWorkdrive.bat` file in your mod directory.
     ```
     ../DayZ-Mod-Name/SetupWorkdrive.bat 
     ```
   - Execute this batch file. It will automatically mount all folders containing a 'Workbench' folder in your repository directory to your Workdrive.

#### Opening the Project in Workbench

1. **Access the Project Directory**:
   - Go to the mod's project directory:
     ```
     ../DayZ-Mod-Name/ModName/Workbench
     ```
   - Here, you will find the `dayz.gproj` file.

2. **Open the Project File**:
   - Double-click on `dayz.gproj`.
   - If prompted, choose to open it with Workbench. You can find Workbench in `steamapps/common/DayZ Tools/Bin/Workbench`.

#### Configuring Source Data Directory in Workbench

This step only needs to be completed one time, unless you change your DayZ install directory.

1. **Set the Source Data Directory**:
   - In Workbench, navigate to `Workbench -> Options`.
   - Set "Source Data Directory" to your DayZ installation path, such as `C:/Program Files (x86)/Steam/steamapps/common/DayZ Exp`.

2. **Handle the Restart Prompt**:
   - Upon setting the directory, a prompt to restart Workbench will appear. Select 'No' to decline this automatic restart.

3. **Manually Restart Workbench**:
   - Close the Resource Browser to ensure all settings are applied.
   - Exit and then reopen Workbench.
   - Reopen the `dayz.gproj` file.


#### With [Dabs Framework](https://github.com/InclementDab/DayZ-Dabs-Framework) on your machine, your project will automatically have plugins built-in. To use these plugins, follow `Using the Workbench Plugins` in the wiki.


## License

Your UI is licensed under [MIT License](LICENSE.md).

For any additional questions or feedback, please raise an issue in this repository or contact [DayZ n Chill](discord.gg/dayznchill).
