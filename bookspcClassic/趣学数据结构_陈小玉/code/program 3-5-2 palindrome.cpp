#include<iostream>          // 回文判定
#include<cstring>
typedef char Elemtype;      // 先类型定义为char 
#include"sqstack.h"         // 引入自定义头文件,源码目录下名为sqstack.h的文件   

using namespace std;

bool palindrome(char *str)  // 判断字符串是否为回文
{
    SqStack S;              // 定义一个栈S
    int len,i;
    char e;
    len=strlen(str);        // 返回字符串长度
    InitStack(S);           // 初始化栈
    for(i=0;i<len/2;i++)    // 将字符串前一半依次入栈
        Push(S,str[i]);
    if(len%2==1)            // 字符串长度为奇数，跳过中心点
        i++;
    while(!Empty(S))        // 如果栈不空
    {
        Pop(S,e);           // 出栈
        if(e!=str[i])       // 比较元素是否相等
            return false;
        else
            i++;
    }
    return true;
}

int main()
{
    char str[20];
    cout<<"请输入一个长度小于20的字符串："<<endl;
    cin>>str;
    if(palindrome(str))
        cout<<"该字符串是回文！"<<endl;
    else
        cout<<"该字符串不是回文！"<<endl;
    return 0;
}
