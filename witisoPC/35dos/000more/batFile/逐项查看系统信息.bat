@echo off
cls
echo.
:menu
echo    ***********************************************
echo.
echo      [1] msinfo32 系统信息windows窗口显示
echo      [2] systeminfo 系统信息命令行显示
echo      [3] net start 开启的服务以命令行显示
echo      [4] services.msc 开启的服务以windows窗口显示
echo      [5] ipconfig 查看网络配置
echo      [6] net config 显示系统网络设置
echo      [7] set 显示当前所有环境变量
echo.
echo      [8] net share 查看本机共享资源列表
echo      [9] net user 查看本机用户帐户列表
echo      [0] exit

echo    ***********************************************
echo.
set /p cho=   please input number,then press enter:  

if "%cho%"=="0" goto 0
if "%cho%"=="1" goto 1
if "%cho%"=="2" goto 2
if "%cho%"=="3" goto 3
if "%cho%"=="4" goto 4
if "%cho%"=="5" goto 5
if "%cho%"=="6" goto 6
if "%cho%"=="7" goto 7
if "%cho%"=="8" goto 8
if "%cho%"=="9" goto 9

goto 0
:1
echo.
cls
msinfo32
goto menu

:2
echo.
cls
systeminfo
pause
goto menu

:3
echo.
cls
net start
pause
goto menu

:4
echo.
cls
services.msc
goto menu

:5
echo.
cls
ipconfig /all
pause
goto menu

:6
echo.
cls
net config
pause
goto menu

:7
echo.
cls
set
pause
goto menu

:8
echo.
cls
net share
pause
goto menu


:9
echo.
cls
net user
pause
goto menu


:0
set cho=
cls
