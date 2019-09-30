@if exist runhide.vbs @goto findvbs
@echo Set ws = CreateObject("Wscript.Shell")>>runhide.vbs 
@echo ws.run "cmd /c "%0"",vbhide >>runhide.vbs
@start runhide.vbs&&exit
:findvbs
del runhide.vbs
@echo off
cls
cmd /c reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Applets\Regedit" /v "LastKey" /d "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders" /f&&start regedit.exe
