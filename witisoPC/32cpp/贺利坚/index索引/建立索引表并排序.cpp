#include <iostream>  // 建立索引表并排序
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
 
 
typedef struct
{
    int NO;
    long offset;  //数据在文件中的偏移量
} StudentIndex;   //高考学生索引
 
 
void createIndex();
void writeIndex(StudentIndex *si, int n);
 
 
int main()
{
    createIndex();
    return 0;
}
/*
功能：创建索引
*/
 
 
void createIndex()
{
    int stuNum;
    StudentIndex *studentsIndex;  //索引表的起始地址
    Student student;
    ifstream binaryFile("binarydata.dat", ios::in|ios::binary);
    if(!binaryFile)
    {
        cerr<<"cannot open binary file!"<<endl;
        exit(1);
    }
    //建立索引
    binaryFile.read((char*)&stuNum, sizeof(stuNum));  //读入实际人数
    //读入数据，建立未排序的索引表
    studentsIndex = new StudentIndex[stuNum];
    int i, j;
    long mOffset;
    for(i=0; i<stuNum; ++i)
    {
        mOffset = binaryFile.tellg();
        binaryFile.read((char*)&student, sizeof(Student));
        studentsIndex[i].NO = student.NO;
        studentsIndex[i].offset = mOffset;   //记录对应学号学生数据的偏移量
    }
    //关闭数据文件
    binaryFile.close();
    //为索引表排序
    StudentIndex temp;   //用于交换的中间变量
    for (i=0; i<stuNum-1; i++)
        for(j=0; j<stuNum-i-1; j++)
            if (studentsIndex[j].NO>studentsIndex[j+1].NO)
            {
                temp=studentsIndex[j];
                studentsIndex[j]=studentsIndex[j+1];
                studentsIndex[j+1]=temp;
            }
    //将建好的索引表通过文件存储
    writeIndex(studentsIndex, stuNum);
    return;
}
 
 
/*
功能：将索引写入文件
参数：si - 索引表起始地址；n - 考生人数，索引记录条数
*/
void writeIndex(StudentIndex *si, int n)
{
    //打开文件
    ofstream indexFile("binarydata.idx", ios::out|ios::binary);
    if(!indexFile)
    {
        cerr<<"cannot open index file!"<<endl;
        exit(1);
    }
    int i;
    for(i=0; i<n; ++i)
    {
        //indexFile<<si[i].NO<<"\t"<<si[i].offset<<endl;  //索引用作文本文件时
       indexFile.write((char*)&si[i], sizeof(StudentIndex)); //索引用二进制文件时  
    }
    //关闭文件
    indexFile.close();
    return;
}