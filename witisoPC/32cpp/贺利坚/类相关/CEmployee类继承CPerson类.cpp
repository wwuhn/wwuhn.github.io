#include <iostream>
#include <string.h>   // CEmployee类继承CPerson类
#include <iomanip> 
using namespace std;

class CPerson 
{
protected:
    char *m_szName;
    char *m_szId;
    int m_nSex;//0:women,1:man
    int m_nAge;
public:
    CPerson(char *name,char *id,int sex,int age);
    void Show1();
    ~CPerson();
};

class CEmployee:public CPerson
{
private:
    char *m_szDepartment;
    float m_Salary;
public:
    CEmployee(char *name,char *id,int sex,int age,char *department,float salary);
    void Show2();
    ~CEmployee();
};

CPerson::CPerson(char *name,char *id,int sex,int age)
{
    m_szName=new char[strlen(name)+1];  //此处的处理是个重点，处理不好，会在程序中植入非常严重且隐蔽性极强的“定时炸弹”
    strcpy(m_szName,name);
    m_szId=new char[strlen(id)+1];      //同上
    strcpy(m_szId,id);
    m_nSex=sex;
    m_nAge=age;
}

void CPerson::Show1()
{
    cout<<setw(10)<<m_szName<<setw(25)<<m_szId;	//setw:设置输出数据的宽度,使用时应#include <iomanip.h> 
    if(m_nSex==0)
        cout<<setw(7)<<"women";
    else
        cout<<setw(7)<<"man";
    cout<<setw(5)<<m_nAge<<endl;
}

CPerson::~CPerson()
{
    delete [ ]m_szName;
    delete [ ]m_szId;
}

CEmployee::CEmployee(char *name,char *id,int sex,int age,char *department,float salary):CPerson(name,id,sex,age)
{
    m_szDepartment=new char[strlen(department)+1];
    strcpy(m_szDepartment,department);
    m_Salary=salary;
}

void CEmployee::Show2()//注意派生类输出函数应输出所有成员变量（含基类继承的成员变量）的值
{
    cout<<setw(10)<<"name"<<setw(25)<<"id"<<setw(7)<<"sex"<<setw(5)<<"age"<<setw(12)<<"department"<<setw(10)<<"salary"<<endl;
    cout<<setw(10)<<m_szName<<setw(25)<<m_szId;	 
    if(m_nSex==0)
        cout<<setw(7)<<"women";
    else
        cout<<setw(7)<<"man";
    cout<<setw(5)<<m_nAge;
    //由于基类CPerson的成员变量采用了protected属性，因此可采用上述述代码显示来自基类的数据成员，否则
    //若基类CPerson的成员变量采用了privated属性，则只能使用CPerson::Show();实现
    cout<<setw(12)<<m_szDepartment<<setw(10)<<m_Salary<<endl;
}

CEmployee::~CEmployee()
{
    delete [ ]m_szDepartment;
}

int main()
{
    char name[10],id[19],department[10];
    int sex,age;
    float salary;
    cout<<"input employee's name,id,sex(0:women,1:man),age,department,salary:\n";
    cin>>name>>id>>sex>>age>>department>>salary;
    CEmployee employee1(name,id,sex,age,department,salary);
    employee1.Show2();

    while(1);
    return 0;
}
/*
wwu 2012 1 44 wh 66
  */