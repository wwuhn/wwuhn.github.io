@echo off
echo Windows Registry Editor Version 5.00 >temp.reg
echo 在文件夹或驱动器右击菜单中添加菜单命令...
echo [+hkey_local_machine\software\classes\directory\shell] >>temp.reg
echo [-hkey_local_machine\software\classes\directory\shell\重启计算机] >>temp.reg
echo [+hkey_local_machine\software\classes\directory\shell\重启计算机] >>temp.reg
echo [+hkey_local_machine\software\classes\directory\shell\重启计算机\commamnd] >>temp.reg
echo [hkey_local_machine\software\classes\directory\shell\重启计算机\command] >>temp.reg
echo @="c:\windows\rundll.exe user.exe,exit windows exec  %1" >>temp.reg
::echo @="notepad %1" >>temp.reg
echo 在任意类型文件的右击菜单中添加菜单命令...
echo [+hkey_classes_root\*\shell] >>temp.reg
echo [-hkey_classes_root\*\shell\记事本] >>temp.reg
echo [+hkey_classes_root\*\shell\记事本] >>temp.reg
echo [+hkey_classes_root\*\shell\记事本\command] >>temp.reg
echo [hkey_classes_root\*\shell\记事本\command] >>temp.reg
::echo @="cmd.exe /c F:\Website\notes\bat\显示或隐藏文件.bat %1" >>temp.reg
echo @="notepad %1" >>temp.reg
echo.
regedit /s temp.reg
::del /q /f temp.reg >nul