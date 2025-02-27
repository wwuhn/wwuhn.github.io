#include<iostream>
using namespace std;

// 分类 ------------- 内部非比较排序
// 数据结构 --------- 数组
// 最差时间复杂度 ---- O(nlogn)或O(n^2)，只有一个桶，取决于桶内排序方式
// 最优时间复杂度 ---- O(n)，每个元素占一个桶
// 平均时间复杂度 ---- O(n)，保证各个桶内元素个数均匀即可
// 所需辅助空间 ------ O(n + bn)
// 稳定性 ----------- 稳定

/* 本程序用数组模拟桶 */
const int bn = 5;    
// 这里排序[0,49]的元素，使用5个桶就够了，也可以根据输入动态确定桶的数量
int C[bn];           // 计数数组，存放桶的边界信息

void InsertionSort(int A[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)  
		// 从第二张牌开始抓，直到最后一张牌
    {
        int get = A[i];
        int j = i - 1;
        while (j >= left && A[j] > get)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = get;
    }
}

int MapToBucket(int x)
{
    return x / 10;    
	//映射函数f(x)，作用相当于快排中的Partition，
	//把大量数据分割成基本有序的数据块
}

void CountingSort(int A[], int n)
{
    for (int i = 0; i < bn; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++)     // 使C[i]保存着i号桶中元素的个数
    {
        C[MapToBucket(A[i])]++;
    }
    for (i = 1; i < bn; i++)    
		// 定位桶边界：初始时，C[i]-1为i号桶最后一个元素的位置
    {
        C[i] = C[i] + C[i - 1];
    }
    int *B = (int *)malloc((n) * sizeof(int));
    for (i = n - 1; i >= 0; i--)
		// 从后向前扫描保证计数排序的稳定性(重复元素相对次序不变)
    {
        int b = MapToBucket(A[i]);  // 元素A[i]位于b号桶
        B[--C[b]] = A[i];           
		// 把每个元素A[i]放到它在输出数组B中的正确位置上
        // 桶的边界被更新：C[b]为b号桶第一个元素的位置
    }
    for (i = 0; i < n; i++)
    {
        A[i] = B[i];
    }
    free(B);
}

void BucketSort(int A[], int n)
{
    CountingSort(A, n);          // 利用计数排序确定各个桶的边界（分桶）
    for (int i = 0; i < bn; i++) // 对每一个桶中的元素应用插入排序
    {
        int left = C[i];         // C[i]为i号桶第一个元素的位置
        int right = (i == bn - 1 ? n - 1 : C[i + 1] - 1);
		// C[i+1]-1为i号桶最后一个元素的位置
        if (left < right)        // 对元素个数大于1的桶进行桶内插入排序
            InsertionSort(A, left, right);
    }
}

int main()
{
    int A[] = { 29, 25, 3, 49, 9, 37, 21, 43 };// 针对桶排序设计的输入
    int n = sizeof(A) / sizeof(int);
    BucketSort(A, n);
    printf("桶排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
	cin.get();
    return 0;
}