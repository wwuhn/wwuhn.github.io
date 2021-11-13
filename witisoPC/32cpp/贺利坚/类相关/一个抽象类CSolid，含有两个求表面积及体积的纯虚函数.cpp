// 一个抽象类CSolid，含有两个求表面积及体积的纯虚函数

#include "iostream"
using namespace std;

const double pai=3.1415926;
// 抽象立体图形基类
class CSolid
{
public:
    virtual double SurfaceArea() const=0;
    virtual double Volume() const=0;
};

// 立方体类
class CCube : public CSolid
{
public:
    CCube(double len=0);
    double SurfaceArea() const;   // 求表面积
    double Volume() const;        // 求体积
private:
    double length;
    
};

// 立方体类构造函数
CCube::CCube(double len)
{
    length=len;
}

// 求立方体表面积
double CCube::SurfaceArea() const
{
    double c;
    c=6*length*length;
    return c;
}

// 求立方体体积
double CCube::Volume() const
{
    double c;
    c=length*length*length;
    return c;
}

// 球体类
class CBall : public CSolid
{
private:
    double radius;              // 圆周率
public:
    CBall(double r=0);
    double SurfaceArea() const;  // 求表面积
    double Volume() const;       // 求体积;
};

// 球体类构造函数
CBall::CBall(double r)
{
    radius=r;
}

// 求球体表面积
double CBall::SurfaceArea() const
{
    double c;
    c=4*pai*radius*radius;
    return c;
}

// 求球体体积
double CBall::Volume() const
{
    double c;
    c=pai*radius*radius*radius*4/3;
    return c;
}

// 圆柱体类
class CCylinder : public CSolid
{
private:
    double radius; 
    double height;
public:
    CCylinder(double r=0,double high=0);
    double SurfaceArea() const;       // 求表面积
    double Volume() const;            // 求体积
};

// 圆柱体类构造函数
CCylinder::CCylinder(double r,double high) 
{
    radius=r;
    height=high;
}

// 求圆柱体表面积
double CCylinder::SurfaceArea() const
{
    double c;
    c=pai*radius*radius+2*pai*radius*height;
    return c;
}

// 求圆柱体体积
double CCylinder::Volume() const
{
    double c;
    c=pai*radius*radius*height;
    return c;
}

int main( )
{
    CSolid *p;
    double s,v;
    CCube x(30);
    cout<<"立方体边长为30"<<endl;
    p=&x;
    s=p->SurfaceArea( );
    v=p->Volume( );
    cout<<"表面积："<<s<<endl;
    cout<<"体积："<<v<<endl;
    cout<<endl;
    CBall y(4.5);
    cout<<"球体半径为4.5"<<endl;
    p=&y;
    s=p->SurfaceArea( );
    v=p->Volume( );
    cout<<"表面积："<<s<<endl;
    cout<<"体积："<<v<<endl;
    cout<<endl;
    CCylinder z(10,20);
    cout<<"圆柱体底面半径、高分别为10, 20"<<endl;
    p=&z;
    s=p->SurfaceArea( );
    v=p->Volume( );
    cout<<"表面积："<<s<<endl;
    cout<<"体积："<<v<<endl;
    cout<<endl;
    system("pause");
    return 0;
}