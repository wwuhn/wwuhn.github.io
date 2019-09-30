@echo off
echo windows registry editor version 5.00 >temp.reg
echo 正在禁用windows的历史记录功能...
echo [hkey_local_machinge\software\microsoft\windows nt\currentversion\policies\explorer] >>temp.reg
echo "noRecentDocsNetHood"=dword:00000001
echo "noRecentDocsHistory"=dword:00000001
echo "noInstrumentation"=dword:00000001
echo "noStartMenuMfuprogramsList"=dword:00000001
echo.
echo 成功禁用windows的历史记录功能！
regedit /s temp.reg
del /f /f temp.reg >nul
