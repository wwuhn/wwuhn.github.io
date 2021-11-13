#include<iostream>    // 直线类继承点类
#include<Cmath>
using namespace std;

class Point //定义坐标点类
{
public:
    double x,y;   //点的横坐标和纵坐标
    Point(){x=0;y=0;}
    Point(double x0, double y0) {x=x0; y=y0;}
    void PrintP(){cout<<"Point:("<<x<<","<<y<<")";}
};

class Line: public Point   //利用坐标点类定义直线类, 其基类的数据成员表示直线的中点
{
private:
    class Point pt1,pt2;   //直线的两个端点
public:
    Line(Point pts, Point pte);  //构造函数
    double Dx(){return pt2.x-pt1.x;}
    double Dy(){return pt2.y-pt1.y;}
    double Length();//计算直线的长度
    void PrintL();  //输出直线的两个端点和直线长度
};

//(1)构造函数，分别用参数初始化对应的端点及由基类属性描述的中点
Line::Line(Point pts, Point pte):Point((pts.x+pte.x)/2,(pts.y+pte.y)/2) {pt1=pts;pt2=pte;} //解题指导：此处关键在于其基类初始化时给对参数

double Line::Length(){return sqrt(Dx()*Dx()+Dy()*Dy());};//(2)计算直线的长度

void Line::PrintL()
{
    cout<<" 1st ";
    pt1.PrintP();
    cout<<"\n 2nd ";
    pt2.PrintP();
    cout<<"\n The middle point of Line: ";
    PrintP();
    cout<<"\n The Length of Line: "<<Length()<<endl; //(3)输出直线长度
}

int main()
{
    Point ps(-2,5),pe(7,9);
    Line l(ps,pe);
    l.PrintL(); //(4)输出直线l的信息
    l.PrintP(); //(5)输出直线l中点的信息，此处再次体会：派生类的对象调用其基类提供的成员函数
    system("pause");
    return 0;
}
