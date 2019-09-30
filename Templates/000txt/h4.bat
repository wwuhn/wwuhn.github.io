cd F:\Website\Templates\000txt
f:
python F:\Website\Templates\000txt\h4.py

::PowerShell -Command "& {get-content original.txt -encoding ascii | set-content original2.txt -encoding utf8}"
::Unknown→utf8是乱码；
::ascii→utf8是乱码；
::python F:\Website\Templates\000txt\blankProcess.py

:: 第一行的文件名不能包含特殊符号，如+?等；
:: 可以把第一个文件内的内容写成函数的形式，被第二个文件import;
:: pause

