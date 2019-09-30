@echo off
cls
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run" /v "autodialboardband" /t reg_sz /d "%systemroot%\rasphone -d bname1" /f

 
