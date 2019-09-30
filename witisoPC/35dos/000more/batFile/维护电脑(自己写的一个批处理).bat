@echo off
echo.
:menu
cls
echo.    _______________________________________________________________
echo.
echo       [00] exit 退出此批处理
echo.    
echo       [  ] regedit /s fname.reg 导入注册表
echo       [  ] scanreg /restore 恢复注册表
echo       [  ] regsvr32 /u fname.dll 手动注册DLL文件
echo       [  ] 用系统安装盘进入系统恢复控制台
echo       [  ] ctrl+c 可结束命令进程
echo.
echo       [01] msinfo32 系统信息(windows窗口显示)
echo       [02] systeminfo 系统信息(命令行显示)
echo       [03] net start 开启的服务\运行的进程(以命令行显示)
echo       [04] services.msc 开启的服务(以windows窗口显示)
echo       [05] ipconfig 查看网络配置
echo.
echo       [06] net config 显示系统网络设置
echo       [07] set 显示当前所有环境变量    
echo       [08] rstrui 系统还原
echo       [09] 启动优化大师进行碎片整理
echo       [10] chkdsk 磁盘检查
echo.
echo       [11] sfc 系统文件检查   
echo       [12] display driver setup 显卡驱动安装
echo       [13] powerword 打开金山词霸
echo       [14] shutdown 一分钟后关机
echo       [15] shutdown 定时关机,输入时间,计算机将在输入的时间后一分钟关机
echo.
echo       [16] shutdown -a 取消关机
echo       [17] at 1 del取消计划任务
echo       [18] event查看eventvwr
echo       [19] 性能监视器perfmon.msc
echo       [20] 驱动查询driverquery
echo.
echo       [21] msconfig 查看自动启用程序、serivces(can hide all windows serivces);
echo       [22] services.msc 设置服务启动方式;
echo       [23] taskmgr 查看CPU、内存占用、每一进程的CPU占用；
echo       [24] 打开internet临时文件夹
echo       [25] 打开系统临时文件夹
echo.    _______________________________________________________________
echo.
set /p cho=  please input number,then enter:  

if "%cho%"=="1" goto 1
if "%cho%"=="2" goto 2
if "%cho%"=="3" goto 3
if "%cho%"=="4" goto 4
if "%cho%"=="5" goto 5
if "%cho%"=="6" goto 6
if "%cho%"=="7" goto 7
if "%cho%"=="8" goto 8
if "%cho%"=="9" goto 9
if "%cho%"=="10" goto 10
if "%cho%"=="11" goto 11
if "%cho%"=="12" goto 12
if "%cho%"=="13" goto 13
if "%cho%"=="14" goto 14
if "%cho%"=="15" goto 15
if "%cho%"=="16" goto 16
if "%cho%"=="17" goto 17
if "%cho%"=="18" goto 18
if "%cho%"=="19" goto 19
if "%cho%"=="20" goto 20

if "%cho%"=="21" goto 21
if "%cho%"=="22" goto 22
if "%cho%"=="23" goto 23
if "%cho%"=="24" goto 24
if "%cho%"=="25" goto 25

if "%cho%"=="0" goto 0

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
echo ------------------------------------------------------------------------
tasklist
echo ------------------------------------------------------------------------
tasklist /svc
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
rstrui
goto menu


:9
echo.
cls
F:\优化大师\WoptiUtilities_CN.exe
goto menu

:10
echo.
cls
echo.
echo 正在查错c盘..............................................................................
echo.
chkdsk /f c:
echo.
echo 正在查错d盘....................................................................................
echo.
chkdsk /f d:
echo.
echo 正在查错e盘....................................................................................
echo.
chkdsk /f e:
echo.
echo 正在查错f盘....................................................................................
echo.
chkdsk /f g:
echo.
echo 正在查错g盘....................................................................................
echo.
chkdsk /f f:
echo.
echo 正在查错h盘....................................................................................
echo.
chkdsk /f h:
echo.
echo 正在查错i盘....................................................................................
echo.
chkdsk /f i:
echo.
echo 正在查错j盘....................................................................................
echo.
chkdsk /f j:
pause
goto menu


:11
echo.
cls
sfc /scannow
goto menu

:12
echo.
cls
echo 1 回车;
echo 2 upper,then回车;
echo 3 回车;
echo 4 e;yes to all
echo 5 回车
e:
cd\
cd software
cd drivers
sp36729
goto menu

:13
echo.
cls
f:
cd\
cd win7\Powerword 2003
XDICT.EXE
goto menu


:14
cls
echo.
shutdown -s -t 5
goto menu

:15
cls
echo.
set /p time= as "24:12" ,input time:
at %time% shutdown -s -t 30
goto menu

:16
cls
echo.
shutdown -a
goto menu


:17
cls
echo.
at /del
goto menu


:18
cls
echo.
eventvwr
goto menu


:19
cls
echo.
%windir%\system32\perfmon.msc
goto menu

:20
cls
echo.
driverquery
pause
goto menu

:21
cls
echo.
msconfig
goto menu

:22
cls
echo.
services.msc
goto menu

:23
cls
echo.
taskmgr
goto menu

:24
cls
echo.
explorer %userprofile%\AppData\Local\Microsoft\Windows\Temporary Internet Files
goto menu

:25
cls
echo.
explorer %temp%
goto menu

:0
set time=
set cho=
cls
