#include <iostream>
using namespace std;
const int MINKEY = 0;  // 假设给定数组中所有数都大于0
const int MAXKEY = 200;// 假设给定数组中所有数都小于200

// 完全二叉树的叶子节点个数比度为2的节点个数多1
void Adjust(int &k, int* &ls, int* &b, int i)
{
    // 控制非叶子结点ls[]的下标
    int t = (i + k) / 2;// 第一个非叶子结点的下标、第二个……
    // 控制叶子结点b[]的下标
    int s = i;
    for (; t > 0; t /= 2){
        if (b[ls[t]]<b[s]){
            swap(s, ls[t]);
        }
        else{
            s = s;
        }
    }
    ls[0] = s;
}
void createLoserTree(int* arr[],int &k, int* &ls, int* &b)
{
    for (int i = 0; i < k; ++i)
        b[i] = arr[i][0];
    b[k] = MINKEY;
    for (i = 0; i < k; ++i)
        ls[i] = k;    //最小值（绝对的胜者）的序号
    //有k个叶子节点
    //从最后一个叶子节点开始，沿着从叶子节点到根节点的路径调整
    for (i = k - 1; i >= 0; --i){
        Adjust(k, ls, b, i);
        for (int i = 0; i < k; ++i)
            cout << ls[i] << " ";
        cout << endl;
    }
}

void kMerge(int* arr[], int* arrayElementsCount, int& k, \
            int* &ls, int* &b, int& mostMinCount)
{
    int* index = new int[k];
    for (int i = 0; i < k; ++i)
        index[i] = 0;
    for (i = 0; i < mostMinCount; ++i){
        int s = ls[0];
        cout << b[s] << " ";
        ++index[s];
        if (index[s] < arrayElementsCount[s])
            arr[s][0] = arr[s][index[s]];
        else
            arr[s][0] = MAXKEY;
        b[s] = arr[s][0];
        Adjust(k, ls, b, s);
    }
    delete[] index;
}

int main()
{
    int arr0[] = { 6, 15, 25 };
    int arr1[] = { 12, 37, 48, 50 };
    int arr2[] = { 10, 15, 16 };
    int arr3[] = { 9, 18, 20 };
    int arr4[] = { 10, 11, 40 };
    int* arr[] = { arr2, arr3, arr4, arr0, arr1 };
    int* arrayElementsCount = new int[5];
    arrayElementsCount[0] = sizeof(arr2) / sizeof(arr2[0]);
    arrayElementsCount[1] = sizeof(arr3) / sizeof(arr3[0]);
    arrayElementsCount[2] = sizeof(arr4) / sizeof(arr4[0]);
    arrayElementsCount[3] = sizeof(arr0) / sizeof(arr0[0]);
    arrayElementsCount[4] = sizeof(arr1) / sizeof(arr1[0]);
    int k = sizeof(arr) / sizeof(arr[0]);
    //记录每个数组的首元素
    int* b = new int[k + 1];
    //记录败者的下标
    int* ls = new int[k];
    createLoserTree(arr, k,ls,b);
    int mostMinCount = 13;
    kMerge(arr, arrayElementsCount, k, ls, b, mostMinCount);
    delete[] b;
    delete[] ls;
    delete[] arrayElementsCount;
    system("pause");
}