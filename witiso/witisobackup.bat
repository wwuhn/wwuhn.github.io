md %userprofile%\desktop\witiso

set path1 = R:\wwuhn\website\witiso
copy  R:\wwuhn\website\witiso\* %userprofile%\desktop\witiso


for /f "tokens=1,2 usebackq delims=." %%a in (`dir R:\wwuhn\website\witiso /o:d /b`) do (
	if "%%a.%%b"=="%%a." (
		md %userprofile%\desktop\witiso\%%a
	)

)
for /f "tokens=1,2 usebackq delims=." %%j in (`dir R:\wwuhn\website\witiso /o:d /b`) do (
	if "%%j.%%k"=="%%j." (
		copy  R:\wwuhn\website\witiso\%%j\*.html %userprofile%\desktop\witiso\%%j
	)

)

for /f "tokens=1,2 usebackq delims=." %%j in (`dir R:\wwuhn\website\witiso /o:d /b`) do (
	if "%%j"=="img" (
		copy  R:\wwuhn\website\witiso\%%j\* %userprofile%\desktop\witiso\%%j
	)
	if "%%j"=="css" (
		copy  R:\wwuhn\website\witiso\%%j\* %userprofile%\desktop\witiso\%%j
	)
	if "%%j"=="js" (
		copy  R:\wwuhn\website\witiso\%%j\* %userprofile%\desktop\witiso\%%j
	)


)



cd %ProgramFiles%\winrar
%systemdrive%

rar a -r %userprofile%\desktop\witiso.rar %userprofile%\desktop\witiso\*


rem a表示创建压缩文档的命令；
rem -m5是指定最大压缩比率；
rem -s是采用固实压缩；
rem -r是递归压缩文件夹中所有文件；
rem 后面的待压缩的若干文件夹。
rem 如果winrar的安装目录不在环境变量PATH中，则需要写全路径，如："C:\Program Files\WinRar\rar" ......