setlocal=enabledelayedexpansion
for /l %%n in ( 1,1,10) do if exist %%n.txt del %%n.txt


	for /f "tokens=* delims= " %%a in (all.txt) do (

		if NOT "%%a" == "2//" ( 
		echo %%a >>1.txt 
		) else  call bat\生成第2个文档.bat	
	
	)		


