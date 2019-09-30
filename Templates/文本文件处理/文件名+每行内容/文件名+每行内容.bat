if exist all.txt del all.txt
for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (
	if not "%%b"=="bat" (
	for /f "tokens=* usebackq" %%f in ("%%a.%%b") do (@echo  %%a ^| %%f >>all.txt)
	)
)
rem usebackq：如果文件名中有空格，要用usebackq;
rem %%a.%%b文件，如果文件名%%a有空格，要用"";
rem tokens=*表示整行处理，无分列操作；