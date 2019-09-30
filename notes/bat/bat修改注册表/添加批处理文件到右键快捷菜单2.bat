@echo off
echo Windows Registry Editor Version 5.00 >temp.reg
echo 在文件夹或驱动器右击菜单中添加菜单命令...
echo [-hkey_local_machine\software\classes\directory\shell\显示或隐藏文件] >>temp.reg
echo [+hkey_local_machine\software\classes\directory\shell\显示或隐藏文件] >>temp.reg
echo [+hkey_local_machine\software\classes\directory\shell\显示或隐藏文件\commamnd] >>temp.reg
echo [hkey_local_machine\software\classes\directory\shell\显示或隐藏文件\commamnd] >>temp.reg
echo @="cmd.exe /c F:\\Website\\notes\\bat\\显示或隐藏文件.bat %1" >>temp.reg


echo.
regedit /s temp.reg
::del /q /f temp.reg >nul