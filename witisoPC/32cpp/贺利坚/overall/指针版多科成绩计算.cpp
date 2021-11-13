#include <iostream>  // 指针版多科成绩计算
#include <Cmath>
#include <string>
using namespace std;
double max(double (*a)[4],int m, int j);    
double min(double (*a)[4],int m, int j);    
double avg(double (*a)[4], int m,int j);    
double stdev(double (*a)[4],int m, int j );  
void output_result(double (*s)[4],int n);
void input(double (*a)[4],int n); //输入成绩，n是学生人数 
void output(double (*a)[4],int n);  
int main ()
{
    
    int num;
    double score[50][4];
    cout<<"请输入同学人数"<<endl;
    cin>>num;
    input(score,num);
    output(score,num);
    return 0; 
}
/*
函数部分
*/
void input(double (*a)[4],int n) //输入成绩，n是学生人数 
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<"请输入学号为"<<i<<"的成绩(高数 英语 C++)"<<endl;
        cin>>*(a[i])>>*(a[i]+1)>>*(a[i]+2);//或cin>>a[i][0]>>a[i][1]>>a[i][2];
        *(*(a+i)+3)=a[i][0]+a[i][1]+a[i][2];//a[i][3]=a[i][0]+a[i][1]+a[i][2];
    }  
    return ;
}

void output(double (*a)[4],int n)
{
    int i;
    string course[4]={"高等数学","英语","C++","总分"}; 
    /*输出成绩
    */
    cout<<"输入的学生成绩为："<<endl;  
    cout<<"学号\t高数\t英语\tC++\t总分"<<endl;  
    for(i=0;i<n;++i)  
    {  
        cout<<i<<'\t'<<a[i][0]<<'\t';  
        cout<<a[i][1]<<'\t';  
        cout<<a[i][2]<<'\t';  
        cout<<a[i][3]<<endl;  
    }  
    /*输出各种成绩
    */
    for(i=0;i<4;i++)  
    {    
        cout<<course[i]<<"的最高成绩是"<<max(a,n,i)<<", ";  
        cout<<"最低成绩是"<<min(a,n,i)<<", ";  
        cout<<"平均成绩是"<<avg(a,n,i)<<", ";  
        cout<<"成绩的标准偏差是"<<stdev(a,n,i)<<endl;    
    }    
    output_result(a,n);  
    return ; 
}


double max(double (*a)[4],int m, int j)
{
    double p=*(a[0]+j);//或p=a[0][j];
    for(int i=1;i<m;i++)
        if(p<a[i][j])
            p=a[i][j];
        return p;
} 

double min(double (*a)[4],int m, int j)
{
    double s=a[0][j];
    for(int i=1;i<m;i++)
        if(s>a[i][j])
            s=a[i][j];
        return s;
}    
double avg(double (*a)[4], int m,int j)
{
    double sum=a[0][j];
    for(int i=1;i<m;i++)
        sum=sum+a[i][j];
    return sum/m;
}
double stdev(double (*a)[4],int m, int j )
{
    double s,x,sum=0;  
    s=avg(a,m,j);//平均成绩   
    for(int i=0;i<m;i++)    
    {    
        x=a[i][j]-s;    
        sum+=x*x;    
    }    
    return sqrt(sum/(m-1));    
}
//输出考得总分最高、最低同学的人数及对应的学号。   
void output_result(double (*s)[4],int n)  
{  
    double m=max(s,n,3);  
    int i,c=0;  
    bool first=true;  
    cout<<"总分最高分为"<<m;  
    for(i=0;i<n;++i)  
    {  
        if(s[i][3]==m)//直接用s[i][3]==m可能会因精度而错误   
            ++c;  
    }  
    cout<<"，有"<<c<<"人达到最高分，他们的学号是：";  
    for(i=0;i<n;++i)  
    {  
        if(s[i][3]==m)  
            if(first)  
            {  
                cout<<i;  
                first=false;  
            }  
            else  
            {  
                cout<<"、"<<i;  
            }  
    }  
    cout<<endl;  
    //关于最低成绩   
    m=min(s,n,3);  
    c=0;  
    first=true;  
    cout<<"总分最低分为"<<m;  
    for(i=0;i<n;++i)  
    {  
        if(s[i][3]==m)   
            ++c;  
    }  
    cout<<"，有"<<c<<"人达到最低分，他们的学号是：";  
    for(i=0;i<n;++i)  
    {  
        if(s[i][3]==m)  
            if(first)  
            {  
                cout<<i;  
                first=false;  
            }  
            else  
            {  
                cout<<"、"<<i;  
            }  
    }  
    cout<<endl;  
    return ;
}