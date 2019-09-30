setlocal=enabledelayedexpansion


set /p n2= 请输入第4个文本文档开始的行数：

	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (

		if NOT "%%a" == "5//" ( 
		echo %%a >>4.txt 
		) else  call bat\生成第5个文档.bat
	)		

)