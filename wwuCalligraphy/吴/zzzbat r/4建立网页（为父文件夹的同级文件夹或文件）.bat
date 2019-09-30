::for %a in (*.html) do echo "<a href=%a>%a</a>" >..\index.html

type head.txt >>..\index.html
echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" >>..\index.html
echo  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >>..\index.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>..\index.html
echo ^<base target="_blank" /^> >>..\index.html

echo ^<head^> >>..\index.html
echo ^<title^>pic list^</title^> >>..\index.html
echo ^<style type=text/css^> >>..\index.html
echo div{width:94.125^%;} >>..\index.html
echo div{margin^:auto^;} >>..\index.html
echo img{display^:block^;margin^:auto;} >>..\index.html
echo img{padding^:2px 22px; height^:200px; float^:left;} >>..\index.html
echo img{border^:0 red solid;} >>..\index.html
echo a:link{text-decoration: none; color:#fff;} >>..\index.html

echo ^</style^>^</head^> >>..\index.html

echo ^<body^>^<div^> >>..\index.html




for /f "tokens=1,2 usebackq delims=." %%a in (`dir ..\ /o:d /b`) do (
if not "%%a"=="zzzbat r" (
if not "%%a.%%b"=="index.html" (

echo ^<a href="%%a\index.html"^>^<img src="%%a\1.jpg" /^>^</a^> >>..\index.html

)))



type end.txt >>..\index.html
echo ^</div^> >>..\index.html
echo ^</body^> >>..\index.html
echo ^</html^> >>..\index.html
