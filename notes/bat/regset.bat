@echo off
cls
rem taskkill /f /t /im 程序名 
rem ntsd -c q -pn 程序名 
rem ntsd -c q -p 进程的PID 

tasklist >list.txt      
find /i "regedit.exe" list.txt      
if "%errorlevel%"=="1" (goto f) else (goto e)                                                                                                             


:e                    
taskkill /f /t /im regedit.exe    
echo HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run >list.txt
clip < list.txt
echo HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run已复制到剪切板
del /q list.txt
echo.
set /p cho1= 请复制或输入需要定位的注册表分支的路径,然后回车:
pause
cmd /c reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Applets\Regedit" /v "LastKey" /d "%cho1%" /f&&start regedit.exe

:f
echo HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run >list.txt
clip < list.txt
echo HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run已复制到剪切板
del /q list.txt
echo.
set /p cho1= 请复制或输入需要定位的注册表分支的路径,然后回车:
pause
cmd /c reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Applets\Regedit" /v "LastKey" /d "%cho1%" /f&&start regedit.exe