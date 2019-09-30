@echo off
cd c:\user\wwu\desktop\
cd c:
echo 正在创建file0.txt~file9.txt共10个文件...
echo.
echo.
for /l %%n in (1,1,3) do ( rem:in后应有空格 echo >>%%n.txt
)
echo 文件创建完毕！