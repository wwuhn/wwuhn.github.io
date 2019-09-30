@echo off
echo.
setlocal enabledelayedexpansion   rem启用批处理变量延时扩充功能。当批处理中使用该功能后，可以使用"!"批处理执行时扩充变量
cd. >a_new.txt
echo 正在替换文件中的字符串，请稍候...
echo.
for /f %%a in (a.txt) do (
set str=%%a
set str=!str:利润=利益! ::两个"!"之间的"str"使用了变量延时功能；
echo !str! >>a_new.txt ::两个"!"之间的"str"使用了变量延时功能；
)
ren a.txt a_old.txt
ren a_new.txt a.txt
echo 成功替换文件中指定的字符串，profit_old.txt文件为未修改前的profit.txt文件！
set str=