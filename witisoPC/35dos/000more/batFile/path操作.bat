@echo off
echo.
cls
echo %%
echo path:%path%
echo systemdriver:%systemdriver%
echo %path:~10,5%
echo %%
echo %%
FOR /F "delims= " %%i IN ('set') DO @echo %%i