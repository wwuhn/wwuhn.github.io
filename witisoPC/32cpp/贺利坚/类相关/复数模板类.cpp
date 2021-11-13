#include <iostream>   // 复数模板类
using namespace std;

template<class T>  //类声明前加模板的声明
class Complex  
{
public:
    Complex( ){real=0;imag=0;}    
    Complex(T r,T i){real=r;imag=i;}   //类声明中的每一个T，将被对象定义时提供的实际类型代替
    Complex complex_add(Complex &c2);
    Complex complex_minus(Complex &c2);
    Complex complex_multiply(Complex &c2);
    Complex complex_divide(Complex &c2);
    void display( );  
private:
    T real;   //数据成员的类型，也将被对象定义时提供的实际类型代替
    T imag;
};

//复数相加： (a+bi)+(c+di)=(a+c)+(b+d)i.
template<class T>  //每一个成员函数的定义前，必须要声明类模板
Complex<T> Complex<T>::complex_add(Complex<T> &c2)  //使用了模板的类，将不再独立使用，其类名的完整表示为“类模板名<虚拟类型参数>”
{
    Complex<T> c;   //凡用到类名处也用“类模板名<虚拟类型参数>”形式；本题中求两个复数的和，自然要产生一个新的复数对象
    c.real=real+c2.real;
    c.imag=imag+c2.imag;
    return c;
}


//复数相减：(a+bi)-(c+di)=(a-c)+(b-d)i.
template <class T>    
Complex<T> Complex<T>::complex_minus(Complex <T> &c2)    
{    
    Complex <T> c;    
    c.real=real-c2.real;    
    c.imag=imag-c2.imag;    
    return c;    
}    

//复数相乘：(a+bi)(c+di)=(ac－bd)+(bc+ad)i.
template <class T>    
Complex<T> Complex<T>::complex_multiply(Complex <T> &c2)     
{    
    Complex <T> c;    
    c.real=real*c2.real-imag*c2.imag;    
    c.imag=imag*c2.real+real*c2.imag;    
    return c;    
}    

//复数相除：(a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +(bc-ad)/(c^2+d^2)i
template <class T>    
Complex<T> Complex<T>::complex_divide(Complex <T> &c2)     
{    
    Complex <T> c;    
    T d=c2.real*c2.real+c2.imag*c2.imag;
    c.real=(real*c2.real+imag*c2.imag)/d;     //此处有危险未排除：除法溢出
    c.imag=(imag*c2.real-real*c2.imag)/d;    
    return c;    
} 

template<class T>
void Complex<T>::display( )  
{
    cout<<"("<<real<<","<<imag<<"i)"<<endl;
}

int main( )
{
    Complex<int> c1(3,4),c2(5,-10),c3; //定义对象时，用“类模板名<实际类型名>”形式
    c3=c1.complex_add(c2); 
    cout<<"c1+c2=";
    c3.display( ); 
    Complex<double> c4(3.1,4.4),c5(5.34,-10.21),c6; //定义对象时，用“类模板名<实际类型名>”形式
    c6=c4.complex_add(c5); 
    cout<<"c4+c5=";
    c6.display( );
    
    
    c6=c4.complex_minus(c5); 
    cout<<"c4-c5=";
    c6.display( );
    
    
    c6=c4.complex_multiply(c5); 
    cout<<"c4*c5=";
    c6.display( );
    
    
    c6=c4.complex_divide(c5); 
    cout<<"c4/c5=";
    c6.display( );
    
    
    system("pause");
    return 0;
}