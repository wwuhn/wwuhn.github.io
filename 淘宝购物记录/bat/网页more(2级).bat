chcp 65001

echo ^<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" >..\index.html
echo  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"^> >>..\index.html
echo ^<html xmlns="http://www.w3.org/1999/xhtml"^> >>..\index.html
echo ^<base target="_blank" /^> >>..\index.html

echo ^<head^> >>..\index.html
echo ^<title^>contents^</title^> >>..\index.html
echo ^<link  href="bat/more.css" rel="stylesheet" type="text/css" /^> >>..\index.html
echo ^<style type=text/css^> >>..\index.html
echo ^</style^>^</head^> >>..\index.html
echo ^<body^>^<div^> >>..\index.html

for /f "tokens=1,2 usebackq delims=." %%a in (`dir ..\ /o:n /b`) do (
	if not "%%a.%%b"=="%%a." (
	if not "%%a.%%b"=="index.html" (
	if not "%%b"=="bat" (
		if "%%b"=="html" (
			echo ^<li^>^<a href="%%a.%%b"^>%%a^</a^>^</li^> >>..\index.html 
		)
	)
	)
	)
)
::echo ^<li^>^</li^>^<li^>^</li^> >>..\index.html
for /f "tokens=1,2 usebackq delims=." %%a in (`dir ..\ /o:n /b`) do (
	if not "%%a.%%b"=="%%a." (
	if not "%%a.%%b"=="index.html" (
	if not "%%b"=="bat" (
		if not "%%b"=="html" (
			echo ^<li^>^<a href="%%a.%%b"^>%%a.^<span style="color:red; "^>%%b^</span^>^</a^>^</li^> >>..\index.html
		)
	)
	)
	)
)

for /f "tokens=1,2 usebackq delims=." %%a in (`dir ..\ /o:n /b`) do (
	if "%%a.%%b"=="%%a." (
	if not "%%a"=="backup" (
    if not "%%a"=="bat" (
	
		echo ^<h4^>%%a^</h4^> >>..\index.html
		for /f "tokens=1,2 usebackq delims=." %%f in (`dir ..\%%a  /o:n /b`) do (
			if "%%f.%%g"=="%%f." (
				echo ^<li^>^<a href="%%a\%%f\a.html"^>^<span style="color:blue; "^>%%f^</span^>^</a^>^</li^> >>..\index.html 
			) else (
				if "%%g"=="html" (
					echo ^<li^>^<a href="%%a\%%f.%%g"^>%%f^</a^>^</li^> >>..\index.html 
				) else (
					echo ^<li^>^<a href="%%a\%%f.%%g"^>%%f.^<span style="color:red; "^>%%g^</span^>^</a^>^</li^> >>..\index.html
				)
			)
		)

	)))

)
echo ^</div^> >>..\index.html
echo ^</body^> >>..\index.html
echo ^</html^> >>..\index.html

::if not "%%b"=="jpg" (



rem 这里是最主要的部分，其实就是使用dir命令以最简单的形式列出当前目录下（包括子目录）的所有的文件
rem 然后使用for来把它转换为超链接的形式，有兴趣可以敲一下这个命令，看看会出现什么样的结果：“dir *.* /a:-d/s/b”
rem for /f "tokens=* delims=" %%i in ('dir *.* /a:-d/s/b') do (
rem echo ^<a href="%%i" target=_blank^>%%i^</a^>^<br^> >> %LISTFILE%
rem )
