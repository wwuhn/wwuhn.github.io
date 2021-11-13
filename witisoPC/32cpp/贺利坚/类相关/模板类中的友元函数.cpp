#include <iostream>   // 模板类中的友元函数
using namespace std;

template<class numtype>
class Complex   
{
public:
    Complex( ){real=0;imag=0;}     
    Complex(numtype r,numtype i){real=r;imag=i;} 
    Complex complex_add(const Complex &c2); 
    template<class numtype> friend Complex<numtype> add_complex(const Complex<numtype> &c1, const Complex<numtype> &c2);   //利用了模板的外部函数要作为友元函数，注意声明方式：类声明中也必须给出模板声明
    void display( );   
private:
    numtype real; 
    numtype imag; 
};

template<class numtype>
Complex<numtype> Complex<numtype>::complex_add(const Complex<numtype> &c2)
{
    Complex<numtype> c;
    c.real=real+c2.real;
    c.imag=imag+c2.imag;
    return c;
} 

//利用了模板的友元函数的定义
template<class numtype> 
Complex<numtype> add_complex(const Complex<numtype> &c1, const Complex<numtype> &c2) 
{
    Complex<numtype> c; 
    c.real=c1.real+c2.real; 
    c.imag=c1.imag+c2.imag; 
    return c; 
} 

template<class numtype> 
void Complex<numtype>::display( )   
{
    cout<<"("<<real<<","<<imag<<"i)"<<endl;
}

int main( )
{
    Complex<int> c1(3,4),c2(5,-10),c3;  
    c3=c1.complex_add(c2);  
    cout<<"c1+c2="; 
    c3.display( );  
    Complex<double> c4(3.1,4.4),c5(5.34,-10.21),c6;  
    c6=c4.complex_add(c5);  
    cout<<"c4+c5="; 
    c6.display( ); 
    Complex<int> c7=add_complex(c1,c2);  
    cout<<"c1+c2="; 
    c7.display( );
    system("pause");
    return 0;
}