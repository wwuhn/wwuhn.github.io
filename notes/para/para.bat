echo.  >f:\website\notes\para\ParaText2.txt

for /f "tokens=*" %%a in (f:\website\notes\para\ParaText.txt) do (

echo ^<p^>%%a^</p^> >>f:\website\notes\para\ParaText2.txt
)