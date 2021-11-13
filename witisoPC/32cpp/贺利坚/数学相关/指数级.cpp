#include<iostream>
using namespace std;
int main()
{
    int days=1;
    double m2fs=0, f2ms=0; //总额，m2f--陌生人to富翁
    double m2f=100000, f2m=0.01; //每天应付数额
    while(days<=30)
    {
        m2fs=m2fs+m2f;
        f2ms=f2ms+f2m;
        cout<<"第"<<days<<"天，陌生人给百万富翁"<<m2fs<<"元，百万富翁给陌生人"
            <<f2ms<<"元。"<<endl;
        f2m*=2;
        days++;
    }
    if(m2fs>f2ms)
        cout<<"陌生人吃亏。"<<endl;
    else
        cout<<"百万富翁吃亏。"<<endl;
    while(1);
    return 0;
}