#include <fstream>
#include<iostream>
#include<string>
using namespace std;
 
//定义学生类
class Student
{
public:
	Student(){};
	Student(string nam, double c, double m, double e):name(nam),cpp(c),math(m),english(e){total=c+m+e;}
	void set_value(string nam, double c, double m, double e);
	string get_name(){return name;}
	double get_cpp(){return cpp;}
	double get_math(){return math;}
	double get_english(){return english;}
	double get_total(){return total;}
	void set_cpp(double c){cpp=c;}
	void set_math(double m){math=m;}
	void set_english(double e){english=e;}
	void set_total(double t){total=t;}
private:
	string name;
	double cpp;
	double math;
	double english;
	double total;
};
 
void Student::set_value(string nam, double c, double m, double e)
{
	name=nam;
	cpp=c;
	math=m;
	english=e;
	total=c+m+e;
}
 
int main( )
{
	Student stud[100],t; //stud[100]为保存数据的对象数组
	string sname;
	double scpp, smath, senglish;
	int i,j;
 
	//将文件中的数据读入到对象数组中
	ifstream infile("score.dat",ios::in);  //以输入的方式打开文件
	if(!infile)       //测试是否成功打开
	{
		cerr<<"open error!"<<endl;
		exit(1);
	}
	for(i=0;i<100;i++)
	{
		infile>>sname>>scpp>>smath>>senglish;
		stud[i].set_value(sname, scpp, smath, senglish);
	}
	infile.close();
 
	//求各科最高分及总分最高分
	Student max_stud("nobody",0,0,0);  //max_stud是一个不存在的学生，存储最高分
	for(i=0;i<100;i++)
	{
		if(stud[i].get_cpp()>max_stud.get_cpp()) max_stud.set_cpp(stud[i].get_cpp());
		if(stud[i].get_math()>max_stud.get_math()) max_stud.set_math(stud[i].get_math());
		if(stud[i].get_english()>max_stud.get_english()) max_stud.set_english(stud[i].get_english());
		if(stud[i].get_total()>max_stud.get_total()) max_stud.set_total(stud[i].get_total());
	}
 
	//按总分排序
	for(j=0;j<100-2;j++) 
	{
		for(i=0;i<100-j-1;i++)   
			if (stud[i].get_total()<stud[i+1].get_total()) 
			{
				t=stud[i]; 
				stud[i]=stud[i+1];
				stud[i+1]=t;
			}
	}
 
	//显示各科及总分的最高分
	cout<<"C++最高分为: "<<max_stud.get_cpp()<<endl;
	cout<<"高等数学最高分为: "<<max_stud.get_math()<<endl;
	cout<<"英语最高分为: "<<max_stud.get_english()<<endl;
	cout<<"总分最高分为: "<<max_stud.get_total()<<endl;
 
	//将按总分排序后的结果存入文件
	cout<<"请到文件ordered_salary.txt中查看排序后的结果"<<endl;
	ofstream outfile("ordered_salary.txt",ios::out); 
	if(!outfile)    
	{
		cerr<<"open error!"<<endl;
		exit(1);
	}
	for(i=0;i<100;i++)
	{
		outfile<<stud[i].get_name()<<"\t";
		outfile<<stud[i].get_cpp()<<"\t";
		outfile<<stud[i].get_math()<<"\t";
		outfile<<stud[i].get_english()<<"\t";
		outfile<<stud[i].get_total()<<endl;
	}
	outfile.close();    
	system("pause");
	return 0;
}