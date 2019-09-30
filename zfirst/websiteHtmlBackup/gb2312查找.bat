@echo off
echo. >D:\websiteHtmlBackup\filelistWithcontent.txt
color 3a
echo.
echo.
echo                       系统正在查找文件，请耐心等候......
echo.
echo.
for %%a in (F:\Novel) do (
  cd /d %%a\
  for /r . %%b in (*.htm) do (
      if exist "%%b" (
	type "%%b" | findstr /i "charset.gb2312" && echo %%b>>D:\websiteHtmlBackup\filelistWithcontent.txt
      )
  )
)
type D:\websiteHtmlBackup\filelistWithcontent.txt | find /i "\"  && goto no

echo.
echo 文件内容没找到!
del D:\websiteHtmlBackup\filelistWithcontent.txt>nul 2>nul
echo.
pause
exit

:no
cls

echo.
echo.
echo 文件查找完毕并记录在D:\websiteHtmlBackup\filelistWithcontent.txt中 !
echo.
echo.
echo.
echo 是否打开文本查看记录 ?
echo.
echo 选择" Y "查看。   选择" N "退出。
echo.
set /p Choice=Y/N: 
IF /I '%Choice:~0,1%'=='y' goto A
IF /I '%Choice:~0,1%'=='n' goto B
pause
exit

:A
start D:\websiteHtmlBackup\filelistWithcontent.txt
exit
pause
:b
exit

:help
cls
echo.
echo.
echo                               帮  助  文  件
echo.
echo        1. 请输入要查找的内容: 输入你要查找的字符串、数字串或文字词组然
echo.
echo           后等待系统为您查询，找到后系统会生成一个文本文件，记录了含有
echo.
echo           所查找内容文件存放的位置，未找到系统会提示文件内容没找到!
echo.
echo           输入完后回车，程序提示输入第二项：文件扩展名.
echo.
echo        2. 输入查找文件扩展名:  扩展名可以是任何文本类型文件，如：txt、
echo.
echo           log、ini、inf、vbs、bat 等，也可以使用 * 来查找所有类型文件，
echo.
echo           不推荐用 * 查找，遇到系统正在使用的文件或大文件时会查找超慢，
echo.
echo           入完后回车，程序开始查找文件.
echo.
echo.
echo 请按任意键返回选择界面!
echo.
pause
cls
goto fh


:end
exit
 
