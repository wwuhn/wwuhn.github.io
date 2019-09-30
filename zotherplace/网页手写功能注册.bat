cls
@echo off
%homedrive%
cd %homedrive%\Users\wwuhnwufuqun\Application Data\Macromedia\Flash Player
md #Security\FlashPlayerTrust
cd %homedrive%\Users\wwuhnwufuqun\Application Data\Macromedia\Flash Player\#Security\FlashPlayerTrust
echo. >shouxieshuru.txt
set /p cho= 请输入本网页的保存路径（可以只输入其保存分区）,然后回车:
echo %cho% >>shouxieshuru.txt
ren shouxieshuru.txt shouxieshuru.cfg