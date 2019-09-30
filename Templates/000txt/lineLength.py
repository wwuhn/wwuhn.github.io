import sys
import os
import re
#original.txt(blankProcess.py)→init.txt(website.py)→temp.txt→website.html→obj.html
arg1 = ''  # 脚本没有参数：不合并段落；否则用空行分段，不是空行的合并
if len(sys.argv) > 1 :
    arg1 = sys.argv[1]

# 1 将init.txt的文本适当处理(文本替换和段落处理)，写到temp.txt文件中
f = open('init.txt','rU',encoding='UTF-8')
fTemp = open('temp.txt','w',encoding="UTF-8")
s = f.read()                            # 整个文本文件作为一个字符串返回
s = s.replace('　','')                  # 处理全角空格
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
s = re.sub(r'\(淫色淫色\S+\)', '', s)
resup =re.compile(r'(\[\d*\])')         # 上标处理
s = resup.sub(r'<sup>\1</sup>', s)


for i in range(4):
    s = s.replace('\n\n','\n')      # 将多余的空行处理掉


fTemp.write(s)
f.close()
fTemp.close()
fNew = open('website.html','w',encoding="UTF-8")
with open('temp.txt','rU',encoding="UTF-8") as f2:
    line = f2.readline()              # 返回单行（段落）string
    while line: 	    	        # 全部读完后，会返回一个空字符串
        if len(line) > 33:
            s = line.strip()
            fNew.write(s)
        else:
            fNew.write(line +'\n' )

        line = f2.readline()        # 第n次执行则返回第n行

fNew.close()
# 4 取第一行做为文件名
with open('temp.txt','rU',encoding="UTF-8") as fTemp3:  
    nfn = fTemp3.readline()
nfn = nfn.strip()
nfn +=  '.html'
if os.path.exists(nfn):
    os.remove(nfn)
os.rename('website.html',nfn)



# 5 打开重命名后的文档
import win32api
win32api.ShellExecute(0,'open',nfn,'','',1)


