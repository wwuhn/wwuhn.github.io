#if 0
#include <stdio.h>  
#include <stdlib.h>  
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 根据步长序列的不同而不同。已知最好的为O(n(logn)^2)
// 最优时间复杂度 ---- O(n)
// 平均时间复杂度 ---- 根据步长序列的不同而不同。
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定
void output(int a[], int n){ //输出数组元素
	for(int i = 0; i<n;++i)
		printf("%2d ",a[i]);
	printf("\n");
}
void ShellSort(int A[], int n)
{
    int h = 0;
    while (h <= n)                          // 生成初始增量
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < n; i++)
        {
            int j = i - h;
            int get = A[i];
            while (j >= 0 && A[j] > get)
            {
                A[j + h] = A[j];
                j = j - h;
            }
            A[j + h] = get;
			printf("gap%2d：\n",h);
			output(A,n);
        }
        h = (h - 1) / 3;                    // 递减增量
    }
}

int main()
{
	int A[] = { 15, 17, 10, 4, 8, 6, 1, 3, 7, 0, 14, 11,5, 12, 2, 9 };
	
    int n = sizeof(A) / sizeof(A[0]);
    for(int i =1;i<=n;++i)
		printf("%2d ",i);
	printf("\n");
	output(A,n);
    ShellSort(A, n);
    printf("\n");
	system("pause");
    return 0;
}
#endif

#if 1  //调试版，可将相关的输出注释掉，这样在做F11逐步调试时，避免干扰
//调试细节：在函数开始处插入断点，按F11逐步运行
// 打开variable、watch调试窗口，在watch中输入需要调试的变量，如a[j+r]
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13
void ShellSort(int* a, int len)
{
	int j,temp;
	int x=0; //中间步骤数量
	for(int r=len/2; r>=1; r/=2) // 分组数量：n/2、n/4、n/8…，相邻两组元素分别比较
	{
		for(int i=r; i<len; i++)
		{
			temp = a[i];
			j=i-r;
			while(j>=0 && temp < a[j])
			{
				a[j+r] = a[j];
				j-=r;//按条件回溯到前面的组（非相邻组）对应的元素
			}
			a[j+r] = temp;//下标=j+r=i（无交换）或i-nr(有交换)
		}
		x++;
		//printf("第%d步排序结果（r=%d）：",x,r);
		//for(int h=0; h<len; h++)
		//{
			//printf("%d ",a[h]);
		//}
		//printf("\n");
	}
}

void main()
{
	int i;
	int arr[SIZE]={107,117,106,129,116,123,111,110,127,119,103,107,114};

	//srand(time(0));
	//for(i=0; i<SIZE; i++)
		//arr[i] = rand()/1000 + 100;

	//printf("排序前：\n");
	//for(i=0; i<SIZE; i++)
		//printf("%d ", arr[i]);
	//printf("\n");

	ShellSort(arr,SIZE);
	printf("排序后：\n");
	for(i=0; i<SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
}
/*
排序前：
						 107 117 106 129 116 123 111 110 127 119 103 107 114
第1步排序结果（r=6）：107 110 106 119 103 107 111 117 127 129 116 123 114

第2步排序结果（r=3）：107 103 106 111 110 107 114 116 123 119 117 127 129
第3步排序结果（r=1）：103 106 107 107 110 111 114 116 117 119 123 127 129
排序后：
103 106 107 107 110 111 114 116 117 119 123 127 129
*/
#endif


#if 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13

void ShellSort(int* a, int len)
{
	int j,temp;
	int x=0;						// 中间步骤数量
	for(int r=len/2; r>=1; r/=2)	// 分组数量：n/2、n/4、n/8…，
									// 相邻两组元素分别比较
	{
		for(int i=r; i<len; i++)
		{
			temp = a[i];
			j=i-r;
			while(j>=0 && temp < a[j])
			{
				a[j+r] = a[j];
				j-=r; // 按条件回溯到前面的组（非相邻组）对应的元素
			}
			a[j+r] = temp; // 下标=j+r=i（无交换）或i-nr(有交换)
		}
		x++;
		printf("第%d步排序结果（r=%d）：",x,r);
		for(int h=0; h<len; h++)
		{
			printf("%d ",a[h]);
		}
		printf("\n");
	}
}

void main()
{
	int i;
	int arr[SIZE];

	srand(time(0));
	for(i=0; i<SIZE; i++)
		arr[i] = rand()/1000 + 100;

	printf("排序前：\n");
	for(i=0; i<SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	ShellSort(arr,SIZE);
	printf("排序后：\n");
	for(i=0; i<SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
}
/*
排序前：
					  107 117 106 129 116 123 111 110 127 119 103 107 114
第1步排序结果（r=6）：107 110 106 119 103 107 111 117 127 129 116 123 114

第2步排序结果（r=3）：107 103 106 111 110 107 114 116 123 119 117 127 129
第3步排序结果（r=1）：103 106 107 107 110 111 114 116 117 119 123 127 129
排序后：
103 106 107 107 110 111 114 116 117 119 123 127 129
*/
#endif