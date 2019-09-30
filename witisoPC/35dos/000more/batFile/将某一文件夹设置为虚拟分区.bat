@echo off
echo.
:menu

echo [1] 将某一文件夹设置为虚拟分区
echo [2] 删除虚拟分区
echo [0] 退出
echo.

set /p choice= please input number,then press enter: 
if "%choice%"=="1" goto 1
if "%choice%"=="2" goto 2
if "%choice%"=="0" goto 0

goto 0
:1
echo.
cls
if not exist d:\a md d:\a
subst a: d:\a
goto menu

:2
echo.
cls
subst a: /del
goto menu

:0