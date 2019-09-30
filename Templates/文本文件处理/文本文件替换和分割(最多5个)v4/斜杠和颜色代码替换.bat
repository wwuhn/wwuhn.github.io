setlocal enabledelayedexpansion
if exist all.txt del all.txt
if exist tmp.txt del tmp.txt
for /f "tokens=1,2,3 usebackq delims=/" %%a in (a.txt) do (
	if "%%b"=="B-RED" (echo %%a/27/%%c>>tmp.txt
	) else echo %%a/%%b/%%c>>tmp.txt
)
for /f "tokens=1,2,3 usebackq delims=/-" %%a in (tmp.txt) do (	

	       if "%%b"=="01" (echo %%a/BLK/%%c>>all.txt
	) else if "%%b"=="02" (echo %%a/WHI/%%c>>all.txt
	) else if "%%b"=="03" (echo %%a/COF/%%c>>all.txt
	) else if "%%b"=="04" (echo %%a/BRO/%%c>>all.txt
	) else if "%%b"=="05" (echo %%a/CRE/%%c>>all.txt
	) else if "%%b"=="06" (echo %%a/noSuchColor/%%c>>all.txt
	) else if "%%b"=="07" (echo %%a/noSuchColor/%%c>>all.txt
	) else if "%%b"=="08" (echo %%a/RED/%%c>>all.txt
	) else if "%%b"=="09" (echo %%a/BLU/%%c>>all.txt
	) else if "%%b"=="10" (echo %%a/YEL/%%c>>all.txt
	) else if "%%b"=="11" (echo %%a/BRE/%%c>>all.txt
	) else if "%%b"=="12" (echo %%a/noSuchColor/%%c>>all.txt
	) else if "%%b"=="13" (echo %%a/SIL/%%c>>all.txt
	) else if "%%b"=="14" (echo %%a/GOL/%%c>>all.txt
	) else if "%%b"=="15" (echo %%a/ORA/%%c>>all.txt
	) else if "%%b"=="16" (echo %%a/APR/%%c>>all.txt
	) else if "%%b"=="17" (echo %%a/noSuchColor/%%c>>all.txt
	) else if "%%b"=="18" (echo %%a/GREY/%%c>>all.txt
	) else if "%%b"=="19" (echo %%a/noSuchColor/%%c>>all.txt
	) else if "%%b"=="20" (echo %%a/PUR/%%c>>all.txt
	) else if "%%b"=="21" (echo %%a/PIN/%%c>>all.txt
	) else if "%%b"=="22" (echo %%a/noSuchColor/%%c>>all.txt
	) else if "%%b"=="23" (echo %%a/noSuchColor/%%c>>all.txt
	) else if "%%b"=="24" (echo %%a/BRON/%%c>>all.txt
	) else if "%%b"=="25" (echo %%a/KKI/%%c>>all.txt
	) else if "%%b"=="26" (echo %%a/CAM/%%c>>all.txt
	) else if "%%b"=="27" (echo %%a/B-RED/%%c>>all.txt
	) else if "%%b"=="28" (echo %%a/noSuchColor/%%c>>all.txt
	) else (
	echo %%a/%%b/%%c>>all.txt
	)
)
del tmp.txt


