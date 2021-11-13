#include <iostream>
using namespace std;
class CFraction
{
private:
	int nume;  // 分子
	int deno;  // 分母
public:
	CFraction(int nu=0,int de=1):nume(nu),deno(de){}
	void simplify();
 
	//输入输出的重载
	friend istream &operator>>(istream &in,CFraction &x);
	friend ostream &operator<<(ostream &out,CFraction x);
	
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
 
// 重载输入运算符>>
istream &operator>>(istream &in,CFraction &x)
{
	char ch;
	while(1)
	{
		cin>>x.nume>>ch>>x.deno;
		if (x.deno==0) 
			cerr<<"分母为! 请重新输入\n";
		else if(ch!='/')
			cerr<<"格式错误（形如m/n）! 请重新输入\n";
		else
			break;
	}
	return cin;
}
 
// 重载输出运算符<<
ostream &operator<<(ostream &out,CFraction x)
{
	cout<<x.nume<<'/'<<x.deno;
	return cout;
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
	if (!c.nume) return *this;   //除法无效（除数为）时，这种情况需要考虑，但这种处理仍不算合理
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
	x.deno=deno;
	return x;     
}
 
// 分数比较大小
bool CFraction::operator>(const CFraction &c)
{
	int this_nume,c_nume,common_deno;
	this_nume=nume*c.deno;        // 计算分数通分后的分子，同分母为deno*c.deno
	c_nume=c.nume*deno; 
	common_deno=deno*c.deno;
	if ((this_nume-c_nume)*common_deno>0) return true;
	return false;
}
 
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
	CFraction x,y,s;
	cout<<"输入x: ";
	cin>>x;
	cout<<"输入y: ";
	cin>>y;
	s=+x+y;
	cout<<"+x+y="<<s<<endl;
	cout<<"x-y="<<s<<endl;
	s=x*y;
	cout<<"x*y="<<s<<endl;
	s=x/y;
	cout<<"x/y="<<s<<endl;
	s=-x+y;
	cout<<"-x+y="<<s<<endl;
	
	cout<<x;
	if (x>y) cout<<"大于";
	if (x<y) cout<<"小于";
	if (x==y) cout<<"等于";
	cout<<y<<endl;
	system("pause");
	return 0;
}