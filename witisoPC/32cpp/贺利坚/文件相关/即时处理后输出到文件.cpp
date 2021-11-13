/*

  读入一个C++程序，输入m、n两个数字，从第m行起的n行代码将作为注释使用（即在这些行前面加上”//”），
  新程序保存到另一个.cpp文件中，并在屏幕上显示处理过的程序，显示时加上行号。
*/

#include <fstream>
#include<iostream>  // 即时处理后输出到文件
#include<cstring>
#include<cstdlib>
using namespace std;
void outprogram(const char *filename);
int main( )
{
    char line[256];
    int m,n;
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
    cout<<"您要将第m行开始的n行代码作为注释，请输入m和n：";
    cin>>m>>n;
    int n1=0;
    while(!sourceFile.eof())
    {
        sourceFile.getline(line,255,'\n');
        n1++;
        if(n1>=m&&n1<m+n)
            outFile.put('/').put('/');
        outFile.write(line,strlen(line));
        outFile.write("\n",1);
    }
    outFile.close();
    sourceFile.close();
    cout<<"经过处理后的源程序是："<<endl;
    outprogram("newsource.cpp");
    return 0;
}

void outprogram(const char *filename)
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