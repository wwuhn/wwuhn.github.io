echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"  >index.html
echo  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >>index.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>index.html
echo ^<base target="_blank" /^> >>index.html

echo ^<head^> >>index.html
echo ^<title^>contents^</title^> >>index.html
echo ^<link  href="../../more.css" rel="stylesheet" type="text/css" /^> >>index.html
echo ^<style type=text/css^> >>index.html
echo div{width:74.125^%%;} >>index.html
echo div{margin^:auto^;font-size^:18px^;} >>index.html

echo li{width^:32^%%^; display^:block^;float^:left^;height^:28px^;line-height^:28px^;overflow^:hidden^;} >>index.html
echo a^:link,a^:visited{color^:black^;text-decoration^:none^;} >>index.html
echo ^</style^>^</head^> >>index.html

echo ^<body^>^<div^> >>index.html

for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (

	if not "%%a.%%b"=="%%a." (
	if not "%%a.%%b"=="index.html" (
	if not "%%b"=="bat" (

		echo ^<li^>^<a href="%%a.%%b"^>%%a.%%b^</a^>^</li^> >>index.html
	)
	)
	)

)
for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (
	if "%%a.%%b"=="%%a." (
	if not "%%a.%%b"=="地图 矢量SVG." (	
		echo ^<li^>^<a href="%%a/index.html"^>%%a^</a^>^</li^> >>index.html
	))
	if "%%a.%%b"=="地图 矢量SVG." (	
		echo ^<li^>^<a href="%%a/tests/index.html"^>%%a^</a^>^</li^> >>index.html
	)
)
echo ^</div^> >>index.html
echo ^</body^> >>index.html
echo ^</html^> >>index.html
