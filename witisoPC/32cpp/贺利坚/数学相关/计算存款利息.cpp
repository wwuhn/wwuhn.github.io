/* 程序头部注释开始   计算存款利息
* 程序的版权和版本声明部分
* Copyright (c)2011, 烟台大学计算机学院
* All rightsreserved.
* 文件名称： interest.cpp
* 作    者： 贺利坚
* 完成日期：  2011 年 11 月 15 日
* 版 本 号：  V1.0

  * 对任务及求解方法的描述部分
  * 输入描述：金额与存期
  * 问题描述：输入存款金额并选择存款种类，计算出利息（不计利息税）。如果是活期存款，需要补充输入天数。利息=金额×年利率×存期（单位：年，活期一年按360天计）。要求使用switch语句，根据选择的存款种类，确定利率和存期后计算。利率使用2011年7月7日公布的最新年利率：活期  0.50%，3个月  3.10%，6个月 3.30%，一年 3.50%，二年 4.40%，三年 5.00%，五年 5.50%。
  * 程序输出：利息及本息合计

*/
#include<iostream>
#include<iomanip>
using namespacestd;
int main( )
{
    double money,rate,years,interest;  //取有意义的变量名将使你自己受益
    int term,days;                  //每一个变量的含义均要明确
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout<<" 请输入存款金额（元）：";
    cin>>money;
    do
    {
        cout<<"  ************************"<<endl;
        cout<<"  1 - 一年"<<endl;     //1,2,3,5和定期年限联系起来，考虑用户方便，直观些
        cout<<"  2 - 二年"<<endl;
        cout<<"  3 - 三年"<<endl;
        cout<<"  5 - 五年"<<endl;
        cout<<"  0 - 活期"<<endl;     //用统一的公式计算，不必将定活期分开，减轻用户负担
        cout<<"  8 - 3个月"<<endl;
        cout<<"  9 - 6个月"<<endl;
        cout<<"请选择存期：";
        cin>>term;
        if(term<0||term==4||term==6||term==7||term>9) //不允许非法选项
        {
            cout<<"请重新选择存期！"<<endl;
            continue;
        }
        else
            break; //term是合法的值，跳出去，接着执行下面的工作
    }while(1);
    
    switch(term)  //根据存期，确定在计算利息时需要用到的参数的值
    {
    case 1:
        rate=0.035; years=1;break;
    case 2:
        rate=0.044; years=2;break;
    case 3:
        rate=0.05; years=3;break;
    case 5:
        rate=0.055; years=5;break;
    case 0:   //活期时有些特殊性，但也仅是由输入的天数变年数而已
        rate=0.005;
        cout<<"请输入天数:";
        cin>>days;
        years=double(days)/360;
        break;
    case 8:   //存期3月
        rate=0.031; years=0.25;break;
    case 9:  //存期6月
        rate=0.033; years=0.5;break;
    }
    interest=money*rate*years;
    cout<<"本金"<<money<<"元，"<<"利息"<<interest<<"元，本息合计"<<interest+money<<"元"<<endl;
    return 0;
}