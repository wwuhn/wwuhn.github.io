%homedrive%
cd %ProgramFiles%\Adobe\Acrobat 11.0\Acrobat
del /f /q amtlib.dll
copy amtlib.dll %ProgramFiles%\Adobe\Acrobat 11.0\Acrobat
cd %ProgramFiles%\Adobe\Acrobat 11.0\Acrobat
dir *.dll
