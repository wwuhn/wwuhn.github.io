//工厂模式
#include<iostream>
using namespace std;
//基类：运算类
class COperation
{
public:
    double numberA;
    double numberB;
    virtual double getResult() = 0;
};
//加法
class AddOperation: public COperation
{
public:
    virtual double getResult()
    {
        return numberA+numberB;
    }
};
//减法
class SubOperation: public COperation
{
public:
    virtual double getResult()
    {
        return numberA-numberB;
    }
};
//乘法
class MultiOperation: public COperation
{
public:
    virtual double getResult()
    {
        return numberA*numberB;
    }
};
//除法
class DivOperation: public COperation
{
public:
    virtual double getResult()
    {
        return numberA/numberB;
    }
};
//工厂类
class CCalculatorFactory
{
public:
    static COperation* Create(char cOperator);
};
 
 
COperation* CCalculatorFactory::Create(char cOperator)
{
    COperation *oper;
 
 
    switch (cOperator)
    {
    case '+':
        oper=new AddOperation();
        break;
    case '-':
        oper=new SubOperation();
        break;
    case '*':
        oper=new MultiOperation();
        break;
    case '/':
        oper=new DivOperation();
        break;
    default:
        oper=new AddOperation();
        break;
    }
    return oper;
}
 
 
int main()
{
restart:
    double a,b;
    char ch;
    cout<<"输入表达式，如3+4：";
    cin>>a>>ch>>b;
    COperation * op=CCalculatorFactory::Create(ch);
    op->numberA=a;
    op->numberB=b;
    cout<<op->getResult()<<endl;
    goto restart;
    return 0;
}