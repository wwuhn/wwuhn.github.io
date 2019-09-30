@echo off
cls
color 3a
:menu
echo.
echo    选择菜单：
echo.
@echo  ╔┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉╗
@echo  ┋                                                                  ┋
@echo  ┋  1. 定时关机,输入时间(如24:12),计算机将在输入的时间后一分钟关闭  ┋
@echo  ┋                                                                  ┋
@echo  ┋  2. 定时关机,输入秒数(如3600),计算机将在输入的秒数后关闭         ┋
@echo  ┋                                                                  ┋
@echo  ┋  3. 查看计划任务(资源管理器窗户窗口)                             ┋
@echo  ┋                                                                  ┋
@echo  ┋  4. 查看计划任务(at命令设置的任务,CMD窗口,也就是本窗口查看)      ┋
@echo  ┋                                                                  ┋
@echo  ┋  5. 取消计划任务和定时关机任务                                   ┋
@echo  ┋                                                                  ┋
@echo  ┋  0. exit                                                         ┋
@echo  ┋                                                                  ┋
@echo  ╚┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉╝

echo.
set /p choice="    选择项目(输入前面的数字)，然后回车:"  
if "%choice%"=="1" goto 1
if "%choice%"=="2" goto 2
if "%choice%"=="3" goto 3
if "%choice%"=="4" goto 4
if "%choice%"=="5" goto 5
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
set /p time= as "3600" ,input seconds:
shutdown -s -t %time%
goto menu

:3
cls
echo.
taskschd.msc
goto menu


:4
cls
echo.
at
goto menu

:5
cls
echo.
shutdown -a
at /del
goto menu

:0
set time=
cls
echo.