::for %a in (*.html) do echo "<a href=%a>%a</a>" >index.html

type head.txt >>index.html

for /d %%a in (*.*) do (?

echo ^<a href=%%a/index.html^>%%a^</a^> >>index.html

echo ^<br^> >>index.html

echo ^<br^> >>index.html

cd %%a

call c:\html.bat

cd ..

)

for %%b in (*) do (

echo ^<a href=%%b^>%%b^</a^> >>index.html

echo ^<br^> >>index.html

echo ^<br^> >>index.html

)

type end.txt >>index.html
