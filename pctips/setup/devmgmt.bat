@if exist runhide.vbs @goto findvbs
@echo Set ws = CreateObject("Wscript.Shell")>>runhide.vbs 
@echo ws.run "cmd /c "%0"",vbhide >>runhide.vbs
@start runhide.vbs&&exit
:findvbs
del runhide.vbs



##########批处理正文开始##########
##########批处理就写这里##########
@devmgmt.msc
##########批处理正文结束##########