import sys
import os
import re
lenLine = 40	# 自己的笔记本电脑设置宽度为65.29%时，中文字符数为42个
# original.txt(blankProcess.py)→init.txt(website.py)→temp1→temp2.txt→

# →website.html→obj.html
arg1 = ''  # 脚本没有参数：不合并段落；否则用空行分段，不是空行的合并
if len(sys.argv) > 1 :
    arg1 = sys.argv[1]

# 1 将init.txt的文本多余的空行替换掉，写到temp1.txt文件中

#   如果不写入的到文件，是否可以由文本用split('\n')分割形成一个列表进行处理
wTemp1 = open('temp1.txt','w',encoding="UTF-8")
with open('init.txt','rU',encoding='UTF-8') as rInit:
    s = rInit.read()
    for i in range(4):
        s = s.replace('\n\n','\n')      # 将多余的空行处理掉，便于后面重新做分行
    wTemp1.write(s)
wTemp1.close()


# 2 将temp1.txt的文本适当处理(文本替换和段落处理)，写到temp2.txt文件中
wTemp2 = open('temp2.txt','w',encoding="UTF-8")
rTemp1 = open('temp1.txt','rU',encoding='UTF-8')
line = rTemp1.readline()                            # 整个文本文件作为一个字符串返回
while line:
    s = line.replace('　','')                  # 处理全角空格
    s = s.replace('' , '\n\n') 
    s = s.replace('ròu' , '肉')
    s = s.replace('xiōng' , '胸')
    s = s.replace('yín' , '淫')
    s = s.replace('yīn' , '阴')
    s = s.replace('yáng' , '阳')
    s = s.replace('玉jīng' , '玉茎')
    s = s.replace('jīng' , '精')
    s = s.replace('shè' , '射')
    s = s.replace('guī' , '龟')
    s = s.replace('nǎi' , '奶')
    s = s.replace('aì' , '爱')
    #s = s.replace('　' , '\n')	# 对于用两个空格来分段的文本(应该无效，前面已替换掉了)
    s = s.replace('xiāo' , '小')
    s = s.replace('jī' , '鸡')
    s = s.replace('xìng' , '性') 
    s = re.sub(r'\(淫色淫色\S+\)', '', s)
    resup =re.compile(r'(\[\d*\])')         # 上标处理
    s = resup.sub(r'<sup>\1</sup>', s)

    if len(s) > lenLine:             # 根据行长，合并一些行，并重新进行分行(段)
        s = s.strip()
        wTemp2.write(s)
    else:
        wTemp2.write(s +'\n' )
    line = rTemp1.readline()

rTemp1.close()
wTemp2.close()

# 'w'覆盖写website.html，'a'为追加写
wPage = open('html\website.html','w',encoding="UTF-8")

# 3 将head.html文件写到website.html文件中
with open('head.html','rU',encoding="UTF-8") as head:
    line = head.readline()              # 返回单行（段落）string
    while line: 	    	        # 全部读完后，会返回一个空字符串
        wPage.write(line)
        line = head.readline()          # 第n次执行则返回第n行

# 4 将temp2.txt的每段加<p></p>\n\n，写到website.html文件中
with open('temp2.txt','rU',encoding="UTF-8") as rtemp2:
    countLines = countChars = 0
    for lines in rtemp2.readlines():    # 返回一个列表list,元素为行（段）
        countLines += 1
        countChars += len(lines)
        if countLines == 1:             # 第一行设置为标题行
            s = '<h4>' + lines.strip() + '</h4>\n\n'
            wPage.write(s)
        else:
            s = lines.replace('\n','')
            s = s.strip()	    	 # 会删除掉\n
            s = '<p>' + s + '</p>\n\n'
            wPage.write(s)
    wPage.write("\n\n本页共")
    wPage.write(str(countLines))
    wPage.write("段，")
    wPage.write(str(countChars))
    wPage.write("个字符，")
fsize = str(os.path.getsize('temp2.txt')) + " Byte(字节)"
wPage.write(fsize)   

# 5 将footer.html文件写到page.txt文件中
ffooter = open('footer.html','r',encoding="UTF-8")
wPage.write(ffooter.read())
wPage.close()
ffooter.close()

# 6 取第一行做为文件名
with open('temp2.txt','rU',encoding="UTF-8") as rTemp2:  
    nfn = rTemp2.readline()
nfn = nfn.strip()
nfn = 'html\\' + nfn +  '.html'
if os.path.exists(nfn):
    os.remove(nfn)
os.rename('html\website.html',nfn)

print(countLines,"lines and",countChars,"chars.","filesize is",fsize)


# 7 打开重命名后的文档
# pip install pypiwin32
import win32api
win32api.ShellExecute(0,'open',nfn,'','',1)


