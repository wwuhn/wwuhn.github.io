setlocal enabledelayedexpansion
set n=0
for /f "tokens=1,2 usebackq delims=." %%A in (`dir ..\ /o:d /b`) do (
	if not "%%A"=="zzzbat r" (
	if  "%%A.%%B"=="%%A." (
     		set /a n=n+1
		if !n! lss 10 (
			ren "../%%A" "0!n!"
		) else (
			ren "../%%A" "!n!"
		)
	)
	)
)
rem 延迟变量n,且必须由"!"引导,如果不延迟,则n永远是0;


