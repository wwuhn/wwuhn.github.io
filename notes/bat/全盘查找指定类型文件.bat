@echo off
setlocal enabledelayedexpansion
echo. >c:\virus.txt
color 3a
echo.
set /a n = 0
set /p b=输入查找文件扩展名:
if /i "%b%"=="" cls && goto fh

echo 系统正在查找文件，请耐心等候......
echo.

::for %%a in (F E D C) do (
for %%a in (E) do (
cd /d %%a:\
	for /r %%b in (*.%b%) do (
		if exist "%%b" (
			echo %%b
			echo %%b>>c:\virus.txt
			set /a n+=1
			echo 现查到%b%文件个数：!n!
		)
	)
)
type c:\virus.txt | find /i "\"  && goto no
echo.
echo 文件内容没找到!
del c:\virus.txt>nul 2>nul
echo.
pause
exit

:no
::cls
echo.
echo 文件查找完毕并记录在c:\virus.txt中 !
echo 现查到%b%文件总的个数：!n!
echo.
echo 是否打开文本查看记录 ?
echo.
echo 选择" Y "查看。   选择" N "退出。
echo.
set /p Choice=Y/N: 
IF /I '%Choice:~0,1%'=='y' goto A
IF /I '%Choice:~0,1%'=='n' goto B
pause
exit

:A
start c:\virus.txt
exit
pause
:b
exit

 
