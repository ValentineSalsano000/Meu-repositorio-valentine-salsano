@echo off
setlocal enabledelayedexpansion
REM Cria um atalho na area de trabalho que aponta para jogar.bat
set "TARGET=%~dp0jogar.bat"
powershell -NoProfile -Command "$s=(New-Object -COM WScript.Shell).CreateShortcut([Environment]::GetFolderPath('Desktop') + '\\Jogar RPG da Vida.lnk');$s.TargetPath='%TARGET%';$s.WorkingDirectory='%~dp0';$s.IconLocation='%TARGET%';$s.Save()"
echo Atalho criado na area de trabalho: "Jogar RPG da Vida.lnk"
pause
