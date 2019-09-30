import sys
import os
import re
#original.txt(blankProcess.py)→init.txt(website.py)→temp.txt→website.html→obj.html
arg1 = ''  # 脚本没有参数：不合并段落；否则用空行分段，不是空行的合并
if len(sys.argv) > 1 :
    arg1 = sys.argv[1]

# 将init.txt的文本适当处理，写到temp.txt文件中
f = open('init.txt','rU',encoding='UTF-8')
fTemp = open('temp.txt','w',encoding="UTF-8")
s = f.read()        	    	# 整个文本文件作为一个字符串返回
s = s.replace('　','')          # 处理全角空格
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
s = s.replace('xìng' , '性') 
s = re.sub(r'\(淫色淫色\S+\)', '', s)
resup =re.compile(r'(\[\d*\])')   # 上标处理
s = resup.sub(r'<sup>\1</sup>', s)

if (arg1 == ''):
    for i in range(4):
        s = s.replace('\n\n','\n')  # 将多余的空行处理掉
else:
    # 处理用空行分段的文本（不是空格的段落合并）
    s = s.replace('\n\n','a1b2c3z0')# 用'a1b2c3z0'作段落标记
    s = s.replace('\n','')
    s = s.replace('a1b2c3z0','\n')

fTemp.write(s)
f.close()
fTemp.close()

# 'w'覆盖写website.html，'a'为追加写
fNew = open('website.html','w',encoding="UTF-8")

# 将head.html文件写到new.txt文件中
with open('head.html','rU',encoding="UTF-8") as head:
    line = head.readline()      # 返回单行（段落）string
    while line: 	    	# 全部读完后，会返回一个空字符串
        fNew.write(line)
        line = head.readline()  # 第n次执行则返回第n行
    #fNew.write(head.read())

# 将temp.txt的每段加<p></p>\n\n，写到website.html文件中
with open('temp.txt','rU',encoding="UTF-8") as fTemp2:
    countLines = countChars = 0
    for lines in fTemp2.readlines():    # 返回一个列表list,元素为行
        countLines += 1
        countChars += len(lines)
        if countLines == 1:
            s = '<h4>' + lines.strip() + '</h4>\n\n'
            fNew.write(s)
        else:
            s = lines.replace('\n','')
            s = s.strip()	    	    # 会删除掉\n
            s = '<p>' + s + '</p>\n\n'
            fNew.write(s)
    fNew.write("\n\n本页共")
    fNew.write(str(countLines))
    fNew.write("段，")
    fNew.write(str(countChars))
    fNew.write("个字符。")
fsize = "文本字节数：" + str(os.path.getsize('temp.txt')) + " KB"
fNew.write(fsize)   

# 将head.html文件写到new.txt文件中
ffooter = open('footer.html','r',encoding="UTF-8")
fNew.write(ffooter.read())
fNew.close()
ffooter.close()

with open('temp.txt','rU',encoding="UTF-8") as fTemp3:  #重命名website.html
    nfn = fTemp3.readline()
nfn = nfn.strip()
nfn +=  '.html'
if os.path.exists(nfn):
    os.remove(nfn)
os.rename('website.html',nfn)
'''
fNew2 = open(nfn,'a',encoding="UTF-8")
fsize = str(os.path.getsize(nfn))
fNew2.write(fsize)
fNew2.close()
'''
print(countLines,"lines and",countChars,"chars.","filesize is",fsize)
#os.system('nfn')
#pip install pypiwin32
import win32api
#import win32process
win32api.ShellExecute(0,'open',nfn,'','',1)


