@echo off
cd /d %userprofile%\desktop\

echo 正在创建1.txt~3.txt共3个文件...
echo.
echo.

for /L %%n in (1,1,3) do (  echo. >%%n.txt 
)
rem:in后应有空格
echo 文件创建完毕！