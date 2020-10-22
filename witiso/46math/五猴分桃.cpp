/*
花果山上五猴，一日采摘桃子若干。因天色已晚，相约明日再分。
一猴夜不能寐，起来先尝一桃，再自行将桃分为5份，恰巧均分，并无余数(下同)，取走1份。
其后又有一猴夜不能寐，也来先尝一桃，然后将桃分为5份，取走1份。
5猴都如是行之。
次日清晨，5猴醒来，见桃子仍是一堆，且正好均分，欢天喜地。
问五猴至少采摘桃子多少才能如此进行。
*/
#include<stdio.h>

int divided(int n, int m)
{
    if(n/5==0 || n%5!=1)
        return 0;
    if(m==1) 
        return 1;
    return divided(n-n/5-1, m-1); // 类型转换n=n-(n-1)/5-1,等同于n=n-n/5-1
    //return divided(n-(n-1)/5-1, m-1);
}

int main1()
{
    int n;
    int m = 5;
    for(n = 1; ; n++)
        if(divided(n,m))
        {
            printf("1st %d\n", n);
            break;
        }
    getchar();
    return 0;
}


bool sumDiv(int n) 
{    
    for(int i=0;i<5;i++)  // 顺推4次
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

void main3()
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
}

#include <iostream>
#include <string>
using namespace std;

void main4(void)
{ 
    int peach=1;
    for (int i=1; ;i++)
    {
        if(i%5==1)    
            peach=(i-1)/5*4;
        if (peach%5==1)
            peach=(peach-1)/5*4;
        if (peach%5==1)
            peach=(peach-1)/5*4;
        if (peach%5==1)
            peach=(peach-1)/5*4;
        if (peach%5==1)
        {
            cout<<i<<endl;
            break;
        }
    }
}

void main5() 
{       
    int i,m,j,k,count;
    for(i=4;i<10000;i+=4)  // i是第5只猴子拿后的桃子数
    {
        count=0;
        m=i;               // m借助的一个中间变量，用于恢复i的值
        for(k=0;k<5;k++)   // 当k=3时，是第一只猴子拿完桃子后，此时的j能被4整除，
                           // 当k=4时，此时的j 值不一定能被4整除
        {
            j=i/4*5+1; 
            i=j;
            
            if(j%4==0)     // 由于每次拿完桃子后剩下的都是4份啊
                count++;
            else
                break;
        }
        i=m;             //恢复i的值
        if(count==4)
        {
            printf("%d\n",j);
            break;
        }
        
    }
}

int peach_monkey(int start,int sumEnd,int monkey){
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
int main6() 
{
    printf("原来有%d个桃子",peach_monkey(4,4,5));
    getchar();
    return 0;
}


int main7() 
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

//////////////////////////////////////////////////////////////////////////////////////////////////////
//  五只猴子分桃。半夜，第一只猴子先起来，它把桃分成了相等的五堆，多出一只。
//  于是，它吃掉了一个，拿走了一堆； 第二只猴子起来一看，只有四堆桃。
//  于是把四堆合在一起，分成相等的五堆，又多出一个。于是，它也吃掉了一个，拿走了一堆；.....
//  其他几只猴子也都是 这样分的。
//  问：这堆桃至少有多少个？ (3121)
//
//  @编译环境：Dev c++ 5.11 
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//  函数声明
int CalcuCount( int n ); 

int main8() 
{
    int sum = CalcuCount(5);
    printf("%d \n" , sum);

    return 0;
}

int CalcuCount( int n )
{
    if ( n <= 1 || n >= 9 )
        return -1;
    int base = n + 1;
    int sum = base;
    int i = 0;

    while ( 1 )
    {
        sum = base;
        for ( i = 0; i < n ; ++i)
        {
            if ( (sum-1) % n == 0 && sum%(n-1) == 0 )
                sum = (sum/(n-1))*n + 1;
            else
                break;
        }
        if (n-1 == i && sum > 0)
            break;
        base += n;
    }
    return sum;
}


#include<stdio.h>
#include<math.h>
int main9()
{
    int n,i;
    n=5;

    int s,a,b=0,p;
    s=pow(5,n)-4;
    p=s;
    for(i=1; i<=n; i++)
    {
        a=(p-1)/5;
        p=p-1-a;
        b=b+a;
    }
    printf("%d %d\n",s,s-b);

    return 0;
}
 
#include<stdio.h>
int main11()
{
    for(int i=1;;i++)
    {
        double a=i;
        for(int j=1;j<=5;j++)
            a=(a-1)*4/5;
        int b=(int)a;
        if(b==a)
        {
            printf("%d %.0lf\n",i,a);
            break;
        }
    }
    getchar();
    return 0;
}