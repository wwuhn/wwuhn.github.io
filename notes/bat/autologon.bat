@echo off
echo Windows Registry Editor Version 5.00 >temp.reg
echo 正在设置自动登录当前系统的帐户...
echo [hkey_local_machin\software\microsoft\windows nt\currentversion\winlogon] >>temp.reg
echo "autoadminlogon"="1" >>temp.reg
echo "defaultusername"="normalaccount" >>temp.reg
echo "defaultpassword"="noprivilege" >>temp.reg
echo.
echo 成功将"normalaccount"帐户设置为当前自动登录的帐户！
pause
regedit /s temp.reg
del /q /f temp.reg >nul