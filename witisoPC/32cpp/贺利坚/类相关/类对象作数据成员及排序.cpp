#include <iostream.h>  // 类对象作数据成员及排序
#include <Cstring>

#define MAX 100


class CDate  // 定义日期类
{
private:
    unsigned short int year;   // 年
    unsigned short int month;  // 月
    unsigned short int day;    // 日
public:
    CDate(int y=0,int m=0,int d=0);
    bool operator < (CDate d);
    friend istream & operator >> (istream &in,CDate &d);
    friend ostream & operator<<(ostream &out,CDate &d);
    friend bool CheckValid(CDate d);
    friend bool LeapYear(int year);
    void SetDate(int y,int m,int d);
};
CDate::CDate(int y,int m,int d):year(y),month(m),day(d){}
// 设置日期
void CDate::SetDate(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
}
// 重载输入运算符>>
istream &operator>>(istream &in,CDate &d)
{
    char ch1,ch2;
    cout<<"请输入日期(输入格式：2021-3-12)：";
    while(1)
    {
        cin>>d.year>>ch1>>d.month>>ch2>>d.day;
        if (ch1=='-' && ch2=='-')
            if (CheckValid(d)) break;
            cerr<<"时间格式不正确! 请重新输入\n";
    }
    return cin;
}
// 重载输出运算符<<
ostream &operator<<(ostream &out,CDate &d)
{
    out<<d.year<<"年"<<d.month<<"月"<<d.day<<"日";
    return out;
}
// 判断日期d1<d2
bool CDate::operator < (CDate d)
{
    if (year<d.year) return true;
    if (year>d.year) return false;
    if (month<d.month) return true;
    if (month>d.month) return false;
    if (day<d.day) return true;
    return false;
}
// 检查日期合法性
bool CheckValid(CDate d)
{
    int n;
    if (d.month<1 || d.month>12) return false;
    if (d.day<1) return false;
    n=31;
    switch(d.month)
    {
    case 2:
        if (LeapYear(d.year)) 
            n=29;
        else              
            n=28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        n=30;
        break;
    }
    if (d.day>n) return false;
    return true;
}
// 检查是否为闰年
bool LeapYear(int year)
{
    if (year%4==0 && year%100 || year%400==0) return true;
    return false;
}


class CStudent
{
private:
    char *name;              // 姓名
    bool sex;                // 性别
    CDate date;              // 出生日期，类对象作数据成员
public:
    static int num;          // 学生人数
    CStudent();
    void InputData();
    friend void Sort();      // 排序
    friend void FindName();  // 按姓名查询
    friend void Statistic(); // 按性别统计
    friend void Display();   // 显示全部信息
} stu[MAX];
int CStudent::num=0;
CStudent::CStudent(){}
// 输入信息
void CStudent::InputData()
{
    int p;
    char s[41];
    cout<<"请输入学生信息（NO."<<num<<"）：\n";
    cout<<"姓名：";
    cin>>s;
    name=new char[strlen(s)+1];
    strcpy(name,s);
    cout<<"性别(1-男，-女)：";
    cin>>p;
    if (p)  sex=true;
    else sex=false;
    cin>>date;
    cout<<endl;
}
// 排序
void Sort()
{
    int i,j,p,num;
    char *tn;
    bool ts;
    CDate td;
    num=CStudent::num;
    for(i=1;i<num;i++)
    {
        p=i;
        for(j=i+1;j<=num;j++)
            if (stu[j].date<stu[p].date) p=j;//找到当前未排序元素中年龄最小的对象的下标
            if (p==i) continue;
            //下面交换stu[i]和stu[p]
            tn=stu[i].name; stu[i].name=stu[p].name; stu[p].name=tn;
            ts=stu[i].sex; stu[i].sex=stu[p].sex; stu[p].sex=ts;
            td=stu[i].date; stu[i].date=stu[p].date; stu[p].date=td;
    }
}
// 按姓名查询
void FindName()
{
    char name[41];
    int i,num;
    cout<<"请输入姓名：";
    cin>>name;
    num=CStudent::num;
    for(i=1;i<=num;i++)
        if (strcmp(stu[i].name,name)==0) break;
        if (i>num)
        {
            cout<<"查无此人!"<<endl<<endl;
            return;
        }
        //如果查到了，显示学生信息
        cout<<"姓名："<<stu[i].name<<endl;
        cout<<"性别：";
        if (stu[i].sex) cout<<"男"<<endl;
        else         cout<<"女"<<endl;
        cout<<"生日："<<stu[i].date<<endl;
        cout<<endl;
}
// 按性别统计
void Statistic()
{
    int i,num,s1,s0;
    num=CStudent::num;
    s1=0;
    s0=0;
    for(i=1;i<=num;i++)
        if (stu[i].sex==1)
            s1++;
        else
            s0++;
        cout<<"男生人数："<<s1<<endl;
        cout<<"女生人数："<<s0<<endl;
        cout<<endl;
}
// 显示全部信息
void Display()
{
    int i,num;
    num=CStudent::num;
    for(i=1;i<=num;i++)
    {
        cout<<stu[i].name<<"  ";
        if (stu[i].sex) 
            cout<<"男";
        else        
            cout<<"女";
        cout<<stu[i].date<<endl;
    }
    cout<<endl;
}
void main()
{
    char *menu[]={ "","输入信息","排序","按姓名查询","按性别统计","显示全部信息","退出" };
    int i,p;
    bool end;
    end=false;
    while(!end)
    {
        for(i=1;i<7;i++)
            cout<<i<<"  "<<menu[i]<<endl;
        cin>>p;
        switch(p)
        {case 1:                          // 输入信息
        CStudent::num++;
        stu[CStudent::num].InputData(); break;
        case 2:                          // 排序
            Sort(); break;
        case 3:                          // 按姓名查询
            FindName(); break;
        case 4:                          // 按性别统计人数
            Statistic(); break;
        case 5:                          // 显示全部信息
            Display(); break;
        case 6:                          // 退出
            end=true; break;
        }
    }
}