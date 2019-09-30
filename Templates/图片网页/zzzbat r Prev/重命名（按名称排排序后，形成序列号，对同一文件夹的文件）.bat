setlocal enabledelayedexpansion
set n=0
for /f "tokens=1,2 usebackq delims=." %%A in (`dir /o:d /b`) do (
	if not "%%B"=="bat" (  rem 不更改bat文件的名称；
	if not "%%B"=="html" ( rem 不更改html文件的名称；
	if not "%%A.%%B"=="%%A" ( rem 不更改文件夹的名称；
		set /a n=n+1
		if n leq 9 (
		ren "%%A.%%B" " "0!n!.%%B"
		)
	)
	)
	)
)