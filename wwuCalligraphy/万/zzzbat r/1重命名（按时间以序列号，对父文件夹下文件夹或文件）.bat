setlocal enabledelayedexpansion
set n=0
for /f "tokens=1 usebackq delims=." %%A in (`dir ..\ /o:d /b`) do (
if not "%%A"=="zzzbat" (

set /a n=n+1
ren "..\%%A" "!n!"
)
)
