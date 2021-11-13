#include <iostream>
using namespace std;  // 更复杂的表达式，更复杂的迭代关系，更多的迭代变量
int main()
{
    const int n=19;
    int i,a,sign=1;
    double f; 
    f=0;
    a=1;  
    for(i=1;i<=n;i++)
    {
        a=a*i;
        f=f+sign*double(1)/a;  
        sign=-sign;  
    }
    cout<<f<<endl;
    while(1);
    return 0;
}
