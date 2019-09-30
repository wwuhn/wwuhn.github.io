@echo off
if "%1"=="" (
echo 命令用法：%0 filename
echo filename表示要插入内容的文件
echo.
echo 未指定要插入内容的文件，无法执行插入操作
echo.
goto end
)
if not exist %1 (
echo.
echo 指定要插入内容的文件%1不存在，请仔细检查
goto end
)
echo 正在进行插入操作...
echo.
cd.>content.txt
echo "本月利润表统计" >>content.txt
copy content.txt+%1 temp.txt >nul
del /f /q %1 >nul
del /f /q content.txt >nul
ren temp.txt %1
echo 成功在%1文件前面插入指定内容
:end