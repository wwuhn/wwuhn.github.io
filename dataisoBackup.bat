md %userprofile%\desktop\dataiso

xcopy /s %~dp0\dataiso %userprofile%\desktop\dataiso

cd /d %ProgramFiles%\winrar
%systemdrive%

rar a -r %userprofile%\desktop\dataiso.rar %userprofile%\desktop\dataiso\*

rem a表示创建压缩文档的命令；
rem -m5是指定最大压缩比率；
rem -s是采用固实压缩；
rem -r是递归压缩文件夹中所有文件；
rem 后面的待压缩的若干文件夹。
rem 如果winrar的安装目录不在环境变量PATH中，则需要写全路径，如："C:\Program Files\WinRar\rar" ......