# 将original.txt的<br />替换为空格，写到temp.txt文件中
f = open('original.txt',encoding='UTF-8')
fTemp = open('temp.txt','w',encoding="UTF-8")
li = f.read()
s = li.replace('　','')
#s = s.replace(' ','')
#s = s.replace('\n\n','a1b2c3z0')
s = s.replace('\n','a1b2c3z0')
s = s.replace('\n','')
s = s.replace('a1b2c3z0','\n')
fTemp.write(s)
f.close()
fTemp.close()

# 覆盖写new.html
fNew = open('new.html','w',encoding="UTF-8")

# 将head.html文件写到new.txt文件中
fHead = open('head.html','r',encoding="UTF-8")
head = fHead.read()
s1 = str(head)
fNew.write(s1)
fHead.close()

# 将txt.txt的每段加<p></p>\n\n，写到temp.txt文件中
fTemp2 = open('temp.txt','r',encoding="UTF-8")
li2 = fTemp2.readlines()
for lines in li2:
    s = lines.replace('\n','')
    s = s.strip()	#会删除掉\n
    s = '<p>' + s + '</p>\n\n'
    fNew.write(s)
fTemp2.close()

# 将head.html文件写到new.txt文件中
fTail = open('tail.html','r',encoding="UTF-8")
tail = fTail.read()
s2 = str(tail)
fNew.write(s2)

fNew.close()
fTail.close()
print("file processed")
