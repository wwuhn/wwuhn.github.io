#include <iostream>         // 数组排序指针版
using namespace std;
void sort(int *p, int num);  //不要对自定义函数的声明有任何改动
void output(int*, int);

int main( )                 //不要对main函数有任何改动
{
    int a[20]={86,46,22,18,77,45,32,80,26,88,57,67,20,18,28,17,54,49,11,16};
    int b[15]={27,61,49,88,4,20,28,31,42,62,64,14,88,27,73};
    sort(a,20);     //用冒泡法按降序排序a中元素
    output(a,20);   //输出排序后的数组
    sort(b,15);     //用冒泡法按降序排序b中元素
    output(b,15);   //输出排序后的数组
    return 0;
}
//下面定义自定义函数
void sort(int *p, int num)
{
    int i,j,t;
    for(j=0;j<num-1;j++)            //共进行num-1趟比较
    {
        for(i=0;i<num-j-1;i++)      //在每趟中要进行num-j次两两比较
        {
            if(*(p+i)<*(p+i+1))     //如果前面的数小于后面的数
            {
                t=*(p+i);           //交换两个数的位置，使小数下沉
                *(p+i)=*(p+i+1);
                *(p+i+1)=t;
            }
        }
    }
    return;
}

void output(int *p, int num)
{
    int i;
    for(i=0;i<num-1;i++)
        cout<<*(p+i)<<",";
    cout<<*(p+num-1)<<"\n"; //最后一个数后面不加逗号，看得更舒服
    return;
}