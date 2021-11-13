#include <iostream>  // 含有静态数据成员和成员函数的Time类
using namespace std;
class Time
{
public:
    Time(int=0,int=0,int=0);
    void show_time( );      //根据is_24和from0，输出适合形式的时间20:23:5/8:23:5 pm/08:23:05 pm
    void add_seconds(int);  //增加n秒钟
    void add_minutes(int);  //增加n分钟  
    void add_hours(int);    //增加n小时  
    static void change24(); //改变静态成员is_24，在12和24时制之间转换
    static void changefrom0();   //改变静态成员from0，转换是否前导0
private:
    static bool is_24; //为true时，24小时制，如20:23:5；为flase，12小时制，显示为8:23:5 pm 
    static bool from0; //为true时，前导0，8:23:5显示为08:23:05
    int hour;
    int minute;
    int sec;
};
bool Time::is_24=true;
bool Time::from0=false;

Time::Time(int h,int m,int s): hour(h), minute(m), sec(s){}

void Time::show_time( )     //不要一遇到需要分情况讨论时就直接用if-else，换一种角度，写出简洁的程序来
{
    //输出 时
    int h=(is_24)?hour:hour%12;  //这样写比下面的简洁
    //if(is_24)   //不要写作if(is_24==true)。对，但显得有些太菜
    //	h=hour;
    //else 
    //	h=hour%12;
    if (h<10 && from0) cout<<'0';   //写成if (h<10 && from0==true)...就显菜了
    cout<<h<<':';
    
    //输出 分
    if(minute<10 && from0) cout<<'0';
    cout<<minute<<':';
    
    //输出 秒
    if(sec<10&&from0) cout<<'0';
    cout<<sec; 
    
    //输出pm或am
    if(!is_24)  //比写if(is_24==false)...强
        cout<<(hour>12)? " pm":" am";//这样写比下面的简洁
    
    //if (hour>12)
    //	cout<<" pm";
    //else
    //	cout<<" am";
    cout<<endl;
}

void Time::add_seconds(int n) //增加n秒钟  
{  
    sec+=n;        
    if (sec>59)     
    {  
        add_minutes(sec/60);    
        sec%=60;        
    }  
}  

void Time::add_minutes(int n) //增加n分钟  
{  
    minute+=n;  
    if (minute>59)   
    {  
        add_hours(minute/60);  
        minute%=60;  
    }  
}  

void Time::add_hours(int n) //增加n小时  
{  
    hour+=n;  
    if (hour>23)  
        hour%=24;       
}  

void Time::change24()
{
    is_24=!is_24;
}
void Time::changefrom0()
{
    from0=!from0;
}

int main( )   
{
    Time t1(23,14,25),t2(8,45,6); 
    cout<<"24时制, 不前导0："<<endl;
    cout<<"    t1是：";
    t1.show_time();
    cout<<"    t2是：";
    t2.show_time();
    t1.add_hours(10);
    t2.add_hours(10);
    Time::changefrom0(); //注意此处调用静态成员
    cout<<"10小时后, 切换是否前导0："<<endl;
    cout<<    "t1是：";
    t1.show_time();
    cout<<    "t2是：";
    t2.show_time();
    t1.change24();
    cout<<"换一种制式："<<endl;
    cout<<"    t1是：";
    t1.show_time();
    cout<<"    t2是：";
    t2.show_time();
    system("pause");
    return 0;
}