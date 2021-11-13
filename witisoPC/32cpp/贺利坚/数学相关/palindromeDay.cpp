#include <iostream>  // 回文日
using namespace std;
// 例如：2021年的回文是 1202 
// month对应2021的后两位来构造成12 
// day对应2021的前两位来构造成02
// 判断12是不是2021合法的月，02是不是2021合法的日
#define STARTY 2021
#define ENDY 2120
int palindromeDay(int year)
{
    int month,day; // 用于从年份构造月、日
    
    month=year%100;                     //month取到的是年的后两位
    month = (month%10)*10 + month/10;   //将后两位倒过来，确定月份
    day=year/100;                       //day取到的是年的前两位
    day=(day%10)*10+day/10;             //将前两位倒过来，确定日期
    bool is_cycle =false;
    switch(month)               //12个月份，各自对应合法的日期范围
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: if(day<=31) is_cycle =true; break;
    case 4:
    case 6:
    case 9:
    case 11: if(day<=30) is_cycle=true; break;
    case 2: if((year%4==0&&year%100!=0)||year%400==0) //闰年
            {
                if(day<=29) is_cycle =true;
            }
        else
            if(day<=28) is_cycle =true; break;
    default: break;         //后两位倒过来根本构不成月份
    }
    int  anothery = 0;          // 构造的回文年月日做为一个整数
    if(is_cycle)            //能构成回文日，将回文日构造成一个整数。
    {
        int y=year;         // 临时用于迭代
        anothery=year; // 构造的回文年月日做为一个整数
        while(y>0)
        {
            anothery=anothery*10+y%10;
            y=y/10;
        }
    }
    return anothery;
}

int main( )
{
    cout<<STARTY<<" - "<<ENDY << "的回文日："<<endl;
    int counts = 0;
    for(int year = STARTY; year < ENDY; year++)
        if(palindromeDay(year))
        {
            cout<<palindromeDay(year)<<endl;
            counts++;
        }
    cout<<ENDY-STARTY+1<<"年，合计 "<<counts<<" 个回文日。"<<endl;
    while(1);
    return 0;
}

#if 0
#include <iostream>
using namespace std;
int main( )
{
	int year,month,day,y,anothery;
	bool is_cycle;
	int count=0;
	for(year = 2012; year < 2092; year++)
	{
		month=year%100; //month取到的是年的后两位
		month = (month%10)*10 + month/10; //将后两位倒过来，确定月份
		day=year/100;   //day取到的是年的前两位
		day=(day%10)*10+day/10; //将前两位倒过来，确定日期
		is_cycle =false;
		switch(month) //12个月份，各自对应合法的日期范围
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: if(day<=31) is_cycle =true; break;
		case 4:
		case 6:
		case 9:
		case 11: if(day<=30) is_cycle=true; break;
		case 2: if((year%4==0&&year%100!=0)||year%400==0) //闰年
				{
					if(day<=29) is_cycle =true;
				}
			else
				if(day<=28) is_cycle =true; break;
		default: continue; //后两位倒过来根本构不成月份
		}
		if(is_cycle) //能构成回文日
		{
			y=year;
			anothery=year;
			while(y>0)
			{
				anothery=anothery*10+y%10;
				y=y/10;
			}
			cout<<anothery<<endl;
			count++;
		}
	}
	cout<<"共有 "<< count <<"个回文日。"<<endl;
	return 0;
}
#endif