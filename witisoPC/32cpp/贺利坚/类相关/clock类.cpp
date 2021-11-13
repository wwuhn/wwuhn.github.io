#include <iostream>
using namespace std;

class Time
{
public:
    void set_time( );   
    void show_time( );  
    inline void add_a_sec();    //增加1秒钟
    inline void add_a_minute(); //增加1分钟
    inline void add_an_hour();  //增加1小时
    void add_seconds(int);      //增加n秒钟
    void add_minutes(int);      //增加n分钟
    void add_hours(int);        //增加n小时
private: 
    bool is_time(int, int, int);
    int hour;
    int minute;
    int sec;
};

void Time::set_time( ) 
{
    char c1,c2;
    cout<<"请输入时间(格式hh:mm:ss)";
    while(1)
    {
        cin>>hour>>c1>>minute>>c2>>sec;
        if(c1!=':'||c2!=':')
            cout<<"格式不正确，请重新输入"<<endl;
        else if (!is_time(hour,minute,sec))
            cout<<"时间非法，请重新输入"<<endl;
        else 
            break;
    }
}

void Time::show_time( )      
{
    cout<<hour<<":"<<minute<<":"<<sec<<endl;
}

bool Time::is_time(int h,int m, int s)
{
    if (h<0 ||h>24 || m<0 ||m>60 || s<0 ||s>60)
        return false;
    return true;
}

inline void Time::add_a_sec()  //增加1秒钟
{
    ++sec;				//直接修改sec的值即可，sec是Time类的数据成员
    if (sec>59)			//sec超出规定的范围，因为只是增加1秒，最多也就是向分钟进位1，所以增加1分钟。		
        add_a_minute();	//至于增加1分钟是否会引起小时变化，由add_a_minute()处理
}

inline void Time::add_a_minute() //增加1分钟
{
    ++minute;
    if (minute>59)		//参见add_a_sec()中的注释
        add_an_hour();
}

inline void Time::add_an_hour() //增加1小时
{
    ++hour;
    if (hour>23)
        hour=0;		//到第2天了
    
}
void Time::add_seconds(int n) //增加n秒钟
{
    sec+=n;			//直接加上去。此操作可能使sec超出取值范围，将在下面处理，我们只要保证此函数执行完sec的取值正确即可
    if (sec>59)		//思考：if中的两条语句能否交换顺序？为什么不能？后果将是……？
    {
        add_minutes(sec/60);	//增加sec/60分钟
        sec%=60;				//秒数应该是sec%=60
    }
}

void Time::add_minutes(int n) //增加n分钟
{
    minute+=n;
    if (minute>59)		//参见add_seconds()中的注释
    {
        add_hours(minute/60);
        minute%=60;
    }
}

void Time::add_hours(int n) //增加n小时
{
    hour+=n;
    if (hour>23)
        hour%=24;		//此程序不涉及日期，如果设计类DateTime，修改将继续下去
}

int main( )
{
    Time t1;  
    Time &t2=t1;
    t1.set_time( );  
    cout<<"现在时间是：";
    t2.show_time( );
    
    t1.add_a_sec();  //增加1秒钟
    cout<<"增加1秒钟后：";
    t1.show_time( );
    
    t1.add_a_minute(); //增加1分钟
    cout<<"增加1分钟后：";
    t1.show_time( );
    
    t1.add_an_hour(); //增加1小时
    cout<<"增加1小时后：";
    t1.show_time( );
    
    t1.add_seconds(40); //增加40秒钟
    cout<<"增加40秒钟后：";
    t1.show_time( );
    
    t1.add_minutes(127); //增加127分钟
    cout<<"增加127分钟后：";
    t1.show_time( );
    
    t1.add_hours(8); //增加8小时
    cout<<"增加8小时后：";
    t1.show_time( );
    while(1);
    return 0;
}