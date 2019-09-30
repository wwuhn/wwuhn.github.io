setlocal=enabledelayedexpansion


set /p n2= 请输入第3个文本开始的行数：

	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (

		if NOT "%%a" == "4//" ( 
		echo %%a >>3.txt 
		) else  call bat\生成第4个文档.bat	
	)		

)