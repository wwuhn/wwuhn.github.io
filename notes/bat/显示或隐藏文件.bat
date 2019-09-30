@ECHO off
setlocal ENABLEDELAYEDEXPANSION
set uu="HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced"
for /f "skip=2 tokens=3" %%i in ('reg query %uu% /v Hidden') do (if "%%i"=="0x0" (goto show) else (goto noshow))
:show
echo 显示隐藏文件和扩展名
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v Hidden /t reg_dword /d 1 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v HideFileExt /t reg_dword /d 0 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v ShowSuperHidden /t reg_dword /d 1 /f
rem 下面这句是不显示 "文件夹选项"菜单
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer" /v NoFolderOptions /t REG_DWORD /d 1 /f
taskkill /im Explorer.exe /f && start Explorer.exe >nul 2>nul
exit
:noshow
echo 不显示隐藏文件和扩展名
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v Hidden /t reg_dword /d 0 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v ShowSuperHidden /t reg_dword /d 0 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v HideFileExt /t reg_dword /d 1 /f
rem 下面这句是恢复 "文件夹选项"菜单
reg delete "HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer" /v NoFolderOptions /f
taskkill /im Explorer.exe /f && start Explorer.exe >nul 2>nul
exit