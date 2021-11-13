#include<stdio.h>//快速排序递归实现
void quicksort(int data[],int first,int last)
{
    int i, j, t, base;
    if (first>last)
        return;
    base=data[first];               /*用首元素作为基数*/
    i=first;
    j=last;
    while(i!=j)                     /*重复下面的过程，直到i和j相遇*/
    {
        while(data[j]>=base && i<j)  /*j从右向左，找到小于基数的元素*/
            j--;
        while(data[i]<=base && i<j)  /*i从左向右，找到大于基数的元素*/
            i++;
        /*当i和j没有相遇有时候，交换两个数*/
        if(i<j)
        {
            t=data[i];
            data[i]=data[j];
            data[j]=t;
        }
    }
    data[first]=data[i];        /*将i,j相遇处的值保存在基数位置*/
    data[i]=base;               /*将基数保存在其应该的位置*/
    quicksort(data,first,i-1);  /*用同样的策略，递归处理左边的部分*/
    quicksort(data,i+1,last);   /*用同样的策略，递归处理右边的部分*/
}

int main( )
{
    int data[10] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    quicksort(data, 0,9);
    int i;
    for(i=0; i<10; i++)
        printf("%d ", data[i]);
    printf("\n");
    return 0;
}