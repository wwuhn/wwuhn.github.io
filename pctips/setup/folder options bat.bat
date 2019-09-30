@echo off
color 5F
mode con cols=100 lines=35
:0
echo.                               ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
echo.                  ╭︿︿︿╮     ▓                                      　▓     ╭︿︿︿╮
echo.                  {/ ︿︿ \}     ▓                                      　▓     {/ ︿︿ \}
echo.                   ( (oo) )      ▓             程序制作:ＰＣＢＵＧ          ▓      ( (oo) ) 
echo.                    ︶︶︶       ▓                                        ▓       ︶︶︶
echo.                               ▓                                        ▓
echo.                               ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
echo.
echo.                                              ╭︿︿︿╮ 　
echo.                                              {/ ︿︿ \}　 
echo.                                               ( (oo) ) 　 
echo.                                                ︶︶︶ 
echo. 
echo    [1] 显示文件扩展名
echo.
echo    [2] 隐藏文件扩展名
echo.
echo    ***************************************************** 
echo    [3] 隐藏带隐藏属性的文件夹
echo.  
echo    [4] 强制彻底隐藏所有带隐藏属性的文件夹
echo.
echo.       第4项说明:运行后，在"文件夹选项"设置显示隐藏文件均无效，可重新运行3、5、6任意一项取消强制隐藏
echo    *****************************************************
echo.
echo    [5] 显示带隐藏属性的文件夹，不显示系统隐藏文件
echo.
echo    [6] 显示隐藏文件夹跟系统隐藏文件
echo.
echo. [7] 退出 
echo. 
echo.    以上操作完成后请刷新已打开的盘符和文件夹窗口即时生效
echo. 
SET Choice=默认1
SET /P Choice=选择[1],[2],[3],[4],[5],[6],[7]继续（直接回车默认选择 1）
IF /I '%Choice%'=='1' goto 01
IF /I '%Choice%'=='2' goto 02
IF /I '%Choice%'=='3' goto 03
IF /I '%Choice%'=='4' goto 04
IF /I '%Choice%'=='5' goto 05
IF /I '%Choice%'=='6' goto 06
IF /I '%Choice%'=='7' goto 退出
if /i '%choice%'=='默认1' goto 01

rem echo %choice%
echo.
echo 无效选择。请重新选择
echo.
goto 0

:01
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v HideFileExt /t REG_DWORD /d "0" /f
echo.                              已对系统设置显示文件扩展名
echo.                    操作完成后请刷新已打开的盘符和文件夹窗口即时生效。
echo.                              批处理将自动回滚到主菜单
echo. & pause
SET Choice=默认0
if /i '%choice%'=='默认0' goto 0

:02
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v HideFileExt /t REG_DWORD /d "1" /f
echo.                              已对系统设置隐藏文件扩展名
echo.                    操作完成后请刷新已打开的盘符和文件夹窗口即时生效。
echo.                              批处理将自动回滚到主菜单
echo. & pause
SET Choice=默认0
if /i '%choice%'=='默认0' goto 0

:03
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v Hidden /t REG_DWORD /d "0" /f
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v ShowSuperHidden /t REG_DWORD /d "0" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\NOHIDDEN" /f /v CheckedValue /t REG_DWORD /d "2" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\SHOWALL" /f /v CheckedValue /t REG_DWORD /d "1" /f
echo.                  隐藏带隐藏属性的文件操作完成 刷新已打开的盘符和文件夹窗口即时生效                             
echo.
echo [1] 退出
echo.
echo [2] 返回主菜单进行其它选项操作
echo.
:A
SET Choice=默认1
SET /P Choice=选择[1],[2]继续（直接回车默认选择１）
IF /I '%Choice%'=='1' goto 退出
IF /I '%Choice%'=='2' goto 0
if /i '%choice%'=='默认1' goto 1

rem echo %choice%
echo.
echo 无效选择。请重新选择
echo.
goto A
exit

:04
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v Hidden /t REG_DWORD /d "0" /f
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v ShowSuperHidden /t REG_DWORD /d "0" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\NOHIDDEN" /f /v CheckedValue /t REG_DWORD /d "2" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\SHOWALL" /f /v CheckedValue /t REG_DWORD /d "0" /f
echo.                           已成功强制隐藏所有带隐藏属性的文件和文件夹
echo.     （运行后，在"文件夹选项"设置显示隐藏文件均无效，可重新运行3、5、6任意一项取消强制隐藏）
echo.                              刷新已打开的盘符和文件夹窗口即时生效
echo.                               
echo.
echo [1] 退出
echo.
echo [2] 返回主菜单进行其它选项操作
echo.
:B
SET Choice=默认1
SET /P Choice=选择[1],[2]继续（直接回车默认选择１）
IF /I '%Choice%'=='1' goto 退出
IF /I '%Choice%'=='2' goto 0
if /i '%choice%'=='默认1' goto 1

rem echo %choice%
echo.
echo 无效选择。请重新选择
echo.
goto B
exit

:05
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v Hidden /t REG_DWORD /d "1" /f
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v ShowSuperHidden /t REG_DWORD /d "0" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\NOHIDDEN" /f /v CheckedValue /t REG_DWORD /d "2" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\SHOWALL" /f /v CheckedValue /t REG_DWORD /d "1" /f
echo.                 显示带隐藏属性的文件夹，不显示系统隐藏文件操作完成
echo.                        刷新已打开的盘符和文件夹窗口即时生效
echo.
echo [1] 退出
echo.
echo [2] 返回主菜单进行其它选项操作
echo.
:C
SET Choice=默认1
SET /P Choice=选择[1],[2]继续（直接回车默认选择１）
IF /I '%Choice%'=='1' goto 退出
IF /I '%Choice%'=='2' goto 0
if /i '%choice%'=='默认1' goto 1

rem echo %choice%
echo.
echo 无效选择。请重新选择
echo.
goto C
exit

:06
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v Hidden /t REG_DWORD /d "1" /f
reg add "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /f /v ShowSuperHidden /t REG_DWORD /d "1" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\NOHIDDEN" /f /v CheckedValue /t REG_DWORD /d "2" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\Hidden\SHOWALL" /f /v CheckedValue /t REG_DWORD /d "1" /f
echo.                    显示隐藏文件夹跟系统隐藏文件操作完成 刷新已打开的盘符和文件夹窗口即时生效
echo.
echo.
echo [1] 退出
echo.
echo [2] 返回主菜单进行其它选项操作
echo.
:D
SET Choice=默认1
SET /P Choice=选择[1],[2]继续（直接回车默认选择１）
IF /I '%Choice%'=='1' goto 退出
IF /I '%Choice%'=='2' goto 0
if /i '%choice%'=='默认1' goto 1

rem echo %choice%
echo.
echo 无效选择。请重新选择
echo.
goto D
exit

:退出
exit 