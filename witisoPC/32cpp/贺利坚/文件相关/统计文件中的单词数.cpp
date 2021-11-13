//本程序统计文件中的单词数
#include <iostream>
#include <fstream>
int wordnum(char str[]);
using namespace std;
int main() 
{
    ifstream sourceFile;
    char ch[100];
    int num_word=0;
    sourceFile.open("a.txt", ios::in);
    if(!sourceFile)             //测试是否成功打开  
    {  
        cerr<<"input file open error!"<<endl;  
        exit(1);  
    }  
    
    while (!sourceFile.eof())   //一篇文章由多行构成
    {	
        //通过循环读取多行，累加每一行的单词数
        sourceFile.getline(ch,100,'\n');   
        num_word+=wordnum(ch); 
    }
    sourceFile.close();
    cout << "文件中共有" <<num_word<<"个单词。"<<endl;
    return 0;
}

int wordnum(char str[])
{
    int i,num=0,word=0;  
    for(i=0;(str[i]!='\0');i++)  
    {
        if (str[i]==' ')
            word=0;  //word为0代表当前不构成一个词（遇到空格当然不是词了）
        else 
            if (word==0) //此处word为0，说明前面读到的是空格，而现在读到的又不是空格，新词开始
            {
                word=1;
                num++;    //新词，故计数
            }  //这儿不必else了，如果要，无非就是令word=1，因为读第一个非空格时已经是1了，不必要再赋值
    }
    return num;
}