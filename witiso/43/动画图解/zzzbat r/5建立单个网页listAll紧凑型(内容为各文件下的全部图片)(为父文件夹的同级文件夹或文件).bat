echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" >..\listAllΩÙ¥’–Õ.html
echo  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >>..\listAllΩÙ¥’–Õ.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>..\listAllΩÙ¥’–Õ.html
echo ^<base target="_blank" /^> >>..\listAllΩÙ¥’–Õ.html

echo ^<head^> >>..\listAllΩÙ¥’–Õ.html
echo ^<title^>total pic list^</title^> >>..\listAllΩÙ¥’–Õ.html
echo ^<style type=text/css^> >>..\listAllΩÙ¥’–Õ.html
echo div{width:94.125^%;} >>..\listAllΩÙ¥’–Õ.html
echo div{margin^:auto^;} >>..\listAllΩÙ¥’–Õ.html
echo img{display^:block^;margin^:auto;} >>..\listAllΩÙ¥’–Õ.html
echo img{padding^:4px 4px; height^:200px; float^:left;} >>..\listAllΩÙ¥’–Õ.html
echo img{border^:0 red solid;} >>..\listAllΩÙ¥’–Õ.html
echo a:link{text-decoration: none; color:#fff;} >>..\listAllΩÙ¥’–Õ.html

echo ^</style^>^</head^> >>..\listAllΩÙ¥’–Õ.html

echo ^<body^>^<div^> >>..\listAllΩÙ¥’–Õ.html

for /f "tokens=1,2 usebackq delims=." %%a in (`dir ..\ /o:d /b`) do (
	if not "%%a"=="zzzbat r" (
	if not "%%b"=="html" (
		for /f "tokens=* usebackq" %%n in (`dir ..\%%a /o:d /b`) do (
			if not "%%n"=="picList.html" (
				echo ^<a href="%%a\%%n"^>^<img src="%%a/%%n" /^>^</a^> >>..\listAllΩÙ¥’–Õ.html
			)
		)
	)
	)
)
echo ^</div^> >>..\listAllΩÙ¥’–Õ.html
echo ^</body^> >>..\listAllΩÙ¥’–Õ.html
echo ^</html^> >>..\listAllΩÙ¥’–Õ.html
