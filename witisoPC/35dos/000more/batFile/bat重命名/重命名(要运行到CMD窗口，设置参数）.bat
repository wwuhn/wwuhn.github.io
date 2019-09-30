@echo off
if not exist %1 (
echo 命令用法如下：
echo %0 filename
echo filename :表示需要修改的文件名
echo.
echo.
goto end
)
set extension=%~x1
for /f "tokens=1-3 delims=/-" %%A in ('date /T') do set date=%%A%%B%%C
ren %1 %date%%extension%
echo.
echo 文件%1已经被成功更名为%date%%extension%
set extension=
set date=
:end