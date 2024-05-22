@echo off
SETLOCAL EnableExtensions DisableDelayedExpansion

:: Function to check if the P:\ drive is mounted
:CheckPDrive
set "PDriveMounted=false"
for /f %%d in ('wmic logicaldisk where "DeviceID='P:'" get DeviceID ^| find ":"') do set "PDriveMounted=true"
if not "%PDriveMounted%"=="true" (
    echo.
    powershell -Command  "Write-Host 'P:\ Drive: Not Mounted' -ForegroundColor DarkRed;"
    powershell -Command  "Write-Host 'Exiting App' -ForegroundColor DarkYellow;"
    exit /b 1
)

:: Reading the existing configuration and setting variables
for /f "tokens=1* delims== eol=#" %%i in (.\Utils\Shared\Globals.cfg) do (
   set "%%i=%%j"
)

:: Show the DayZ n Chill Dev Logo.
SET "ASCIIARTPATH=.\Utils\Shared\Branding.txt"
SET "COLORS=Blue,Green,Cyan,DarkBlue,DarkGreen,DarkCyan"
powershell -Command "$colors = '%COLORS%'.Split(','); $randomColor = Get-Random -InputObject $colors; $content = Get-Content -Path '%ASCIIARTPATH%'; $content | ForEach-Object {Write-Host $_ -ForegroundColor $randomColor}"

:: Begin DayZ Project Manager Setup
echo This setup file will help you configure your project with ease so you should only have to do this once.
echo Please follow along with the prompts and you will be ready to go in no time at all.
echo.
pause

:: Detect the directory of this batch file
SET "DETECTEDDIR=%~dp0"

:: Ask the user if this directory should be the new PROJECTDIR
echo.
powershell -Command  "Write-Host 'PROJECT DIRECTORY:' -ForegroundColor DarkMagenta -NoNewline; Write-Host ' %DETECTEDDIR%' -ForegroundColor DarkCyan;"
powershell -Command  "Write-Host 'This should be the directory where you downloaded, or cloned the dayz-project-template from GitHub.' -ForegroundColor Gray;"

:: Define the message string
echo.
powershell -Command "$message = 'Please verify that this is your Project''s location listed above?'; Write-Host -ForegroundColor Yellow -NoNewline $message; Write-Host ' (Y/N)' -NoNewline;"

set /p USERCONFIRM=

if /i "%USERCONFIRM%" neq "Y" (
    echo.
    powershell -Command "Write-Host 'Please enter the path to your project directory manually: ' -ForegroundColor Yellow"
    set /p NEWPROJECTDIR=
    powershell -Command "Write-Host 'Setting project directory in Global.cfg ' -ForegroundColor Cyan"
) else (
    SET "NEWPROJECTDIR=%DETECTEDDIR%"
    echo.
    powershell -Command "Write-Host 'Setting project directory in Global.cfg ' -ForegroundColor Cyan"
)

:: Remove trailing backslash from PROJECTDIR if it exists
if "%NEWPROJECTDIR:~-1%"=="\" (
    SET "NEWPROJECTDIR=%NEWPROJECTDIR:~0,-1%"
)

:: Create a temporary file for the updated configuration
SET "TEMPCFGFILE=%TEMP%\temp_globals.cfg"
if exist "%TEMPCFGFILE%" del "%TEMPCFGFILE%"

:: Read and write config file lines, modifying only PROJECTDIR
(for /f "tokens=1* delims== eol=#" %%i in (.\Utils\Shared\Globals.cfg) do (
    set "key=%%i"
    set "value=%%j"
    setlocal EnableDelayedExpansion
    if "!key!"=="PROJECTDIR" (
        echo PROJECTDIR=!NEWPROJECTDIR!>> "!TEMPCFGFILE!"
    ) else if "!key!"=="YOURMODDIR" (
        echo YOURMODDIR=!NEWPROJECTDIR!\Mod-Name>> "!TEMPCFGFILE!"
    ) else (
        echo !key!=!value!>> "!TEMPCFGFILE!"
    )
    endlocal
)) >nul

:: Replace the original Globals.cfg with the updated one
move /y "%TEMPCFGFILE%" "./Utils/Shared/Globals.cfg" >nul

powershell -Command "Write-Host 'PROJECTDIR updated successfully.' -ForegroundColor Green"

:: Run NameMod.ps1 using PowerShell
powershell -ExecutionPolicy Bypass -File ".\Utils\Batch\Setup\NameMod.ps1"

:: Reload the configuration from Globals.cfg
for /f "tokens=1* delims== eol=#" %%i in (.\Utils\Shared\Globals.cfg) do (
   set "%%i=%%j"
)
:: Set Simlinks
echo.
powershell -Command "Write-Host 'Setting up symlinks.' -ForegroundColor Magenta"
call .\Utils\Batch\Setup\WorkshopSymlink.Bat 
echo.

powershell -Command "Write-Host 'Setup is Complete.' -ForegroundColor Green"
timeout /t 30 /nobreak 
exit
