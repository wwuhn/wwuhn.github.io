@echo off
setlocal enabledelayedexpansion
echo MB=filepath >c:\bigfiles.xls
color 3a
echo.
::for %%a in (F E D C) do (
for %%a in (F) do (
cd /d %%a:\
	for /r %%i in (*.*) do (
		set /a size = %%~zi
		if !size! GTR 1024000000 (
			set /a sizem = !size!/1024000
			set /a n+=1
			echo 1G以上文件!n! !sizem! MB：%%i
			echo !sizem!=%%i >>c:\bigfiles.xls
		) else if !size! GTR 536870912 (
			set /a sizem = !size!/1024000
			set /a b+=1
			echo 500M-1G文件!b! !sizem! MB：%%i
			echo !sizem!=%%i >>c:\bigfiles.xls
		) else if !size! GTR 102400000 (
			set /a sizem = !size!/1024000
			set /a c+=1
			echo 100-500M文件!c! !sizem! MB：%%i
			echo !sizem!=%%i >>c:\bigfiles.xls
		)

	)
)

type c:\bigfiles.xls | find /i "\"  && goto detail
echo.
echo 文件内容没找到!
del c:\virus.txt>nul 2>nul
echo.
pause
exit

:detail
::cls
echo.
echo 文件查找完毕并记录在c:\bigfiles.xls中 !
echo 1G以上文件：!n!
echo 500M-1G文件：!b!
echo 100-500M文件：!c!
start c:\bigfiles.xls

pause


 
