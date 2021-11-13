#include  <iostream> //二维数组存取扫雷棋盘
#include <ctime>
#include <cstdlib>
using namespace std;
void setdata(int a[8][8]);      //设置随机数
void out(int a[8][8]);          //输出数组
void outDiagonal(int a[8][8]);  //输出对角线元素的值
void mine(int a[8][8],int x, int y);    //按“扫雷”游戏的规则输出相邻格子
void change(int a[8][8]);               //按要求改变数值
int main()
{
    int a[8][8],x,y;
    setdata(a);
    out(a);
    outDiagonal(a);
    cout<<"输入一个位置:";
    cin>>x>>y;
    mine(a,x,y);
    change(a);
    cout<<"按规则改变后的数组值为:"<<endl;
    out(a);
    while(1);
    return 0;
}


void setdata(int a[8][8])
{
    int i,j;
    srand(time(NULL));//需要用当前时间作“种子”，以便每次运行取得的序列不同
    for(i=0; i<8; i++)
        for(j=0; j<8; j++)
            a[i][j]=rand()%50+1;  //了解rand()函数，请阅读有关系统函数的文档
        return;
}


//按行序优先输出数组
void out(int a[8][8])
{
    int i,j;
    cout<<"按行序输出的二维数组为:"<<endl;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
            cout<<a[i][j]<<'\t';
        cout<<endl;
    }
    cout<<endl;
    return;
}


//输出对角线元素的值（从左上到右下、从右上到左下）
void outDiagonal(int a[8][8])
{
    int i;
    //输出从左上到右下对角线上的元素的值
    cout<<"从左上到右下对角线上的元素的值为："<<endl;
    for(i=0; i<8; i++)
        cout<<a[i][i]<<'\t';   //不必刻意用a[i][j]形式，很麻烦地保持i和j的关系
    cout<<endl;
    //输出从右上到左下对角线上的元素的值
    cout<<"从右上到左下对角线上的元素的值为："<<endl;
    for(i=0; i<8; i++)
        cout<<a[i][7-i]<<'\t';   // a[i][7-i]，斜对角
    cout<<endl;
    cout<<endl;
}


//按扫雷游戏规则，输出a[x][y]周围的8个数字
void mine(int a[8][8],int x, int y)
{
    int i,j,sum=0;
    cout<<"a["<<x<<"]["<<y<<"]周围的数是："<<endl;
    for (i = x - 1; i <= x +1; i++)
    {
        for (j = y - 1; j<= y + 1; j++)
        {
            if ((i>= 0) && (i <= 7) && (j >= 0) && (j <= 7)&& !((i == x ) && (j == y))) //用if中的条件将不可以输出的所有元素“屏蔽”掉，要学会这种简洁的思路，不要一来就一一列举，需要写出很多if语句来完成
            {
                cout<<a[i][j]<<'\t';
                sum+=a[i][j];
            }
        }
    }
    cout<<endl<<"这些数的和是:"<<sum<<endl<<endl;
}


//按题目中所言规则更改元素的值
/*改变的规则是：
从第2行（即a[1]行）开始到最后一行，每一元素是其正上方元素和右上方元素之和，例如
a[1][0]取a[0][0]和a[0][1]之和，
a[1][1]取a[0][1]和a[0][2]之和，……。
对各行最后一列元素，其右上方无数据，取上一行中的第一个元素，如
a[1][7]取a[0][7]和a[0][0]之和。
*/
void change(int a[8][8])
{
    int i,j;
    for(i=1; i<8; i++)
        for(j=0; j<8; j++)
            a[i][j]=a[i-1][j]+a[i-1][(j+1)%8];  //(j+1)%8将使j=7时，访问到a[i][0]元素
        return;
}
