setlocal enabledelayedexpansion
set n=0
dir /b >list.txt
for /f  "usebackq tokens=* delims=" %%A in (list.txt) do (
if not "%%A"=="w.bat" (
if not "%%A"=="list.txt" (
set /a n=n+1
ren %%A !n!.jpg
)
)
)