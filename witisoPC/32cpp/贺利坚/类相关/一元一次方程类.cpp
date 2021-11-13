#include "iostream"    // 一元一次方程类
using namespace std;
class CEquation
{
private:
	double a;     // 未知数系数
	double b;     // 常数项
	char unknown; // 未知数的符号
public:
	CEquation(double aa=0,double bb=0);
	friend istream &operator >> (istream &in,CEquation &e);
	friend ostream &operator << (ostream &out,CEquation &e);
	double Solve();
	char getUnknown();
};
 
CEquation::CEquation(double aa,double bb):a(aa),b(bb){}
 
// 输入方程
istream &operator >> (istream &in,CEquation &e)
{
	char ch1,ch2,ch3,ch4;
	while(1)
	{
		cin>>e.a>>ch1>>ch2>>e.b>>ch3>>ch4;
		if (ch1>='a' && ch1<='z')
			if ((ch2=='+' || ch2=='-') && ch3=='=' && ch4=='0') break;
		cout<<"输入的方程格式不符合规范，请重新输入\n";
	}
	if (ch2=='-') e.b=-e.b;
	e.unknown=ch1;
	return in;
}
 
// 输出方程
ostream &operator << (ostream &out,CEquation &e)
{
	cout<<e.a<<e.unknown;
	if (e.b>=0) cout<<"+";
	cout<<e.b<<"=0"<<endl;
	return out;
}
 
// 求解
double CEquation::Solve()
{
	double x;
	if (a==0)
	{
		if (b==0) cout<<"任意一个实数均为方程的解。"<<endl;
		else cout<<"方程无解。"<<endl;
		return 0;
	}
	x=-b/a;
	return x;
}
 
char CEquation::getUnknown()
{
	return unknown;
}
 
int main()
{
	CEquation e;
	cout<<"请输入一元一次方程(输入格式：3x-8=0)：";
	cin>>e;   //在两次测试中，分别输入3x-8=0和5s+18=0
	cout<<"方程为："<<e;
	cout<<"方程的解为："<<e.getUnknown()<<"="<<e.Solve()<<endl; //对两次测试，分别输出x=...和s=...
	e.Solve();
	system("pause");
	return 0;
}