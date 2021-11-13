#if 0
#include <iostream.h>
#include<Cmath>

class Point
{
public:
    Point(double x=0,double y=0);		    //构造函数
    double distance(const Point &p) const;	//求距离
    double getx() const {return x;} 
    double gety() const {return y;} 
    void setx(double x1){x=x1;}
    void sety(double y1){y=y1;}
    friend ostream & operator<<(ostream &,const Point &);//重载运算符“<<”
protected:										 //受保护成员
    double x,y;
};


//Point的构造函数
Point::Point(double a,double b):x(a),y(b){}

double Point::distance(const Point &p) const	//求距离
{
    double dx = x-p.x;
    double dy = y-p.y;
    return sqrt(dx*dx+dy*dy);
}

ostream & operator<<(ostream &output,const Point &p)
{
    output<<"["<<p.x<<","<<p.y<<"]"<<endl;
    return output;
}

class Circle:public Point //circle是Point类的公用派生类
{
public:
    Circle(double x=0,double y=0,double r=0); //构造函数
    double area ( ) const; //计算圆面积
    friend ostream &operator<<(ostream &,const Circle &);//重载运算符“<<”
    friend int locate(const Point &p, const Circle &c); //判断点p在圆上、圆内或圆外，返回值：<0圆内，==0圆上，>0 圆外
    //重载关系运算符（种）运算符，使之能够按圆的面积比较两个圆的大小；
    bool operator>(const Circle &);
    bool operator<(const Circle &);
    bool operator>=(const Circle &);
    bool operator<=(const Circle &);
    bool operator==(const Circle &);
    bool operator!=(const Circle &);
    //给定一点p，求出该点与圆c的圆心相连成的直线与圆的两个交点p1和p2
    // (为了带回计算结果，p1和p2需要声明为引用)
    friend void crossover_point(Point &p,Circle &c, Point &p1,Point &p2 ) ;
protected:
    double radius;
};

//定义构造函数，对圆心坐标和半径初始化
Circle::Circle(double a,double b,double r):Point(a,b),radius(r){ }

//计算圆面积
double Circle::area( ) const
{
    return 3.14159*radius*radius;
}

//重载运算符“<<”，使之按规定的形式输出圆的信息
ostream &operator<<(ostream &output,const Circle &c)
{
    output<<"Center=["<<c.x<<", "<<c.y<<"], r="<<c.radius<<endl;
    return output;
}

//判断点p在圆内、圆c内或圆c外
int locate(const Point &p, const Circle &c)
{
    const Point cp(c.x,c.y); //圆心
    double d = cp.distance(p);
    if (abs(d - c.radius) < 1e-7)
        return 0;  //相等
    else if (d < c.radius)
        return -1;  //圆内
    else 
        return 1;  //圆外
}

//重载关系运算符（种）运算符，使之能够按圆的面积比较两个圆的大小；
bool Circle::operator>(const Circle &c)
{
    return (this->radius - c.radius) > 1e-7;
}

bool Circle::operator<(const Circle &c)
{
    return (c.radius - this->radius) > 1e-7;
}

bool Circle::operator>=(const Circle &c)
{
    return !(*this < c);
}

bool Circle::operator<=(const Circle &c)
{
    return !(*this > c);
}

bool Circle::operator==(const Circle &c)
{
    return abs(this->radius - c.radius) < 1e-7;
}

bool Circle::operator!=(const Circle &c)
{
    return abs(this->radius - c.radius) > 1e-7;
}

//给定一点p，求出该点与圆c的圆心相连成的直线与圆的两个交点p1和p2(为了带回计算结果，p1和p2需要声明为引用)
void crossover_point(Point &p, Circle &c, Point &p1,Point &p2 )
{
    p1.setx (c.getx() + sqrt(c.radius*c.radius/(1+((c.gety()-p.gety())/(c.getx()-p.getx()))*((c.gety()-p.gety())/(c.getx()-p.getx())))));
    p2.setx (c.getx() - sqrt(c.radius*c.radius/(1+((c.gety()-p.gety())/(c.getx()-p.getx()))*((c.gety()-p.gety())/(c.getx()-p.getx())))));
    p1.sety (p.gety() + (p1.getx() -p.getx())*(c.gety()-p.gety())/(c.getx()-p.getx()));
    p2.sety (p.gety() + (p2.getx() -p.getx())*(c.gety()-p.gety())/(c.getx()-p.getx()));
}

