#if 1
//太阳角度计算
/*
*文件名：  精确太阳角度计算 
*程序功能：此程序计算规定规定日期的规定时间的地平方位角和视高度角
*程序版本：针对太阳角度计算做了修改 
*改动部分：对太阳赤纬角、时角等算法做了修正，加入时差等补偿
2019 11 12
17 0 0
113 23

*输入参数：
*所测时间的年、月、日          y，m，d
*所测时间的时分秒              h,m,s
*所测地地理经度                LONG
*所测地地理纬度                LAT
*程序输出：                    屏幕打印*/

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

#define PI 3.14159265358979

/*
*积日(日期在年内的顺序号)计算函数n_ca
*输入参数为月：a、日：b
*输出为当天为当年的第n天*/
unsigned int  n_ca(unsigned int y, unsigned int a,unsigned int b);

/*
*日角计算函数=2πt/365.2422
*输入参数为：年：y，积日：n
*输出为日角 angle_day */
double angle_day_ca(unsigned int n,unsigned int y)
{
	double n0;
	n0=79.6764+0.2433*(y-1985)-((y-1985)/4);
	n0=79.6764+0.2422*(y-1985)-int((y-1985)/4);//百度百科
	//cout<<"日角的n0:"<<n0<<endl;
	double t=n-n0;
	return 2*PI*t/365.2422;
}

/*
*赤纬角的计算函数delt_sun_ca
*赤纬角：赤纬（过北天极、太阳的弧线）与天赤道相正交，
	     *太阳与地球的连线与天赤道平面形成的角度
*输入参数为：日角angle_day
*输出为赤纬角 delt_sun*/
double delt_sun_ca(double a)
{
	double d=(0.3723+23.2567*sin(a)+0.1149*sin(2*a)-0.1712*sin(a)-0.758*cos(a)+
			0.3656*cos(2*a)+0.0201*cos(3*a))*PI/180;//0.1712*sin(3*a)
	return d;

}
double delt_sun_ca1(double a)
{
	double d = (0.3723+23.2567*sin(a)+0.1149*sin(2*a)-0.1712*sin(3*a)-0.758*cos(a)+
			0.3656*cos(2*a)+0.0201*cos(3*a))*PI/180;//0.1712*sin(3*a) //百度百科

	return d;

}
double delt_sun_ca2(unsigned int n) //输入参数：积日 //不对
{
	double d = 0.98563*(n-173)/180*PI;
	d = 0.39795*cos(d); //百度百科sinδ=0.39795cos[0.98563(N-173)/180*pi]，
								// δ单位为弧度，式中N为日数，自每年1月1日开始计算
	d = asin(d);
	return d;

}

double delt_sun_ca3(unsigned int n) //输入参数：积日 //不对
{
	double b = 2*PI*(n-1)/365;
	double d = 0.006918-0.399912*cos(b)+0.070257*sin(b)-0.006758*cos(2*b)+0.000907*sin(2*b)-0.002697*cos(3*b)+0.00148*sin(3*b);
	d = 180/PI*(d);
	return d;
}
double delt_sun_ca4(unsigned int n) //输入参数：积日 //不对
{
	double d = 23.45*sin((284+n)/365*360);
	return d;
}

/*
*时差计算函数
*输入参数为日角angle_day
*输出为时差et*/
double et_ca(double a)
{
	return 0.0028-1.9857*sin(a)+9.9059*sin(2*a)-7.0924*cos(a)-0.6882*cos(2*a);
}

/*
*时角计算函数
*输入参数为:时分秒：hour，minute，sec；时差et,地理经度LONG
*输出为时角angle_hour*/
double angle_hour_ca(unsigned int h,unsigned int m,unsigned s,double e,double l)
{
	return  (h-12)+(m-(120*PI/180-l)*4*180/PI+e)/60+(s/3600)*15*PI/180;
}


