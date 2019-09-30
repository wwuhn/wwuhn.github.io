@echo off
echo.
:menu
cls
echo 选择菜单：
echo.

echo   1  没有空行的中文文本处理（cn(合并空字符),段落正常）
echo   2  有空行的中文文本处理（cn(合并空字符),空行做段落，不是空行的段落合并）
echo   3  没有空行的英文文本处理（en(不合并空字符),段落正常）
echo   4  有空行的英文文本处理（en(不合并空字符),空行做段落，不是空行的段落合并）
echo   0  exit 退出此批处理
echo.     __________________________________________________________________________
echo.    
set /p cho=  输入选项的数字，然后回车:  

if "%cho%"=="1" goto 1
if "%cho%"=="2" goto 2
if "%cho%"=="3" goto 3
if "%cho%"=="4" goto 4

if "%cho%"=="0" goto 0

goto 0
:1
echo.
python F:\Website\Templates\000txt\new.py
pause
goto menu

:2
echo.
python F:\Website\Templates\000txt\newnn.py
pause
goto menu

:3
echo.
python F:\Website\Templates\000txt\newen.py
pause
goto menu

:4
echo.
python F:\Website\Templates\000txt\newnnen.py
pause
goto menu

:0
set time=
set cho=
cls