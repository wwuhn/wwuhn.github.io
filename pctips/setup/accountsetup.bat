@echo off
cls
set /p name1= 现在开始建立管理员帐户，请输入帐户名,然后回车:
set /p pw1= 请输入帐户密码,然后回车:

net user %name1% %pw% /add
net localgroup administrators %name1% /add
