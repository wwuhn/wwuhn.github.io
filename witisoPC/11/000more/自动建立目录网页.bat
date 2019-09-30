echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" >dirList.html
echo  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >>dirList.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>dirList.html
echo ^<base target="_blank" /^> >>dirList.html

echo ^<head^> >>dirList.html
echo ^<title^>contents^</title^> >>dirList.html
echo ^<link  href="../../more.css" rel="stylesheet" type="text/css" /^> >>dirList.html
echo ^<style type=text/css^> >>dirList.html


echo ^</style^>^</head^> >>dirList.html

echo ^<body^>^<div^> >>dirList.html

for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (

	if not "%%a.%%b"=="%%a." (
	if not "%%a.%%b"=="dirList.html" (
		if "%%b"=="html" (
			echo ^<li^>^<a href="%%a.%%b"^>%%a^</a^>^</li^> >>dirList.html 
		) else (
			echo ^<li^>^<a href="%%a.%%b"^>%%a.^<span style="color:red; "^>%%b^</span^>^</a^>^</li^> >>dirList.html
		)
	)
	)
)
for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (
	if "%%a.%%b"=="%%a." (
		echo ^<li^>^<a href="%%a/a.html"^>^<span style="color:blue; "^>%%a^</span^>^</a^>^</li^> >>dirList.html
	)

)
echo ^</div^> >>dirList.html
echo ^</body^> >>dirList.html
echo ^</html^> >>dirList.html
