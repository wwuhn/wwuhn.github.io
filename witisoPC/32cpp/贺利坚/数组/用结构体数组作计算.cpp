//用结构体数组作计算

#include <iostream>
#include <fstream>
#include <cstdlib>  //在codeblocks下，exit(1)需要这个头文件
using namespace std;
struct Student
{
    char num[13]; //尽管都是由数字构成，但看作为字符更合适。学号12位，定义为13个字符，便于处理成字符串
    char name[10]; //每个汉字占两个字节，中国人的名字，5个汉字够用
    int cpp;
    int math;
    int english;
    int grade;
};
//声明函数
int getData(Student s[]);
void outputData(Student s[],int n);
void sort(Student s[],int n);
void listScholars1(Student s[],int n);
void listScholars2(Student s[],int n);
 
const int N=200;
int main( )
{
    int stuNum;
    //定义结构体数组
    Student stu[N];
 
    //（1）从文件中读出数据，存放到你定义的结构体数组中；
    //（2）求出每名同学的总分（可以在读入过程中“顺便”计算）；
    stuNum=getData(stu);
 
    //（3）按总分排序（降序），用了选择排序，用冒泡腻了
    sort(stu,stuNum);
 
    //（4）输出排序后的成绩单；
    outputData(stu,stuNum);
 
    //（5）有30名同学可以获得奖学金，规则是总分高者优先，有挂科不能得奖学金。请输出可以得奖学金同学的名单。
    //下面输出得奖学金同学的名单(貌似合理的解法)
    listScholars1(stu,stuNum);
 
    //如果有人的总分与第30名相同，且没有挂科，不给他奖学金是不合理的，下面的输出弥补了这一问题，加名额吧
    //如果要采取题目中没有交待的其他办法（如抽签），作为感兴趣的扩展吧
    listScholars2(stu,stuNum);
 
    //（6）选做：统计各门课及总分的平均成绩、最高和最低成绩、标准偏差，并输出。 (这一点不做参考了，耐心做，能做出来。)
 
    while(1);
    return 0;
}
 
//定义函数
//（1）从文件中读出数据，存放到你定义的结构体数组中；
//（2）求出每名同学的总分（可以在读入过程中“顺便”计算）；
//返回值为学生人数
int getData(Student s[])
{
    ifstream infile("score.txt",ios::in); 	//以输入的方式打开文件
    if(!infile)   				//测试是否成功打开
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    int i=0;
    while(!infile.eof())
    {
        infile>>s[i].num>>s[i].name>>s[i].cpp>>s[i].math>>s[i].english;
        s[i].grade=s[i].cpp+s[i].math+s[i].english;
        ++i;
    }
    infile.close();
    return i;  //i为学生人数
}
 
//（3）按总分排序（降序），用了选择排序
void sort(Student s[],int n)
{
    int i,j,k;
    Student t_stu;
 
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
            if(s[j].grade>s[k].grade) k=j;  //排序的依据是总分，此for循环找出当前总分最高的学生的下标k
        t_stu=s[k];  //交换，结构体变量可以直接赋值。当然，结构体数组元素的值可以赋值给结构体变量
        s[k]=s[i];
        s[i]=t_stu;
    }
    return;
}
 
//（4）输出成绩单；
void outputData(Student s[],int n)
{
    for(int i=0; i<n; ++i)
    {
        cout<<s[i].num<<"\t"<<s[i].name<<"\t"<<s[i].cpp<<"\t"<<s[i].math<<"\t"<<s[i].english<<"\t"<<s[i].grade<<endl;
    }
    return;
}
 
//（5）有30名同学可以获得奖学金，规则是总分高者优先，有挂科不能得奖学金。
void listScholars1(Student s[],int n)
{
    cout<<"恭喜以下同学获得奖学金（奖学金用于改善学习条件，杜绝请客吃饭！）"<<endl;
    int i=0,j=1;
    while (j<=30&&j<=n)
    {
        if (s[i].cpp>=60&&s[i].math>=60&&s[i].english>=60)
        {
            cout<<j<<'\t'<<s[i].name<<'\t'<<s[i].grade<<endl;
            j++;
        }
        i++;
    }
}
 
//另一种奖学金规则
void listScholars2(Student s[],int n)
{
    cout<<"恭喜以下同学获得奖学金（奖学金用于改善学习条件，杜绝请客吃饭！）"<<endl;
    int i=0,j=1;
    int g;
    while (j<=30&&j<=n)
    {
        if (s[i].cpp>=60&&s[i].math>=60&&s[i].english>=60)
        {
            cout<<j<<'\t'<<s[i].name<<'\t'<<s[i].grade<<endl;
            g=s[i].grade;
            j++;
        }
        i++;
    }
    while(g==s[i].grade)//和刚才输出的最后一个总分相同的同学都有机会获得奖学金
    {
        if (s[i].cpp>=60&&s[i].math>=60&&s[i].english>=60)
        {
            cout<<j<<'\t'<<s[i].name<<'\t'<<s[i].grade<<endl;
            j++;
        }
        i++;
    }
}