::for %a in (*.html) do echo "<a href=%a>%a</a>" >index.html

for /f "tokens=1,2 usebackq delims=." %%C in (`dir ..\ /o:d /b`) do (
if not "%%C"=="zzzbat r" (

type head.txt >>..\%%C\index.html
echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"  >>..\%%C\index.html
echo "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >>..\%%C\index.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>..\%%C\index.html

echo ^<head^> >>..\%%C\index.html
echo ^<title^>pic list^</title^> >>..\%%C\index.html
echo ^<style type=text/css^> >>..\%%C\index.html
echo div{width:94.125^%;} >>..\%%C\index.html
echo div{margin^:auto^;} >>..\%%C\index.html
echo img{display^:block^;margin^:auto;} >>..\%%C\index.html
echo img{padding^:2px 22px;} >>..\%%C\index.html
echo img{border^:0 red solid;} >>..\%%C\index.html
echo a:link{text-decoration: none; color:#fff;} >>..\%%C\index.html

echo ^</style^>^</head^> >>..\%%C\index.html

echo ^<body^>^<div^> >>..\%%C\index.html

for /f "tokens=1,2 usebackq delims=." %%a in (`dir ..\%%C /o:d /b`) do (

if not "%%a.%%b"=="index.html" (

echo ^<a href="%%a.%%b" title="%%a.%%b"^>^<img src="%%a.%%b" /^>^</a^> >>..\%%C\index.html
))
type end.txt >>..\%%C\index.html
echo ^</div^> >>..\%%C\index.html
echo ^</body^> >>..\%%C\index.html
echo ^</html^> >>..\%%C\index.html
)
)