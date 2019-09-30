setlocal=enabledelayedexpansion


set /p n2= 请输入第5个文本文档开始的行数：

	for /f "tokens=* skip=%n2%" %%a in (all.txt) do (

		if NOT "%%a" == "6//" ( 
		echo %%a >>5.txt 
		) else  exit	
	)		

)