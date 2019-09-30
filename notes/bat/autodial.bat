@echo off
echo windows registry editor version 5.00 >temp.reg
echo 正在设置系统启动时自动拨号连接网络...
echo.
echo [hkey_local_machine\software\microsoft\windows\currentversion\run] >>temp.reg
echo "autodial"=rasdial pppoe 404 4048016 >>temp.reg
echo 成功设置系统启动后，宽带自动连接网络！
regedit /s temp.reg
del /q /f temp.reg
<p>用户名是否要加引号？"
rem C:\windows\system32\rasphone.exe -d 宽带连接
::1 让系统保存了宽带连接的用户名和密码
::控制面板→网络和Internet→查看网络状态和任务→设置新的连接或网络→连接到Internet→您如何连接？：选择宽带→输入用户名、密码、宽带连接名称：宽带连接，勾选：记住密码。

::查看建立的连接：控制面板→网络和 Internet网络和共享中心→更改适配器设置：即可查看本地连接宽带连接无线连接。

::2 设置“宽带连接”属性
::状态栏右下角单已有建立的连接的图标→右击”宽带连接"→属性→“选项”选项卡：去掉勾选：提示名称、密码和证书；

::或用win+r→rasphone快捷键。

::3 设置Internet属性
::win+R→inetcpl.cpl，打开“Internet属性“对话框→”连接“选项卡勾选：”始终拨打默认连接“。

::4 开机启动拨号程序
::4.1 使用批处理脚本设置注册表添加自启动项
::新建一个批处理文件，输入以下内容：
::reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run" /v autodial /t REG_SZ /d "%SystemRoot%\system32 \rasphone.exe -d 宽带连接" /f

::c:windowssystem32 asphone.exe是拨号程序的路径。

::-d是指进行宽带连接，最后的“宽带连接”是要自动拨号的宽带连接名。

::脚本运行后，注册HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run下添加一个值项：

::4.2 使用计划任务

::c:\Windows\System32\rasphone.exe -d 宽带连接
