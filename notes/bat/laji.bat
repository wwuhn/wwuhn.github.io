@echo off
echo 准备清理以下文件，按任意键即可开始：
echo.
echo 1  清除系统临时文件夹中的文件！           2  清除当前用户临时文件夹中的文件！
echo 3  清除当前用户所有的cookies记录！        4  清除当前用户最近使用文件记录！
echo 5  当前用户IE临时文件夹中的文件！         6  清除系统盘所有文件夹中的tmp文件！
echo 7  清除系统盘中的.old文件！               8  清除垃圾箱中的文件！
echo.
echo 9  清除系统盘中的gid文件！
echo   “.gid”后缀的文件是全索引文件。Windows有时要创建这样的文件，用这些文件来保存
echo    帮助文件的信息，并且将它们以隐藏文件的形式和帮助文件存储在同一个目录下。
echo.
echo 10  清除系统盘中的CHK文件！
echo     是用户在使用“磁盘碎片整理程序”整理硬盘后所产生的“丢失簇的恢复文件”，
echo     移动存储设备在读取数据的时候遇到断电或被强行拔出,也会产生大量的CHK文件。
 
echo.
echo 11  清除当系统盘windows目录下的.bak文件！
echo     bak是备份文件，保存修改前的内容为bak的备份文件(前提是设置了备份功能)。
echo.

pause
echo.
echo 按任意键开始清除操作



del /f /q %windir%\temp\*.* >nul
echo 成功清除系统临时文件夹中的垃圾文件！
echo.
del /f /s /q %userprofile%\cookies\*.* >nul
echo 成功清除当前用户所有的cookies记录！
echo.
del /f /s /q %userprofile%\recent\*.* >nul
echo 成功清除当前用户最近使用文件记录！
echo.
del /f /s /q %userprofile%\local settings\temp\*.* >nul
echo 成功清除当前用户临时文件夹中的垃圾文件！
echo.
del /f /s /q %userprofile%\local settings\temporary internet files\*.* >nul
echo 成功清除当前用户internet临时文件夹中的垃圾文件！
echo.

del /f /s /q %systemdrive%\*.tmp
del /f /s /q %systemdrive%\*._mp
rd /s /q %windir%\temp & md %windir%\temp
echo 成功清除系统盘所有文件夹中的tmp文件！
echo.
del /f /s /q %systemdrive%\*.gid
echo. 
echo 成功清除了系统盘中的gid文件！
echo “.gid”后缀的文件是全索引文件。
echo Windows有时要创建这样的文件，用这些文件来保存帮助文件的信息，
echo 并且将它们以隐藏文件的形式和帮助文件存储在同一个目录下。
echo.

del /f /s /q %systemdrive%\*.chk
echo 成功清除了系统盘中的gid文件！
echo CHK的文件是用户在使用“磁盘碎片整理程序”整理硬盘后所产生的“丢失簇的恢复文件”，
echo 移动存储设备在读取数据的时候遇到断电或被强行拔出,也会产生大量的CHK文件。
echo.

del /f /s /q %systemdrive%\*.old
echo 成功清除了系统盘中的.old文件！
echo.

del /f /s /q %systemdrive%\recycled\*.*
echo 成功清除了垃圾箱中的文件！
echo.
del /f /s /q %windir%\*.bak
echo 成功清除当系统盘windows目录下的.bak文件！
echo bak是备份文件，保存修改前的内容为bak的备份文件(前提是设置了备份功能)。
echo.
del /f /s /q %windir%\prefetch\*.*
echo 成功清除当前用户internet临时文件夹中的垃圾文件！
echo.

echo 垃圾文件已经清理完毕！