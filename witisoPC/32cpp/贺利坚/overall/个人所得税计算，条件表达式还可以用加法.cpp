/*
个人所得税计算，条件表达式还可以用加法
*/
#if 0

//1 先提供一个用if-else完成的解法

#include <iostream>    
using namespace std;

int main( )  
{  
    double dSalary,dTax=0,dNetIncome=0;//请欣符合匈牙利命名法的变量名
    double dValue; //在模板基础上加一个变量，表示超出起征点的收入
    cout<<"请输入您本月的收入总额（元）：";
    cin>>dSalary;
    dValue=dSalary-3500; //在起征点基础上考虑纳税 
    if(dValue<=0.0)  
        dTax=0.0;
    else  
    {  
        if(dValue<=1500)
            dTax=dValue*0.03-0.0; //直接根据税率和速算扣除数计算
        else if(dValue<=4500)
            dTax=dValue*0.10-105.0; 
        else if(dValue<=9000)
            dTax=dValue*0.20-555.0;
        else if(dValue<=35000)
            dTax=dValue*0.25-1005.0; 
        else if(dValue<=55000) 
            dTax=dValue*0.30-2755.0;
        else if(dValue<=80000)
            dTax=dValue*0.35-5505.0;
        else 
            dTax=dValue*0.45-13505.0;
    }  
    dNetIncome=dSalary-dTax; //计算得到
    cout<<"您本月应缴个人所得税 "<<dTax<<" 元，税后收入是 "<<dNetIncome<<" 元。\n";
    cout<<"依法纳税，共享繁荣。谢谢使用！\n";
    while(1);
    return 0;
}  

#endif

#if 0

//参考2：在参考1基础上做些改进的解法
#include <iostream>    
using namespace std;
int main( )  
{  
    double dSalary,dTax = 0,dNetIncome = 0;//请欣符合匈牙利命名法的变量名
    double dValue; //在模板基础上加一个变量，表示超出起征点的收入
    double dRate, dOffset;//分别表示税率和速算扣除数
    cout<<"请输入您本月的收入总额（元）：";
    cin>>dSalary;
    dValue = dSalary - 3500; //在起征点基础上考虑纳税 
    if(dValue <= 0.0)  
        dTax = 0.0;//不需要交税
    else  
    {  
        if(dValue <= 1500)
            dRate = 0.03, dOffset = 0.0; //这一组if语句用于得到税率和速算扣除数
        else if(dValue <= 4500)
            dRate = 0.1, dOffset = 105.0; 
        else if(dValue <= 9000)
            dRate = 0.2, dOffset = 555.0;
        else if(dValue <= 35000)
            dRate = 0.25, dOffset = 1005.0; 
        else if(dValue <= 55000) 
            dRate = 0.3, dOffset = 2755.0;
        else if(dValue <= 80000)
            dRate = 0.35, dOffset = 5505.0;
        else 
            dRate = 0.45, dOffset = 13505.0;
        dTax = dValue * dRate - dOffset;//计算所得税，体会将“确定参数”与“计算”分开的好处：思路更明晰，不易在计算公式上犯大错
    }  
    dNetIncome = dSalary-dTax;      //计算税后收入
    cout<<"您本月应缴个人所得税 "<<dTax<<" 元，税后收入是 "<<dNetIncome<<" 元。\n";
    cout<<"依法纳税，共享繁荣。谢谢使用！\n"; 
    while(1);
    return 0;
}  

#endif

#if 0


