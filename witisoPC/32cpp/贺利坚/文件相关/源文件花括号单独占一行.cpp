#include <fstream>  // 源文件花括号单独占一行
#include<iostream>
//#include<string>
#include<cstdlib>
using namespace std;
void outprogram(char *filename);
int main( )
{
    char ch1,ch2;
    //将文件中的数据读入到字符数组中
    ifstream sourceFile("source.cpp",ios::in);  //以输入的方式打开文件
    if(!sourceFile)       //测试是否成功打开
    {
        cerr<<"source code read error!"<<endl;
        exit(1);
    }
    ofstream outFile("newsource.cpp",ios::out);  //以输出的方式打开文件
    if(!outFile)       //测试是否成功打开
    {
        cerr<<"new source code write error!"<<endl;
        exit(1);
    }
    
    ch1='\0';
    while(!sourceFile.eof())
    {
        sourceFile.get(ch2);
        //读到了花括号，且前一个符号不是换行，应该加入一个换行
        if((ch2=='{'||ch2=='}')&&(ch1!='\n'))
            outFile.put('\n');
        else
            //当前读到的不是换行，但前一个是花括号，此时也该加
            if((ch1=='{'||ch1=='}')&&(ch2!='\n'))
                outFile.put('\n');
            outFile.put(ch2); //输出当前读入的符号
            ch1=ch2;
    }
    outFile.close();
    sourceFile.close();
    cout<<"经过处理后的源程序是："<<endl;
    outprogram("newsource.cpp");
    return 0;
}

void outprogram(char *filename)
{
    char line[256];
    int n = 1;
    ifstream inFile(filename, ios::in);  //以输入的方式打开文件
    if(!inFile)       //测试是否成功打开
    {
        cerr<<"file open error!"<<endl;
        exit(1);
    }
    while (!inFile.eof())
    {
        inFile.getline(line,255,'\n');
        cout<<n<<'\t'<<line<<endl;
        n++;
    }
    inFile.close();
    return;
}