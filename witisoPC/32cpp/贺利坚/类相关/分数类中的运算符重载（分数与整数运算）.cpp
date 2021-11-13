#include <iostream>
using namespace std; // 分数类中的运算符重载（分数与整数运算）
class CFraction
{
private:
    int nume;  // 分子
    int deno;  // 分母
public:
    CFraction(int nu=0,int de=1):nume(nu),deno(de){}
    void simplify();
    void display();
    
    friend CFraction operator+(const CFraction &c1, const CFraction &c2);  //两个分数相加，结果要化简
    friend CFraction operator-(const CFraction &c1, const CFraction &c2);  //两个分数相减，结果要化简
    friend CFraction operator*(const CFraction &c1, const CFraction &c2);  //两个分数相乘，结果要化简
    friend CFraction operator/(const CFraction &c1, const CFraction &c2);  //两个分数相除，结果要化简
    
    friend CFraction operator+(const CFraction &c, int i);  
    friend CFraction operator+(int i, const CFraction &c );  
    friend CFraction operator-(const CFraction &c, int i);  
    friend CFraction operator-(int i, const CFraction &c );  
    friend CFraction operator*(const CFraction &c, int i);  
    friend CFraction operator*(int i, const CFraction &c );  
    friend CFraction operator/(const CFraction &c, int i);  
    friend CFraction operator/(int i, const CFraction &c );  
    
    CFraction operator+();  //取正一目运算
    CFraction operator-();  //取反一目运算
    
    friend bool operator>(const CFraction &c1, const CFraction &c2);
    friend bool operator<(const CFraction &c1, const CFraction &c2);
    friend bool operator==(const CFraction &c1, const CFraction &c2);
    friend bool operator!=(const CFraction &c1, const CFraction &c2);
    friend bool operator>=(const CFraction &c1, const CFraction &c2);
    friend bool operator<=(const CFraction &c1, const CFraction &c2);
    
    friend bool operator>(const CFraction &c, int i);
    friend bool operator>(int i, const CFraction &c);
    friend bool operator<(const CFraction &c, int i);
    friend bool operator<(int i, const CFraction &c);	
    friend bool operator==(const CFraction &c, int i);
    friend bool operator==(int i, const CFraction &c);	
    friend bool operator!=(const CFraction &c, int i);
    friend bool operator!=(int i, const CFraction &c);
    friend bool operator>=(const CFraction &c, int i);
    friend bool operator>=(int i, const CFraction &c);
    friend bool operator<=(const CFraction &c, int i);
    friend bool operator<=(int i, const CFraction &c);
};

