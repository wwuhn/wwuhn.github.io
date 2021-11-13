/*

*/
#if 1
#include<iostream>
#include<string>
using namespace std;
void input(double s[][4],int n); //输入成绩
void output(double s[][4],int n); //输出成绩
double max(double s[][4],int n,int i); //求第i门课的最高成绩，i=3时是总分
double min(double s[][4],int n,int i); //求第i门课的最低成绩
double avg(double s[][4],int n,int i); //求第i门课的平均成绩
 
int main()
{
    int i,num;
    string temp;
    double score[100][4]; //设一个班最多100人，实际按输入来
    string course[4]= {"高等数学","英语","C++","总分"};
    cout<<"输入学生人数：";
    cin>>num;
    //（1）输入成绩并求出总分
    input(score,num);
    //（2）输出成绩
    output(score,num);
 
    //（3）输出各门课及总分的最高成绩、最低成绩、平均成绩和成绩的标准偏差；
    for(i=0; i<4; ++i)
    {
        cout<<course[i]<<"的最高成绩是"<<max(score,num,i)<<", ";
        cout<<"最低成绩是"<<min(score,num,i)<<", ";
        cout<<"平均成绩是"<<avg(score,num,i)<<", ";
        cout<<endl;
    }
 
    return 0;
}
 
void input(double s[][4],int n) //输入成绩
{
    cout<<"输入学生成绩(按高数、英语、C++的顺序依次输入：)"<<endl;
    for(int i=0; i<n; ++i)
    {
        cin>>s[i][0]>>s[i][1]>>s[i][2];
        s[i][3]=s[i][0]+s[i][1]+s[i][2];
    }
}
 
void output(double s[][4],int n) //输出成绩
{
    cout<<"输入的学生成绩为："<<endl;
    cout<<"学号\t高数\t英语\tC++\t总分"<<endl;
    for(int i=0; i<n; ++i)
    {
        cout<<i<<'\t'<<s[i][0]<<'\t';
        cout<<s[i][1]<<'\t';
        cout<<s[i][2]<<'\t';
        cout<<s[i][3]<<endl;
    }
}
//求第j门课的最高成绩，i=3时是总分，下类似
double max(double s[][4],int n,int j)
{
    double m=s[0][j];
    for(int i=1; i<n; ++i)
        if (m<s[i][j])
            m=s[i][j];
    return m;
}
double min(double s[][4],int n,int j)
{
    double m=s[0][j];
    for(int i=1; i<n; ++i)
        if (m>s[i][j])
            m=s[i][j];
    return m;
}
double avg(double s[][4],int n,int j)
{
    double sum=s[0][j];
    for(int i=1; i<n; ++i)
        sum+=s[i][j];
    return sum/n;
}

#else

#include<iostream>
#include<string>
#include<cmath>
using namespace std;
void input(double s[][4],string name[],int n); //输入成绩
void output(double s[][4],string name[],int n); //输出成绩
double max(double s[][4],int n,int i); //求第i门课的最高成绩，i=3时是总分
double min(double s[][4],int n,int i); //求第i门课的最低成绩
double avg(double s[][4],int n,int i); //求第i门课的平均成绩
void outputByScore(double s[][4],string name[], int n, int i, double si); //输出第i门课成绩为si的同学姓名
int main()
{
    int i,num;
    string temp;
    double score[100][4]; //设一个班最多100人，实际按输入的人数计
    string name[100];
    string course[4]= {"高等数学","英语","C++","总分"};
    cout<<"输入学生人数：";
    cin>>num;
    //（1）输入成绩并求出总分
    input(score,name,num);
    //（2）输出成绩
    output(score,name,num);
 
    //（3）输出各门课及总分的最高成绩、最低成绩、平均成绩和成绩的标准偏差；
    for(i=0; i<4; ++i)
    {
        cout<<course[i]<<"的最高成绩是"<<max(score,num,i)<<", ";
        cout<<"最低成绩是"<<min(score,num,i)<<", ";
        cout<<"平均成绩是"<<avg(score,num,i)<<", ";
        cout<<endl;
    }
 
    for(i=0; i<4; ++i)
    {
        cout<<course[i]<<"的最高成绩获得者是：";
        outputByScore(score,name,num,i,max(score,num,i)); //输出第i科最高成绩者名单
        cout<<endl;
    }
    return 0;
}
 
void input(double s[][4],string name[],int n) //输入成绩
{
    cout<<"输入学生成绩(按姓名、高数、英语、C++的顺序依次输入：)"<<endl;
    for(int i=0; i<n; ++i)
    {
        cin>>name[i]>>s[i][0]>>s[i][1]>>s[i][2];
        s[i][3]=s[i][0]+s[i][1]+s[i][2];
    }
}
 
void output(double s[][4],string name[],int n) //输出成绩
{
    cout<<"输入的学生成绩为："<<endl;
    cout<<"学号\t姓名\t高数\t英语\tC++\t总分"<<endl;
    for(int i=0; i<n; ++i)
    {
        cout<<i<<'\t'<<name[i]<<'\t';
        cout<<s[i][0]<<'\t';
        cout<<s[i][1]<<'\t';
        cout<<s[i][2]<<'\t';
        cout<<s[i][3]<<endl;
    }
}
//求第i门课的最高成绩，i=3时是总分，下类似
double max(double s[][4],int n,int j)
{
    double m=s[0][j];
    for(int i=1; i<n; ++i)
        if (m<s[i][j])
            m=s[i][j];
    return m;
}
double min(double s[][4],int n,int j)
{
    double m=s[0][j];
    for(int i=1; i<n; ++i)
        if (m>s[i][j])
            m=s[i][j];
    return m;
}
double avg(double s[][4],int n,int j)
{
    double sum=s[0][j];
    for(int i=1; i<n; ++i)
        sum+=s[i][j];
    return sum/n;
}
 
//输出第i门课成绩为si的同学姓名
void outputByScore(double s[][4],string name[], int n, int i, double si)
{
    for(int j=0; j<n; ++j)
    {
        if(abs(s[j][i]-si)<1e-7)  //用第j位同学的第i门课成绩比较
            cout<<name[j]<<" ";
   }
    return;
}


#endif

#if 0


#endif
/*

*/