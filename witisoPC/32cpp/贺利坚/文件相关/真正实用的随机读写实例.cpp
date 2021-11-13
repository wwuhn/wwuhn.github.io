#include<iostream>  // 真正实用的随机读写实例
#include <fstream>
#include<cstdlib>
#include<cstring>
using namespace std;

class Student
{
public:
    Student(void) {}
    Student(int n, char nam[20], float s):
    num(n),score(s)
    {
        strcpy(name,nam);
    }
    void setNum(int n)
    {
        num=n;
    }
    void setName(char nam[20])
    {
        strcpy(name,nam);
    }
    void setScore(float s)
    {
        score=s;
    }
    void show()
    {
        cout<<num<<" "<<name<<" "<<score<<endl;    //显示通过<<的重载实现更自然
    }
private:
    int num;
    char name[20];
    float score;
};

int main( )
{
    Student stud[5]=
    {
        Student(1001,"Li",85),
            Student(1002,"Fun",97.5),
            Student(1004,"Wang",54),
            Student(1006,"Tan",76.5),
            Student(1010,"ling",96)
    };
    fstream iofile("stud.dat", ios::in|ios::out|ios::binary);
    
    if(!iofile)
    {
        cerr<<"open error!"<<endl;
        abort( );
    }
    
    cout<<"（1）向磁盘文件输出个学生的数据并显示出来"<<endl;
    int i;
    for(i=0; i<5; i++)
    {
        iofile.write((char *)&stud[i],sizeof(stud[i]));
        stud[i].show();
    }
    
    cout<<"（2）将磁盘文件中的第1,3,5个学生数据读入程序，并显示出来"<<endl;
    Student stud1[5];
    for(i=0; i<5; i=i+2)
    {
        iofile.seekg(i*sizeof(stud[i]),ios::beg);
        iofile.read((char *)&stud1[i/2],sizeof(stud1[0]));
        stud1[i/2].show();;
    }
    cout<<endl;
    cout<<"（3）将第个学生的数据修改后存回磁盘文件中的原有位置"<<endl;
    stud[2].setNum(1012);
    stud[2].setName("Wu");
    stud[2].setScore(60);
    iofile.seekp(2*sizeof(stud[0]),ios::beg);
    iofile.write((char *)&stud[2],sizeof(stud[2]));
    iofile.seekg(0,ios::beg);
    cout<<"（4）从磁盘文件读入修改后的个学生的数据并显示出来"<<endl;
    for(i=0; i<5; i++)
    {
        iofile.read((char *)&stud[i],sizeof(stud[i]));
        stud[i].show();
    }
    iofile.close( );
    while(1);
    return 0;
}