function Get-ProjectDirectory {
    <#
    Retrieves the project directory from the configuration file.
    #>
    param(
        [string]$configPath
    )
    if (-Not (Test-Path -Path $configPath)) {
        Write-Host "Configuration file does not exist: $configPath" -ForegroundColor Red
        return $null
    }
    try {
        foreach ($line in Get-Content -Path $configPath) {
            if ($line.Trim().StartsWith('PROJECTDIR')) {
                return $line.Trim().Split('=')[1].Trim()
            }
        }
    } catch {
        Write-Host "Error while reading configuration: $_" -ForegroundColor Red
    }
    return $null
}

function Set-TextInFile {
    <#
    Sets the specified text in a file.
    #>
    param(
        [string]$filePath,
        [string]$oldText,
        [string]$newText
    )
    if (-Not (Test-Path -Path $filePath)) {
        Write-Host "File does not exist: $filePath" -ForegroundColor Red
        return $false
    }
    try {
        $content = Get-Content -Path $filePath -Raw
        $newContent = $content.Replace($oldText, $newText)
        if ($content -ne $newContent) {
            Set-Content -Path $filePath -Value $newContent
            return $true
        } else {
            Write-Host "No changes needed in $filePath" -ForegroundColor Cyan
            return $false
        }
    } catch {
        Write-Host "Failed to update ${filePath}: $_" -ForegroundColor Magenta
        return $false
    }
}

function Rename-ModFolder {
    <#
    Renames the mod folder.
    #>
    param(
        [string]$oldFolderPath,
        [string]$newFolderPath
    )
    if (-Not (Test-Path -Path $oldFolderPath)) {
        return $false
    }
    try {
        Rename-Item -Path $oldFolderPath -NewName $newFolderPath
        return $true
    } catch {
        return $false
    }
}

function Invoke-ModUpdateProcess {
    Write-Host ""  # Empty line for spacing
    Write-Host "Starting file & folder pathing process..." -ForegroundColor Magenta
    Write-Host "Enter the name of your" -ForegroundColor Yellow -NoNewline
    Write-Host " 'Mod-Name': " 
    $newModName = Read-Host
    if (-not $newModName) {
        Write-Host "No mod name entered. Exiting." -ForegroundColor Red
        return
    }

    if ($newModName -contains ' ') {
        Write-Host "It's best practice to avoid spaces in directory names. Choose an option:" -ForegroundColor Cyan
        Write-Host "[1] Camel Case (ExampleCamelCase)"
        Write-Host "[2] Underscores (example_underscores)"
        Write-Host "[3] Leave as is (with spaces)"
        $choice = Read-Host "Enter your choice (1, 2, or 3)"
        switch ($choice) {
            '1' { $newModName = -join ($newModName -split ' ' | ForEach-Object { $_.Substring(0,1).ToUpper() + $_.Substring(1).ToLower() }) }
            '2' { $newModName = $newModName -replace ' ', '_' }
            '3' { } # Leave as is
            default {
                Write-Host "Invalid choice, using the name with spaces." -ForegroundColor Red
            }
        }
    }

    $Global:UserInputModName = $newModName 
    if ($null -ne $Global:UserInputModName) { }

    $currentDir = Get-Location
    $configPath = Join-Path -Path $currentDir -ChildPath "Utils\Shared\Globals.cfg"
    $projectDir = Get-ProjectDirectory -configPath $configPath
    if (-not $projectDir) {
        Write-Host "Failed to load the project directory from configuration. Exiting." -ForegroundColor Red
        return
    }

    $oldModPath = Join-Path -Path $projectDir -ChildPath "Mod-Name"
    $newModPath = Join-Path -Path $projectDir -ChildPath $newModName

    $filesToModify = @{
        "BuildMods.bat" = Join-Path -Path $projectDir -ChildPath "Utils\Batch\Build\BuildMods.bat"
        "Globals.cfg"   = $configPath
        "config.cpp"    = Join-Path -Path $oldModPath -ChildPath "Scripts\config.cpp"
        "dayz.gproj"    = Join-Path -Path $oldModPath -ChildPath "Workbench\dayz.gproj"
        "DayZTools.c"   = Join-Path -Path $oldModPath -ChildPath "Workbench\ToolAddons\Plugins\DayZTools.c"
    }

    Write-Host ""  # Empty line for spacing
    Write-Host "Updating all files with the proper pathing for your mod name." -ForegroundColor Magenta
    
    $updatedFiles = @()
    foreach ($fileDescription in $filesToModify.Keys) {
        $result = Set-TextInFile -filePath $filesToModify[$fileDescription] -oldText "Mod-Name" -newText $newModName
        if ($result) {
            $updatedFiles += $fileDescription
        }
    }

    Write-Host "Files to update:" -ForegroundColor Cyan -NoNewline
    Write-Host " $($updatedFiles -join ', ')" -ForegroundColor Gray
    foreach ($fileDescription in $updatedFiles) {
        Write-Host "Updated:" -ForegroundColor Green -NoNewline
        Write-Host " $($filesToModify[$fileDescription])" -ForegroundColor DarkGray
    }

    if ($updatedFiles.Count -gt 0) {
        Write-Host ""  # Empty line for spacing
        Write-Host "Updated all pathing and folders from" -ForegroundColor Magenta -NoNewline
        Write-Host " 'Mod-Name'" -ForegroundColor Gray -NoNewline
        Write-Host " to" -ForegroundColor Magenta -NoNewline
        Write-Host " '$newModName'" -ForegroundColor Gray -NoNewline
        Write-Host " in all listed files." -ForegroundColor Magenta
        
        $renameResult = Rename-ModFolder -oldFolderPath $oldModPath -newFolderPath $newModPath
        if (-not $renameResult) {
            Write-Host "Failed to rename the mod folder. Please check the paths and permissions." -ForegroundColor Red
        } else {
            Write-Host "Renamed folder:" -ForegroundColor Green -NoNewline
            Write-Host " '$oldModPath'" -ForegroundColor DarkGray -NoNewline
            Write-Host " to" -ForegroundColor Cyan -NoNewline
            Write-Host " '$newModPath'" -ForegroundColor DarkGray
        }

        # Setting the environment variable for the new mod path
        $env:newModPath = "%$newModPath%"
    } else {
        Write-Host "No files were updated; folder rename skipped." -ForegroundColor Magenta
    }

    Write-Host ""  # Empty line for final spacing
    Write-Host "Modification process is complete." -ForegroundColor Green
    Write-Host "Thank you for using DayZ n Chill Dev Tools!" -ForegroundColor Green
}

Invoke-ModUpdateProcess
