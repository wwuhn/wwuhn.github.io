setlocal enabledelayedexpansion
set n=0
rem 取得路径包括了最后一个斜线\
set tempPath=%~dp0

rem 把路径中的最后一个斜线去掉
set tempPath=!tempPath:~,-1!
echo %tempPath%
for %%a in ("!tempPath!") do (

set dirName=%%~na

)

for /f "tokens=1,2 usebackq delims=." %%A in (`dir /o:n /b`) do (
	if not "%%~nA"=="%~n0"  (  rem 不更改bat文件的名称；
	if not "%%B"=="html" ( rem 不更改html文件的名称；
	if not "%%A.%%B"=="%%A." ( rem 不更改文件夹的名称；

		set /a n=n+1

		if !n! lss 10 (
			ren "%%A.%%B" "!dirName!0!n!.%%B"
		) else (
			ren "%%A.%%B" "!dirName!!n!.%%B"
		)

	)
	)
	)
)


::图片批量重命名的时候，可能会想到用acdsee7.0以上的版本来实现。
::打开文件夹，全选图片文件，然后按着ctrl键不放，在第一个图片上右健单击重命名，就批量改成了list(1).jpg、list(2).jpg、list(3).jpg这样。

::set /p name=""		"="前后不能有空格；
::) else (		"else"前后必须有空格；
:: if !n! lss 10 ( 此处符号必须是"!"，而不是"%";





