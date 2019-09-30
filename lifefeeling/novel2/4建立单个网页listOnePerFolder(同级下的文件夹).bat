echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" >index.html
echo  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >>index.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>index.html
echo ^<base target="_blank" /^> >>index.html

echo ^<head^> >>index.html
echo ^<title^>list^</title^> >>index.html
echo ^<style type=text/css^> >>index.html
echo div{width:64.125^%%;} >>index.html
echo div{margin^:auto^;} >>index.html
echo img{display^:block^;margin^:auto;} >>index.html
echo img{padding^:2px 22px; height^:200px; float^:left;} >>index.html
echo img{border^:0 red solid;} >>index.html
echo a:link{text-decoration: none; color:#000;} >>index.html
echo a:visited{text-decoration: none; color:#000;} >>index.html
echo a{display:block; width:^24%%;} >>index.html
echo a{float:left;height:36px; font-size:22px;} >>index.html

echo ^</style^>^</head^> >>index.html

echo ^<body^>^<div^> >>index.html

for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (
	if "%%a.%%b"=="%%a." (


		echo ^<a href="%%a/1.html"^>%%a^</a^> >>index.html


	)
)
echo ^</div^> >>index.html
echo ^</body^> >>index.html
echo ^</html^> >>index.html
