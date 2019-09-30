@echo off
cls
rem taskkill /f /t /im 程序名 
rem ntsd -c q -pn 程序名 
rem ntsd -c q -p 进程的PID 

taskkill /f /t /im regedit.exe


set /p cho1= 请复制或输入需要定位的注册表分支的路径,然后回车:

cmd /c reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Applets\Regedit" /v "LastKey" /d "%cho1%" /f&&start regedit.exe