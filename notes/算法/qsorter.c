/* qsorter.c -- using qsort to sort groups of numbers */
#include <stdio.h>
#include <stdlib.h>

#define NUM 40
void fillarray(double ar[], int n);
void showarray(const double ar[], int n);
int mycomp(const void * p1, const void * p2);
/*
void qsort(
		   void *base, 
		   size_t nitems, 
		   size_t size, 
		   int (*compar)(const void *, const void*))
参数
void *base：类型为void*，相当于泛型，指向要排序的数组的第一个元素的指针。
nitems：数组中元素的个数在数组指针只无法内含，需要另外的参数提供。
size：因为数据指针提供的是void*类型，需要另外的参数来提供数组中每个元素的大小，以字节为单位。
compar：注意元素的类型是void*，可以是各种基本类型及字符串，结构体的某个关键字，
//用来比较两个元素的函数，即函数指针（回调函数）

*/

int main(void)
{
    double vals[NUM];
    fillarray(vals, NUM);
    puts("Random list:");
    showarray(vals, NUM);
    qsort(
		vals, 
		NUM, 
		sizeof(double), 
		mycomp);
    puts("\nSorted list:");
    showarray(vals, NUM);
	system("pause");
    return 0;
}

void fillarray(double ar[], int n)
{
    int index;
    
    for( index = 0; index < n; index++)
        ar[index] = (double)rand()/((double) rand() + 0.1);
}

void showarray(const double ar[], int n)
{
    int index;
    
    for( index = 0; index < n; index++)
    {
        printf("%9.4f ", ar[index]);
        if (index % 6 == 5)
            putchar('\n');
    }
    if (index % 6 != 0)
        putchar('\n');
}

/* sort by increasing value */
int mycomp(const void * p1, const void * p2)
{
    /* need to use pointers to double to access values   */
    const double * a1 = (const double *) p1;
    const double * a2 = (const double *) p2;
	return *(int*)a-*(int*)b;   
    if (*a1 < *a2)
        return -1;
    else if (*a1 == *a2)
        return 0;
    else
        return 1;
}
