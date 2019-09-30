# 将original.txt的<br />替换为空格，写到temp.txt文件中
f = open('original.txt','rU',encoding='UTF-8')
fTemp = open('temp.txt','w',encoding="UTF-8")
s = f.read()        	    	# 返回一个字符串

s = s.replace('　','')          # 处理全角空格
#s = s.replace(' ','')           # 处理半角空格（全中文可以使用）
s = s.replace('\n\n','\n')      # 处理段落没有问题的文本
'''
#处理用空行分段的文本（不是空格的段落合并）
s = s.replace('\n\n','a1b2c3z0')# 用'a1b2c3z0'作段落标记
s = s.replace('\n','')
s = s.replace('a1b2c3z0','\n')
'''
fTemp.write(s)
f.close()
fTemp.close()

# 'w'覆盖写new.html，'a'为追加写
fNew = open('new.html','w',encoding="UTF-8")

# 将head.html文件写到new.txt文件中
with open('head.html','rU',encoding="UTF-8") as head:
    line = head.readline()      # 返回单行（段落）string
    while line:
        fNew.write(line)
        line = head.readline()
    #fNew.write(head.read())

# 将txt.txt的每段加<p></p>\n\n，写到temp.txt文件中
fTemp2 = open('temp.txt','rU',encoding="UTF-8")
countLines = countChars = 0
for lines in fTemp2.readlines():    # 返回一个列表list,元素为行
    countLines += 1
    countChars += len(lines)
    s = lines.replace('\n','')
    s = s.strip()	    	    # 会删除掉\n
    s = '<p>' + s + '</p>\n\n'
    fNew.write(s)

fNew.write("\n\n本页共")
fNew.write(str(countLines))
fNew.write("段，")
fNew.write(str(countChars))
fNew.write("个字符。")
fTemp2.close()

# 将footer.html文件写到new.txt文件中
ffooter = open('footer.html','r',encoding="UTF-8")
fNew.write(ffooter.read())

fNew.close()
ffooter.close()
print(countLines,"lines and",countChars,"chars.")
