#include<iostream>
using namespace std;

// 分类 ------------- 内部非比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n * dn)
// 最优时间复杂度 ---- O(n * dn)
// 平均时间复杂度 ---- O(n * dn)
// 所需辅助空间 ------ O(n * dn)
// 稳定性 ----------- 稳定

const int dn = 3;                // 待排序的元素为三位数及以下
const int k = 10;                
// 基数为10，每一位的数字都是[0,9]内的整数
int C[k];

int GetDigit(int x, int d)          // 获得元素x的第d位数字
{
    int radix[] = { 1, 1, 10, 100 };
	// 最大为三位数，所以这里只要到百位就满足了
    return (x / radix[d]) % 10;
}

void CountingSort(int A[], int n, int d)
	// 依据元素的第d位数字，对A数组进行计数排序
{
    for (int i = 0; i < k; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        C[GetDigit(A[i], d)]++;
    }
    for (i = 1; i < k; i++)
    {
        C[i] = C[i] + C[i - 1];
    }
    int *B = (int*)malloc(n * sizeof(int));
    for (i = n - 1; i >= 0; i--)
    {
        int dight = GetDigit(A[i], d);  
		// 元素A[i]当前位数字为dight   
        B[--C[dight]] = A[i];           
// 根据当前位数字，把每个元素A[i]放到它在输出数组B中的正确位置上
		// 当再遇到当前位数字同为dight的元素时，会将其放在
		//当前元素的前一个位置上保证计数排序的稳定性
    }
    for (i = 0; i < n; i++)
    {
        A[i] = B[i];
    }
    free(B);
}

void LsdRadixSort(int A[], int n)// 最低位优先基数排序
{
    for (int d = 1; d <= dn; d++)// 从低位到高位
        CountingSort(A, n, d);   // 依据第d位数字对A进行计数排序
}

int main()
{
    int A[] = { 329, 457, 657, 839, 436, 720, 355 };
	// 针对基数排序设计的输入
    int n = sizeof(A) / sizeof(int);
    LsdRadixSort(A, n);
    printf("基数排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
	cin.get();
    return 0;
}