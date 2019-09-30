@echo off
cls
echo.
echo.
echo -----------------请选择要执行的操作------------------------
echo ----1 输入数字1并按回车键,启动Telnet服务----
echo ----2 输入数字1并按回车键,停止Telnet服务----
echo ----3 输入数字1并按回车键,暂停Telnet服务----
echo ----4 输入数字1并按回车键,恢复Telnet服务----
echo ----5 输入其他字符,直接退出批处理----
echo.
echo.
set /p num=请选择要执行的操作:
if "%num%"=="1"(
echo.
echo.
net start telephony
echo 成功启动Telnet服务......
goto exit
)

if "%num%"=="2"(
echo.
echo.
net stop task schedule
echo 成功停止Telnet服务......
goto exit
)

if "%num%"=="3"(
echo.
echo.
task schedule  pause
echo 成功暂停Telnet服务......
goto exit
)

if "%num%"=="4"(
echo.
echo.
task schedule  continue
echo 成功恢复被暂停Telnet服务......
goto exit
)
echo.
echo.
echo 你输入了%num%字符,批处理自动退出......
:exit
