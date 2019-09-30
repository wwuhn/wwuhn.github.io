@if exist runhide.vbs @goto findvbs
@echo Set ws = CreateObject("Wscript.Shell") >runhide.vbs 
@echo ws.run "cmd /c "%0"",vbhide >>runhide.vbs
@start runhide.vbs
:findvbs

@rem 上面的内容，可以确保在网页上提示“运行或保存”，而不是显示；


@echo.
echo.

@set /p address="请输入网址:"
@set /p linkName="请输入链接名:"

echo ^<li^>^<a href="%address%"^>%linkName%^</a^>^</li^>  >> F:/Website/notes/noteshtml.html

start F:/Website/notes/noteshtml.html
del %~dp0%\runhide.vbs


::比如你有个批处理a.bat在D:/qq文件夹下  
::a.bat内容为cd /d %~dp0 
::在这里cd /d %~dp0的意思就是cd /d d:/qq 
::%0代表批处理本身 d:/qq/a.bat
::~dp是变量扩充
::d既是扩充到分区号 d:
::p就是扩充到路径 /qq 
::dp就是扩充到分区号路径 d:/qq 