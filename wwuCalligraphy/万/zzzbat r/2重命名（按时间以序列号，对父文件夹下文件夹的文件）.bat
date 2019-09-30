setlocal enabledelayedexpansion


for /f "tokens=1 usebackq delims=." %%C in (`dir ..\  /o:d /b`) do (
set n=0
if not "%%C"=="zzzbat" (
for /f "tokens=1,2 usebackq delims=." %%A in (`dir ..\%%C /o:d /b`) do (

set /a n=n+1
ren "..\%%C\%%A.%%B" "!n!.%%B"

)
))