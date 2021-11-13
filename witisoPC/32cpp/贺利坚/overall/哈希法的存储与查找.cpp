/*
哈希法的存储与查找
这段代码是典型的用空间换时间的算法，数据与存储其所占空间的下标完全相同。这段代码不具有任何的实用性，
但充分说明了这种思路。

  
*/
#if 1

#include <iostream>
using namespace std;
int search(int h[], int key);
void store(int h[], int data);
int main()
{
    int data[1000]={0};
    int m, n;
    for (int i = 0; i < 6; i++)
    {
        cin>>n;
        store(data, n);
    }
    cin>>m;
    int result = search(data, m);
    if (result)
        cout<<"在数组中找到." <<endl;
    else
        cout<<"没有此数据!"<<endl;
    return 0;
}
int search(int d[], int key)
{
    return d[key];
}
void store(int d[], int n)
{
    d[n]=n;
}

#else
//下面是采用哈希法存储数据并实现查找的示例。
//实现哈希函数用“除法取余法”，解决冲突为“开放地址法”。

#include <iostream>
using namespace std;
int searchHash(int h[], int l, int key);
void insertHash(int h[], int l, int data);
int main()
{
    const int hashLength = 13;//哈希表长度
    int hashTable[hashLength]={0};
    int m, n;
    //创建hash
    for (int i = 0; i < 6; i++)
    {
        cin>>n;
        insertHash(hashTable, hashLength, n);
    }
    cin>>m;
    int result = searchHash(hashTable,hashLength, m);
    if (result != -1)
        cout<<"已经在数组中找到，位置为：" << result<<endl;
    else
        cout<<"没有此原始"<<endl;
    return 0;
}

int searchHash(int h[], int l, int key)
{
    // 哈希函数
    int hashAddress = key % l;
    // 指定hashAdrress对应值存在但不是关键值，则用开放寻址法解决
    while (h[hashAddress] != 0 && h[hashAddress] != key)
    {
        hashAddress = (++hashAddress) % l;
    }
    // 查找到了开放单元，表示查找失败
    if (h[hashAddress] == 0)
        return -1;
    return hashAddress;
}
// 数据插入Hash表
void insertHash(int h[], int l, int data)
{
    // 哈希函数
    int hashAddress = data % l;
    // 如果key存在，则说明已经被别人占用，此时必须解决冲突
    while (h[hashAddress] != 0)
    {
        // 用开放寻址法找到
        hashAddress = (++hashAddress) % l;
    }
    // 将data存入字典中
    h[hashAddress] = data;
}

#endif

#if 0


#endif
/*

*/