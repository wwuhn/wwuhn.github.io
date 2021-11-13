#include<iostream>  // 数论的正整数类
#include<Cmath>
using namespace std;
class NaturalNumber
{
private:
    int n; 
public:
    void setValue (int x);  //置数据成员n的值，要求判断是否是正整数
    int getValue();         //返回私有数据成员n的值
    bool isPrime();         //判断数据成员n是否为素数，是返回true，否则返回false
    void printFactor();     //输出数据成员n的所有因子，包括和n自身
    bool isPerfect();       //判断数据成员n是否为完全数。若一个正整数n的所有小于n的因子之和等于n, 则称n为完全数, 如=1+2+3是完全数。
    bool isReverse(int x);  //判断形式参数x是否为数据成员n的逆向数（例是的逆向数）。
    bool isDaffodil(int x); //判断形式参数x是否是水仙花数。水仙花数的各位数字立方和等于该数，如=1*1*1+5*5*5+3*3*3
    void printDaffodils();  //显示所有大于，且小于数据成员n的水仙花数；
};

void main(void)
{
    NaturalNumber nn;	//定义类的一个实例（对象）
    nn.setValue (6);
    cout<<nn.getValue()<<(nn.isPrime()?"是":"不是")<<"素数" <<endl;
    
    nn.setValue (37); 
    cout<<nn.getValue()<<(nn.isPrime()?"是":"不是")<<"素数" <<endl;
    
    nn.setValue (84); 
    cout<<nn.getValue()<<"的因子有：";
    nn.printFactor();
    
    nn.setValue (29); 
    cout<<nn.getValue()<<"的因子有：";
    nn.printFactor();
    
    nn.setValue (6);
    cout<<nn.getValue()<<(nn.isPerfect()?"是":"不是")<<"完全数" <<endl;
    
    nn.setValue (37); 
    cout<<nn.getValue()<<(nn.isPerfect()?"是":"不是")<<"完全数" <<endl;
    
    nn.setValue (1237); 
    int x=732;
    cout<<nn.getValue()<<" 和"<<x<<" "<<(nn.isReverse(x)?"是":"不是")<<"逆向数" <<endl;
    
    cout<<"所有大于，且小于数据成员"<<nn.getValue()<<" 的水仙花数有：";
    nn.printDaffodils(); 
    
    system("PAUSE");
}

//请在下面定义类中的各个成员函数
void NaturalNumber::setValue (int x)    //置数据成员n的值，要求判断是否是正整数
{
    n=x;
}

int NaturalNumber::getValue()           //返回私有数据成员n的值
{
    return n;
}

bool NaturalNumber::isPrime()//判断数据成员n是否为素数，是返回true，否则返回false
{
    bool prime=true;
    for(int i=2;i<=sqrt(double(n));i++)
    {
        if(n%i==0) 
        {
            prime=false;
            break;
        }
    }
    return prime;
}

void NaturalNumber::printFactor()  //输出数据成员n的所有因子，包括和n自身
{
    for(int i=1;i<=n;i++)
        if(n%i==0) cout<<i<<' ';
        cout<<endl;
}

bool NaturalNumber::isPerfect() //判断数据成员n是否为完全数。若一个正整数n的所有小于n的因子之和等于n, 则称n为完全数, 如=1+2+3是完全数。
{
    bool perfect=false;
    int s=1;
    for(int i=2;i<n;i++)
        if(n%i==0) 
            s=s+i;
        if(n==s) 
            perfect=true;
    return perfect;
}

bool NaturalNumber::isReverse(int x)//判断形式参数x是否为数据成员n的逆向数（例是的逆向数）。
{
    bool reverse=false;
    int s=0;
    while(x>0)
    {
        s=s*10+x%10;
        x=x/10;
    }
    if(n==s) reverse=true;
    return reverse;
}

bool NaturalNumber::isDaffodil(int x) //判断形式参数x是否是水仙花数。水仙花数的各位数字立方和等于该数，如=1*1*1+5*5*5+3*3*3
{
    bool daffodil=false;
    int s=0,p=x;
    int m;
    while(p>0)
    {
        m=p%10;
        s=s+m*m*m;
        p=p/10;
    }
    if(x==s) daffodil=true;
    return daffodil;
}

void NaturalNumber::printDaffodils() //显示所有大于，且小于数据成员n的水仙花数；
{
    for(int i=2;i<n;++i)
        if(isDaffodil(i)) cout<<i<<" ";
        cout<<endl;
        return;
}