for /l %%n in ( 1,1,10) do if exist %%n.txt del %%n.txt
	for /f "tokens=* delims= " %%a in (all.txt) do (
		if NOT "%%a" == "2//" ( 
		echo %%a >>1.txt
		set /a m=m+1
		) else goto second	
	)

:second
	set /a m=m+1
	for /f "tokens=* skip=%m%" %%a in (all.txt) do (
		if NOT "%%a" == "3//" ( 
		echo %%a >>2.txt 
		set /a m=m+1
		) else goto third	
	)
)

:third
	set /a m=m+1
	for /f "tokens=* skip=%m%" %%a in (all.txt) do (
		if NOT "%%a" == "4//" ( 
		echo %%a >>3.txt
		set /a m=m+1
		) else  goto four
	)
)

:four
	set /a m=m+1
	for /f "tokens=* skip=%m%" %%a in (all.txt) do (
		if NOT "%%a" == "5//" ( 
		echo %%a >>4.txt
		set /a m=m+1
		) else   goto five
	)
)

:five
	set /a m=m+1
	for /f "tokens=* skip=%m%" %%a in (all.txt) do (
		if NOT "%%a" == "6//" ( 
		echo %%a >>5.txt 
		) else  exit	
	)
)