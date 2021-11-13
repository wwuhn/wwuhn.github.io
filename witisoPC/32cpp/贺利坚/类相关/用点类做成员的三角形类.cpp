#include <iostream>  // 用点类做成员的三角形类
#include <Cmath>
using namespace std;

class CPoint
{
private:
    double x;  // 横坐标          
    double y;  // 纵坐标
public:
    CPoint(double xx=0,double yy=0);
    double distance(CPoint p) const;   // 两点之间的距离
    void input();  //以x,y 形式输入坐标点
    void output(); //以(x,y) 形式输出坐标点
};

class CTriangle
{
public:
    CTriangle(CPoint &X,CPoint &Y,CPoint &Z):A(X),B(Y),C(Z){} //给出三点的构造函数
    void setTriangle(CPoint &X,CPoint &Y,CPoint &Z);//
    double perimeter(void);     //计算三角形的周长
    double area(void);          //计算并返回三角形的面积
    bool isRightTriangle();     //是否为直角三角形
    bool isIsoscelesTriangle(); //是否为等腰三角形
private:
    CPoint A,B,C; //三顶点
};

CPoint::CPoint(double xx,double yy)
{
    x=xx;
    y=yy;
}

// 输入坐标点
void CPoint::input()
{
    char ch;
    cout<<"请输入坐标点(格式x,y )：";
    while(1)
    {
        cin>>x>>ch>>y;
        if (ch==',') break;
        cout<<"输入的数据格式不符合规范，请重新输入\n";
    }
}

// 输出坐标点
void CPoint::output()
{
    cout<<"("<<x<<", "<<y<<")"<<endl;
}

// 求两点之间的距离
double CPoint::distance(CPoint p) const
{
    double d;
    d=sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
    return d;
}

void CTriangle::setTriangle(CPoint &X,CPoint &Y,CPoint &Z)
{
    A=X;
    B=Y;
    C=Z;
}

double CTriangle::perimeter(void)
{
    double a=B.distance(C),b=C.distance(A),c=A.distance(B);
    return (a + b + c);
}

double CTriangle::area(void)
{
    double a=B.distance(C),b=C.distance(A),c=A.distance(B);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

bool CTriangle::isRightTriangle()//是否为直角三角形
{
    double a=B.distance(C),b=C.distance(A),c=A.distance(B);
    double max=a;
    if(b>max) max=b;
    if(c>max) max=c;
    if(((max==a)&&(abs(a*a-b*b-c*c)<1e-7))||((max==b)&&(abs(b*b-a*a-c*c)<1e-7))||((max==c)&&(abs(c*c-b*b-a*a)<1e-7)))
        return true;
    else
        return false;
}
bool CTriangle::isIsoscelesTriangle() //是否为等腰三角形
{
    double a=B.distance(C),b=C.distance(A),c=A.distance(B);
    if((abs(a-b)<1e-7)||(abs(b-c)<1e-7)||(abs(c-a)<1e-7))
        return true;
    else
        return false;
}

int main()
{
    CPoint X(2,5),Y(5,2),Z(7,8);
    CTriangle Tri1(X,Y,Z);  //定义三角形类的一个实例（对象）
    cout<<"该三角形的周长为："<<Tri1.perimeter()<<"，面积为："<<Tri1.area()<<endl<<endl;
    cout<<"该三角形"<<(Tri1.isRightTriangle()?"是":"不是")<<"直角三角形"<<endl;
    cout<<"该三角形"<<(Tri1.isIsoscelesTriangle()?"是":"不是")<<"等腰三角形"<<endl;
    return 0;
}