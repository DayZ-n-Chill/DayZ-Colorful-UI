@echo off
SETLOCAL EnableExtensions DisableDelayedExpansion

:: Function to check if the P:\ drive is mounted
:CheckPDrive
set "PDriveMounted=false"
for /f %%d in ('powershell -Command "Get-PSDrive -Name P -ErrorAction SilentlyContinue | Select-Object -ExpandProperty Name"') do set "PDriveMounted=true"
if not "%PDriveMounted%"=="true" (
    echo.
    powershell -Command "Write-Host 'P:\ Drive: Not Mounted' -ForegroundColor DarkRed; Write-Host 'Exiting App' -ForegroundColor DarkYellow"
    exit /b 1
)

:: Reading existing configuration and setting variables
if exist ".\Utils\Shared\Globals.cfg" (
    for /f "tokens=1* delims== eol=#" %%i in (.\Utils\Shared\Globals.cfg) do (
        set "%%i=%%j"
    )
) else (
    echo Globals.cfg not found. Exiting...
    exit /b 1
)

:: Display DayZ n Chill Dev Logo
SET "ASCIIARTPATH=.\Utils\Shared\Branding.txt"
SET "COLORS=Blue,Green,Cyan,DarkBlue,DarkGreen,DarkCyan,DarkRed,DarkMagenta,DarkYellow"
powershell -Command "$colors = '%COLORS%'.Split(','); $randomColor = Get-Random -InputObject $colors; Get-Content -Path '%ASCIIARTPATH%' | ForEach-Object {Write-Host $_ -ForegroundColor $randomColor}"

:: Begin DayZ Project Manager Setup
echo This setup file will help you configure your project with ease so you should only have to do this once.
echo Follow along with the prompts, and you will be ready to go in no time.
echo.
powershell -Command "Write-Host 'WARNING:' -ForegroundColor DarkYellow; Write-Host 'If you installed DayZ on a drive other than C:\,' -ForegroundColor DarkCyan; Write-Host 'please exit this application and manually edit the Globals.cfg file.' -ForegroundColor DarkCyan"
echo.
pause

:: Detect the script directory
SET "DETECTEDDIR=%~dp0"

:: Confirm PROJECTDIR setup
echo.
powershell -Command "Write-Host 'PROJECT DIRECTORY:' -ForegroundColor DarkMagenta -NoNewline; Write-Host ' %DETECTEDDIR%' -ForegroundColor DarkCyan; Write-Host 'This should be the directory where you downloaded or cloned the DayZ project template from GitHub.' -ForegroundColor Gray; Write-Host 'Verify the project directory listed above.' -ForegroundColor Yellow -NoNewline; Write-Host ' (Y/N)' -NoNewline"
set /p USERCONFIRM=

if /i "%USERCONFIRM%" neq "Y" (
    echo.
    powershell -Command "Write-Host 'Please enter your project directory manually: ' -ForegroundColor Yellow"
    set /p NEWPROJECTDIR=
) else (
    SET "NEWPROJECTDIR=%DETECTEDDIR%"
)

:: Trim trailing backslash from NEWPROJECTDIR if it exists
if "%NEWPROJECTDIR:~-1%"=="\" SET "NEWPROJECTDIR=%NEWPROJECTDIR:~0,-1%"

:: Create a temporary config file and update Globals.cfg
SET "TEMPCFGFILE=%TEMP%\temp_globals.cfg"
if exist "%TEMPCFGFILE%" del "%TEMPCFGFILE%"

(for /f "tokens=1* delims== eol=#" %%i in (.\Utils\Shared\Globals.cfg) do (
    set "key=%%i"
    set "value=%%j"
    setlocal EnableDelayedExpansion
    if "!key!"=="PROJECTDIR" (
        echo PROJECTDIR=!NEWPROJECTDIR!>> "!TEMPCFGFILE!"
    ) else if "!key!"=="YOURMODDIR" (
        echo YOURMODDIR=!NEWPROJECTDIR!\Colorful-UI>> "!TEMPCFGFILE!"
    ) else (
        echo !key!=!value!>> "!TEMPCFGFILE!"
    )
    endlocal
)) >nul

move /y "%TEMPCFGFILE%" "./Utils/Shared/Globals.cfg" >nul
powershell -Command "Write-Host 'PROJECTDIR updated successfully.' -ForegroundColor Green"

:: Reload configuration from Globals.cfg
for /f "tokens=1* delims== eol=#" %%i in (.\Utils\Shared\Globals.cfg) do (
    set "%%i=%%j"
)

:: Set up symlinks and complete setup
echo.
powershell -Command "Write-Host 'Setting up symlinks.' -ForegroundColor Magenta"

IF NOT EXIST "%PDRIVE%" (
    powershell -Command "Write-Host 'WARNING: The P drive is not mounted. Please ensure it is mounted and restart the setup.' -ForegroundColor Red"
    pause
    exit /b
)

:: Check if the Workshop directory exists
IF NOT EXIST "%WORKDIR%" (
    powershell -Command "Write-Host 'WARNING: The Workshop directory provided does not exist ' -ForegroundColor Red"
    echo Provided Folder: "%WORKDIR%".
    echo Please make sure the Workshop folder is located there.
    pause
    exit /b
)

:: Create a junction from the Workshop directory to the target directory on the P drive
mklink /J "%MODDIR%" "%WORKDIR%" >nul 2>&1
IF ERRORLEVEL 1 (
    powershell -Command "Write-Host 'SUCCESS:' -ForegroundColor Green -NoNewline; Write-Host ' P:\Mods\' -ForegroundColor Cyan -NoNewline; Write-Host ' already exists, Carry On!' -ForegroundColor Green -NoNewline;"
    echo. 
) ELSE (
    echo.
    powershell -Command "Write-Host 'Junction created successfully.' -ForegroundColor Green; Write-Host 'Workshop mods are linked to' -ForegroundColor Green -NoNewline; Write-Host ' \"%MODDIR%\" ' -ForegroundColor Cyan -NoNewline; Write-Host 'on the P drive.' -ForegroundColor Green;"
)

:: Create a symlink for SYMLDIR on the P drive
mklink /J "%SYMLDIR%" "%YOURMODDIR%" >nul 2>&1
IF ERRORLEVEL 1 (
    powershell -Command "Write-Host 'ERROR:' -ForegroundColor DarkMagenta -NoNewline; Write-Host ' Failed to create symlink for' -ForegroundColor DarkRed -NoNewline; Write-Host ' %SYMLDIR%.' -ForegroundColor Cyan; Write-Host 'Folder may already exist.' -ForegroundColor DarkCyan;"
    pause
    exit /b
) ELSE (
    echo.
    powershell -Command "Write-Host 'Symlink created successfully.' -ForegroundColor Green; Write-Host 'SYMLDIR' -ForegroundColor Green -NoNewline; Write-Host ' %SYMLDIR%' -ForegroundColor Cyan -NoNewline; Write-Host ' is now linked.' -ForegroundColor Green;"
)

echo.
powershell -Command "Write-Host 'Setup is Complete.' -ForegroundColor Green"
echo.
powershell -Command "Write-Host 'Thank you for using Colorful-UI' -ForegroundColor Magenta; Write-Host 'This Setup uses a modified version of the DayZ Project Template.' -ForegroundColor DarkGray; Write-Host 'Get it Here!' -ForegroundColor DarkGray; Write-Host 'https://github.com/DayZ-n-Chill/DayZ-Project-Template' -ForegroundColor DarkGray"

timeout /t 30 /nobreak
exit /b 0
