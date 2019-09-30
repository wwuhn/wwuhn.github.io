@echo off
cls
:menu

echo [1] 定时关机,输入时间,计算机将在输入的时间后一分钟关闭
echo [2] 取消关机
echo [3] 取消计划任务
echo [0] exit
echo.
set /p choice=  please choice and press enter:  
if "%choice%"=="1" goto 1
if "%choice%"=="2" goto 2
if "%choice%"=="3" goto 3
if "%choice%"=="0" goto 0
echo.

goto 0
:1
cls
echo.
set /p time= as "24:12" ,input time:
at %time% shutdown -s -t 30
goto menu

:2
cls
echo.
shutdown -a
goto menu


:3
cls
echo.
at /del
goto menu

:0
set time=
cls
echo.