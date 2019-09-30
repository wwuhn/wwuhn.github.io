::假设批处理文件保存在：e:\website下，echo %~dp0会显示：E:\Website\ 
::假设批处理文件保存在：e:\website下，md %~dp0new222会建立文件夹E:\Website\new222
::也可以在后面加"\",新建文件夹和复制文件时都无错，只是在echo %~dp0\aaanew >a.txt,内容是E:\Website\\aaanew
::set path1 = %~dp0 是无效的，因为"="的右边只能是string

md %userprofile%\desktop\witisoPC
copy  %~dp0\witisoPC\* %userprofile%\desktop\witisoPC

for /f "tokens=1,2 usebackq delims=." %%a in (`dir %~dp0\witisoPC /o:d /b`) do (
	if "%%a.%%b"=="%%a." (
		md %userprofile%\desktop\witisoPC\%%a
	)
)
for /f "tokens=1,2 usebackq delims=." %%j in (`dir %~dp0\witisoPC /o:d /b`) do (
	if "%%j.%%k"=="%%j." (
		copy  %~dp0witisoPC\%%j\*.html %userprofile%\desktop\witisoPC\%%j
	)
)

for /f "tokens=1,2 usebackq delims=." %%j in (`dir %~dp0\witisoPC /o:d /b`) do (
	if "%%j"=="zfirst" (
		xcopy /s %~dp0witisoPC\zfirst %userprofile%\desktop\witisoPC\zfirst
	)
	if "%%j"=="css" (
		copy  %~dp0witisoPC\%%j\* %userprofile%\desktop\witisoPC\%%j
	)
	if "%%j"=="js" (
		copy  %~dp0witisoPC\%%j\* %userprofile%\desktop\witisoPC\%%j
	)
)

cd %ProgramFiles%\winrar
%systemdrive%

rar a -r %userprofile%\desktop\witisoPC.rar %userprofile%\desktop\witisoPC\*

rem python F:\Website\witisoPC.py

rem a表示创建压缩文档的命令；
rem -m5是指定最大压缩比率；
rem -s是采用固实压缩；
rem -r是递归压缩文件夹中所有文件；
rem 后面的待压缩的若干文件夹。
rem 如果winrar的安装目录不在环境变量PATH中，则需要写全路径，如："C:\Program Files\WinRar\rar" ......