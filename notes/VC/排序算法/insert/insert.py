import random
Range = 100
Length = 5
list = random.sample(range(Range),Length)    
#在指定序列中随机获取指定长度片段
print('before sort:',list)
for i in range(1,Length):                   #默认第一个元素已经在有序序列中，从后面元素开始插入    
    for j in range(i,0,-1):                 
	#逆向遍历比较，交换位置实现插入        
        if list[j] < list[j-1]:            
            list[j],list[j-1] = list[j-1],list[j]
print('after sort:',list)

