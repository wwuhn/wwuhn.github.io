setlocal enabledelayedexpansion
set n=0
for /f "tokens=* usebackq delims=." %%A in (`dir ..\ /o:d /b`) do (
	if not "%%A"=="zzzbat r" (
		set /a n=n+1
		ren "..\%%A" "!n!"
	)
)

rem 延迟变量n,且必须由"!"引导,如果不延迟,则n永远是0;