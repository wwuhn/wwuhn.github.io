#include <iostream> // 复数类中运算符重载（非成员函数实现）
using namespace std;
class Complex
{
public:
    Complex(){real=0;imag=0;}
    Complex(double r,double i){real=r;imag=i;}
    friend Complex operator+(Complex &c1, Complex &c2);
    friend Complex operator-(Complex &c1, Complex &c2);
    friend Complex operator*(Complex &c1, Complex &c2);
    friend Complex operator/(Complex &c1, Complex &c2);
    void display();
private:
    double real;
    double imag;
};

//复数相加：(a+bi)+(c+di)=(a+c)+(b+d)i. 
Complex operator+(Complex &c1, Complex &c2)
{
    Complex c;
    c.real=c1.real+c2.real;
    c.imag=c1.imag+c2.imag;
    return c;
}

//复数相减：(a+bi)-(c+di)=(a-c)+(b-d)i.
Complex operator-(Complex &c1, Complex &c2)
{
    Complex c;
    c.real=c1.real-c2.real;
    c.imag=c1.imag-c2.imag;
    return c;
}

//复数相乘：(a+bi)(c+di)=(ac－bd)+(bc+ad)i.
Complex operator*(Complex &c1, Complex &c2)
{
    Complex c;
    c.real=c1.real*c2.real-c1.imag*c2.imag;
    c.imag=c1.imag*c2.real+c1.real*c2.imag;
    return c;
}

//复数相除：(a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +(bc-ad)/(c^2+d^2)i 
Complex operator/(Complex &c1, Complex &c2)
{
    Complex c;
    c.real=(c1.real*c2.real+c1.imag*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);
    c.imag=(c1.imag*c2.real-c1.real*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);
    return c;
}

void Complex::display()
{
    cout<<"("<<real<<","<<imag<<"i)"<<endl;
}

int main()
{
    Complex c1(3,4),c2(5,-10),c3;
    cout<<"c1=";
    c1.display();
    cout<<"c2=";
    c2.display();
    c3=c1+c2;
    cout<<"c1+c2=";
    c3.display();
    c3=c1-c2;
    cout<<"c1-c2=";
    c3.display();
    c3=c1*c2;
    cout<<"c1*c2=";
    c3.display();
    c3=c1/c2;
    cout<<"c1/c2=";
    c3.display();
    system("pause");
    return 0;
}