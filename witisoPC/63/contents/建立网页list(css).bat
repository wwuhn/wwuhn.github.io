echo ^<!DOCTYPE html5^> >list.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>list.html
echo ^<base target="_blank" /^> >>list.html
echo ^<link  href="list.css" rel="stylesheet" type="text/css" /^> >>list.html
echo ^<head^> >>list.html
echo ^<title^>fileList^</title^> >>list.html
echo ^<style type=text/css^> >>list.html
echo div{width^:74.125^%%;} >>list.html
echo div{margin^:auto;} >>list.html
echo div{margin^:auto;} >>list.html
echo li{width^:33^%%;} >>list.html
echo li{float^:left;} >>list.html
echo li{height^:32px;} >>list.html
echo li{line-height^:32px;} >>list.html
echo li{overflow^:hidden;} >>list.html
echo li{white-space^:nowrap;} >>list.html
echo li{text-overflow^:ellipsis;} >>list.html
echo img{border^:0 red solid;} >>list.html
echo a:link{text-decoration: none; color:#000;} >>list.html
echo ^</style^>^</head^> >>list.html
echo ^<body^>^<div^> >>list.html
for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (
	if not "%%a.%%b"=="%%a." (
	if not "%%a.%%b"=="list.html" (
		echo ^<li^>^<a href="%%a.%%b"^>%%a.%%b^</a^>^</li^> >>list.html
	)))
for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (
	if "%%a.%%b"=="%%a." (
		echo ^<li^>^<a href="%%a/list.html"^>%%a^</a^>^</li^> >>list.html
	))
echo ^</div^> >>list.html
echo ^</body^> >>list.html
echo ^</html^> >>list.html
