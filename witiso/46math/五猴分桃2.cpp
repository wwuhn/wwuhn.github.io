/*
花果山上五猴，一日采摘桃子若干。因天色已晚，相约明日再分。
一猴夜不能寐，起来先尝一桃，再自行将桃分为5份，恰巧均分，并无余数(下同)，取走1份。
其后又有一猴夜不能寐，也来先尝一桃，然后将桃分为5份，取走1份。
5猴都如是行之。
次日清晨，5猴醒来，见桃子仍是一堆，且正好均分，欢天喜地。
问五猴至少采摘桃子多少才能如此进行。
*/
#include<stdio.h>

bool sumDiv(int n) 
{    
    for(int i=0;i<5;i++)  // 顺推
    {  
        if(n%5!=1)
            return false;    
        n=(n-1)/5*4;     // 类型转换 可以写成n=n/5*4
    } 
    return true;  
}
int peaches()
{
    for(int n=1;;n++)    // 枚举
        if(sumDiv(n))      
            return n; 
}

int main()  
{    
    printf("起初的桃子数：%d\n",peaches());  
    getchar();
    return 0;  
} 

int main2()   // 逆推
{
    int start=4,sumEnd=4,monkey=5;
    while (monkey!=0) {
        if (sumEnd%4==0&&sumEnd!=0) {//因为sumEnd必须是4的倍数
            sumEnd=(sumEnd/4)*5+1;
            monkey--;
        }else{
            start+=4;
            sumEnd=start;
            monkey=5;
        }
    }
    printf("原来有 %d 个桃子\n",sumEnd);
    getchar();
    return 0;
}

void main3() // 逆推
{
    int lastPart = 1; // 最后那只猴子拿到的那份桃子数，
    int onePart = 0;  // 通过最后那份桃子推理出第一份的桃子数，
    int count = 1;    // 循环的次数，设置为条件。一共要循环4次
    while(count<5)
    {
        onePart = lastPart; 
        for(int i = 0;i<4;i++)
        {
            int allPeach = onePart*5+1; // 假设第i次桃子的总数 ,从第五次开始
            if(allPeach%4!=0)           // 如果不能整除4就不能推理出上次桃子的份数，
                                        // 叠加桃子数重新开始循环
            {
                lastPart++;
                count = 1;      // 循环计数器次数重置为1
                break;
            }
            onePart=allPeach/4; // 可以求出上次桃子的个数
            count++;            // 叠加计数器
            
        }
    }
    printf("最少有(%d)个桃子",onePart*5+1);
	getchar();
}


int divided(int n, int m)  // 迭代
{
    if(n/5==0 || n%5!=1)
        return 0;
    if(m==1) 
        return 1;
    return divided(n-n/5-1, m-1); // 类型转换n=n-(n-1)/5-1,等同于n=n-n/5-1
    //return divided(n-(n-1)/5-1, m-1);
}

int main4()
{
    int n;
    int m = 5;
    for(n = 1; ; n++)
        if(divided(n,m))
        {
            printf("原来的桃子数：%d\n", n);
            break;
        }
    getchar();
    return 0;
}

int peach_monkey(int start,int sumEnd,int monkey){  // 迭代
    if (monkey==0) {
        return sumEnd;
    }
    else{
        if (sumEnd%4==0&&sumEnd!=0) {
            return peach_monkey(start,(sumEnd/4)*5+1, --monkey);
        }else{
            start+=4;
            return peach_monkey(start, start, 5);
        }
    }
}
int main5() 
{
    printf("原来有桃子%d个",peach_monkey(4,4,5));
    getchar();
    return 0;
}


