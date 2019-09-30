@if exist runhide.vbs @goto findvbs
@echo Set ws = CreateObject("Wscript.Shell")>>runhide.vbs 
@echo ws.run "cmd /c "%0"",vbhide >>runhide.vbs
@start runhide.vbs&&exit
:findvbs
del runhide.vbs

@echo off
echo.
%windir%\system32\migwiz\migwiz.exe