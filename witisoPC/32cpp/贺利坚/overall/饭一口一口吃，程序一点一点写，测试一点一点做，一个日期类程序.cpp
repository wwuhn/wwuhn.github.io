#include <iostream>  //饭一口一口吃，程序一点一点写，测试一点一点做，一个日期类程序
using namespace std;
struct Time
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};


//输入一个限定范围内的整型数值
int getNum(char *prompt, int min, int max)
{
    int value=-1;
    cout<<"输入"<<prompt<<"，范围["<<min<<","<<max<<"]:";
    do
    {
        cin>>value;
    }
    while(value<min || value>max);
    return value;
}


//返回y年m月的天数
int daysOfMonth(int m,int y)
{
    int days;
    switch(m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days=31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days=30;
        break;
    case 2:
        if((y%4==0&&y%100!=0)||y%400==0)
            days=29;
        else
            days=28;
    }
    return days;
}


//输入时间，参数为引用类型，可以影响实参的值
void getTime(Time &t)
{
    t.year=getNum("年",0,3000); //用于输入一定范围内的数
    t.month=getNum("月",1,12);
    t.day=getNum("日",1,daysOfMonth(t.month, t.year));
    t.hour=getNum("时",0,24);
    t.minute=getNum("分",0,59);
    t.second=getNum("秒",0,59);
}


//输出时间，参数也用作引用是对结构常见的处理办法
void outputTime(Time &t)
{
    cout<<"时间为: "<<t.year<<"年"<<t.month<<"月"<<t.day<<"日"<<t.hour<<"时"<<t.minute<<"分"<<t.second<<"秒"<<endl;
}


//这天是这一年的第几天
int dayOfYear(Time &t)
{
    int days=0;
    int m=1;
    while(m<t.month)  //前若干月的天数加起来
    {
        days+=daysOfMonth(m,t.year);  //充分利用已经设计的函数
        ++m;
    }
    days+=t.day; //再加上本月的天数
    return days;
}


//这天是这一天的第几秒
int secondOfDay(Time &t)
{
    return t.hour*3600+t.minute*60+t.second;
}


//返回一年有多少天（365或366天）
int daysOfYear(int y)
{
    return ((y%4==0&&y%100!=0)||y%400==0)?366:365;
}


//求你输入的时间d天后是哪年哪月哪日
Time afterDays(Time t,int d)
{
    Time t1=t;
    int d1=d+dayOfYear(t); //dayOfYear(t)求出t是当年第几天
    t1.month=1;
    t1.day=0;  //这样，将问题转换为在当年1月0日基础上加d1天(这个0有意思)，避免以后老为2月操心，以及剩余天数一加以后持续进位
    //    cout<<"转换为";
    //    outputTime(t1);
    //    cout<<"这一天后"<<d1<<"天。";
    while(d1>daysOfYear(t1.year))  //天数还够一个整年
    {
        d1-=daysOfYear(t1.year);
        ++t1.year;
    }
    //天数不够一整年后，再考虑月，因为从1月1日开始，不用担心Nt.year再加1年
    while(d1>daysOfMonth(t1.month,t1.year))  //天数还够一个整月
    {
        d1-=daysOfMonth(t1.month,t1.year);
        ++t1.month;
    }
    //剩全天数加到日上
    t1.day+=d1;
    return t1;
}


int main()
{
    Time t,nt;
    //（1）输入一个时间（注意各部分数据的取值范围）将输入的时间保存在一个结构体变量中；
    cout<<"请输入一个时间(包括年，月，日，时，分，秒):"<<endl;
    getTime(t);
    outputTime(t);
    //（2）输出该日在本年中是第几天（注意闰年问题）；
    cout<<"这是这一年中的第"<<dayOfYear(t)<<"天。"<<endl;
    //（3）输出这是这一天中的第几秒；
    cout<<"这是这一天中的第"<<secondOfDay(t)<<"秒。"<<endl;
    //（4）输出这是这一年中的第几秒；
    cout<<"这是这一年中的第"<<dayOfYear(t)*24*3600+secondOfDay(t)<<"秒。"<<endl;
    //（5）求你输入的时间d天后是哪年哪月哪日，将结果保存在一个结构体变量中输出；
    int d;
    cout<<"请输入一个天数";
    cin>>d;
    nt=afterDays(t,d);
    cout<<"这一天后d（如10000）天后是：";
    outputTime(nt);
    //（6）求你输入的时间s秒后是何日何时，将结果保存在一个结构体变量中输出；
    
    while(1);
    return 0;
}