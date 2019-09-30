import re
f0 = open('init.txt','w',encoding="UTF-8")
#处理文本中的空格，只要含有“英文+空格+英文”就不处理
re2 =re.compile(r'(第[\s\S]{1,8}[章节回卷])\s*') # 保留章节后的空格
pattern =re.compile(u"[a-zA-Z]+\s+[a-zA-Z]+")
with open('original.txt', 'rU',encoding="UTF-8") as file:
    strs = file.read()
    # entxt = re.findall(pattern,strs)
    entxt = pattern.findall(strs)


if (not entxt):                 # 如果没有“英文 空格 英文”字符
    
    s = re2.sub(r'\1a1b2c3z4', strs)  # 要在处理半角空格前
    s = re.compile(r'([\W])\.').sub(r'\1。',s) # 非数字字母后的.替换为。
    
    s = re.compile(r'(\D)\,').sub(r'\1，',s) # 非数字后的,替换为，
    s = s.replace('!' , '！')
    s = s.replace('?' , '？')
    s = s.replace(' ' , '')      # 处理半角空格（全中文可以使用）
    #s = s.replace('a1b2c3z4',"    ")
    s = re.sub('a1b2c3z4',' ',s)
    
    f0.write(s)
    f0.close()
else:                           # 如果有“英文 空格 英文”字符

    pattern =re.compile(r'([\u4e00-\u9fa5，]{1})\s+([\u4e00-\u9fa5，]{1})')

    with open('original.txt', 'rU',encoding="UTF-8") as f2:
        str = f2.readline()
        
        while str:  	    	    # readline()方法读到最后会返回一个空字符
            s = pattern.sub(r'\1\2', str)
            s = s.strip() + "\n"  # strip()方法会把尾端的\n也去掉
            
            s = re2.sub(r'\1a1b2c3z4', s)  #保留章节后的空格
            # s = s.replace('a1b2c3z4',' ')
            s = re.sub(r'a1b2c3z4',' ',s)
            f0.write(s)
            str = f2.readline()          # readline()方法每次只读取一行
    f0.close()     # 如果不是使用上面的with方法，需要close()后文档才会写入nex.txt
print("txt processed!")

