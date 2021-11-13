#if 0     // 文件读写对象版

#include <fstream>
#include<iostream>
using namespace std;
int main( )
{
    float a[500],t;
    int i,j;
    ifstream infile("salary.txt",ios::in);  //以输入的方式打开文件
    if(!infile)       //测试是否成功打开
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(i=0;i<500;i++)
        infile>>a[i];   //从文件中读取数据
    infile.close();
    for(i=0;i<10;i++)
        a[i]+=100;      //涨工资了
 
    for(j=0;j<500-2;j++)    //排序，用冒泡法，其他法类似
    {
        for(i=0;i<500-j-1;i++)   
            if (a[i]>a[i+1])
            {
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
    }
    //输出结果
    ofstream outfile("ordered_salary.txt",ios::out);
    if(!outfile)    //测试文件打开操作是否成功，不成功则提示后退出。
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(i=0;i<500;i++)
    {
        outfile<<a[i]<<endl;
        if(i%5==0) cout<<endl;
        cout<<a[i]<<"\t";
    }
    outfile.close();     //关闭文件。用完了必须关闭，否则会丢失数据
    system("pause");
    return 0;
}

#else

#include<iostream>    
#include<fstream>   
using namespace std;    

class Salary  
{  
public:  
    void ordered_salary_add();
    void ordered_salary();
    void input_salary();
    void ordered_salary_txt();
private:
    double salary[500];
    int number;  
};
int main()  
{  
    Salary s1; 
	//cout<<"500人的原始工资为："<<endl;
    s1.input_salary();  
    //cout<<endl;  
    cout<<"排序后工资为:";  
    cout<<endl;  
    s1.ordered_salary();  
    cout<<endl;  
	s1.ordered_salary_txt();
	system("PAUSE");  
    return 0;  
}
void Salary::input_salary()  
{  
    int i=0;  
	ifstream infile("salary.txt",ios::in);
	if (!infile)
	{
		cerr<<"open error!"<<endl;
		exit(1);
	}
	for (i=0;i<500;i++)
		infile>>salary[i];
	infile.close();
	//for(i=0;i<500;i++)
		//cout<<salary[i]<<"  ";
	//cout<<endl;
    number=500;  
}
void Salary::ordered_salary_add()  
{  
    int i;  
    for (i=0;i<number;i++)  
    {  
        salary[i]=salary[i]+100;  
        //cout<<salary[i]<<"  ";  
    }  
    return;  
}  
void Salary::ordered_salary()  
{  
	
    int i,j;  
    double t;  
    for(i=0;i<number-1;i++) 
	{
        for(j=0;j<number-i-1;j++) 
		{
            if(salary[j]>salary[j+1])  
            {  
                t=salary[j];  
                salary[j]=salary[j+1];  
                salary[j+1]=t;  
            }  
		}
	}
	for (i=0;i<number;i++)  
	{  
		cout<<salary[i]<<"  ";  
	}  
	return;  
}  
 
void Salary::ordered_salary_txt()
{
	ofstream outfile("ordered_salary.txt",ios::out);
	if(!outfile)
	{
		cerr<<"open error!"<<endl;
		exit(1);
	}
	for(int i=0;i<500;i++)
		outfile<<salary[i]<<"\n";
	outfile.close();
	return ;
}


#endif