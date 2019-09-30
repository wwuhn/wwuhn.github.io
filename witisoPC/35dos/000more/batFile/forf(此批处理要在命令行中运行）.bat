@echo off
CLS
echo wwu hn 123 supervisor wwuhn@hotmail.com
set p="wwu hn 123 supervisor wwuhn@hotmail.com"
for /f "tokens=1-5" %%A in ("wwu hn 123 supervisor wwuhn@hotmail.com") do (echo %%A 
echo %%B 
echo %%C 
echo %%D 
echo %%E
)

for /f "tokens=1-5" %%1 in ("wwu hn 123 supervisor wwuhn@hotmail.com") do (echo %%1 
echo %%2 
echo %%3 
echo %%4 
echo %%5
)

for /f "tokens=1-5" %%1 in ("wwu hn 123 supervisor wwuhn@hotmail.com") do (echo %%1 
echo %%2 
echo %%3 
echo %%4 
echo %%5
)