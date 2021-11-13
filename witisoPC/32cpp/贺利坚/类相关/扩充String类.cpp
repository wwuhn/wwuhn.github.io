/*
扩充String类】在String类中增加一个数据成员len表示字符串中字符个数，
然后构造String类的相关运算。这些运算可以包括：
s1 + s2用于两个字符串的连接；
s1 - s2用于将s1的尾部空格和s2的前导空格去除后的连接；
s1*n的结果为将s1中的字符重复n次；
s1/s2表示在s1中删除所有与s2相同的子串。
这些运算本身并无统一的规范，多想一些字符串上的操作，利用运算符的重载实现之。
*/

#include <iostream.h>
#include <Cstring>
 
class String
{
public:
    String( );                         //默认构造函数
    String(const char *s);
    String(String &str);               //构造函数
    ~String();
    void display( );
    friend String operator + (String &s1,String &s2 );
    friend String operator - (String &s1,String &s2 );
    friend String operator * (String &s1,int n );       //未实现,先发出来了
    friend String operator / (String &s1,String &s2 );  //未实现，先发出来了
private:
    char *p;
    int len;                                       //字符型指针，用于指向字符串
};
String::String()
{
    len = 0;
    p = NULL;
}

String::String(const char *s)
{
    len = strlen(s);
    p = new char[len+1];
    strcpy(p,s);
}
 
String::String(String &str)
{
    len = str.len;
    p = new char[len+1];
    strcpy(p,str.p);
}
 
String::~String()
{
    if(!p)
        delete []p;
}
 
void String::display( )     //输出p所指向的字符串
{
    cout<<p<<endl;
}
 
String operator + (String &s1, String &s2 )
{
    String s;
    s.len = s1.len+s2.len;
    s.p = new char(s.len+1);
    strcpy(s.p,s1.p);
    strcat(s.p,s2.p);
    return s;
}
 
String operator - (String &s1, String &s2 )
{
    String s;
    //c1为截去尾部空格的字符串
    char *c1=new char[s1.len+1];
    strcpy(c1,s1.p);
    int i=s1.len-1;
    while(i>=0&&c1[i]==' ') --i;
    c1[i+1]='\0';
 
    //c2为去除前导空格的字符串
    char *c2=new char[s2.len+1];
    strcpy(c2,s2.p);
    i=0;
    while(i<s2.len&&c2[i]==' ') ++i;
    int j=0;
    while(i<s2.len&&c2[i]!='\0')
    {
        c2[j]=c2[i];
        ++i;
        ++j;
    }
    c2[j+1]='\0';
 
    //将这两部分接起来
    s.len = strlen(c1)+strlen(c2);
    s.p = new char(s.len+1);
    strcpy(s.p,c1);
    strcat(s.p,c2);
    delete c1;
    delete c2;
    return s;
}
 
int main( )
{
    String string1(" Hello  "),string2(" World ");
    string1.display();

    String string3;
    string3 = string1 + string2;
    string3.display();
    string3 = string1 - string2;
    string3.display();
    while(1);
    return 0;
}