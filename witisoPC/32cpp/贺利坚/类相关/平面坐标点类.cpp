#include "iostream"  // 平面坐标点类
#include "Cmath"
using namespace std;


class CPoint
{
private:
    double x;  // 横坐标
    double y;  // 纵坐标
public:
    CPoint(double xx=0,double yy=0);
    double Distance(CPoint p) const;   // 两点之间的距离
    double Distance0() const;          // 到原点的距离
    CPoint SymmetricAxis(char style) const;   // 返回对称点
    void input();  //以x,y 形式输入坐标点
    void output(); //以(x,y) 形式输出坐标点
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
double CPoint::Distance(CPoint p) const
{
    double d;
    d=sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
    return d;
}

// 求点到原点的距离
double CPoint::Distance0() const
{
    double d;
    d=sqrt(x*x+y*y);
    return d;
}

// 求对称点, style取'x','y'和'o'分别表示按x轴, y轴, 原点对称
CPoint CPoint::SymmetricAxis(char style) const
{
    CPoint p(this->x,this->y);//用复制构造函数时，写作p(*this)
    switch(style)
    {
    case 'x':
        p.y=-y; break;
    case 'y':
        p.x=-x; break;
    case 'o':
        p.x=-x;p.y=-y;
    }
    return p;
}

int main( )
{
    double distance;
    CPoint p1,p2,p;
    cout<<"第1个点p1，";
    p1.input();
    cout<<"第2个点p2，";
    p2.input();
    distance=p1.Distance(p2);
    cout<<"两点的距离为："<<distance<<endl;
    distance=p1.Distance0();
    cout<<"p1到原点的距离为："<<distance<<endl;
    p=p1.SymmetricAxis('x');
    cout<<"p1关于x轴的对称点为：";
    p.output();
    p=p1.SymmetricAxis('y');
    cout<<"p1关于y轴的对称点为：";
    p.output();
    p=p1.SymmetricAxis('o');
    cout<<"p1关于原点的对称点为：";
    p.output();
    return 0;
}