int main()/*主函数计算太阳高度角与方位角*/
{
	// 输入年月日，时刻
	unsigned int  y,m,d;
	unsigned int hour,minute,sec;
	cout<<"输入当前年月日，如2019 9 29:"<<endl;
	cin>>y>>m>>d;

	cout<<"输入当前时分秒，如14 14 14:"<<endl;
	cin>>hour>>minute>>sec;

	// 输入经纬度
	double  LONG,LAT;
	cout<<"输入当地经度LONG、与当地纬度LAT(角度)，如113 23："<<endl;
	cin>>LONG>>LAT;

	cout<<endl;
	LONG=LONG*PI/180;
	LAT=LAT*PI/180;
	cout<<"输入的经度、纬度（弧度）："<<LONG<<","<<LAT<<"rad\n";
	
	// 计算当前赤纬角
	double  delt_sun,angle_day;
	unsigned int n;
	n=n_ca(y,m,d);
	cout<<"现在是一年中的第"<<n<<"天。\n";
	angle_day=angle_day_ca(n,y);
	// delt_sun=delt_sun_ca(angle_day);
	//delt_sun=delt_sun_ca2(n);
	//delt_sun=delt_sun_ca4(n);
	cout<<"当前的太阳赤纬（角度）为："<<(delt_sun*180/PI)<<"度\n";
	cout<<"当前的太阳赤纬（弧度）为："<<delt_sun<<"\n";
	
	
	// 计算高度角
	//sinH＝ sinφsinδ＋ cosφcosδcost
	//其中,H是太阳高度角,φ是当地的地理纬度,δ是当日的太阳赤纬,t是当时的太阳时角。
	double et,angle_hour;
	et=et_ca(angle_day); // 时差
	angle_hour=angle_hour_ca(hour,minute,sec,et,LONG);
	cout<<"现在太阳的时角为"<<(angle_hour*180/PI)<<"度\n";

	double sin_h, h_sun,h_sun1;
	/*计算高度角的正弦值*/
	sin_h=sin(LAT)*sin(delt_sun)+cos(LAT)*cos(delt_sun)*cos(angle_hour);
	h_sun=asin(sin_h);
	h_sun1=h_sun*180/PI;
	cout<<"转换成当前太阳的高度角为："<<h_sun1<<"度\n";
	
	// 计算方位角
	double cos_gam,gam_sun,gam_sun1;
	cos_gam=(sin_h*sin(LAT)-sin(delt_sun))/(cos(h_sun)*cos(LAT));
	gam_sun=acos(cos_gam);
	gam_sun1=gam_sun*180/PI;//转换成角度制
	cout<<"当前太阳的方位角为:"<<gam_sun<<"rad,"<<gam_sun1<<" 度\n";
	system("pause");
	return 0;
}

/*****函数定义部分*****/
/*积日计算函数定义*/
int daysOfMonth(unsigned int y,unsigned int m)
{
	int leap=(y%4==0 && y%100!=0||y%400==0)?1:0;
	switch(m)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:return 31;
	case 2:return 28+leap;
	case 4:case 6:case 9:case 11:return 30;
	default:
		cout<<"月份输入错误！\n";
	}
}
unsigned int  n_ca(unsigned int y, unsigned int m,unsigned int d)
{
	unsigned int sum = d;
	for(int i=1;i<m;++i)
		sum+=daysOfMonth(y,i);
	return sum;
}

/*******************************程序结束*****************************/
/*
输入当前年月日，如2019 9 29:
2019 9 29
输入当前时分秒，如14 14 14:
14 14 14
输入当地经度LONG与当地纬度LAT，如113 23：
113 23
输入的经度纬度分别为：1.97222rad,0.401426rad
现在是一年中的第272天。
当前的太阳赤纬为：-0.0382322rad
转换成角度制太阳赤纬角为-2.19054度
现在太阳的时角为1.93047rad.
转换成当前太阳的高度角为：-19.7971度
当前太阳的方位角为:1.67968rad,96.2383 度
*/
#endif


#if 0   //太阳赤纬角的计算换了一种方式，相差无几
//太阳角度计算
/****************************************************************************
*文件名：  精确太阳角度计算 
*程序功能：此程序计算规定规定日期的规定时间的地平方位角和视高度角
*程序版本：针对太阳角度计算做了修改 
*改动部分：对太阳赤纬角、时角等算法做了修正，加入时差等补偿
*****************************************************************************
*输入参数：
*所测时间的年、月、日          y，m，d
*所测时间的时分秒              h,m,s
*所测地地理经度                LONG
*所测地地理纬度                LAT
*程序输出：                    屏幕打印
******************************************************************************/
#include<iostream>
#include<math.h>
using namespace std;

#define  PI   3.14159265358979


/****************************************************************************
*积日(日期在年内的顺序号)计算函数n_ca
*输入参数为月：a、日：b
*输出为当天为当年的第n天*/
unsigned int  n_ca(unsigned int a,unsigned int b);

/****************************************************************************
*日角计算函数=2πt/365.2422
*输入参数为：年：y，积日：n
*输出为日角 angle_day */

double angle_day_ca(unsigned int n,unsigned int y)
{
	double n0=79.6764+0.2433*(y-1985)-((y-1985)/4);
	double t=n-n0;
	return 2*PI*t/365.2422;
}


/****************************************************************************
*赤纬角的计算函数delt_sun_ca2
*输入参数为：月、日
*输出为赤纬角 delt_sun*/

double delt_sun_ca2(double m,double d)
{
	int N = n_ca(m,d);
	double b =2*PI*(N-1)/365;
	
    return 0.006918-0.399912*cos(b)+0.070257*sin(b)-0.006758*cos(2*b)+ 
		   0.000907*sin(2*b)-0.002697*cos(3*b)+0.00148*sin(3*b);

// 其中delta的单位为度(deg)；pi=3.1415926为圆周率；
// b=2*pi*(N-1)/365，单位为弧度；
// N为日数，自每年1月1日开始计算。
}
/****************************************************************************
*时差计算函数
*输入参数为日角angle_day
*输出为时差et*/
double et_ca(double a)
{
	return 0.0028-1.9857*sin(a)+9.9059*sin(2*a)-7.0924*cos(a)-0.6882*cos(2*a);
}

