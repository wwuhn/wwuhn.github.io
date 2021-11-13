// Time类中运算符重载
#include <iostream>
using namespace std;
class CTime
{
private:
	unsigned short int hour;    // 时
	unsigned short int minute;  // 分
	unsigned short int second;  // 秒
public:
	CTime(int h=0,int m=0,int s=0);
	void setTime(int h,int m,int s);
 
	//输入输出运算的重载
	friend istream &operator>>(istream &in,CTime &t);
	friend ostream &operator<<(ostream &out,CTime t); 
	//比较运算符(二目)的重载
	bool operator > (CTime &t);
	bool operator < (CTime &t);
	bool operator >= (CTime &t);
	bool operator <= (CTime &t);
	bool operator == (CTime &t);
	bool operator != (CTime &t);
	//二目运算符的重载
	CTime operator+(CTime &c);//返回c所规定的时、分、秒后的时间，例t1(8,20,25),t2(11,20,50)，t1+t2为:41:15
	CTime operator-(CTime &c);//对照+理解
	CTime operator+(int s);//返回s秒后的时间
	CTime operator-(int s);//返回s秒前的时间
	//一目运算符的重载
	CTime operator++(int);//后置++，下一秒
	CTime operator++();//前置++，下一秒
	CTime operator--(int);//后置--，前一秒
	CTime operator--();//前置--，前一秒
	//赋值运算符的重载  
	CTime operator+=(CTime &c);
	CTime operator-=(CTime &c);
	CTime operator+=(int s);//返回s秒后的时间
	CTime operator-=(int s);//返回s秒前的时间
};
 
//构造函数
CTime::CTime(int h,int m,int s)
{
	hour=h;
	minute=m;
	second=s;
}
// 设置时间
void CTime::setTime(int h,int m,int s)
{
	hour=h;
	minute=m;
	second=s;
}
 
// 重载输入运算符>>
istream &operator>>(istream &in,CTime &t)
{
	char ch1,ch2;
	while(1)
	{
		cout<<"请输入时间(hh:mm:ss) ";
		cin>>t.hour>>ch1>>t.minute>>ch2>>t.second;
		if (ch1==':' && ch2==':')
			if (t.hour>-1 && t.hour<24 && t.minute>-1 && t.minute<60 && t.second>-1 && t.second<60) break;
		cerr<<"时间格式不正确! 请重新输入\n";
	}
	return cin;
}
 
// 重载输出运算符<<
ostream &operator<<(ostream &out,CTime t)
{
	out<<t.hour<<':'<<t.minute<<':'<<t.second;
	return out;
}
 
 
//比较运算符的重载
bool CTime::operator > (CTime &t) // 判断时间t1>t2
{
	if (hour>t.hour) return true;
	if (hour<t.hour) return false;
	if (minute>t.minute) return true;
	if (minute<t.minute) return false;
	if (second>t.second) return true;
	return false;
}
 
bool CTime::operator < (CTime &t)// 判断时间t1<t2
{
	if (hour<t.hour) return true;
	if (hour>t.hour) return false;
	if (minute<t.minute) return true;
	if (minute>t.minute) return false;
	if (second<t.second) return true;
	return false;
}
 
bool CTime::operator == (CTime &t)// 判断时间t1==t2
{
	if (*this<t || *this>t) return false;
	return true;
}
 
bool CTime::operator != (CTime &t) // 判断时间t1!=t2
{
	if (*this==t) return false;
	return true;
}
 
bool CTime::operator >= (CTime &t)// 判断时间t1>=t2
{
	if (*this<t) return false;
	return true;
}
 
bool CTime::operator <= (CTime &t) // 判断时间t1<=t2
{
	if (*this>t) return false;
	return true;
}
 
//二目运算符的重载
// 计算时间之和, 返回c所规定的时、分、秒后的时间，例t1(8,20,25),t2(11,20,50)，t1+t2为:41:15
CTime CTime::operator + (CTime &t)
{
 
	int h,m,s;
	s=second+t.second;
	m=minute+t.minute;
	h=hour+t.hour;
	if (s>59)
	{
		s-=60;
		m++;
	}
	if (m>59)
	{
		m-=60;
		h++;
	}
	while (h>23) h-=24;
	CTime t0(h,m,s);
	return t0;
}
 
//返回s秒后的时间
CTime CTime::operator+(int s)
{
	int ss=s%60;
	int mm=(s/60)%60;
	int hh=s/3600;
	CTime t0(hh,mm,ss);
	return *this+t0;
}
 
// 计算时间之差
CTime CTime::operator - (CTime &t)
{
	int h,m,s;
	s=second-t.second;
	m=minute-t.minute;
	h=hour-t.hour;
	if (s<0)
	{
		s+=60;
		m--;
	}
	if (m<0)
	{
		m+=60;
		h--;
	}
	while (h<0) h+=24;
	CTime t0(h,m,s);
	return t0;
}
 
//返回s秒前的时间
CTime CTime::operator-(int s)
{
	int ss=s%60;
	int mm=(s/60)%60;
	int hh=s/3600;
	CTime t0(hh,mm,ss);
	return *this-t0;
}
 
//一目运算符的重载
CTime CTime::operator++(int)//后置++，下一秒
{
	CTime t=*this;
	*this=*this+1;
	return t;
}
 
CTime CTime::operator++()//前置++，下一秒
{
	*this=*this+1;
	return *this;
}
 
CTime CTime::operator--(int)//后置--，前一秒
{
	CTime t=*this;
	*this=*this-1;
	return t;
}
 
CTime CTime::operator--()//前置--，前一秒
{
	*this=*this-1;
	return *this;
}
 
//赋值运算符的重载  
CTime CTime::operator+=(CTime &c)
{
	*this=*this+c;
	return *this;
}
CTime CTime::operator-=(CTime &c)
{
	*this=*this-c;
	return *this;
}
CTime CTime::operator+=(int s)//返回s秒后的时间
{
	*this=*this+s;
	return *this;
}
CTime CTime::operator-=(int s)//返回s秒前的时间
{
	*this=*this-s;
	return *this;
}
 
int main()
{
	CTime t1,t2,t;
 
	cout<<"t1为：";
	cin>>t1;
	cout<<"t2为：";
	cin>>t2;
	cout<<"下面比较两个时间大小：\n";
	if (t1>t2) cout<<"t1>t2"<<endl;
	if (t1<t2) cout<<"t1<t2"<<endl;
	if (t1==t2) cout<<"t1＝t2"<<endl; 
	if (t1!=t2) cout<<"t1≠t2"<<endl;
	if (t1>=t2) cout<<"t1≥t2"<<endl;
	if (t1<=t2) cout<<"t1≤t2"<<endl;
	cout<<endl;
	cout<<"t1= "<<t1<<endl;
	cout<<"t2= "<<t2<<endl;
 
	cout<<"t=t1++"<<endl;
	t=t1++;
	cout<<"t= "<<t<<"    t1= "<<t1<<endl;
 
	cout<<"t=++t1"<<endl;
	t=++t1;
	cout<<"t= "<<t<<"    t1= "<<t1<<endl;
 
	cout<<"t1+t2= "<<t1+t2<<endl;
	cout<<"t1-t2= "<<t1-t2<<endl;
	cout<<"t1+2000= "<<t1+2000<<endl;
	cout<<"t1-5000= "<<t1-5000<<endl;
 
	system("pause");
	return 0;
}