::type head.txt >docList.html

echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >docList.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>docList.html

echo ^<head^> >>docList.html
echo ^<title^>picList^</title^> >>docList.html
echo ^<style type=text/css^> >>docList.html
echo div{width:78.125^%%;} >>docList.html
echo div{margin^:auto^;} >>docList.html



echo img{display^:block^;margin^:auto;} >>docList.html
echo img{padding^:2px 22px;} >>docList.html
echo li{width^:24%%^;display^:block^;float^:left^;height^:24px^;} >>docList.html
echo a:link{text-decoration: none; color:#000;} >>docList.html

echo ^</style^>^</head^> >> docList.html

echo ^<body^>^<div^> >>docList.html


for /f "tokens=1,2 usebackq delims=." %%b in (`dir /o:d /b`) do (
	if not "%%c" == "bat" (
	if not "%%b.%%c" == "docList.html" (
	if not "%%b.%%c" == "%%b." (
		echo ^<li^>^<a href="%%b.%%c" title="%%b"^>^%%b^</a^>^</li^> >>docList.html
	)
	)
	)
)

echo ^</div^> >>docList.html
echo ^</body^> >>docList.html
echo ^</html^> >>docList.html

::for %a in (*.html) do echo "<a href=%a>%a</a>" >>docList.html
::type end.txt >>docList.html
::delims=.后面如果有空格，对于文件名中如果有空格时则会出错；
::dir /o:d /b：显示文件夹名或文件名（包括扩展名）；