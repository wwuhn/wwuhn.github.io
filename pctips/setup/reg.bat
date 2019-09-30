@echo off
cls
cmd /c reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Applets\Regedit" /v "LastKey" /d "HKEY_CLASSES_ROOT" /f&&start regedit.exe
