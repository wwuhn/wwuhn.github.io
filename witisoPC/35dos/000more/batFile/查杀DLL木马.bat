@echo off

dir %systemroot%\system32\*.exe >exebackNow.txt
dir %systemroot%\system32\*.dll >dllbackNow.txt
Fc exebackNow.txt exebackPrev.txt >diff.txt
Fc dllbackNow.txt dllbackPrev.txt >>diff.txt