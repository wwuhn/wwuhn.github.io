#include <iostream>  // 摩托车继承自行车和机动车
#include<conio.h>
#include <windows.h>
using namespace std;

enum VehicleStaus {rest, running};  //车辆状态：泊车、行进

class Vehicle //车辆类
{
protected:
    int maxSpeed;		//最大车速
    int currentSpeed;	//当前速度
    int weight;			//车重
    VehicleStaus status; //rest-泊车状态；running-行进状态
public:
    Vehicle(int maxS, int w);   //构造函数，初始时，当前速度总为0且处在停车状态
    void start();               //由rest状态到running, 初速为1
    void stop();                //由running状态到rest, 当前速度小于5时，才允许停车
    void speed_up();            //加速，调用1次，速度加1
    void slow_down();           //减速，调用1次，速度减1，速度为0时，停车
};

//构造函数，初始时，当前速度总为0且处在停车状态
Vehicle::Vehicle(int maxS, int w):maxSpeed(maxS), currentSpeed(0),weight(w), status(rest) {}

//启动：由rest状态到running, 初速为1
void Vehicle::start()
{
    if (status==rest)
    {
        status=running;
        currentSpeed=1;
    }
    else
        cout<<"车辆已经行驶！"<<endl;
}
//由running状态到rest, 当前速度小于5时，才允许停车
void Vehicle::stop()
{
    if (status==running)
        if(currentSpeed<5)
        {
            status=rest;
            currentSpeed=0;
        }
        else
            cout<<"车速太快！先减速再停车……"<<endl;
        else
            cout<<"车辆未启动！"<<endl;
}

//加速，调用1次，速度加1
void Vehicle::speed_up()
{
    if (status==running)
        if(currentSpeed<maxSpeed)
            ++currentSpeed;
        else
            cout<<"请不要超速行驶……"<<endl;
        else
            cout<<"车辆未启动！"<<endl;
}
//减速，调用1次，速度减1，速度为0时，停车
void Vehicle::slow_down()
{
    if (status==running)
    {
        if(currentSpeed>0)
            --currentSpeed;
    }
    else
        cout<<"车辆未启动！"<<endl;
    if(currentSpeed==0)
        status=rest;
}

class Bicycle :virtual public Vehicle       //（）自行车类
{
protected:
    double height;                              //车高
public:
    Bicycle(int maxS=10, int w=50, int h=0.7);   //定义构造函数
};

Bicycle::Bicycle(int maxS, int w, int h):Vehicle(maxS, w),height(h) {}

class Motorcar : virtual public Vehicle     //（）机动车类
{
protected:
    int seatNum;     //座位数
    int passengerNum; //乘客人数
public:
    Motorcar(int maxS=150, int w=1500, int s=5, int p=1);   //定义构造函数
    void addPassenger(int p=1);   //搭载乘客，超员要拒载，有人下车时，p为负数。当然车上乘客至少有1个（司机）。上下车时要保证安全……
};

//定义构造函数
Motorcar::Motorcar(int maxS, int w, int s, int p): Vehicle(maxS, w),seatNum(s),passengerNum(p) {}

//搭载乘客，超员要拒载，有人下车时，p为负数。当然车上乘客至少有1个（司机）。上下车时要保证安全……
void Motorcar::addPassenger(int p)
{
    if (status==running)
    {
        cout<<"车辆正在行驶，停车后再上下车！"<<endl;
    }
    else
    {
        passengerNum+=p;
        if(passengerNum>seatNum)
        {
            passengerNum=seatNum;
            cout<<"涉嫌超员，已清理后达到满员！"<<endl;
        }
        else if (passengerNum<1)
        {
            passengerNum=1;
            cout<<"请司机不要离开岗位！"<<endl;
        }
    }
}

class Motorcycle: public Bicycle, public Motorcar //（）摩托车类
{
public:
    Motorcycle(int maxS=90, int w=100, int s=3, int p=1, int h=0.7);   //定义构造函数
    void show(); //显示摩托车的运行状态
};

//定义构造函数
Motorcycle::Motorcycle(int maxS, int w, int s, int p, int h):Vehicle(maxS, w),Bicycle(maxS, w, h),Motorcar(maxS, w, s, p) {}

//显示摩托车的运行状态
void Motorcycle::show()
{
    cout<<"状态：";
    if(status==rest)
        cout<<"泊车；\t";
    else
        cout<<"行进；\t";
    cout<<"车速："<<currentSpeed<<" / "<< maxSpeed <<"\t当前乘员："<<passengerNum<<" / "<< seatNum << endl;
}

int main( )
{
    Motorcycle m;
    bool end=false;
    while (!end)
    {
        cout<<"请操作：1-启动  2-加速  3-减速  4-有人上车  5-有人下车  6-停车 0-结束"<<endl;
        char keydown= _getch(); //_getch()返回键盘上读取的字符,应包含头文件<conio.h>
        switch(keydown)
        {
        case '1':
            cout<<"选中的操作是1-启动\t";
            m.start();
            break;
        case '2':
            cout<<"选中的操作是2-加速\t";
            m.speed_up();
            break;
        case '3':
            cout<<"选中的操作是3-减速\t";
            m.slow_down();
            break;
        case '4':
            cout<<"选中的操作是4-有人上车\t";
            m.addPassenger();
            break;
        case '5':
            cout<<"选中的操作是5-有人下车\t";
            m.addPassenger(-1);
            break;
        case '6':
            cout<<"选中的操作是6-停车\t";
            m.stop();
            break;
        case '0':
            end=true;
            break;
        }
        m.show();
        cout<<endl;
        Sleep(200);  //要包含头文件<windows.h>
    }
    while(1);
    return 0;
}