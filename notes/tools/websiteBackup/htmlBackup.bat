md %userprofile%\desktop\websitehtml
for /r e:\website %%h in (*.html) do @copy %%h %userprofile%\desktop\websitehtml

::因为novel内html文件较多，所以特意把novel这个文件夹先剪切出来

::for /r 目录 %变量 in (集) do 命令
::注意参数的两个限定：
::1.目录，限定操作的范围；
::2.集，限定操作的文件或文件类（使用通配符），当于与前面每个目录相配的文件集；

::在/r 之后的那个路径，指包含它之下的整个目录树（相当于DOS命令tree里的范围）中的所有目录，
::如果仅为一个英文句点 . ，是指当前路径下的目录树，
::如果省略了路径则特指当前目录，

