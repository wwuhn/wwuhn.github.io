// 点派生出直线类

#include<iostream>
#include<Cmath>
using namespace std;

class Point //定义坐标点类
{
public:
    Point():x(0),y(0) {};
    Point(double x0, double y0):x(x0), y(y0) {};
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    void PrintPoint(); //输出点的信息
private:
    double x,y;   //点的横坐标和纵坐标
};
void Point::PrintPoint()
{
    cout<<"Point:("<<x<<","<<y<<")";    //输出点
}
 
class Line: public Point   //利用坐标点类定义直线类, 其基类的数据成员表示直线的中点
{
public:
    Line(Point pts, Point pte);  //构造函数，用初始化直线的两个端点及由基类数据成员描述的中点
    double Length();    //计算并返回直线的长度
    void PrintLine();   //输出直线的两个端点和直线长度
private:
    class Point pts,pte;   //直线的两个端点
};
//构造函数，分别用初始化直线的两个端点及由基类数据成员(属性)描述的中点
Line::Line(Point pt1, Point pt2):Point((pt1.getX()+pt2.getX())/2,(pt1.getY()+pt2.getY())/2)
{
    pts=pt1;
    pte=pt2;
}
double Line::Length()  //计算并返回直线的长度
{
    double dx = pts.getX() - pte.getX();
    double dy =pts.getY() - pte.getY();
    return sqrt(dx*dx+dy*dy);
}
void Line::PrintLine()
{
    cout<<" 1st ";
    pts.PrintPoint();
    cout<<"\n 2nd ";
    pte.PrintPoint();
    cout<<"\n The Length of Line: "<<Length()<<endl;
}
int main()
{
    Point ps(-2,5),pe(7,9);
    Line l(ps,pe);
    l.PrintLine();//输出直线l的信息
    cout<<"\n The middle point of Line: ";
    l.PrintPoint() ;//输出直线l中点的信息
    while(1);
    return 0;
}