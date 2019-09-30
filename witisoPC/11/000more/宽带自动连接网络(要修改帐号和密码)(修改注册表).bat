@echo off
echo windows registry editor version 5.00 >temp.reg
echo 正在设置系统启动时自动拨号连接网络...
echo.
echo [hkey_local_machine\software\microsoft\windows\currentversion\run] >>temp.reg
echo "autodial"=rasdial pppoe accountname password >>temp.reg
echo 成功设置系统启动后，宽带自动连接网络！
regedit /s temp.reg
del /q /f temp.reg
