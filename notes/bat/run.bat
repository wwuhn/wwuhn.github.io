@echo off
echo.相同路径在HKEY_LOCAL_MACHINE和HKEY_CURRENT_USER分别存在：
echo.
echo user(machine)\SOFTWARE\Microsoft\Windows   \CurrentVersion\Run
echo user(machine)\SOFTWARE\Microsoft\Windows   \CurrentVersion\Policies\Explorer\run
echo user(machine)\Software\Microsoft\Windows NT\CurrentVersion\Windows\load=
echo user(machine)\Software\Microsoft\Windows NT\CurrentVersion\Windows\winlogon\userinit=

echo.
echo 选择菜单：
echo   [1] HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run
echo   [2] HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Run
echo   [3] HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion\Windows
echo   [4] HKEY_CURRENT_USER\Software\Microsoft\Windows NT\CurrentVersion\Windows

echo.

set /p cho=  Please input number,then ENTER:  

if "%cho%"=="1" goto 1
if "%cho%"=="2" goto 2
if "%cho%"=="3" goto 3
if "%cho%"=="4" goto 4


if "%cho%"=="0" goto 0

goto 0
:1
echo.
cls
cmd /c reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Applets\Regedit" /v "LastKey" /d "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run" /f&&start regedit.exe
goto menu

:2
echo.
cls
cmd /c reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Applets\Regedit" /v "LastKey" /d "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Run" /f&&start regedit.exe
goto menu

:3
echo.
cls
cmd /c reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Applets\Regedit" /v "LastKey" /d "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion\Windows" /f&&start regedit.exe
goto menu

:4
echo.
cmd /c reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Applets\Regedit" /v "LastKey" /d "HKEY_CURRENT_USER\Software\Microsoft\Windows NT\CurrentVersion\Windows" /f&&start regedit.exe
goto menu



:0
set time=
set cho=
cls
