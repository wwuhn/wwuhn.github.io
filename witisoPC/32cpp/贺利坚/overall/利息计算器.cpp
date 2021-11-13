#include<iostream>
using namespace std; 
int main()  
{  
    int  type, days;  
    double money, period, rate, interest;  
    cout << "欢迎使用利息计算器！"<<endl;
    cout << "请输入存款金额：";  
    cin >> money;  
    cout << "======存款期限======" << endl;  
    cout << "1. 活期存款" << endl;
    cout << "2. 3个月 " << endl;
    cout << "3. 6个月" << endl;
    cout << "4. 一年 " << endl;
    cout << "5. 二年" << endl;
    cout << "6. 三年" << endl;
    cout << "7. 五年" << endl;
    cout << "请输入存款期限的代号：";
    cin >> type;
    if (type>=1 && type <=7)
    {
        switch(type)//在if中嵌入了switch分情况处理
        {
        case 1: 
            cout<<"请输入存款天数：";
            cin >> days;
            period = days/360.0;
            rate = 0.005;
            break;
        case 2:
            period = 0.25;
            rate = 0.031;
            break;
        case 3:
            period = 0.5;
            rate = 0.033;
            break;
        case 4:
            period = 1;
            rate = 0.035;
            break;
        case 5:
            period = 2;
            rate = 0.044;
            break;
        case 6:
            period = 3;
            rate = 0.05;
            break;
        case 7:
            period = 5;
            rate = 0.055;
            break;		
        }
        interest = money * period * rate;
        cout << "到期利息为：" << interest << "元，本息合计共"<< interest + money <<"元。"<<endl;  
    }
    else
        cout << "选择存款类型错误！"<<endl;
    cout << "感谢您的使用，欢迎下次光临！"<<endl;  
    while(1);
    return 0;  
}  