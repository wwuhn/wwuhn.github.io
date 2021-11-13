#ifndef LISTRING_H_INCLUDED
#define LISTRING_H_INCLUDED

typedef struct snode
{
    char data;
    struct snode *next;
} LiString;

void StrAssign(LiString *&s,char cstr[]);   //字符串常量cstr赋给串s
void StrCopy(LiString *&s,LiString *t);     //串t复制给串s
bool StrEqual(LiString *s,LiString *t);     //判串相等
int StrLength(LiString *s);                 //求串长
LiString *Concat(LiString *s,LiString *t);  //串连接
LiString *SubStr(LiString *s,int i,int j);  //求子串
LiString *InsStr(LiString *s,int i,LiString *t) ;       //串插入
LiString *DelStr(LiString *s,int i,int j);              //串删去
LiString *RepStr(LiString *s,int i,int j,LiString *t);  //串替换
void DispStr(LiString *s);                              //输出串

#endif // LISTRING_H_INCLUDED
#include <stdio.h>
#include <malloc.h>
//#include "liString.h"

void StrAssign(LiString *&s,char cstr[])    //字符串常量cstr赋给串s
{
    int i;
    LiString *r,*p;
    s=(LiString *)malloc(sizeof(LiString));
    r=s;                                    //r始终指向尾节点
    for (i=0;cstr[i]!='\0';i++)
    {   p=(LiString *)malloc(sizeof(LiString));
        p->data=cstr[i];
        r->next=p;r=p;
    }
    r->next=NULL;
}
void StrCopy(LiString *&s,LiString *t)  //串t复制给串s
{
    LiString *p=t->next,*q,*r;
    s=(LiString *)malloc(sizeof(LiString));
    r=s;                //r始终指向尾节点
    while (p!=NULL)     //将t的所有节点复制到s
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
}
bool StrEqual(LiString *s,LiString *t)  //判串相等
{
    LiString *p=s->next,*q=t->next;
    while (p!=NULL && q!=NULL && p->data==q->data)
    {   p=p->next;
        q=q->next;
    }
    if (p==NULL && q==NULL)
        return true;
    else
        return false;
}

int StrLength(LiString *s)  //求串长
{
    int i=0;
    LiString *p=s->next;
    while (p!=NULL)
    {   i++;
        p=p->next;
    }
    return i;
}

LiString *Concat(LiString *s,LiString *t)   //串连接
{
    LiString *str,*p=s->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    r=str;
    while (p!=NULL)         //将s的所有节点复制到str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    p=t->next;
    while (p!=NULL)         //将t的所有节点复制到str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}

LiString *SubStr(LiString *s,int i,int j)   //求子串
{
    int k;
    LiString *str,*p=s->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    str->next=NULL;
    r=str;                      //r指向新建链表的尾节点
    if (i<=0 || i>StrLength(s) || j<0 || i+j-1>StrLength(s))
        return str;             //参数不正确时返回空串
    for (k=0;k<i-1;k++)
        p=p->next;
    for (k=1;k<=j;k++)          //将s的第i个节点开始的j个节点复制到str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}
LiString *InsStr(LiString *s,int i,LiString *t)     //串插入
{
    int k;
    LiString *str,*p=s->next,*p1=t->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    str->next=NULL;
    r=str;                              //r指向新建链表的尾节点
    if (i<=0 || i>StrLength(s)+1)       //参数不正确时返回空串
        return str;
    for (k=1;k<i;k++)                   //将s的前i个节点复制到str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    while (p1!=NULL)                    //将t的所有节点复制到str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p1->data;
        r->next=q;r=q;
        p1=p1->next;
    }
    while (p!=NULL)                     //将*p及其后的节点复制到str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}


LiString *DelStr(LiString *s,int i,int j)   //串删去
{
    int k;
    LiString *str,*p=s->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    str->next=NULL;
    r=str;                      //r指向新建链表的尾节点
    if (i<=0 || i>StrLength(s) || j<0 || i+j-1>StrLength(s))
        return str;             //参数不正确时返回空串
    for (k=0;k<i-1;k++)         //将s的前i-1个节点复制到str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    for (k=0;k<j;k++)               //让p沿next跳j个节点
        p=p->next;
    while (p!=NULL)                 //将*p及其后的节点复制到str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}
LiString *RepStr(LiString *s,int i,int j,LiString *t)   //串替换
{
    int k;
    LiString *str,*p=s->next,*p1=t->next,*q,*r;
    str=(LiString *)malloc(sizeof(LiString));
    str->next=NULL;
    r=str;                          //r指向新建链表的尾节点
    if (i<=0 || i>StrLength(s) || j<0 || i+j-1>StrLength(s))
        return str;                 //参数不正确时返回空串
    for (k=0;k<i-1;k++)             //将s的前i-1个节点复制到str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;q->next=NULL;
        r->next=q;r=q;
        p=p->next;
    }
    for (k=0;k<j;k++)               //让p沿next跳j个节点
        p=p->next;
    while (p1!=NULL)                //将t的所有节点复制到str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p1->data;q->next=NULL;
        r->next=q;r=q;
        p1=p1->next;
    }
    while (p!=NULL)                 //将*p及其后的节点复制到str
    {   q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;q->next=NULL;
        r->next=q;r=q;
        p=p->next;
    }
    r->next=NULL;
    return str;
}
void DispStr(LiString *s)   //输出串
{
    LiString *p=s->next;
    while (p!=NULL)
    {   printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}

#include <stdio.h>
//#include "liString.h"
int main()
{
    LiString *s,*s1,*s2,*s3,*s4;
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
    s2=DelStr(s,2,3);
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
