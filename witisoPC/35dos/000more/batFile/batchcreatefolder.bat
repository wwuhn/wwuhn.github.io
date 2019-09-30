@echo off
cd c:\user\wwu\desktop\
cd c:
echo 正在创建file0.txt~file9.txt共10个文件...
echo.
echo.
for /l %%n in (1,1,26) do ( md %%n
)
echo 文件创建完毕！