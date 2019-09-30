import sys
import os
import re
# original.txt(blankProcess.py)→init.txt(website.py)→temp.txt→
# →page.html→obj.html
arg1 = ''  # 脚本没有参数：不合并段落；否则用空行分段，不是空行的合并
if len(sys.argv) > 1 :
    arg1 = sys.argv[1]

# 1 将original.txt的文本适当处理(文本替换和段落处理)，写到temp.txt文件中

rInit = open('original.txt','rU',encoding='UTF-8')
wTemp = open('temp.txt','w',encoding="UTF-8")

nfn = str(rInit.readline()) # 第一行用作标题
nfn =nfn.replace("<p>","")
nfn =nfn.replace("</p>","")
nfn =nfn.replace("<h4>","")
nfn =nfn.replace("</h4>","")
nfn =nfn.replace("++","PP")
nfn =nfn.replace(" ","")
nfn =nfn.replace("/","")
nfn =nfn.replace("\\","")

nfn2 = str(rInit.readline()) # 第二行用于替换
nfn = nfn.strip()
kk = len(nfn)
nfn = nfn[1:kk]

s = rInit.read()                    # 整个文本文件作为一个字符串返回
s = s.replace('　','')              # 处理全角空格
s = s.replace("<<","&lt;&lt;")
s = s.replace("#include <","#include &lt;")
s = s.replace("#include<","#include&lt;")
#s = s.replace(">","&gt;")
if len(nfn2) > 2:
    s = s.replace(nfn2,"")               # 在今日头条中，一些图片用标题做说明，处理掉
#s = re.sub(nfn,"",s)
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
s = s.replace('xiāo' , '小')
s = s.replace('jī' , '鸡')
s = s.replace('xìng' , '性')
s = s.replace(',?' , ',”')
s = s.replace('.?' , '.”')
s = s.replace('\n\r' , '\n')
s = s.replace('\r\n' , '\n')
s = s.replace('Jos?' , 'José ')
s = s.replace(' 　　　　　　' , '\n\n')
s = re.sub(r'</div><div class="\w\d*">', '<p></p>', s)

s = re.sub(r'\(淫色淫色\S+\)', '', s)
#resup =re.compile(r'(\[\d*\])')         # 上标处理
#s = resup.sub(r'<sup>\1</sup>', s)
rejiu =re.compile(r'<\S{,8}九\S{,22}</\S{,5}>') 
s = rejiu.sub("", s)
if (arg1 == ''):
    for i in range(4):
        s = s.replace('\n\n','\n')      # 将多余的空行处理掉
else:
    # 处理用空行分段的文本（不是空格的段落合并）
    s = s.replace('\n\n','a1b2c3z0')    # 用'a1b2c3z0'作段落标记
    s = s.replace('\n','')
    s = s.replace('a1b2c3z0','\n')
wTemp.write(nfn)                        # 标题写回
wTemp.write("\n")

wTemp.write(s)
rInit.close()
wTemp.close()

# 'w'覆盖写page.html，'a'为追加写
wPage = open('html\page.html','w',encoding="UTF-8")

# 将head.html文件写到page.txt文件中
with open('head.html','rU',encoding="UTF-8") as head:
    line = head.readline()              # 返回单行（段落）string
    while line: 	    	        # 全部读完后，会返回一个空字符串
        wPage.write(line)
        line = head.readline()          # 第n次执行则返回第n行

# 2 将temp.txt的每段加<p></p>\n\n，写到page.html文件中
with open('temp.txt','rU',encoding="UTF-8") as fTemp2:
    countLines = countChars = 0
    for lines in fTemp2.readlines():    # 返回一个列表list,元素为行（段）
        countLines += 1
        countChars += len(lines)
        if countLines == 1:             # 第一行设置为标题行
            s = '<h4>' + lines.strip() + '</h4>\n\n'
            wPage.write(s)
        else:
            #s = lines
            s = lines.replace('\n','')
            s = s.strip()	    	 # 会删除掉\n
            if s.startswith('hhh'):
                s = '<h4>' + s + '</h4>\n\n'
                s = s.replace('hhh','')
            if s.startswith('。'):
                t = list(s)
                t = t[1:]
                s = '“' + ''.join(t)
            s = lines.replace('<p><h4>' , '<h4>')
            s = s.replace('</h4></p>' , '</h4>')
            #s = '<p>' + s + '</p>\n\n'
            
            wPage.write(s)
    wPage.write("\n\n<p style='float:right;'>本页共")
    wPage.write(str(countLines))
    wPage.write("段，")
    wPage.write(str(countChars))
    wPage.write("个字符，")
fsize = str(os.path.getsize('temp.txt')) + " Byte(字节)</p>"
wPage.write(fsize)
 

# 3 将footer.html文件写到website.txt文件中，可以定义为一个函数，以文件名为参数
ffooter = open('footer.html','r',encoding="UTF-8")
wPage.write(ffooter.read())
wPage.close()
ffooter.close()

# 4 取第一行做为文件名

nfn = 'html\\' + nfn +  '.html'

if os.path.exists(nfn):
    os.remove(nfn)
os.rename('html\page.html',nfn)

print(countLines,"lines and",countChars,"chars.","filesize is",fsize)


# 5 打开重命名后的文档
# pip install pypiwin32
import win32api
# win32api.ShellExecute(0,'open','F:\\Website\\notes\\tools\\npp\\notepad++.exe',nfn,'',1)
win32api.ShellExecute(0,'open',nfn,'','',1)

""
# 第一个参数默认为0.打开，路径名，默认空，默认空，是否显示程序1 or 0

"""
使用ShellExecute函数运行其他程序
除了使用os模块中的os.system()函数以外，还可以使用win32api模块中的ShellExecute()函数。其函数如下所示。
ShellExecute(hwnd, op , file , params , dir , bShow )
其参数含义如下所示。
hwnd：父窗口的句柄，如果没有父窗口，则为0。
op：要进行的操作，为“open”、“print”或者为空。
file：要运行的程序，或者打开的脚本。
params：要向程序传递的参数，如果打开的为文件，则为空。
dir：程序初始化的目录。
bShow：是否显示窗口。
"""




