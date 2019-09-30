@echo off
echo windows registry editor version 5.00 >temp.reg
echo 正在解决IE或资源管理器故障，导致所有窗口同时关闭问题...
echo [hkey_current_user\software\microsoft\windows\currentversion\explorer] >>temp.reg
echo "desktopprocess"=dword:00000001 >>temp.reg
echo [hkey_current_user\software\microsoft\windows\currentversion\explorer\advanced] >>temp.reg
echo "separateProcess"=dword:00000001 >>temp.reg
echo [hkey_current_user\software\microsoft\windows\currentversion\explorer\browsenewprocess] >>temp.reg
echo "browsenewprocess"="yes" >>temp.reg
echo.
regedit /s temp.reg
del /q /f temp.reg >nul
