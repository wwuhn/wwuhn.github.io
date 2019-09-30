@echo off
mode con lines=25
title time shutdown
color if
cls

echo.
echo.
echo.
echo.
echo    使用时间使用24小时制，可入输入多个时间点，
echo        多个时间点用空格分开
echo.
echo.
echo------------------------------------------------
echo.
set times=
set /p times=             请输入关机时间：
if not "%times%"=="" for %%i in (%times%) do ( at %%i /every:M,t,w,th,f,s,su shutdown -s)
