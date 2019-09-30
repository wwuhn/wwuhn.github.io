echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" >a.html
echo  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >>a.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>a.html
echo ^<base target="_blank" /^> >>a.html

echo ^<head^> >>a.html
echo ^<title^>contents^</title^> >>a.html
echo ^<link  href="more.css" rel="stylesheet" type="text/css" /^> >>a.html
echo ^<style type=text/css^> >>a.html


echo ^</style^>^</head^> >>a.html

echo ^<body^>^<div^> >>a.html

for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (

	if not "%%a.%%b"=="%%a." (
	if not "%%a.%%b"=="a.html" (
	if not "%%b"=="bat" (
		echo ^<li^>^<a href="%%a.%%b"^>%%a.%%b^</a^>^</li^> >>a.html
	)
	)
	)
)
for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (
	if "%%a.%%b"=="%%a." (
		echo ^<li^>^<a href="%%a/a.html"^>%%a^</a^>^</li^> >>a.html
	)

)
echo ^</div^> >>a.html
echo ^</body^> >>a.html
echo ^</html^> >>a.html
