@echo off


echo.
echo   使用命令del /f ...  >nul
echo   %userprofile%\cookies\*.*
echo   %userprofile%\recent\*.* >nul

echo   %userprofile%\local settings\temp\*.*
echo   %userprofile%\local settings\temporary internet files\*.*
set /p cho="请确认是否要清除上面的文件吗？(y/n):"
if "%cho%"=="y" goto y
if "%cho%"=="n" goto n

:y
echo 清理工作正在进行，请稍等...
echo.
del /f /q %windir%\temp\*.* >nul
echo 成功清除系统临时文件夹中的垃圾文件！
echo.
del /f /q %userprofile%\cookies\*.* >nul
echo 成功清除当前用户所有的cookies记录！
echo.
del /f /q %userprofile%\recent\*.* >nul
echo 成功清除当前用户最近使用文件记录！
echo.
del /f /q /s %userprofile%\local settings\temp\*.* >nul
echo 成功清除当前用户临时文件夹中的垃圾文件！
echo.
del /f /q /s %userprofile%\local settings\temporary internet files\*.* >nul
echo 成功清除当前用户internet临时文件夹中的垃圾文件！
echo.
echo 垃圾文件已经清理完毕！

:n
cls
cho=
