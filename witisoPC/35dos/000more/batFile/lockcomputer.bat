@echo off
rem 锁定计算机，只有用户输入正确的密码才可以重新登录
echo 正在锁定计算机...
rundll32.exe user32.dll,LockWorkStation ::调用了user32.dll动态库中的"LockWorkStation"函数用于锁定当前计算机。需要注意的是，函数名是区分大小写。