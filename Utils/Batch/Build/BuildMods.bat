@echo off
SETLOCAL

@REM Set paths to tools and directories
SET MakePboPath="C:\Program Files (x86)\Mikero\DePboTools\bin\MakePbo.exe"
SET AddonBuilderPath="C:\Program Files (x86)\Steam\steamapps\common\DayZ Tools\Bin\AddonBuilder\AddonBuilder.exe"

SET ClientSource="P:\Colorful-UI"
SET ClientOutput="P:\Mods\@Colorful-UI\Addons"

@REM Run AddonBuilder to pack the mod files
%AddonBuilderPath% %ClientSource% %ClientOutput% -packonly -clear

@REM Check the exit code of AddonBuilder
IF %ERRORLEVEL% NEQ 0 (
    powershell -Command "Write-Host 'Error: Mod build failed!' -ForegroundColor Red"
    pause
    exit /b %ERRORLEVEL%
) ELSE (
    powershell -Command "Write-Host 'All mods have been built from the C Drive.' -ForegroundColor Green"
    powershell -Command "Write-Host 'Please check your local server to verify.' -ForegroundColor DarkYellow"
    timeout /t 5 /nobreak
    exit
)

