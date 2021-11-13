#include <iostream>  // 输入输出流运算符重载，注意其参数及位置以及返回值，
                 // 需要是友元（因为第一个参数是流对象而不是类对象，需要返回流引用，方便链式操作
using namespace std;
class Complex
{
public:
	Complex(){real=0;imag=0;}
	Complex(double r,double i){real=r;imag=i;}
	Complex operator-();
	//实现输入、输出的运算符重载
	friend ostream& operator << (ostream& output,Complex& c);
	friend istream& operator >> (istream& input,Complex& c);
	//实现加减乘除的运算符重载
	friend Complex operator+(Complex &c1, Complex &c2);
	friend Complex operator+(double d1, Complex &c2);
	friend Complex operator+(Complex &c1, double d2);
	friend Complex operator-(Complex &c1, Complex &c2);
	friend Complex operator-(double d1, Complex &c2);
	friend Complex operator-(Complex &c1, double d2);
	friend Complex operator*(Complex &c1, Complex &c2);
	friend Complex operator*(double d1, Complex &c2);
	friend Complex operator*(Complex &c1, double d2);
	friend Complex operator/(Complex &c1, Complex &c2);
	friend Complex operator/(double d1, Complex &c2);
	friend Complex operator/(Complex &c1, double d2);
private:
	double real;
	double imag;
};
 
//实现输出的运算符重载
ostream& operator << (ostream& output,Complex& c)
{	output<<"("<<c.real;
	if(c.imag>=0) output<<"+";  
	output<<c.imag<<"i)";    
	return output;
}
 
//实现输入的运算符重载
istream& operator >> (istream& input,Complex& c)
{	int a,b;
	char sign,i;
	do
	{	cout<<"input a complex number(a+bi或a-bi):";
		input>>a>>sign>>b>>i;
	}
	while(!((sign=='+'||sign=='-')&&i=='i'));
	c.real=a;
	c.imag=(sign=='+')?b:-b;
	return input;
}
 
 
Complex Complex::operator-()
{
	return(0-*this);
}
 
//复数相加：(a+bi)+(c+di)=(a+c)+(b+d)i. 
Complex operator+(Complex &c1, Complex &c2)
{
	Complex c;
	c.real=c1.real+c2.real;
	c.imag=c1.imag+c2.imag;
	return c;
}
Complex operator+(double d1, Complex &c2)
{
	Complex c(d1,0);
	return c+c2; //按运算法则计算的确可以，但充分利用已经定义好的代码，既省人力，也避免引入新的错误，但可能机器的效率会不佳
}
Complex operator+(Complex &c1, double d2)
{
	Complex c(d2,0);
	return c1+c;
}
//复数相减：(a+bi)-(c+di)=(a-c)+(b-d)i.
Complex operator-(Complex &c1, Complex &c2)
{
	Complex c;
	c.real=c1.real-c2.real;
	c.imag=c1.imag-c2.imag;
	return c;
}
Complex operator-(double d1, Complex &c2)
{
	Complex c(d1,0);
	return c-c2;  
}
Complex operator-(Complex &c1, double d2)
{
	Complex c(d2,0);
	return c1-c;
}
 
//复数相乘：(a+bi)(c+di)=(ac－bd)+(bc+ad)i.
Complex operator*(Complex &c1, Complex &c2)
{
	Complex c;
	c.real=c1.real*c2.real-c1.imag*c2.imag;
	c.imag=c1.imag*c2.real+c1.real*c2.imag;
	return c;
}
Complex operator*(double d1, Complex &c2)
{
	Complex c(d1,0);
	return c*c2;
}
Complex operator*(Complex &c1, double d2)
{
	Complex c(d2,0);
	return c1*c;
}
 
//复数相除：(a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +(bc-ad)/(c^2+d^2)i 
Complex operator/(Complex &c1, Complex &c2)
{
	Complex c;
	c.real=(c1.real*c2.real+c1.imag*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);
	c.imag=(c1.imag*c2.real-c1.real*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);
	return c;
}
Complex operator/(double d1, Complex &c2)
{
	Complex c(d1,0);
	return c/c2;
}
 
Complex operator/(Complex &c1, double d2)
{
	Complex c(d2,0);
	return c1/c;
}
 
int main()
{
	Complex c1,c2,c3;
	double d=11;
	cout<<"c1: "<<endl;; 
	cin>>c1;          
	cout<<"c2: "<<endl;
	cin>>c2;
	cout<<"c1="<<c1<<endl;
	cout<<"c2="<<c2<<endl;
	cout<<"d="<<d<<endl;
	cout<<"-c1="<<(-c1);
	c3=c1+c2;
	cout<<"c1+c2="<<c3<<endl;
	cout<<"c1+d="<<(c1+d)<<endl;
	cout<<"d+c1="<<(d+c1)<<endl;
	c3=c1-c2;
	cout<<"c1-c2="<<c3<<endl;
	cout<<"c1-d="<<(c1-d)<<endl;
	cout<<"d-c1="<<(d-c1)<<endl;
	c3=c1*c2;
	cout<<"c1*c2="<<c3<<endl;
	cout<<"c1*d="<<(c1*d)<<endl;
	cout<<"d*c1="<<(d*c1)<<endl;
	c3=c1/c2;
	cout<<"c1/c2="<<c3<<endl;
	cout<<"c1/d="<<(c1/d)<<endl;
	cout<<"d/c1="<<(d/c1)<<endl;
 
	system("pause");
	return 0;
}