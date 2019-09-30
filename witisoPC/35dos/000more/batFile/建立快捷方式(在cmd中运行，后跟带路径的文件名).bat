@echo off
if "%1"=="" (
echo 该批处理文件的正确用法如下：
echo %0 filename
echo 参数filename表示要创建快捷方式的文件
echo.
echo 批处理无法创建快捷方式。因为没有指定文件
goto end
)
echo 正在为指定的文件创建快捷方式...
set shortcutname=%~n1.url
echo [InternetShortcut] >%shortcutname%
echo URL=%~f1 >>%shortcutname%
echo IconIndex=1 >>%shortcutname%
echo IconFile=%windir%\system32\shell32.dll >>%shortcutname%
copy %shortcutname% "%userprofile%\desktop" >nul
echo.
echo 成功创建%1的快捷方式%shortcutname%,该快捷方式已经发送到桌面！
set shortcutname=
:end