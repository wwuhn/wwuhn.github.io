for /f "tokens=1,2 usebackq delims=." %%C in (`dir ..\ /o:d /b`) do (
	if not "%%C"=="zzzbat r" (
	
		echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^>  >..\%%C\picList.html
		echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>..\%%C\picList.html
		
		echo ^<head^> >>..\%%C\picList.html
		echo ^<title^>pic list^</title^> >>..\%%C\picList.html
		echo ^<style type=text/css^> >>..\%%C\picList.html
		echo div{width:94.125^%;} >>..\%%C\picList.html
		echo div{margin^:auto^;} >>..\%%C\picList.html
		echo img{display^:block^;margin^:auto;} >>..\%%C\picList.html
		echo img{padding^:2px 22px;} >>..\%%C\picList.html
		echo img{border^:0 red solid;} >>..\%%C\picList.html
		echo a:link{text-decoration: none; color:#fff;} >>..\%%C\picList.html
		
		echo ^</style^>^</head^> >>..\%%C\picList.html
		
		echo ^<body^>^<div^> >>..\%%C\picList.html
		
		for /f "tokens=1,2 usebackq delims=." %%a in (`dir ..\%%C /o:d /b`) do (
		
			if not "%%a.%%b"=="picList.html" (
				echo ^<a href="%%a.%%b" title="%%a.%%b"^>^<img src="%%a.%%b" /^>^</a^> >>..\%%C\picList.html
			)
		)
		
		echo ^</div^> >>..\%%C\picList.html
		echo ^</body^> >>..\%%C\picList.html
		echo ^</html^> >>..\%%C\picList.html
	)
)