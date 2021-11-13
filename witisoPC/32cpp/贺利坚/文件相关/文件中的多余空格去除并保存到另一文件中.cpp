//本程序用于将文件中的多余空格去除并保存到另一文件中
#include <iostream>
#include <fstream>
void alltrim(char *);
using namespace std;
int main() 
{
    ifstream sourceFile;
    ofstream targetFile;
    char str[100];
    int num_char=0, num_line=0;
    int i;
    sourceFile.open("c.txt", ios::in);
    if(!sourceFile)       //测试是否成功打开  
    {  
        cerr<<"input file open error!"<<endl;  
        exit(1);  
    }  
    targetFile.open("b.txt", ios::out);
    if(!targetFile)       //测试是否成功打开  
    {  
        cerr<<"output file open error!"<<endl;  
        exit(1);  
    }  
    while (!sourceFile.eof())   //一篇文章由多行构成
    {	
        sourceFile.getline(str,100,'\n');   
        alltrim(str);  //删去多余空格
        //保存删去空格后的字符
        i=0;
        while(*(str+i)!='\0')
        {
            targetFile.put(*(str+i));
            ++i;
        }
        targetFile.put('\n');
    }
    sourceFile.close();
    targetFile.close();
    cout<<"处理完毕，请查看文件。"<<endl;
    return 0;
}

//本函数删除原文件中所有多余空格并保存到另一文件中
void alltrim(char *str)
{
    char *p=str,*q=str;
    bool notSpace=false;
    while(*q==' ')
        q++;
    while(*q!='\0')
    {
        if (*q!=' ') 
        {
            notSpace=true;
            *p++=*q++; // 不是空格，复制   
        }
        else if (notSpace)   //是空格，但目前是第一个（因为之前notSpace=true;的条件是遇非空格）
        {                
            notSpace=false;   //第一个空格仍然要复制
            *p++=*q++;     
        }
        else   //如遇第二个或更后的空格，正是由于遇到第一个空格并复制后，notSpace=false;的原因，会走到这儿
        {
            q++;   //不复制
        }
    }
    *p='\0';
}