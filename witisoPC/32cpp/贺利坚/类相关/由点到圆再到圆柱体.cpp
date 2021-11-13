#if 0  // 一、实现基类Point类及用于测试的main()函数
#include <iostream.h>
//由点到圆再到圆柱体
class Point
{
public:
    Point(double x=0,double y=0);				//构造函数
    void setPoint(double,double);               //设置坐标值
    double getX( ) const {return x;}            //读x坐标
    double getY( ) const {return y;}            //读y坐标
    friend ostream & operator<<(ostream &,const Point &);   //重载运算符“<<”
protected:										            //受保护成员
    double x,y;
};


//Point的构造函数
Point::Point(double a,double b)	
{
    x=a;
    y=b;
}
//设置x和y的坐标值
void Point::setPoint(double a,double b)  
{
    x=a;
    y=b;
}

ostream & operator<<(ostream &output,const Point &p)
{
    output<<"["<<p.x<<","<<p.y<<"]"<<endl;
    return output;
}

int main( )
{
    Point p(3.5,6.4); 
    cout<<"x="<<p.getX( )<<",y="<<p.getY( )<<endl;  
    p.setPoint(8.5,6.8);                             
    cout<<"p:"<<p<<endl; 
    while(1);
    return 0;
}
#endif

#if 0  // 二、实现派生类Circle及其测试函数
#include <iostream.h>

class Point
{
public:
    Point(double x=0,double y=0);				    //构造函数
    void setPoint(double,double);                   //设置坐标值
    double getX( ) const {return x;}                //读x坐标
    double getY( ) const {return y;}                //读y坐标
    friend ostream & operator<<(ostream &,const Point &);//重载运算符“<<”
protected:										    //受保护成员
    double x,y;
};


//Point的构造函数
Point::Point(double a,double b)	
{
    x=a;
    y=b;
}
//设置x和y的坐标值
void Point::setPoint(double a,double b)  
{
    x=a;
    y=b;
}

ostream & operator<<(ostream &output,const Point &p)
{
    output<<"["<<p.x<<","<<p.y<<"]"<<endl;
    return output;
}

class Circle:public Point   //circle是Point类的公用派生类
{
public:
    Circle(double x=0,double y=0,double r=0);  //构造函数
    void setRadius(double);                  //设置半径值
    double getRadius( ) const;               //读取半径值
    double area ( ) const;                   //计算圆面积
    friend ostream &operator<<(ostream &,const Circle &);//重载运算符“<<”
protected:
    double radius;    // 应该由圆心的坐标来计算radius
};

//定义构造函数，对圆心坐标和半径初始化
Circle::Circle(double a,double b,double r):Point(a,b),radius(r){ }

//设置半径值
void Circle::setRadius(double r)
{
    radius=r;
}

//读取半径值
double Circle::getRadius( ) const
{
    return radius;
}

//计算圆面积
double Circle::area( ) const
{
    return 3.14159*radius*radius;
}

//重载运算符“<<”，使之按规定的形式输出圆的信息
ostream &operator<<(ostream &output,const Circle &c)
{
    output<<"Center=["<<c.x<<", "<<c.y<<"], r="<<c.radius<<", area="<<c.area( )<<endl;
    return output;
}

int main( )
{
    Circle c(3.5,6.4,5.2);
    cout<<"original circle:\nx="<<c.getX()<<", y="<<c.getY()<<", r="<<c.getRadius( ) <<", area="<<c.area( )<<endl;  
    c.setPoint(5,5);       
    cout<<"new circle:\n"<<c;     
    while(1);
    return 0;
}
#endif

#if 1 //三、实现Circle的派生类Cylinder及测试函数
#include <iostream.h>

class Point
{
public:
	Point(double x=0,double y=0);					 //构造函数
	void setPoint(double,double);                  //设置坐标值
	double getX( ) const {return x;}              //读x坐标
	double getY( ) const {return y;}              //读y坐标
	friend ostream & operator<<(ostream &,const Point &);//重载运算符“<<”
protected:										 //受保护成员
	double x,y;
};
 
 
//Point的构造函数
Point::Point(double a,double b)	
{
	x=a;
	y=b;
}
//设置x和y的坐标值
void Point::setPoint(double a,double b)  
{
	x=a;
	y=b;
}
 
ostream & operator<<(ostream &output,const Point &p)
{
	output<<"["<<p.x<<","<<p.y<<"]"<<endl;
	return output;
}
 
class Circle:public Point   //circle是Point类的公用派生类
{
public:
	Circle(double x=0,double y=0,double r=0);  //构造函数
	void setRadius(double);                  //设置半径值
	double getRadius( ) const;               //读取半径值
	double area ( ) const;                   //计算圆面积
	friend ostream &operator<<(ostream &,const Circle &);//重载运算符“<<”
protected:
	double radius;
};
 
//定义构造函数，对圆心坐标和半径初始化
Circle::Circle(double a,double b,double r):Point(a,b),radius(r){ }
 
//设置半径值
void Circle::setRadius(double r)
{
	radius=r;
}
 
//读取半径值
double Circle::getRadius( ) const
{
	return radius;
}
 
//计算圆面积
double Circle::area( ) const
{
	return 3.14159*radius*radius;
}
 
//重载运算符“<<”，使之按规定的形式输出圆的信息
ostream &operator<<(ostream &output,const Circle &c)
{
	output<<"Center=["<<c.x<<", "<<c.y<<"], r="<<c.radius<<", area="<<c.area( )<<endl;
	return output;
}
 
class Cylinder:public Circle
{
public:
	Cylinder (double x=0,double y=0,double r=0,double h=0);//构造函数
	void setHeight(double);                      //设置圆柱高
	double getHeight( ) const;                    //读取圆柱高
	double area( ) const;                         //计算圆表面积
	double volume( ) const;                       //计算圆柱体积
	friend ostream& operator<<(ostream&,const Cylinder&);//重载运算符“<<”
protected:
	double height;                               //圆柱高
};
 
//定义构造函数
Cylinder::Cylinder(double a,double b,double r,double h) :Circle(a,b,r),height(h){}
 
//设置圆柱高
void Cylinder::setHeight(double h)
{
	height=h;
}
 
//读取圆柱高
double Cylinder::getHeight( ) const 
{
	return height;
}
 
//计算圆柱表面积
double Cylinder::area( ) const
{ 
	return 2*Circle::area( )+2*3.14159*radius*height;
}
 
//计算圆柱体积
double Cylinder::volume() const
{
	return Circle::area()*height;
}
 
//重载运算符“<<”
ostream &operator<<(ostream &output,const Cylinder& cy)
{
	output<<"Center=["<<cy.x<<","<<cy.y<<"], r="<<cy.radius<<", h="<<cy.height
		<<"\narea="<<cy.area( )<<", volume="<<cy.volume( )<<endl;
	return output;
}
 
int main( )
{
	Cylinder cy1(3.5,6.4,5.2,10);
	cout<<"\noriginal cylinder:\nx="<<cy1.getX( )<<", y="<<cy1.getY( )<<", r="
		<<cy1.getRadius( )<<", h="<<cy1.getHeight( )<<"\narea="<<cy1.area()
		<<",volume="<<cy1.volume()<<endl;
	cy1.setHeight(15);     
	cy1.setRadius(7.5);      
	cy1.setPoint(5,5);       
	cout<<"\nnew cylinder:\n"<<cy1;        
	while(1);
	return 0;
}

#endif