int main( )
{
    Circle c1(3,2,4),c2(4,5,5);      //c2应该大于c1
    Point p1(1,1),p2(3,-2),p3(7,3);  //分别位于c1内、上、外
    
    cout<<"圆c1: "<<c1;
    cout<<"点p1: "<<p1;
    cout<<"点p1在圆c1之"<<((locate(p1, c1)>0)?"外":((locate(p1, c1)<0)?"内":"上"))<<endl;
    cout<<"点p2: "<<p2;
    cout<<"点p2在圆c1之"<<((locate(p2, c1)>0)?"外":((locate(p2, c1)<0)?"内":"上"))<<endl;	
    cout<<"点p3: "<<p3;
    cout<<"点p3在圆c1之"<<((locate(p3, c1)>0)?"外":((locate(p3, c1)<0)?"内":"上"))<<endl;
    cout<<endl; 
    
    cout<<"圆c1: "<<c1;
    if(c1>c2) cout<<"大于"<<endl;
    if(c1<c2) cout<<"小于"<<endl; 
    if(c1>=c2) cout<<"大于等于"<<endl;
    if(c1<=c2) cout<<"小于等于"<<endl; 
    if(c1==c2) cout<<"等于"<<endl; 
    if(c1!=c2) cout<<"不等于"<<endl; 
    cout<<"圆c2: "<<c2;
    cout<<endl; 
    
    Point p4,p5;
    crossover_point(p1,c1, p4, p5);
    
    cout<<"点p1: "<<p1;
    cout<<"与圆c1: "<<c1;
    cout<<"的圆心相连，与圆交于两点，分别是："<<endl;
    cout<<"交点: "<<p4;
    cout<<"交点: "<<p5;
    cout<<endl; 
    
    while(1);
    return 0;
}
#endif
/*

对于Circle类，需要重载<<运算符（友元函数）；根据上面main()函数中08、10、12行的调用形式，
显然locate()函数应该为返回int型的友元函数；判断两圆大小关系的6个比较运算符处理为成员函数；
crossover_point()函数的设计是个难点，从main()函数中可以看出，
crossover_point()应该是一友元函数或一般函数，其返回值为void型，
要求位置关系的点和圆分别是第1个参数p1和第2个参数c1，而后两个参数p4和p5则用于返回值
（回想函数部分的相关知识，p4和p5应该为引用，这很重要。）
*/
#if 1
#include <iostream.h>
#include<Cmath>

class Point
{
public:
	Point(double x=0,double y=0);		//构造函数
	double distance(const Point &p) const;	//求距离
	double getx() const{return x;} 
	double gety() const{return y;} 
	void setx(double x1){x=x1;}
	void sety(double y1){y=y1;}
	friend ostream & operator<<(ostream &,const Point &);//重载运算符“<<”
protected:										 //受保护成员
	double x,y;
};
 
 
//Point的构造函数
Point::Point(double a,double b):x(a),y(b){}
 
double Point::distance(const Point &p) const	//求距离
{
	double dx = x-p.x;
	double dy = y-p.y;
	return sqrt(dx*dx+dy*dy);
}
 
ostream & operator<<(ostream &output,const Point &p)
{
	output<<"["<<p.x<<","<<p.y<<"]"<<endl;
	return output;
}
 
struct Two_points   //专为crossover_point()函数返回值定义的结构体
{
	Point p1;
	Point p2;
};
 
class Circle:public Point //circle是Point类的公用派生类
{
public:
	Circle(double x=0,double y=0,double r=0); //构造函数
	double area ( ) const; //计算圆面积
	friend ostream &operator<<(ostream &,const Circle &);//重载运算符“<<”
	friend int locate(const Point &p, const Circle &c); //判断点p在圆上、圆内或圆外，返回值：<0圆内，==0圆上，>0 圆外
	//重载关系运算符（种）运算符，使之能够按圆的面积比较两个圆的大小；
	bool operator>(const Circle &);
	bool operator<(const Circle &);
	bool operator>=(const Circle &);
	bool operator<=(const Circle &);
	bool operator==(const Circle &);
	bool operator!=(const Circle &);
	//再给一种解法：给定一点p，求出该点与圆c的圆心相连成的直线与圆的两个交点（返回Two_points型值）
	Two_points crossover_point(Point &p);
protected:
	double radius;
};
 
