@echo off
echo.
:menu
cls
echo 选择菜单：
echo.

echo   1  没有空行的文本处理
echo   2  有空行的文本处理
echo   0  exit 退出此批处理
echo.     __________________________________________________________________________
echo.    
set /p cho=  输入选项的数字，然后回车:  

if "%cho%"=="1" goto 1
if "%cho%"=="2" goto 2


if "%cho%"=="0" goto 0

goto 0
:1
echo.
python F:\Website\Templates\000txt\new.py
goto menu

:2
echo.
python F:\Website\Templates\000txt\newnn.py
pause
goto menu

:0
set time=
set cho=
cls