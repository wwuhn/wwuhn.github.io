//有指针成员的工资类

#include<iostream>
using namespace std;
class Salary
{
public:
    Salary(int n);
    ~Salary();
    void input_salary();
    void show_salary();
private:
    double *salary;
    int number;
};

Salary::Salary(int n)
{
    number=n;
    salary = new double[number];  //根据职工人数，确定分配空间的大小
}
Salary::~Salary()
{
    delete []salary;   //注意：必须在析构函数中释放动态分配的空间
}

void Salary::input_salary()
{
    int i;
    cout << "请输入"<<number<<"名职工的工资:" << endl;
    for(i = 0; i < number; ++i) 
        cin >> *(salary+i);
    return ;
}

void Salary::show_salary()
{
    cout << "职工工资清单: " ;
    for(int i = 0; i < number; ++i)
        cout << *(salary+i)<<" ";
    cout << endl;
    return ;
}

int main()
{
    Salary s(10);
    s.input_salary();
    s.show_salary();
    return 0;
}