echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" >..\listAllÊúÅÅÐÍ.html
echo  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >>..\listAllÊúÅÅÐÍ.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>..\listAllÊúÅÅÐÍ.html
echo ^<base target="_blank" /^> >>..\listAllÊúÅÅÐÍ.html

echo ^<head^> >>..\listAllÊúÅÅÐÍ.html
echo ^<title^>total pic list^</title^> >>..\listAllÊúÅÅÐÍ.html
echo ^<style type=text/css^> >>..\listAllÊúÅÅÐÍ.html
echo div{width:94.125^%;} >>..\listAllÊúÅÅÐÍ.html
echo div{margin^:auto^;} >>..\listAllÊúÅÅÐÍ.html
echo img{display^:block^;margin^:auto;} >>..\listAllÊúÅÅÐÍ.html
echo img{padding^:4px 4px;} >>..\listAllÊúÅÅÐÍ.html
echo img{border^:0 red solid;} >>..\listAllÊúÅÅÐÍ.html
echo a:link{text-decoration: none; color:#fff;} >>..\listAllÊúÅÅÐÍ.html

echo ^</style^>^</head^> >>..\listAllÊúÅÅÐÍ.html

echo ^<body^>^<div^> >>..\listAllÊúÅÅÐÍ.html

for /f "tokens=1,2 usebackq delims=." %%a in (`dir ..\ /o:d /b`) do (
	if not "%%a"=="zzzbat r" (
	if not "%%b"=="html" (
		for /f "tokens=* usebackq" %%n in (`dir ..\%%a /o:d /b`) do (
			if not "%%n"=="picList.html" (
				echo ^<a href="%%a/%%n"^>^<img src="%%a/%%n" /^>^</a^> >>..\listAllÊúÅÅÐÍ.html
			)
		)
	)
	)
)
echo ^</div^> >>..\listAllÊúÅÅÐÍ.html
echo ^</body^> >>..\listAllÊúÅÅÐÍ.html
echo ^</html^> >>..\listAllÊúÅÅÐÍ.html
