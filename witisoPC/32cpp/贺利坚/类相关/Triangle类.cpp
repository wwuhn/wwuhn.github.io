#include<iostream>  // Triangle类
#include<Cmath>
using namespace std;

class Triangle
{
public:
    void Setabc(float x, float y, float z);     //置三边的值，注意要能成三角形
    void Getabc(float *x, float *y, float *z);  //取三边的值
    float Perimeter(void);                      //计算三角形的周长
    float Area(void);                           //计算并返回三角形的面积
private:
    float a,b,c;            //三边为私有成员数据
};

int main(void)
{
    Triangle  Tri1;	        //定义三角形类的一个实例（对象）
    Tri1.Setabc(4,5,6);	    //为三边置初值
    float x,y,z;
    Tri1.Getabc(&x,&y,&z);   //将三边的值为x,y,z赋值
    cout<<"三条边为："<<x<<'\t'<<y<<'\t'<<z<<endl;
    cout<<"三角形的周长为："<< Tri1.Perimeter()<<'\t'<<"面积为："<< Tri1.Area()<<endl;
    system("PAUSE");  //在VS环境中，这一句是需要的，否则输出结果"一闪而过"
    return;
}

void Triangle::Setabc(float x, float y, float z)
{
    if(x+y>z&&x+z>y&&y+z>x)
    {
        a=x;
        b=y;
        c=z;
    }
    else //这样处理可能也不好，想想有何高招？
    {
        a=0;
        b=0;
        c=0;
    }
}

void Triangle::Getabc(float *x, float *y, float *z)
{
    *x=a;
    *y=b;
    *z=c;
}

float Triangle::Perimeter(void)
{
    return a+b+c;
}

float Triangle::Area(void)
{
    float p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}