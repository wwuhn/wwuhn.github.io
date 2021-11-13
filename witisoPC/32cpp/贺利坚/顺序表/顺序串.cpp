#ifndef SqString_H_INCLUDED
#define SqString_H_INCLUDED

#define MaxSize 100             //最多的字符个数
typedef struct
{   
    char data[MaxSize];         //定义可容纳MaxSize个字符的空间
    int length;                 //标记当前实际串长
} SqString;

void StrAssign(SqString &s,char cstr[]);    //字符串常量cstr赋给串s
void StrCopy(SqString &s,SqString t);       //串t复制给串s
bool StrEqual(SqString s,SqString t);   //判串相等
int StrLength(SqString s);              //求串长
SqString Concat(SqString s,SqString t); //串连接
SqString SubStr(SqString s,int i,int j);//求子串
SqString InsStr(SqString s1,int i,SqString s2);     //串插入
SqString DelStr(SqString s,int i,int j) ;           //串删去
SqString RepStr(SqString s,int i,int j,SqString t); //串替换
void DispStr(SqString s);   //输出串

#endif // SqString_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
//#include "SqString.h"

void StrAssign(SqString &s,char cstr[]) //s为引用型参数
{   int i;
    for (i=0;cstr[i]!='\0';i++)
        s.data[i]=cstr[i];
    s.length=i;
}
void StrCopy(SqString &s,SqString t)    //s为引用型参数
{   int i;
    for (i=0;i<t.length;i++)
        s.data[i]=t.data[i];
    s.length=t.length;
}
bool StrEqual(SqString s,SqString t)
{   bool same=true;
    int i;
    if (s.length!=t.length)             //长度不相等时返回0
        same=false;
    else
        for (i=0;i<s.length;i++)
            if (s.data[i]!=t.data[i])   //有一个对应字符不相同时返回0
            {   same=false;
                break;
            }
    return same;
}
int StrLength(SqString s)
{
    return s.length;
}
SqString Concat(SqString s,SqString t)
{   SqString str;
    int i;
    str.length=s.length+t.length;
    for (i=0;i<s.length;i++)    //将s.data[0..s.length-1]复制到str
        str.data[i]=s.data[i];
    for (i=0;i<t.length;i++)    //将t.data[0..t.length-1]复制到str
        str.data[s.length+i]=t.data[i];
    return str;
}
SqString SubStr(SqString s,int i,int j)
{   SqString str;
    int k;
    str.length=0;
    if (i<=0 || i>s.length || j<0 || i+j-1>s.length)
        return str;                 //参数不正确时返回空串
    for (k=i-1;k<i+j-1;k++)         //将s.data[i..i+j]复制到str
        str.data[k-i+1]=s.data[k];
    str.length=j;
    return str;
}
SqString InsStr(SqString s1,int i,SqString s2)
{   int j;
    SqString str;
    str.length=0;
    if (i<=0 || i>s1.length+1)  //参数不正确时返回空串
        return str;
    for (j=0;j<i-1;j++)             //将s1.data[0..i-2]复制到str
        str.data[j]=s1.data[j];
    for (j=0;j<s2.length;j++)       //将s2.data[0..s2.length-1]复制到str
        str.data[i+j-1]=s2.data[j];
    for (j=i-1;j<s1.length;j++)     //将s1.data[i-1..s1.length-1]复制到str
        str.data[s2.length+j]=s1.data[j];
    str.length=s1.length+s2.length;
    return str;
}
SqString DelStr(SqString s,int i,int j)
{   int k;
    SqString str;
    str.length=0;
    if (i<=0 || i>s.length || i+j>s.length+1) //参数不正确时返回空串
        return str;
    for (k=0;k<i-1;k++)             //将s.data[0..i-2]复制到str
        str.data[k]=s.data[k];
    for (k=i+j-1;k<s.length;k++)    //将s.data[i+j-1..s.length-1]复制到str
        str.data[k-j]=s.data[k];
    str.length=s.length-j;
    return str;
}
SqString RepStr(SqString s,int i,int j,SqString t)
{   int k;
    SqString str;
    str.length=0;
    if (i<=0 || i>s.length || i+j-1>s.length) //参数不正确时返回空串
        return str;
    for (k=0;k<i-1;k++)             //将s.data[0..i-2]复制到str
        str.data[k]=s.data[k];
    for (k=0;k<t.length;k++)        //将t.data[0..t.length-1]复制到str
        str.data[i+k-1]=t.data[k];
    for (k=i+j-1;k<s.length;k++)    //将s.data[i+j-1..s.length-1]复制到str
        str.data[t.length+k-j]=s.data[k];
    str.length=s.length-j+t.length;
    return str;
}
void DispStr(SqString s)
{   int i;
    if (s.length>0)
    {   for (i=0;i<s.length;i++)
            printf("%c",s.data[i]);
        printf("\n");
    }
}

#include <stdio.h>
//#include "sqString.h"
int main()
{
    SqString s,s1,s2,s3,s4;
    printf("链串的基本运算如下:\n");
    printf("  (1)建立串s和串s1\n");
    StrAssign(s,"abcdefghijklmn");
    printf("  (2)输出串s:");
    DispStr(s);
    StrAssign(s1,"123");
    printf("  (2)输出串s1:");
    DispStr(s1);
    printf("  (3)串s的长度:%d\n",StrLength(s));
    printf("  (4)在串s的第9个字符位置插入串s1而产生串s2\n");
    s2=InsStr(s,9,s1);
    printf("  (5)输出串s2:");
    DispStr(s2);
    printf("  (6)删除串s第2个字符开始的5个字符而产生串s2\n");
    s2=DelStr(s,2,5);
    printf("  (7)输出串s2:");
    DispStr(s2);
    printf("  (8)将串s第2个字符开始的5个字符替换成串s1而产生串s2\n");
    s2=RepStr(s,2,5,s1);
    printf("  (9)输出串s2:");
    DispStr(s2);
    printf("  (10)提取串s的第2个字符开始的10个字符而产生串s3\n");
    s3=SubStr(s,2,10);
    printf("  (11)输出串s3:");
    DispStr(s3);
    printf("  (12)将串s1和串s2连接起来而产生串s4\n");
    s4=Concat(s1,s2);
    printf("  (13)输出串s4:");
    DispStr(s4);
    while(1);
    return 0;
}
