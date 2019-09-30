rem 重命名每个文件夹下的文件（按时间以序列号，对父文件夹下文件夹的文件）
setlocal enabledelayedexpansion
for /f "tokens=1,2 usebackq delims=." %%C in (`dir ..\  /o:d /b`) do (
  set n=0
  if not "%%C"=="zzzbat r" (
  if  "%%C.%%D"=="%%C." (
     for /f "tokens=1,2 usebackq delims=." %%A in (`dir ..\%%C /o:d /b`) do (
     set /a n=n+1
		if !n! lss 10 (
			ren "..\%%C\%%A.%%B" "0!n!.%%B"
		) else (
			ren "..\%%C\%%A.%%B" "!n!.%%B"
		)
     )
   )
   )
)
rem delims==."的."中间无空格,不然对文名称有空的文件或文件夹处理不了;
rem 延迟变量n,且必须由"!"引导,如果不延迟,则n永远是0;