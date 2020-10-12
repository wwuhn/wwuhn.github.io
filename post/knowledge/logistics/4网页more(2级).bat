chcp 65001

echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" >index.html
echo  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >>index.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>index.html
echo ^<base target="_blank" /^> >>index.html

echo ^<head^> >>index.html
echo ^<title^>contents^</title^> >>index.html
echo ^<link  href="../../more.css" rel="stylesheet" type="text/css" /^> >>index.html
echo ^<style type=text/css^> >>index.html
echo ^</style^>^</head^> >>index.html
echo ^<body^>^<div^> >>index.html

for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (
	if not "%%a.%%b"=="%%a." (
	if not "%%a.%%b"=="index.html" (
	if not "%%b"=="bat" (
		if "%%b"=="html" (
			echo ^<li^>^<a href="%%a.%%b"^>%%a^</a^>^</li^> >>index.html 
		)
	)
	)
	)
)
::echo ^<li^>^</li^>^<li^>^</li^> >>index.html
for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (
	if not "%%a.%%b"=="%%a." (
	if not "%%a.%%b"=="index.html" (
	if not "%%b"=="bat" (
		if not "%%b"=="html" (
			echo ^<li^>^<a href="%%a.%%b"^>%%a.^<span style="color:red; "^>%%b^</span^>^</a^>^</li^> >>index.html
		)
	)
	)
	)
)

for /f "tokens=1,2 usebackq delims=." %%a in (`dir  /o:n /b`) do (
	if "%%a.%%b"=="%%a." (
	if not "%%a"=="backup" (
	
		echo ^<h4^>%%a^</h4^> >>index.html
		for /f "tokens=1,2 usebackq delims=." %%f in (`dir %%a  /o:n /b`) do (
			if "%%f.%%g"=="%%f." (
				echo ^<li^>^<a href="%%a\%%f\a.html"^>^<span style="color:blue; "^>%%f^</span^>^</a^>^</li^> >>index.html 
			) else (
				if "%%g"=="html" (
					echo ^<li^>^<a href="%%a\%%f.%%g"^>%%f^</a^>^</li^> >>index.html 
				) else (
					echo ^<li^>^<a href="%%a\%%f.%%g"^>%%f.^<span style="color:red; "^>%%g^</span^>^</a^>^</li^> >>index.html
				)
			)
		)

	))

)
echo ^</div^> >>index.html
echo ^</body^> >>index.html
echo ^</html^> >>index.html

::if not "%%b"=="jpg" (
