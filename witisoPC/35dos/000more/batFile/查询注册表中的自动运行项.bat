@echo off
for /f "tokens=2 delims=:" %%i in ('reg query hklm\software\microsoft\windows\currentVersion\run') do echo %systemDrive%%%i
for /f "tokens=2 delims=:" %%i in ('reg query hkcu\software\microsoft\windows\currentVersion\run') do echo %systemDrive%%%i
pause>nul