/****************************************************************************
*时角计算函数
*输入参数为:时分秒：hour，minute，sec；时差et,地理经度LONG
*输出为时角angle_hour*/
double angle_hour_ca(unsigned int h,unsigned int m,unsigned s,double e,double l)
{
	return  (h-12)+(m-(120*PI/180-l)*4*180/PI+e)/60+(s/3600)*15*PI/180;
}

/****************主函数计算太阳高度角与方位角************/
int main()
{
	/**************输入年月日，时刻***************/
	unsigned int  y,m,d;
	unsigned int hour,minute,sec;
	cout<<"输入当前年月日，如2019 9 29:"<<endl;
	cin>>y>>m>>d;
	cout<<"输入当前时分秒，如14 14 14:"<<endl;
	cin>>hour>>minute>>sec;
	
	/***************输入经纬度****************/
	double  LONG,LAT;
	cout<<"输入当地经度LONG与当地纬度LAT，如113 23："<<endl;
	cin>>LONG>>LAT;
	LONG=LONG*PI/180;
	LAT=LAT*PI/180;
	cout<<"输入的经度纬度分别为："<<LONG<<"rad,"<<LAT<<"rad\n";
	
	/***************计算当前赤纬角***********/
	double  delt_sun,angle_day;
	unsigned int n;
	n=n_ca(m,d);
	cout<<"现在是一年中的第"<<n<<"天。\n";
	angle_day=angle_day_ca(n,y);
	//delt_sun=delt_sun_ca(angle_day);
	delt_sun=delt_sun_ca2(m,d);
	cout<<"当前的太阳赤纬为："<<delt_sun<<"rad\n";
	cout<<"转换成角度制太阳赤纬角为"<<(delt_sun*180/PI)<<"度\n";
	
	/****************计算高度角**************/
	//sinH＝ sinφsinδ＋ cosφcosδcost

	//其中,H是太阳高度角,φ是当地的地理纬度,δ是当日的太阳赤纬,t是当时的太阳时角。
	double et,angle_hour;
	et=et_ca(angle_day);
	angle_hour=angle_hour_ca(hour,minute,sec,et,LONG);
	cout<<"现在太阳的时角为"<<angle_hour<<"rad.\n";
	double sin_h, h_sun,h_sun1;
	sin_h=sin(LAT)*sin(delt_sun)+cos(LAT)*cos(delt_sun)*cos(angle_hour);//计算高度角的正弦值
	h_sun=asin(sin_h);
	h_sun1=h_sun*180/PI;
	cout<<"转换成当前太阳的高度角为："<<h_sun1<<"度\n";
	
	//计算方位角
	double cos_gam,gam_sun,gam_sun1;
	cos_gam=(sin_h*sin(LAT)-sin(delt_sun))/(cos(h_sun)*cos(LAT));
	gam_sun=acos(cos_gam);
	gam_sun1=gam_sun*180/PI;//转换成角度制
	cout<<"当前太阳的方位角为:"<<gam_sun<<"rad,"<<gam_sun1<<" 度\n";
	cout<<endl;
	


	system("pause");
	return 0;
}

/*****函数定义部分*****/
/*积日计算函数定义*/
unsigned int  n_ca(unsigned int a,unsigned int b)
{
	int n=0;
	switch(a)
	{
	case 1:
		n=b;break;
	case 2:
		n=31+b;break;
	case 3:
		n=31+28+b;break;
	case 4:
		n=31+28+31+b;break;
	case 5:
		n=31+28+31+30+b;break;
	case 6:
		n=31+28+31+30+31+b;break;
	case 7:
		n=31+28+31+30+31+30+b;break;
	case 8:
		n=31+28+31+30+31+30+31+b;break;
	case 9:
		n=31+28+31+30+31+30+31+31+b;break;
	case 10:
		n=31+28+31+30+31+30+31+31+30+b;break;
	case 11:
		n=31+28+31+30+31+30+31+31+30+31+b;break;
	case 12:
		n=31+28+31+30+31+30+31+31+30+31+30+b;break;
	default:
		cout<<"月份输入错误！\n";
	}
	return  n;
}

/*******************************程序结束*****************************/
/*
2019 11 12
17 14 14
113 23

输入当前年月日，如2019 9 29:
2019 9 29
输入当前时分秒，如14 14 14:
14 14 14
输入当地经度LONG与当地纬度LAT，如113 23：
113 23
输入的经度纬度分别为：1.97222rad,0.401426rad
现在是一年中的第272天。
当前的太阳赤纬为：-0.0382322rad
转换成角度制太阳赤纬角为-2.19054度
现在太阳的时角为1.93047rad.
转换成当前太阳的高度角为：-19.7971度
当前太阳的方位角为:1.67968rad,96.2383 度
*/
#endif
