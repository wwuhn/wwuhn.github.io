#include <iostream>  // 友元类
using namespace std;

// 为体验友元类，实际上本例并不一定是一个好的设计，
// 将两个类的合并为一个DateTime，日期、时间都处理更好
class Date;     //对Date类的提前引用声明
class Time
{
public:
    Time(int,int,int);
    void add_a_second(Date &);  //增加1秒，1秒后可能会到了下一天，乃到下一月、下一年
    void display(Date &);       //显示时间，格式：月/日/年 时:分:秒
private:
    int hour;
    int minute;
    int sec;
};
 
class Date
{
public:
    Date(int,int,int);
    friend class Time;  //Time定义为Date的友元类
private:
    int month;
    int day;
    int year;
};
 
int main( )
{
    Time t1(23,59,32);
    Date d1(12,25,2012);
    for(int i=0; i<=80; i++)
    {
        t1.add_a_second(d1);
        t1.display(d1);
    }
    while(1);
    return 0;
}
//下面定义两个类中的成员函数，要求不得再增加成员函数
//注意体会在Time的成员函数中可以调用Date类的私有数据成员
Time::Time(int h,int m,int s)
{
    hour=h;
    minute=m;
    sec=s;
}
Date::Date(int m,int d,int y)
{
    month=m;
    day=d;
    year=y;
}
void Time::add_a_second(Date &d)
{
    if(++sec>=60) ++minute,sec-=60;
    if(minute>=60) ++hour,minute-=60;
    if(hour>=24) ++d.day,hour-=24;
    if(d.day>30) ++d.month,d.day-=30;//Q.这里需要再完善，并不是每一个月都是30天
    if(d.month>12) ++d.year,d.month-=12;//Q.
}
void Time::display(Date &d)
{
    cout<<d.month<<"/"<<d.day<<"/"<<d.year<<" ";
    cout<<hour<<":"<<minute<<":"<<sec<<endl;
}