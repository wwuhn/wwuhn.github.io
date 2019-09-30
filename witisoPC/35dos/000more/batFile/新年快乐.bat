::made by [email]523066680@cn-dos.net[/email]   2008-12-25
::blog: hi.baidu.com/523066680
::首发于:
@set evern1= 35 4248x+ 53 64 57 66 7179x+ 9397x+ 75f5y+ f4 b3 c2 b7 c8 3e 4d 5c 5bcby+ db ea f9 7b7fx+ 7efey+
@set evern2= 2535y+ 44 5352x- 464dx+ 656cx+ 6595y+ a3adx+ 49g9y+
@set evern3= 62 71 24g4y+ 55 66 77 484ex+ 5e7ey+ 878gx+ 2bbby+ ca d9 e8 f7 cc dd ee ff fg
@set evern4= 2c 3b 4a49x- 5857x- 5655x- 6575y+ 84 93 939fx+ 6ahay+ h9 c6 d5 e4 cd de ef 

@echo off&setLocal enabLedeLayedexpansion
title made by [email]523066680@cn-dos.net[/email]
mode con coLs=40 Lines=22
color 40
  set end= cn-dos 523066680 祝 大 家 
  set "L0=" &set "str=■" &set "num=0123456789abcdefghi"
  for /l %%a in (1,1,18) do (set L=!L!)
  for /l %%a in (0,1,18) do (set n!num:~%%a,1!=%%a)

for /l %%n in (1,1,4) do (
  for /l %%a in (1,1,18) do (set L%%a=%L%)
  for %%a in (!evern%%n!) do (call :a %%a)
  for /l %%a in (1,1,18) do (set "L%%n_%%a=!L%%a!")
  ping -n 2 127.1>nul
)
color 4e
for /l %%a in (0,1,30) do (
   set /p x=!end:~%%a,1!<nul
   for /l %%b in (1,1,5) do (ping -n 1 127.0>nul)
)
mode con cols=75 lines=37
cls,
for /l %%a in (1,1,18) do (echo,!L1_%%a! !L2_%%a!)
for /l %%a in (1,1,18) do (echo,!L3_%%a! !L4_%%a!)
ping -n 5 127.1>nul
exit
:a
set n=%~1
if "%n:~3%"=="" (set "do=::") else (set "do=")
  set /a ya=n%n:~0,1%,xa=n%n:~1,1%,xa2=xa+1
  %do% set /a yb=n%n:~2,1%,xb=n%n:~3,1%,xb2=xb+1
  %do% set "YorX=%n:~4,1%" &set "add=%n:~5,1%"
  :a-1
  set L%ya%=!L%ya%:~0,%xa%!%str%!L%ya%:~%xa2%!
  call :echo call yes
  %do% set /a %YorX%a%add%=1,xa2=xa+1
  %do% if not !%YorX%a! equ !%YorX%b! (goto :a-1)
  %do% set L%ya%=!L%ya%:~0,%xa%!%str%!L%ya%:~%xa2%!
:echo
  if "%2"=="yes" (set for=3) else (set for=5)
  for /l %%a in (1,1,%for%) do (ping -n 1 127.1>nul)
  cLs
  for /l %%a in (0,1,18) do (echo, !L%%a!)
  goto :eof