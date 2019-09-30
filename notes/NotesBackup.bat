md %userprofile%\desktop\notes
md %userprofile%\desktop\notes\Assistants
md %userprofile%\desktop\notes\Assistants\res
md %userprofile%\desktop\notes\consoleProgram
md %userprofile%\desktop\notes\VC\方法调用与消息传递

copy %~dp0\Assistants\*.* %userprofile%\desktop\notes\Assistants
copy %~dp0\Assistants\res\*.* %userprofile%\desktop\notes\Assistants\res
copy %~dp0\consoleProgram\*.* %userprofile%\desktop\notes\consoleProgram
copy %~dp0\VC\方法调用与消息传递\*.* %userprofile%\desktop\notes\VC\方法调用与消息传递


cd /d %ProgramFiles%\winrar
rar a -r %userprofile%\desktop\notes.rar %userprofile%\desktop\notes\*
::python F:\notes\notes.py

rem 复制文件下所有文件，包括子文件夹
rem xcopy /s %~dp0\consoleProgram\*.* %userprofile%\desktop\notes\consoleProgram
rem a表示创建压缩文档的命令；
rem -m5是指定最大压缩比率；
rem -s是采用固实压缩；
rem -r是递归压缩文件夹中所有文件；
rem 后面的待压缩的若干文件夹。
rem 如果winrar的安装目录不在环境变量PATH中，则需要写全路径，如："C:\Program Files\WinRar\rar" ......