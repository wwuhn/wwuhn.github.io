import shutil,os
f = open("D:\\websiteHtmlBackup\\fileList.txt") #文件内不能有空行,文件名中不能有半角?号
lines = f.readlines()

for line in lines:
    str = R""+line
    str1 = "\\";
    k = str.rfind(str1, len(str1))
    copytoDir = "D"+str[1:k]
    if not os.path.exists(copytoDir):
        os.makedirs(copytoDir);
    srcFile=line.splitlines()[0] #去掉后面的\n
    shutil.copy(srcFile,copytoDir)
    print (srcFile)
    
# 如果因文件名的问题而出现中断，记住中断的位置，
# 然后删除文本文件中此前的内容再继续即可。

 



