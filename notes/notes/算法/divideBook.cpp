#include <iostream>
using namespace std;

int like[5][5]={
    {0,0,1,1,0},
    {1,1,0,0,1},
    {0,1,1,0,1},
    {1,0,0,1,0},
    {0,1,0,0,1}};

int take[5]={0,0,0,0,0};  // 记录每一本书的分配情况
int n = 0;                // n表示分书方案数

void trynext(int i);

int main()
{
    trynext(0);
    cin.get();
    return 0;
}

void trynext(int i)        // 对第 i 个人进行分配
{
    for(int j=0;j<5;j++)   // 穷举
    {
        if(like[i][j]&&take[j]==0)
        {
            take[j]=i+1;// 把第j本书分配给第i个人
            if(i==4)    // 第5个人分配结束，也即所有的书已经分配完毕，
                        // 可以将方案进行输出
            {
                n++;
                cout<<"分配方案"<<n<<":"<<endl;
                for(int k=0;k<5;k++)
                    cout<<"书本"<<k<<"→"<<static_cast<char>(take[k]+'A'-1)<<endl;
                cout<<endl;
            }
            else
                trynext(i+1);    // 递归，对下一个人进行分配
            take[j]=0;           // 回溯，寻找下一种方案
        }
    }
}
/*
分配方案1:
书本0→B
书本1→C
书本2→A
书本3→D
书本4→E

分配方案2:
书本0→B
书本1→E
书本2→A
书本3→D
书本4→C

分配方案3:
书本0→D
书本1→B
书本2→C
书本3→A
书本4→E

分配方案4:
书本0→D
书本1→E
书本2→C
书本3→A
书本4→B

*/    