@echo off
echo windows registry editor version 5.00 >temp.reg
echo 正在禁用注册表中相应的自动运行项，请稍候...
echo [hkey_current_user\software\microsoft\windows\currentversion\policies\explorer] >>temp.reg
echo "disableLocalMachinRun"=dword:00000001 >>temp.reg
echo "disableLocalMachinRunonce"=dword:00000001 >>temp.reg
echo "disableCurrentUserRun"=dword:00000001 >>temp.reg
echo "disableCurrentUserRunonce"=dword:00000001 >>temp.reg
echo 成功按要求禁用了注册表中相应的运行项
echo.
regedit /s temp.reg
del /q /f temp.reg >nul
