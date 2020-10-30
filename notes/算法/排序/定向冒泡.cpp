#include <stdio.h>
#include <stdlib.h>
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果序列在一开始已经大部分排序过的话,会接近O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void CocktailSort(int A[], int n)
{
    int left = 0;                            // 初始化边界
    int right = n - 1;
    while (left < right)
    {
        for (int i = left; i < right; i++)   // 前半轮,将最大元素放到后面
        {
            if (A[i] > A[i + 1])
            {
                Swap(A, i, i + 1);
            }
        }
        right--;
        for (i = right; i > left; i--)   // 后半轮,将最小元素放到前面
        {
            if (A[i - 1] > A[i])
            {
                Swap(A, i - 1, i);
            }
        }
        left++;
    }
}

int main()
{
    int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };   // 从小到大定向冒泡排序
    int n = sizeof(A) / sizeof(int);
    CocktailSort(A, n);
    printf("鸡尾酒排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
	system("pause");
    return 0;
}