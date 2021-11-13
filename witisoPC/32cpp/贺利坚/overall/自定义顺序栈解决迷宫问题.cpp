#include <iostream> // 自定义顺序栈解决迷宫问题
#include <iomanip>
#include <cstdlib>
using namespace std;
 
#define MaxSize 100
int maze[10][10] =   //定义一个迷宫，0表示通道，1表示墙
{
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};
 
struct Try //定义一个栈，保存路径
{
    int i;               //当前方块的行号
    int j;               //当前广场的列号
    int d;               //di是下一可走方位的方位号
} path[MaxSize];         //定义栈
 
int top = -1;            //初始化栈指针
 
void findPath(int xb, int yb, int xe, int ye)          //路径为从(xb,yb)到(xe,ye)
{
    int i, j, d, find, k;
    top++;                                             //初始方块进栈
    path[top].i = xb;
    path[top].j = yb;
    path[top].d = -1;
    maze[xb][yb] = -1;
    while(top>-1)                                      //栈不为空时循环
    {
        i = path[top].i;
        j = path[top].j;
        d = path[top].d;
        if(i==xe && j==ye)                             //找到了出口，输出路径
        {
            cout << "迷宫路径如下：\n";
            for(k=0; k<=top; k++)
            {
                cout << "\t(" << path[k].i << "," << path[k].j << ")";
                if((k+1)%5==0) cout << endl;            //每输出五个方块后换一行
            }
            cout << endl;
            return;
        }
        find = 0;
        while(d<4 && find==0)                          //找下一个可走的点
        {
            d++;
            switch(d)
            {
            case 0:  //向上
                i = path[top].i-1;
                j = path[top].j;
                break;
            case 1: //向右
                i = path[top].i;
                j = path[top].j+1;
                break;
            case 2:  //向下
                i = path[top].i+1;
                j = path[top].j;
                break;
            case 3:  //向左
                i = path[top].i;
                j = path[top].j-1;
                break;
            }
            if(maze[i][j]==0) find = 1;                    //找到通路
        }
        if(find==1)                                        //找到了下一个可走方块
        {
            path[top].d = d;                               //修改原栈顶元素的d值
            top++;                                         //下一个可走方块进栈
            path[top].i = i;
            path[top].j = j;
            path[top].d = -1;
            maze[i][j] = -1;                                 //避免重复走到这个方块
            //cout << "\t(" << path[top].i << "," << path[top].j << ")"; //显示经过的试探
        }
        else  //没有路可走，则退栈
        {
            maze[path[top].i][path[top].j] = 0;                  //让该位置变成其它路径可走方块
            top--;
        }
    }
    cout << "没有可走路径！\n";
}
 
int main()
{
    findPath(1,1,8,8);  //从(1,1)入，(8,8)出
    while(1);
    return 0;
}