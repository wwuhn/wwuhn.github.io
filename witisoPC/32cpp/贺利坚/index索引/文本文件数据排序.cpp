#include <iostream> // 文本文件数据排序
#include <fstream>
#include <cstdlib>
 
 
using namespace std;
typedef struct
{
    int NO;
    char name[8];
    int chinese;
    int math;
    int english;
    int Comprehensive;
    int total;
} Student;  //高考学生信息
void display(Student*, int);
void sort(Student*, int);
int main()
{
    int stuNum = 0;
    Student *students;
    fstream binaryFile("binarydata.dat", ios::in|ios::out|ios::binary);
    if(!binaryFile)
    {
        cerr<<"cannot open binary file!"<<endl;
        exit(1);
    }
    //读入考生人数
    binaryFile.read((char*)&stuNum, sizeof(stuNum));
 
 
    //读入数据
    students = new Student[stuNum];
    int i;
    for(i=0; i<stuNum; ++i)
    {
        binaryFile.read((char*)&students[i], sizeof(Student));
    }
    display(students, stuNum);
 
 
    //各种操作（例排序，还可以查找、修改等）
    sort(students, stuNum);
 
 
    //查看操作结果
    //display(students, stuNum);
    //将数据再写入文件
    binaryFile.seekg(0, ios::beg);
    binaryFile.write((char*)&stuNum, sizeof(stuNum));
    for(i=0; i<stuNum; ++i)
    {
        binaryFile.write((char*)&students[i], sizeof(Student));
    }
    //关闭文件
    binaryFile.close();
 
 
    return 0;
}
 
 
void display(Student *s, int n)
{
    cout<<"共"<<n<<"名考生："<<endl;
    int i;
    for(i=0; i<n; ++i)
    {
        cout<<i<<": "<<s[i].NO<<"\t";
        cout<<s[i].name<<"\t";
        cout<<s[i].chinese<<"\t";
        cout<<s[i].math<<"\t";
        cout<<s[i].english<<"\t";
        cout<<s[i].Comprehensive<<"\t";
        cout<<s[i].total<<"\t"<<endl;
    }
}
 
 
void sort(Student *s, int n)
{
    int i, j;
    Student temp;   //用于交换的中间变量
    for (i=0; i<n-1; i++)
        for(j=0; j<n-i-1; j++)
            if (s[j].NO>s[j+1].NO)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
    return;
}