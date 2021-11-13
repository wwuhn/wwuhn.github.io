#include <iostream>
using namespace std;  // 分数类中的运算符重载
class CFraction
{
private:
    int nume;  // 分子
    int deno;  // 分母
public:
    CFraction(int nu=0,int de=1):nume(nu),deno(de){}
    void simplify();
    void display();
    CFraction operator+(const CFraction &c);  //两个分数相加，结果要化简
    CFraction operator-(const CFraction &c);  //两个分数相减，结果要化简
    CFraction operator*(const CFraction &c);  //两个分数相乘，结果要化简
    CFraction operator/(const CFraction &c);  //两个分数相除，结果要化简
    CFraction operator+();  //取正一目运算
    CFraction operator-();  //取反一目运算
    bool operator>(const CFraction &c);
    bool operator<(const CFraction &c);
    bool operator==(const CFraction &c);
    bool operator!=(const CFraction &c);
    bool operator>=(const CFraction &c);
    bool operator<=(const CFraction &c);
};

// 分数化简
void CFraction::simplify()
{
    int m,n,r;
    n=abs(deno);
    m=abs(nume);
    while(r=m%n)  // 求m，n的最大公约数
    {
        m=n;
        n=r;
    }
    deno/=n;     // 化简
    nume/=n;
    if (deno<0)  // 将分母转化为正数
    {
        deno=-deno;
        nume=-nume;
    }
}

//显示分数
void CFraction::display()
{
    cout<<"("<<nume<<"/"<<deno<<")"<<endl;
}

// 分数相加
CFraction CFraction::operator+(const CFraction &c)
{
    CFraction t;
    t.nume=nume*c.deno+c.nume*deno;
    t.deno=deno*c.deno;
    t.simplify();
    return t;
}

// 分数相减
CFraction CFraction:: operator-(const CFraction &c)
{
    CFraction t;
    t.nume=nume*c.deno-c.nume*deno;
    t.deno=deno*c.deno;
    t.simplify();
    return t;
}

// 分数相乘
CFraction CFraction:: operator*(const CFraction &c)
{
    CFraction t;
    t.nume=nume*c.nume;
    t.deno=deno*c.deno;
    t.simplify();
    return t;
}

// 分数相除
CFraction CFraction:: operator/(const CFraction &c)
{
    CFraction t;
    if (!c.nume) return *this;   //除法无效（除数为0）时，这种情况需要考虑，但这种处理仍不算合理
    t.nume=nume*c.deno;
    t.deno=deno*c.nume;
    t.simplify();
    return t;
}

// 分数取正号
CFraction CFraction:: operator+()
{
    return *this;
}

// 分数取负号
CFraction CFraction:: operator-()
{
    CFraction x;
    x.nume=-nume;
    x.deno=deno;   //我在这儿出现了逻辑错误，nume取负了，deno就不用取负了。谢谢马琳指出
    return x;     
}

// 分数比较大小
bool CFraction::operator>(const CFraction &c)
{
    int this_nume,c_nume,common_deno;
    this_nume=nume*c.deno;        // 计算分数通分后的分子，同分母为deno*c.deno
    c_nume=c.nume*deno; 
    common_deno=deno*c.deno;
    //if (this_nume>c_nume) return true; 无法应对common_deno<0的情形
    //下面的语句更简练的一种写法if ((this_nume-c_nume)*common_deno>0) return true;
    if (this_nume>c_nume&&common_deno>0||this_nume<c_nume&&common_deno<0) 
        return true; // 将通分后的分子比较大小
    return false;
}//其他方法：郭岩岩同学指出：为什么在比较大小的时候不能用两个分数直接做差判断是否大于零啊？
// 我回答：“你的想法灰常好，可以这样做”

// 分数比较大小
bool CFraction::operator<(const CFraction &c)
{
    int this_nume,c_nume,common_deno;
    this_nume=nume*c.deno;      
    c_nume=c.nume*deno;
    common_deno=deno*c.deno;
    if ((this_nume-c_nume)*common_deno<0) return true; 
    return false;
}

// 分数比较大小
bool CFraction::operator==(const CFraction &c)
{
    if (*this!=c) return false;
    return true;
}

// 分数比较大小
bool CFraction::operator!=(const CFraction &c)
{
    if (*this>c || *this<c) return true;
    return false;
}

// 分数比较大小
bool CFraction::operator>=(const CFraction &c)
{
    if (*this<c) return false;
    return true;
}

// 分数比较大小
bool CFraction::operator<=(const CFraction &c)
{
    if (*this>c) return false;
    return true;
}

int main()
{
    CFraction x(1,3),y(-5,10),s;
    cout<<"分数x=1/3      y=-5/10"<<endl;
    s=+x+y;
    cout<<"+x+y=";
    s.display();
    s=x-y;
    cout<<"x-y=";
    s.display();
    s=x*y;
    cout<<"x*y=";
    s.display();
    s=x/y;
    cout<<"x/y=";
    s.display();
    s=-x+y;
    cout<<"-x+y=";
    s.display();
    
    x.display();
    if (x>y) cout<<"大于"<<endl;
    if (x<y) cout<<"小于"<<endl;
    if (x==y) cout<<"等于"<<endl;
    y.display();
    cout<<endl;
    system("pause");
    return 0;
}