// 参考3：下面是用switch语句完成的程序。如果感觉这样做还不如直接用if，这种看法也是对的，
// 这种解法的意义也就仅在于练习switch了。
#include <iostream>    
using namespace std;
int main( )  
{  
    double dSalary,dTax = 0,dNetIncome = 0;//请欣符合匈牙利命名法的变量名
    double dValue; //在模板基础上加一个变量，表示超出起征点的收入
    double dRate, dOffset;//分别表示税率和速算扣除数
    int iStep;     //用于确定交税的“档次”
    cout<<"请输入您本月的收入总额（元）：";
    cin>>dSalary;
    dValue = dSalary - 3500; //在起征点基础上考虑纳税 
    if(dValue <= 0.0)  
        dTax = 0.0;//不需要交税
    else  
    {  
        //这一组if语句确定交税的档次
        if(dValue <= 1500)
            iStep = 1;
        else if(dValue <= 4500)
            iStep = 2;
        else if(dValue <= 9000)
            iStep = 3;
        else if(dValue <= 35000)
            iStep = 4;
        else if(dValue <= 55000) 
            iStep = 5;
        else if(dValue <= 80000)
            iStep = 6;
        else 
            iStep = 7;
        
        //根据确定的档次，得到税率和速算扣除数，这样处理和问题中给出的列表形式有较好的对应
        //如果按照教材中的例子，通过类似c=s/n（n最大取500）的形式得到switch的<表达式>，下面的清单得列的很长
        switch(iStep)
        {
        case 1:
            dRate = 0.03, dOffset = 0.0;break; 
        case 2:
            dRate = 0.1, dOffset = 105.0;break;
        case 3:
            dRate = 0.2, dOffset = 555.0; break;
        case 4:
            dRate = 0.25, dOffset = 1005.0;break;
        case 5:
            dRate = 0.3, dOffset = 2755.0; break;
        case 6:
            dRate = 0.35, dOffset = 5505.0; break;
        case 7:
            dRate = 0.45, dOffset = 13505.0;
        }
        dTax = dValue * dRate - dOffset;//计算所得税，体会将“确定参数”与“计算”分开的好处：思路更明晰，不易在计算公式上犯大错
    }  
    dNetIncome = dSalary-dTax;      //计算税后收入
    cout<<"您本月应缴个人所得税 "<<dTax<<" 元，税后收入是 "<<dNetIncome<<" 元。\n";
    cout<<"依法纳税，共享繁荣。谢谢使用！\n";
    while(1);
    return 0;
} 

#endif



#if 0


// 参考4：话说到这里过早了，需要在switch前用点脑子，
// 下面是2011级一位同学给出的解答（原始链接）

#include <iostream>  
using namespace std;
int main( )
{
    double m=0,s=0,f=0; //m为总收入，s为需要缴税的部分,f为税额
    int t=0;          //t用做判断
    cout<<"你丫的一个月挣多少银子？？？"<<'\n';
    cin>>m;
    if (m<=3500)
        cout<<"你不需要缴税，谢谢使用，请努力工作争取加工资！";
    else
    {
        s=m-3500;
        t=(s>=1500)+(s>=4500)+(s>=9000)+(s>=35000)+(s>=55000)+(s>=80000); 
        //这是亮点，条件表达式为真，其值为1，t表示符合条件的个数
        switch(t)
        {
        case 6:f=s*0.45-13505;break;
        case 5:f=s*0.35-5505;break;
        case 4:f=s*0.30-2755;break;
        case 3:f=s*0.25-1005;break;
        case 2:f=s*0.20-555;break;
        case 1:f=s*0.10-105;break;
        case 0:f=s*0.03;break;
        }
        cout<<"您的税后收入为： "<<m-f<<'\n';
        cout<<'\n';
        cout<<"* * * * * * * * * * *"<<'\n';
        cout<<"* 爱国护税,人人有责 *"<<'\n';
        cout<<"* * * * * * * * * * *"<<'\n';
    }
    return 0;
}


#endif







#if 1


//参考5：引入数组，实现了数据与程序的分离。其实，分离的程度还不够。在正式的项目中，
// 数据几乎没有定义在程序中的。如果感兴趣，自己看一看数组，再理解这个解答；
// 如果觉得太费脑子，看一下忽略过去，反正后面才学。

#include <iostream>
using namespace std;
int main( )
{
    double dSalary,dTax = 0,dNetIncome = 0;//请欣赏符合匈牙利命名法的变量名
    double dValue; //在模板基础上加一个变量，表示超出起征点的收入
    double dValues[]={1500,4500,9000,35000,55000,80000};//用数组表示各段分界线
    double dRate  []={0.03,0.10,0.20, 0.25,0.30, 0.35,0.45};//用数组描述各段税率
    double dOffset[]={0,   105, 555,  1005,2755, 5505,13505};  //用数组描述速算扣除数
    int iStep, i;     //iStep用于确定交税的“档次”，i用作为循环变
    cout<<"请输入您本月的收入总额（元）：";
    cin>>dSalary;
    dValue = dSalary - 3500; //在起征点基础上考虑纳税
    if(dValue <= 0.0)
        dTax = 0.0;//不需要交税
    else
    {
        i=0;
        while(dValue > dValues[i] && i<=6)//通过在数组中查找确定交税的档次
            i++;
        iStep=i;
        dTax = dValue * dRate[iStep] - dOffset[iStep];//计算所得税，这种解决方法将程序和数据分开，更简洁
    }
    dNetIncome = dSalary-dTax;      //计算税后收入
    cout<<"您本月应缴个人所得税 "<<dTax<<" 元，税后收入是 "<<dNetIncome<<" 元。\n";
    cout<<"依法纳税，共享繁荣。谢谢使用！\n";
    while(1);
    return 0;
}
#endif