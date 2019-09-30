@echo off
setlocal
rem 以下默认是按文件名排序的；/b是指只显示文件名；

set listfile=%userprofile%\desktop\listlist1.txt


k:
echo K:\tutorial >%listfile%
dir /a:d /b /o:N >>%listfile%
dir /a:-d /b /o:N >>%listfile%


l:

echo l:\software video >>%listfile%
dir /a:d /b /o:N >>%listfile%
dir /a:-d /b /o:N >>%listfile%

M:

echo M:\movie >>%listfile%
dir /a:d /b /o:N >>%listfile%
dir /a:-d /b /o:N >>%listfile%

N:

echo N:\sys gho >>%listfile%
dir /a:d /b /o:N >>%listfile%
dir /a:-d /b /o:N >>%listfile%

o:

echo o:\tutorial overall >>%listfile%
dir /a:d /b /o:N >>%listfile%
dir /a:-d /b /o:N >>%listfile%

p:

echo p:\tutorial en >>%listfile%
dir /a:d /b /o:N >>%listfile%
dir /a:-d /b /o:N >>%listfile%

q:

echo q:\综艺 娱乐 棋牌 >>%listfile%
dir /a:d /b /o:N >>%listfile%
dir /a:-d /b /o:N >>%listfile%

r:

echo r:\人物 励志 讲座 谈话 创业 职场 >>%listfile%
dir /a:d /b /o:N >>%listfile%
dir /a:-d /b /o:N >>%listfile%

s:

echo s:\backup >>%listfile%
dir /a:d /b /o:N >>%listfile%
dir /a:-d /b /o:N >>%listfile%

t:

echo t:\wwuhn >>%listfile%
dir /a:d /b /o:N >>%listfile%
dir /a:-d /b /o:N >>%listfile%