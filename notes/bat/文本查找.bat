@echo off
echo. >c:\virus.txt
color 3a
echo.
echo  作者：【北极长老】 2013.3.7 windowsXP
:fh
echo.
echo  本程序可以为您全盘查找含有特定内容的文件的位置
echo.
@echo  ╔┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉╗
@echo  ┋                                              ┋
@echo  ┋  1. 阅读帮助文件                             ┋
@echo  ┋                                              ┋
@echo  ┋  2. 运行文件查找                             ┋
@echo  ┋                                              ┋
@echo  ┋  3. 退出                                     ┋
@echo  ┋                                              ┋
@echo  ╚┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉╝
echo.
echo  选择对应项1、2、3或直接回车进入第二项进行查询!
echo.
:Choice2
set choice2=
set /p choice2= 请选择:
IF NOT "%Choice2%"=="" SET Choice2=%Choice2:~0,1%
if /i "%choice2%"=="1" goto help
if /i "%choice2%"=="2" goto run
if /i "%choice2%"=="3" goto end

:run
echo.
echo.
set /p a=请输入要查找的内容:
if /i "%a%"=="" cls && goto fh

echo.
set /p b=输入查找文件扩展名:
if /i "%b%"=="" cls && goto fh

echo.
echo.
echo.
echo.
echo                       系统正在查找文件，请耐心等候......
echo.
echo.
for %%a in (C D E F) do (
  cd /d %%a:\
::for %%a in (F:\website) do (
::cd /d %%a\
  for /r . %%b in (*.%b%) do ( rem 第一个.点表示查找cd转到的当前目录,\r的选项会递归遍历子目录
      if exist "%%b" (
	type "%%b" | find /i "%a%" && echo %%b>>c:\virus.txt rem 如果不是绝对路径，则保存到cd转到的目录下
      )
  )
)
type c:\virus.txt | find /i "\"  && goto no

echo.
echo 文件内容没找到!
del c:\virus.txt>nul 2>nul
echo.
pause
exit

:no
cls
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo                       文件查找完毕并记录在c:\virus.txt中 !
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
start c:\virus.txt
exit
pause
:b
exit

:help
cls
echo.
echo                               帮  助  文  件
echo.
echo        1. 请输入要查找的内容: 输入你要查找的字符串、数字串或文字词组。
echo           输入完后回车，程序提示输入第二项：文件扩展名.
echo.
echo        2. 输入查找文件扩展名:  扩展名可以是任何文本类型文件，如：txt、
echo           log、ini、inf、vbs、bat 等，也可以使用 * 来查找所有类型文件，
echo           不推荐用 * 查找，遇到系统正在使用的文件或大文件时会查找超慢，
echo           入完后回车，程序开始查找文件.
echo.
echo        3. 然后等待系统为您查询，找到后系统会生成一个文本文件，记录了含有
echo           所查找内容文件存放的位置，未找到系统会提示文件内容没找到!
echo.
echo        3. 注意事项：
echo           默认是全盘C D E F查找某种类型的文件，速度会非常慢，建议具体到
echo           某一路径查找，速度会快一些，如果是具体路径，后面的cd后的:要去掉
echo.
echo        4. findstr可以使用通配符，如.代表任意字符。
echo	       type "%%b" | findstr /i "charset.gb2312" && echo %%b>>D:\content.txt
echo           find要查找的内容放在""内，如果要查找""，可以使用""""
echo.
echo        请按任意键返回选择界面!
echo.
pause
cls
goto fh


:end
exit
 
