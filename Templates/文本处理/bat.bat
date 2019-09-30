@ echo off
::echo %~dp0
::set /p var= 请输入路径：
::echo %var%
::set a=%var:~1,-1%
::echo %a%
set file="proceTxt.py"
set path=%~dp0%file%
echo %path%
python F:\Website\Templates\文本处理\proceTxt.py
pause