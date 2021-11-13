#include <iostream>  //从文件中读出数据，存放到你定义的结构体数组
#include <fstream>
#include <cstdlib>   //在codeblocks下，exit(1)需要这个头文件
using namespace std;
struct Student
{
    char num[13];  //尽管都是由数字构成，但看作为字符更合适。学号12位，定义为13个字符，便于处理成字符串
    char name[10]; //每个汉字占两个字节，中国人的名字，5个汉字够用
    int cpp;
    int math;
    int english;
    int grade;
};
const int N=200;
int main( )
{
    int i, stuNum=0;
    //定义结构体数组
    Student stu[N];
 
    //下面从文件中读取数据到结构体数组，在读入的过程中计算总分
    ifstream infile("score.txt",ios::in); 	//以输入的方式打开文件
    if(!infile)   				//测试是否成功打开
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    i=0;
    while(!infile.eof())
    {
        infile>>stu[i].num>>stu[i].name>>stu[i].cpp>>stu[i].math>>stu[i].english;
        stu[i].grade=stu[i].cpp+stu[i].math+stu[i].english;
        ++stuNum;
        ++i;
    }
    infile.close();
    for(i=0; i<stuNum; ++i)
    {
        cout<<stu[i].num<<"\t"<<stu[i].name<<"\t"<<stu[i].cpp<<"\t"<<stu[i].math<<"\t"<<stu[i].english<<"\t"<<stu[i].grade<<endl;
    }
    while(1);
    return 0;
}