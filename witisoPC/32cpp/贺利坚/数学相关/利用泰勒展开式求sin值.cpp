#include <iostream>
using namespace std;

const double pi=3.1415926;
double mysin(double x);
double myabs(double x);
int main( )
{
    cout<<"sin(π/2)的值为"<<mysin(pi/2)<<endl;
    cout<<"sin(56°)的值为"<<mysin((56.0/180)*pi)<<endl;
    while(1);
    return 0;
}
//下面定义mysin函数，求sin值            利用泰勒展开式求sin值
double mysin(double x)
{
    double sum=x,x_pow=x,item;
    int n=1,fact=1,sign=1;     //定义变量时赋初值，已经将第一项考虑到累加和sum中
    do
    {
        fact=fact*(n+1)*(n+2);  //fact用于表示阶乘，在公式中作分母
        x_pow*=x*x;             //x_pow是分子中用于表示阶乘，在公式中作分母
        sign=-sign;             //确定即将要累加的这一项的符号
        item =x_pow/fact*sign;  //计算出要累加的项
        sum+=item;              //将该项累加上去
        n+=2;
    }while(myabs(item)>1e-6);
    return sum;
}

//下面定义myabs函数
double myabs(double x)
{
    return ((x>=0)?x:-x);
}