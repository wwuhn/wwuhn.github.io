import re
temp = open('h4.txt','w')
tag = re.compile(r'<h\d>')            # 可以直接写成tag = r'<h\d>'
endtag = re.compile(r'</h\d>') 
with open('original.txt','rU',encoding="UTF-8") as f:
    for line in f.readlines():          # 返回单行（段落）string
        #if line.startswith("h4"):
        #if line.find("h4") != -1:     # 返回开始位置，否则返回-1
        list1 = re.findall(tag,line)
        if list1!=[]:
            #str = line.replace("h4","")
            str = re.sub(tag,"",line)
            str = re.sub(endtag,"",str)
            temp.write(str)
temp.close()
# 也可以将文件内容做为一个字符串返回，利用以下正则表达式及查找返回一个列表：

# res = r'<div>.*?</div>' # 使用非贪婪模式
print("finished!")
import win32api

#win32api.ShellExecute(0,'open',"F:\\Website\\Templates\\000txt\\h4.txt",'','',1)
#将F:\\Website\\Templates\\000txt\\original.txt中的h4中包含的文本提取到文本框

