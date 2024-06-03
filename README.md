![Header Image](https://cdn.discordapp.com/attachments/1139653291182141540/1246675033389010965/cui25.png?ex=665d401a&is=665bee9a&hm=b62b5028109a9d06752ce4843029db7570e658954efe46cee0c8d3da36621b88&)

# Colorful UI 2.5 - Community Edition Template

## Features
- Fully Responsive Design (UHD & Ultrawide Supported)
- Loading Screen with Synced BG Images, & Tips
- Main Menu with Static BG Image and Custom Music.
- Modified layout on all Default Layouts.
- Easily Editable Layout Files with Prefab Elements.
- Simple Configuration
- Customize EVERY ELEMENT INDIVIDUALLY!
- Death Screen
- NO MOD DEPENDENCIES!

## Coming Soon in 3.0
- Server Panel
- Multiple Prefab & Custom Theme Colors
- Customizable Stamina Colors
- Customizable Status Icon Colors
- MultiLanguage
- Player Stats
- Leaderboards
- Killfeed

## Open Source
Let's build together. This project is open source under the MIT License. If you have things you would like to see improve on this template base, send me a pull request on GitHub.

### Artistic Freedom
In addition to the Source Code, there are also some art files. Here is the original PSD file used to create this layout. Use it to learn more about how I put these layouts together.

# Installation Guide
A Comprehensive Mod Template for DayZ. Optimized with Workbench for Advanced Scripting and pboProject for Efficient Building.
This is my personal template that I use for all projects.

# Creating Your Project from a Template
Follow these steps to clone the DayZ Mod Template, set up your project environment, and initialize your own Git repository.

## Step 1

**Install Git and Git LFS**:
- Make sure you have Git and Git LFS installed on your system. If not, get them here:
  - [Git](https://git-scm.com/)
  - [Git LFS](https://git-lfs.github.com/)

## Step 2

**Use the Template Repository**:
- Navigate to the DayZ Mod Template repository on GitHub: [https://github.com/DayZ-n-Chill/DayZ-Colorful-UI/](https://github.com/DayZ-n-Chill/DayZ-Colorful-UI/)
- Click on the "Use this template" button near the top of the repository page.
- https://www.gitkraken.com/download  I would reccomend GitKraken for repo management. But use what you want. 

## Step 3

**Clone the Repository**:
- Clone the repository to a drive other than your P drive, preferably a project directory.

## Step 4

**Mount Your P Drive and Install Required Tools**:
- Make sure your P drive is mounted. Ensure you have DayZ, DayZ Tools, and DayZServer installed.
  - **Note:** If they are not installed in the default location on the C Drive, you will need to edit their locations in the `globalcfg` under the `shared` folder in the `utils` directory.

## Step 5

**Run the Start Script**:
- Run the `start.bat` in the root of the directory. This will symlink the needed folders.

## Step 6

**Edit Your UI**:
- You can now edit your UI in VSCode or your preferred editor.
  - If you want to use Workbench, navigate to the `workbench` folder in the `P:\colorful-ui` folder and double-click the `dayz.gproj`.
  - **Note:** You may have to tell Windows to run it with Workbench the first time you try.

## Step 7

**Build Your Code**:
- Use the `build` batch file.

## Step 8

**Test on Local Server**:
- Choose from one of 7 built-in maps including:
  - Chernarus
  - Livonia
  - Deer Isle
  - Empty Map
  - Valning
  - Rio
  - Melkart

**Note:** Follow their structure to add more maps to your development environment.

That's it!

**Best Practice**:
- Create shortcuts to these batch files on your desktop. There are multiple batch files to help you out including:
  - `build.bat`
  - `killdayzdiag64.bat`
  - `log burner`
  - several servers and other tools.
