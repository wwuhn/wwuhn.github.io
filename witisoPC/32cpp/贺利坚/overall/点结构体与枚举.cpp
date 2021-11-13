#include "iostream"   // 点结构体与枚举
#include "Cmath"
using namespace std;

enum SymmetricStyle {axisx,axisy,point};//分别表示按x轴, y轴, 原点对称
struct Point
{
    double x;  // 横坐标
    double y;  // 纵坐标
};
double distance(Point p1, Point p2);                // 两点之间的距离
double distance0(Point p1);                         // p1到原点的距离
Point symmetricAxis(Point p,SymmetricStyle style);  // 返回对称点(关于x、y轴或原点对称)

int main( )
{
    Point p1={1,5},p2={4,1},p;
    cout<<"两点的距离为："<<distance(p1,p2)<<endl;
    cout<<"p1到原点的距离为："<<distance0(p1)<<endl;
    p=symmetricAxis(p1,axisx);
    cout<<"p1关于x轴的对称点为："<<"("<<p.x<<", "<<p.y<<")"<<endl;
    p=symmetricAxis(p1,axisy);
    cout<<"p1关于y轴的对称点为："<<"("<<p.x<<", "<<p.y<<")"<<endl;
    p=symmetricAxis(p1,point);
    cout<<"p1关于原点的对称点为："<<"("<<p.x<<", "<<p.y<<")"<<endl;
    return 0;
}

// 求两点之间的距离
double distance(Point p1,Point p2)
{
    double d;
    d=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    return d;
}

// 求点到原点的距离
double distance0(Point p)
{
    double d;
    d=sqrt(p.x*p.x+p.y*p.y);
    return d;
}

// 求对称点
Point symmetricAxis(Point p1,SymmetricStyle style)
{
    Point p;
    p.x=p1.x;
    p.y=p1.y;
    switch(style)
    {
    case axisx:
        p.y=-p1.y; break;
    case axisy:
        p.x=-p1.x; break;
    case point:
        p.x=-p1.x;p.y=-p1.y;
    }
    return p;
}