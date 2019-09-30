@echo off
cls
mode con: lines=420
:menu
echo 1 打开服务管理器（各项服务都有描述）
echo 2 停用以下服务（net stop）
echo		2.1 Offline Files(简称OF，脱机文件服务) 将网络上的共享内容在本地缓存，
echo			使用户可以在脱机状态下访问共享文件;
echo		2.2 HomeGroup Listener 维护家庭组pc之间的关联配置，并为之提供接收服务
echo		2.3 HomeGroup Provider 执行与家庭组的配置和维护相关的任务。
echo		2.4 Computer Browser，浏览局域网上的其他pc，并自动更新局域网中的pc列表
echo		2.5 workstation 使用SMB协议创建并维护客户端网络与远程服务器之间的连接
echo		2.6 Power 电源管理策略,如果你的电脑是台式机或者并没有启用电源管理策略
echo		2.7 Tablet PC Input Service 提供手写板支持和笔触感应功能;
echo			如果你用不到手写板又不是平板电脑，那么可以禁用服务
echo		2.8 BITS,Background Intelligent Transfer Service
echo			使用空闲的网络带宽在后台传输客户端和服务器之间的数据，
echo			主要就是对系统的WindowsUpdate功能提供支持。
echo		2.9 WMPNetworkSvc 提供的Windows Media Player媒体库网络共享功能
echo		2.10 Diagnostic Policy Service(诊断策略服务，简称DPS)服务
echo		2.11 TrkWks Distributed Link Tracking Client客户端分布式链接跟踪服务
echo		2.12 WerSvc，Windows Error Reporting Service
echo		2.13 ShellHWDetection，Shell Hardware Detection，硬件检测服务	
echo			为自动播放的设备或硬件提供通知功能
echo		2.14 WSearch，搜索功能
echo		2.15 Windows Update
echo		2.16 DNS Client DNS解析服务,你的电脑不做DNS服务器的话可以停掉
echo		2.17 Print Spooler 将文件加载到内存中以供稍后打印;
echo		2.18 Portable Device Enumerator Service 
echo			能够使用可移动大容量存储设备传输和同步内容。
echo    	2.19 StiSvc，windows Image Acquisition(Windows图像采集服务)
echo			为扫描仪和照相机提供图像采集服务的。(一般没有启用)
echo		2.20 server 允许计算机通过网络共享文件。
echo 3 上面服务全部设为禁用
echo 4 上面服务全部设为手动
echo 5 上面服务全部设为自动
echo 6 启用上面的服务（net start）
echo 7 查看开放的端口
echo 0 exit
set /p cho=   请输入选择的数字[1,2,3,4,5,0]，然后回车，即可执行相应功能:  
if "%cho%"=="0" goto 0
if "%cho%"=="1" goto 1
if "%cho%"=="2" goto 2
if "%cho%"=="3" goto 3
if "%cho%"=="4" goto 4
if "%cho%"=="5" goto 5
if "%cho%"=="6" goto 6
if "%cho%"=="7" goto 7
goto 0

:1
echo.
cls
@echo off
services.msc
pause
cls
goto menu

:2
echo.
cls
echo ______________________________________________________________________
echo.
:: 以下服务有依赖关系，所以顺序不同时执行效果会有区别
net stop "Offline Files"
net stop "HomeGroup Listener"
net stop "HomeGroup Provider"
net stop "Computer Browser"
net stop Workstation
net stop Power
net stop "Tablet PC Input Service"
net stop BITS
net stop WMPNetworkSvc
net stop DPS
net stop TrkWks
net stop WerSvc
net stop ShellHWDetection
net stop WSearch
net stop "Windows Update"
net stop "DNS Client"
net stop "Print Spooler"
net stop "Portable Device Enumerator Service"
net stop StiSvc
net stop Server
echo ______________________________________________________________________
echo.
pause
cls
goto menu

:3
echo.
cls
@echo off
::以下命令必须使用服务名(不是描述名），=前面没空格，后面需要空格
sc config CscService start= disabled
sc config HomeGroupListener start= disabled
sc config HomeGroupProvider start= disabled
sc config Browser start= disabled
sc config LanmanWorkstation start= disabled
sc config Power start= disabled
sc config TabletInputService start= disabled
sc config BITS start= disabled
sc config WMPNetworkSvc start= disabled
sc config DPS start= disabled
sc config TrkWks start= disabled
sc config WerSvc start= disabled
sc config ShellHWDetection start= disabled
sc config WSearch start= disabled
sc config wuauserv start= disabled
sc config Dnscache start= disabled
sc config Spooler start= demand
sc config WPDBusEnum start= disabled
sc config StiSvc start= disabled
sc config LanmanServer start= disabled
:: 如果要设置为自动，则参数为：auto
pause
cls
goto menu

:4
echo.
cls
@echo off
sc config CscService start= demand
sc config HomeGroupListener start= demand
sc config HomeGroupProvider start= demand
sc config Browser start= demand
sc config LanmanWorkstation start= demand
sc config Power start= demand
sc config TabletInputService start= demand
sc config BITS start= demand
sc config WMPNetworkSvc start= demand
sc config DPS start= demand
sc config TrkWks start= demand
sc config WerSvc start= demand
sc config ShellHWDetection start= demand
sc config WSearch start= demand
sc config wuauserv start= demand
sc config Dnscache start= demand
sc config Spooler start= demand
sc config WPDBusEnum start= demand
sc config StiSvc start= demand
sc config LanmanServer start= demand
pause
goto menu



:5
echo.
cls
@echo off
sc config CscService start= auto
sc config HomeGroupListener start= auto
sc config HomeGroupProvider start= auto
sc config Browser start= auto
sc config LanmanWorkstation start= auto
sc config Power start= auto
sc config TabletInputService start= auto
sc config BITS start= auto
sc config WMPNetworkSvc start= auto
sc config DPS start= auto
sc config TrkWks start= auto
sc config WerSvc start= auto
sc config ShellHWDetection start= auto
sc config WSearch start= auto
sc config wuauserv start= auto
sc config Dnscache start= auto
sc config Spooler start= auto
sc config WPDBusEnum start= auto
sc config StiSvc start= auto
sc config LanmanServer start= auto
pause
goto menu

:6
echo.
cls
@echo off
net start "Offline Files"
net start "HomeGroup Listener"
net start "HomeGroup Provider"
net start "Computer Browser"
net start Workstation
net start Power
net start "Tablet PC Input Service"
net start BITS
net start WMPNetworkSvc
net start DPS
net start TrkWks
net start WerSvc
net start ShellHWDetection
net start WSearch
net start "Windows Update"
net start "DNS Client"
net start "Print Spooler"
net start "Portable Device Enumerator Service"
net start StiSvc
net start Server
pause
goto menu


:7
echo.
cls
@echo off
netstat -ano
pause
goto menu

:0
set cho=
cls