// 分数化简
void CFraction::simplify()
{
    int m,n,r;
    m=abs(deno);
    n=abs(nume);
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
CFraction operator+(const CFraction &c1, const CFraction &c2)
{
    CFraction t;
    t.nume=c1.nume*c2.deno+c2.nume*c1.deno;
    t.deno=c1.deno*c2.deno;
    t.simplify();
    return t;
}

// 分数相减
CFraction operator-(const CFraction &c1, const CFraction &c2)
{
    CFraction t;
    t.nume=c1.nume*c2.deno-c2.nume*c1.deno;
    t.deno=c1.deno*c2.deno;
    t.simplify();
    return t;
}

// 分数相乘
CFraction operator*(const CFraction &c1, const CFraction &c2)
{
    CFraction t;
    t.nume=c1.nume*c2.nume;
    t.deno=c1.deno*c2.deno;
    t.simplify();
    return t;
}

// 分数相除
CFraction operator/(const CFraction &c1, const CFraction &c2)
{
    CFraction t;
    if (!c2.nume) return c1;
    t.nume=c1.nume*c2.deno;
    t.deno=c1.deno*c2.nume;
    t.simplify();
    return t;
}

CFraction operator+(const CFraction &c, int i)
{
    CFraction c1(c.nume+i*c.deno,c.deno);
    c1.simplify();
    return c1;
}

CFraction operator+(int i, const CFraction &c )
{
    CFraction c1(c.nume+i*c.deno,c.deno);
    c1.simplify();
    return c1;
}

CFraction operator-(const CFraction &c, int i)  
{
    CFraction c1(c.nume-i*c.deno,c.deno);
    c1.simplify();
    return c1;
}

CFraction operator-(int i, const CFraction &c )
{
    CFraction c1(i*c.deno-c.nume,c.deno);
    c1.simplify();
    return c1;
}
CFraction operator*(const CFraction &c, int i)
{
    CFraction c1(c.nume*i,c.deno);
    c1.simplify();
    return c1;
}

CFraction operator*(int i, const CFraction &c )
{
    CFraction c1(c.nume*i,c.deno);
    c1.simplify();
    return c1;
}

CFraction operator/(const CFraction &c, int i)
{
    CFraction c1(c.nume,c.deno*i);
    c1.simplify();
    return c1;
}

CFraction operator/(int i, const CFraction &c )
{
    CFraction c1(i*c.deno,c.nume);
    c1.simplify();
    return c1;
}

// 分数取正号
CFraction CFraction:: operator+()
{
    return *this;
}

// 分数取负号
CFraction CFraction:: operator-()
{
    CFraction c;
    c.nume=-nume;
    c.deno=-deno;
    return c;     
}

// 分数比较大小
bool operator>(const CFraction &c1, const CFraction &c2)
{
    int c1_nume,c2_nume,common_deno;
    c1_nume=c1.nume*c2.deno;        // 计算分数通分后的分子，同分母为c1.deno*c2.deno
    c2_nume=c2.nume*c1.deno; 
    common_deno=c1.deno*c2.deno;
    //if (c1_nume>c2_nume) return true; 无法应对common_deno<0的情形
    //下面的语句更简练的一种写法if ((c1_nume-c2_nume)*common_deno>0) return true;
    if (c1_nume>c2_nume&&common_deno>0||c1_nume<c2_nume&&common_deno<0) return true; // 将通分后的分子比较大小
    return false;
}

// 分数比较大小
bool operator<(const CFraction &c1, const CFraction &c2)
{
    int c1_nume,c2_nume,common_deno;
    c1_nume=c1.nume*c2.deno;      
    c2_nume=c2.nume*c1.deno;
    common_deno=c1.deno*c2.deno;
    if ((c1_nume-c2_nume)*common_deno<0) return true; 
    return false;
}

// 分数比较大小
bool operator==(const CFraction &c1, const CFraction &c2)
{
    if (c1!=c2) return false;
    return true;
}

// 分数比较大小
bool operator!=(const CFraction &c1, const CFraction &c2)
{
    if (c1>c2 || c1<c2) return true;
    return false;
}

// 分数比较大小
bool operator>=(const CFraction &c1, const CFraction &c2)
{
    if (c1<c2) return false;
    return true;
}

// 分数比较大小
bool operator<=(const CFraction &c1, const CFraction &c2)
{
    if (c1>c2) return false;
    return true;
}

bool operator>(const CFraction &c, int i)
{
    if(c.deno>0) 
        return c.nume>(i*c.deno);
    else 
        return c.nume<(i*c.deno);
}

bool operator>(int i, const CFraction &c)
{
    if(c.deno>0) 
        return (i*c.deno)>c.nume;
    else 
        return (i*c.deno)<c.nume;
}

bool operator<(const CFraction &c, int i)
{
    if(c.deno>0) 
        return c.nume<(i*c.deno);
    else 
        return c.nume>(i*c.deno);
}

bool operator<(int i, const CFraction &c)
{
    if(c.deno>0) 
        return (i*c.deno)<c.nume;
    else 
        return (i*c.deno)>c.nume;
}

bool operator==(const CFraction &c, int i)
{
    return c.nume==(i*c.deno);
}

bool operator==(int i, const CFraction &c)
{
    return c.nume==(i*c.deno);
}

bool operator!=(const CFraction &c, int i)
{
    return c.nume!=(i*c.deno);
}

bool operator!=(int i, const CFraction &c)
{
    return c.nume!=(i*c.deno);
}

bool operator>=(const CFraction &c, int i)
{
    return !(c<i);
}

bool operator>=(int i, const CFraction &c)
{
    return !(i<c);
}

bool operator<=(const CFraction &c, int i)
{
    return !(c>i);
}

bool operator<=(int i, const CFraction &c)
{
    return !(i>c);
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
    
    CFraction c1(5,3),c2;
    //以下建议在调试环境中完成测试，
    c2=c1+5;
    c2=5+c1;
    
    c2=c1-5;
    c2=5-c1;
    
    c2=c1*5;
    c2=5*c1;
    
    c2=c1/5;
    c2=5/c1;
    
    bool b;
    
    b=(c1>2);
    b=(2>c1);
    
    system("pause");
    return 0;
}