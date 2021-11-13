//调用函数printchs输出星号图
#include <iostream>
using namespace std;
//在下面写printchs函数的定义，功能是输出一行若干个指定字符


#include <stdio.h> // 使用函数，二维变一维嵌套
void printchs(int n,char ch)
{
    for(int i=0;i<n;i++)
        printf("%c",ch);
}
int main( )
{ 
    int n=6; //n代表要输出的行数
    int i;
    //通过在下面的循环里调用printchs函数，输出右面的图
    for(i=1; i<=n; ++i)
    {
        printchs(n-i,' ');
        printchs(2*i-1,'*') ;
        cout<<endl;
    }
    while(1);
    return 0;
} 