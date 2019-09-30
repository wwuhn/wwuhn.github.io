@echo off
echo.
echo 从当前盘符切换到c:\program files目录下...
pushd c:\windows
echo c:\program files 目录中包含以下文件夹
dir /ad /b
echo.
echo 返回到批处理运行时所在的盘符及路径
popd

::pushd c:就是记录下c：盘当你转去E:盘后用popd就可以转回c盘 