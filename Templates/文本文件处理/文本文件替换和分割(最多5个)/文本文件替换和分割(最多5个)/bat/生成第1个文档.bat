setlocal=enabledelayedexpansion

for /l %%i in ( 2,1,10) do (

	for /f "tokens=*" %%a in (all.txt) do (

		if NOT "%%a" == "%%i" ( 
		echo %%a >>1.txt 
		) else  call 生成第2个文档.bat	
	
	)		

)
