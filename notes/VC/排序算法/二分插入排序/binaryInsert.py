# 二分法插入排序是在插入排序的基础上，使用二分法查找将元素插入的方法
# 基本原理：（升序）
# 1.将元素依次放入有序序列中
# 2.取出待排序元素，与有序序列的前半段进行比较
# 3.缩小有序序列范围，进一步划分比较，直至范围内仅有1或2个数字
# 4.将插入值与范围进行比较
# 3.重复实现升序
# 实现过程：外层循环控制循环次数，中层循环实现有序排列，内层循环实现查找插入
import random
 
# 生成序列
Range = 10
Length = 5
list = random.sample(range(Range),Length)
print('before sort:',list)
 
# 元素插入
for i in range(1,Length):            #从第2个元素开始，插入到前一部分元素中
    beg,end = 0,i-1                  #定义插入范围
    mid = (beg + end) // 2           #定义二分/中间边界
 
    while beg < end:                #当边界顺序时，进行二分比较
        mid = (beg + end) // 2
        if mid == beg:               #如果中间值与边界相等，则边界已确定，结束二分
            break
        #在确定中间与边界不相等时，对边界继续缩小
        if list[i] == list[mid]:
            break
        elif list[i]<list[mid]:
            end = mid
        else:
            beg = mid
 
    #首先确定是否因为找到同值而提前终止
    if list[i] == list[mid]:
        list.insert(mid, list[i])
        list.pop(i + 1)
    else:
        if beg == end:              #如果范围内仅仅有一个值
            if list[i] < list[beg]:
                list.insert(beg,list[i])
            else:
                list.insert(beg+1, list[i])
            list.pop(i + 1)
        elif beg < end:             #如果范围内有两值
            if list[i] < list[beg]:
                list.insert(beg,list[i])
            elif list[i] < list[end]:
                list.insert(end, list[i])
            else:
                list.insert(end+1, list[i])
            list.pop(i + 1)
        else:
            print("wrong, start at ",beg,', and end with ',end)
 
print('after sort:',list)