//定义构造函数，对圆心坐标和半径初始化
Circle::Circle(double a,double b,double r):Point(a,b),radius(r){ }
 
//计算圆面积
double Circle::area( ) const
{
	return 3.14159*radius*radius;
}
 
//重载运算符“<<”，使之按规定的形式输出圆的信息
ostream &operator<<(ostream &output,const Circle &c)
{
	output<<"Center=["<<c.x<<", "<<c.y<<"], r="<<c.radius<<endl;
	return output;
}
 
//判断点p在圆内、圆c内或圆c外
int locate(const Point &p, const Circle &c)
{
	const Point cp(c.x,c.y); //圆心
	double d = cp.distance(p);
	if (abs(d - c.radius) < 1e-7)
		return 0;  //相等
	else if (d < c.radius)
		return -1;  //圆内
	else 
		return 1;  //圆外
}
 
//重载关系运算符（种）运算符，使之能够按圆的面积比较两个圆的大小；
bool Circle::operator>(const Circle &c)
{
	return (this->radius - c.radius) > 1e-7;
}
 
bool Circle::operator<(const Circle &c)
{
	return (c.radius - this->radius) > 1e-7;
}
 
bool Circle::operator>=(const Circle &c)
{
	return !(*this < c);
}
 
bool Circle::operator<=(const Circle &c)
{
	return !(*this > c);
}
 
bool Circle::operator==(const Circle &c)
{
	return abs(this->radius - c.radius) < 1e-7;
}
 
bool Circle::operator!=(const Circle &c)
{
	return abs(this->radius - c.radius) > 1e-7;
}
 
//再给一种解法：给定一点p，求出该点与圆的圆心相连成的直线与圆的两个交点（返回Two_points型值）
Two_points Circle::crossover_point(Point &p)
{
	Two_points pp;
	pp.p1.setx ( x + sqrt(radius*radius/(1+((y-p.gety())/(x-p.getx()))*((y-p.gety())/(x-p.getx())))));
	pp.p2.setx ( x - sqrt(radius*radius/(1+((y-p.gety())/(x-p.getx()))*((y-p.gety())/(x-p.getx())))));
	pp.p1.sety ( p.gety() + (pp.p1.getx() -p.getx())*(y-p.gety())/(x-p.getx()));
	pp.p2.sety ( p.gety() + (pp.p2.getx() -p.getx())*(y-p.gety())/(x-p.getx()));
	return pp;
}
 
int main( )
{
	Circle c1(3,2,4),c2(4,5,5);      //c2应该大于c1
	Point p1(1,1),p2(3,-2),p3(7,3);  //分别位于c1内、上、外
 
	cout<<"圆c1: "<<c1;
	cout<<"点p1: "<<p1;
	cout<<"点p1在圆c1之"<<((locate(p1, c1)>0)?"外":((locate(p1, c1)<0)?"内":"上"))<<endl;
	cout<<"点p2: "<<p2;
	cout<<"点p2在圆c1之"<<((locate(p2, c1)>0)?"外":((locate(p2, c1)<0)?"内":"上"))<<endl;	
	cout<<"点p3: "<<p3;
	cout<<"点p3在圆c1之"<<((locate(p3, c1)>0)?"外":((locate(p3, c1)<0)?"内":"上"))<<endl;
	cout<<endl; 
 
	cout<<"圆c1: "<<c1;
	if(c1>c2) cout<<"大于"<<endl;
	if(c1<c2) cout<<"小于"<<endl; 
	if(c1>=c2) cout<<"大于等于"<<endl;
	if(c1<=c2) cout<<"小于等于"<<endl; 
	if(c1==c2) cout<<"等于"<<endl; 
	if(c1!=c2) cout<<"不等于"<<endl; 
	cout<<"圆c2: "<<c2;
	cout<<endl; 
 
	cout<<"用另外一种方法求交点："<<endl;
	Two_points twoPoint = c1.crossover_point(p1);
	cout<<"点p1: "<<p1;
	cout<<"与圆c1: "<<c1;
	cout<<"的圆心相连，与圆交于两点，分别是："<<endl;
	cout<<"交点: "<<twoPoint.p1;
	cout<<"交点: "<<twoPoint.p2;
	while(1);
	return 0;

}
#endif