cls
@echo off
set /p cho1= 请输入需要建立的文件夹所在的盘符（如g）,然后回车:
set cho=%cho1%:
%cho%
md %cho%\%USERNAME%\desktop
md %cho%\%USERNAME%\favorite
md %cho%\%USERNAME%\documents
md %cho%\%USERNAME%\quickLaunch
md %cho%\%USERNAME%\desktoppaper