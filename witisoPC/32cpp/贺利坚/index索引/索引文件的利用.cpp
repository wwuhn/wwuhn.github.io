//索引文件的利用

#include <iostream>
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
 
 
//为方便起见，下面变量用全局变量表示。若用局部变量，各模块间通过引用传递参数亦可
fstream dataFile, indexFile;
int stuNum, maxNum;
StudentIndex *studentsIndex;  //索引表入口地址
 
 
//函数声明
void createIndex();
void writeIndex(StudentIndex *si, int n);
void init();
void work();
int chooseInMenu();
void done();
void displayByIndex();
void displayStudent(Student &s);
 
 
int main()
{
    char yn;
    cout<<"需要重建索引吗？(Y/N)";
    cin>>yn;
    if('Y'==yn||'y'==yn)
        createIndex();
    init();
    work();
    done();
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
 
 
/*
功能：初始化，为几个全局变量获得初值
*/
void init()
{
    //第一件工作：打开数据文件
    dataFile.open("binarydata.dat", ios::in|ios::out|ios::binary);
    if(!dataFile)
    {
        cerr<<"cannot open data file!"<<endl;
        exit(1);
    }
    //读入考生人数
    dataFile.read((char*)&stuNum, sizeof(stuNum));  //读入实际人数
    maxNum = stuNum * 1.1;   //最多人数多留10%的空间，以备增加数据用（本例用不着）
    studentsIndex = new StudentIndex[maxNum];  //为索引表分配空间
 
 
    //从索引文件中读取数据，保存在索引表中
    //在业务运行过程中，索引表独立工作，以发挥其速度优势
    //打开文件
    indexFile.open("binarydata.idx", ios::in|ios::binary);
    if(!indexFile)
    {
        cerr<<"cannot open index file!"<<endl;
        exit(1);
    }
    int i;
    for(i=0; i<stuNum; ++i)
    {
        indexFile.read((char*)&studentsIndex[i], sizeof(StudentIndex)); //索引用二进制文件时
    }
    //关闭文件
    indexFile.close();
    return;
}
 
 
/*
功能：完成"善后"工作
*/
void work()
{
    int iChoice;   //用于选择系统功能
    //办理业务
    do
    {
        iChoice = chooseInMenu();  //从菜单中获得功能代码
        switch(iChoice)
        {
        case 1:
            displayByIndex();  //按索引显示
            break;
        case 2:
            out<<"请设计函数searchStudent()，输入考号，在索引表中二分查找，然后到数据文件中读取数据并显示"<<endl;
            break;
        case 3:
            cut<<"请设计函数updateStudent()，输入考号，在索引表中二分查找，输入新值，并且更新数据文件中的数据"<<endl;
            break;
        case 4:
            cout<<"请设计函数addStudent()，输入考生息，保存到数据文件的最后，将新考生的信息插入在索引表中的合适位置，以使索引表与数据文件仍然同步"<<endl;
            break;
        case 5:
            cout<<"索引表与数据文件相配合开展工作，在工程中太实用了，请自提需求，尝试实现"<<endl;
            break;
        case 0:
            cout<<"欢迎您再来. "<<endl;
        }
    }
    while(iChoice);
    cout<<"什么也没有做！"<<endl;
 
 
}
 
 
/*
功能：显示菜单并由业务员选择
返回值：用户选择的功能，范围0-9
*/
int chooseInMenu()
{
    int i;
    while(1)
    {
        cout<<endl;
        cout<<"+---------------+"<<endl;
        cout<<"+ 1 按索引显示  +"<<endl;
        cout<<"+ 2 查询考生    +"<<endl;
        cout<<"+ 3 更新数据    +"<<endl;
        cout<<"+ 4 增加考生    +"<<endl;
        cout<<"+ 5 增加考生    +"<<endl;
        cout<<"+ 0 退出        +"<<endl;
        cout<<"+---------------+"<<endl;
        cout<<"请输入操作指令:"<<endl;
        cin>>i;
        if(i>=0 && i<=5)
            break;
        else
            cout<<"请重新选择功能\n"<<endl;
    }
    return i;
}
 
 
void done()
{
    //关闭数据文件
    dataFile.close();
    //若数据进行过增删改，索引表会发生变化，重新保存到文件中
    writeIndex(studentsIndex, stuNum);
}
 
 
void displayByIndex()
{
    Student stu;
    indexFile.seekg(ios::beg);
    int i;
    long location;
    cout<<"共"<<stuNum<<"名考生："<<endl;
    for(i=0; i<stuNum; ++i)
    {
        location = studentsIndex[i].offset;
        dataFile.seekg(location, ios::beg);
        dataFile.read((char*)&stu, sizeof(Student));
        cout<<i<<": ";
        displayStudent(stu);
    }
}
 
 
void displayStudent(Student &s)
{
    cout<<s.NO<<"\t";
    cout<<s.name<<"\t";
    cout<<s.chinese<<"\t";
    cout<<s.math<<"\t";
    cout<<s.english<<"\t";
    cout<<s.Comprehensive<<"\t";
    cout<<s.total<<"\t"<<endl;
}