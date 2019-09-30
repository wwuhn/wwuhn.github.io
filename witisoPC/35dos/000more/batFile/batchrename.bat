@echo off
echo 开始更改文件名...
set ext=.rar
set /a sum=0
for %%m in (*)do (
if not "%%m"=="batchrename.bat"(
ren %%m %%m%ext%
set /a sum=sum+1
)
)
echo 文件改名完成，一共有%sum%个文件被改名！
set sum=
set ext=