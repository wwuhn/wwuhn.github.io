@echo off
:repeate
cls
echo.
echo.
echo ------请选择要执行的操作---
echo ---1 输入数字1并按回车，则显示当前日期---
echo ---2 输入数字2并按回车，则显示当前时间---
echo ---3 输入数字3并按回车，则显示文件列表---
echo ---4 输入数字4并按回车，则终止批处理---
echo.
echo.
echo 请选择要执行的操作：
set /p num=
if "%num%"=="1" (
cls
echo.
echo.
echo 当前日期为：
date /t
pause
goto repeate
)
if "%num%"=="2" (
cls
echo.
echo.
echo 当前时间为：
time /t
pause
goto repeate
)
if "%num%"=="3" (
cls
echo.
echo.
echo 当前目录下的内容为：
dir /w
pause
goto repeate
)
echo.
echo.
echo 你输入了%num%字符，批处理自动退出。
