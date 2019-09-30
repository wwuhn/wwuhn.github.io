setlocal=enabledelayedexpansion


set /p n2= 请输入第2个文本开始的行数：

	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (

		if NOT "%%a" == "3//" ( 
		echo %%a >>2.txt 
		) else  call bat\生成第3个文档.bat	
	)		

)