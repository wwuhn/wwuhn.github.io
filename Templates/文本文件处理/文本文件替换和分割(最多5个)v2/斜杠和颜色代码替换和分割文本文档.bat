setlocal=enabledelayedexpansion
if exist all.txt del all.txt
for /f "tokens=1,2,3 usebackq delims=/-" %%a in (a.txt) do (	

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


for /l %%n in ( 1,1,10) do if exist %%n.txt del %%n.txt
	for /f "tokens=* delims= " %%a in (all.txt) do (
		if NOT "%%a" == "2//" ( 
		echo %%a >>1.txt 
		) else goto second	
	)

:second
set /p n2= 请输入第2个文本开始的行数：
	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (
		if NOT "%%a" == "3//" ( 
		echo %%a >>2.txt 
		) else goto third	
	)
)

:third
set /p n2= 请输入第3个文本开始的行数：
	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (
		if NOT "%%a" == "4//" ( 
		echo %%a >>3.txt 
		) else  goto four
	)
)

:four
set /p n2= 请输入第4个文本文档开始的行数：
	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (
		if NOT "%%a" == "5//" ( 
		echo %%a >>4.txt 
		) else   goto five
	)
)

:five
set /p n2= 请输入第5个文本文档开始的行数：
	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (

		if NOT "%%a" == "6//" ( 
		echo %%a >>5.txt 
		) else  exit	
	)
)