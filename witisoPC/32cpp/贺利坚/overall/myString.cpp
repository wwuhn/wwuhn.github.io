/*
对于要定义的字符串类CMyString，
数据成员包括：
- 字符串的长度；
- 指向字符串第一个字符的指针
成员函数包括：
- 不带参数的构造函数；
- 带一个类型为const char *类型的参数(用于对字符串初始化)的构造函数；
- 带一个const CMyString&类型的复制构造参数；
- 析构函数；
- Strlen函数 (用于求字符串的长度)；
- int Find(char c) (找出字符c在本字符串中第一次出现的位置，并返回其下标；如果本字符串中不包含c，则返回-1)；
- int Find(const char *str1) ( 找出字符串str1在本字符串中第一次出现的位置，并返回其下标；如果本字符串中不包含字符串str1，则返回-1),
- int Find(const CMyString&  str1) (找出字符串str1在本字符串中第一次出现的位置，并返回其下标；如果本字符串中不包含字符串str1，则返回-1)，
- int Replace(char c1, char c2) (将本字符串中出现的所有字符c1用字符c2替换, 返回替换的次数)；
- void Replace(const char *str1, const char *str2) (将本字符串中第一次出现的字符串str1用字符串str2替换)；
- void Display() (用于显示字符串)
对运算符[]+=等进行重载，例如，设str1和str2是两个CMyString类的对象，
- 用str1[i]表示字符串str1的下标为i的字符；
- str1+str2的结果是将str2连在str1的后面，并将结果仍然存放在 str1中；
- 用=表示赋值。
(2)编写主函数，定义几个CMyString类的对象，并利用键盘输入字符串的内容，编程验证以上定义的所有函数。
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


class CMyString
{
private:
    int m_nLen;
    char *m_szStr;
public:
    CMyString(void);
    CMyString(const char *str);
    CMyString(const CMyString& str1);
    ~CMyString(void);
    int Strlen(void);
    int Find(char c);
    int Find(const char *str1);
    int Find(const CMyString&  str1);
    int Replace(char  c1, char c2);
    void Replace(const char *str1, const char *str2);
    char& operator[](int i);
    CMyString operator+(const CMyString& str1);
    CMyString& operator=(const CMyString& str1);
    void Display()
    {
        cout<<m_szStr<<endl;
    };
};


//注意下面三个构造函数中均要分配存储空间
CMyString::CMyString(void)
{
    m_nLen=0;
    m_szStr=new char[m_nLen+1];//+1的空间用于存放字符串结束标志
    strcpy(m_szStr,"");
}


CMyString::CMyString(const char *str)
{
    m_nLen=strlen(str);
    m_szStr=new char[m_nLen+1];
    strcpy(m_szStr,str);
}


CMyString::CMyString(const CMyString& str1)
//复制构造函数，注意复制构造函数的深复制、浅复制问题，函数体若写成
//{
//	m_szStr=str1.m_szStr;
//	m_nLen=str1.m_nLen;
//}
//是不正确的。
{
    m_nLen=str1.m_nLen;
    m_szStr=new char[m_nLen+1];
    strcpy(m_szStr,str1.m_szStr);
}


CMyString::~CMyString(void)
{
    delete []m_szStr;
}


int CMyString::Strlen(void)
{
    return m_nLen;
}


int CMyString::Find(char c)
//找出字符c在本字符串中第一次出现的位置，并返回其下标；如果本字符串中不包含c，则返回-1
{
    int i=0;
    while(m_szStr[i]!='\0'&&m_szStr[i]!=c)
        i++;
    if (m_szStr[i]=='\0')
        return -1;
    else
        return i;
}


int CMyString::Find(const char *str1)
// 找出字符串str1在本字符串中第一次出现的位置，并返回其下标；如果本字符串中不包含字符串str1，则返回-1
{
    int len=strlen(str1);
    int find=0;
    int i;
    //将CMyString对象从第i个字符开始的，长度与str1相等的字符串依次与str1比较
    for(i=0; i<=m_nLen-len; i++)
    {
        find=1;
        for(int j=0; j<len; j++)
            if(m_szStr[i+j]!=str1[j])
                find=0;
            if (find) break;
    }
    if (find)
        return i;
    else
        return -1;
}


int CMyString::Find(const CMyString&  str1)
// 找出字符串str1在本字符串中第一次出现的位置，并返回其下标；如果本字符串中不包含字符串str1，则返回-1
{
    int len=str1.m_nLen;
    int find=0;
    int i;
    for(i=0; i<=m_nLen-len; i++)
    {
        find=1;
        for(int j=0; j<len; j++)
            if(m_szStr[i+j]!=str1.m_szStr[j])
                find=0;
            if (find) break;
    }
    if (find)
        return i;
    else
        return -1;
}


int CMyString::Replace(char  c1, char c2)
//将本字符串中出现的所有字符c1用字符c2替换, 返回替换的次数
{
    int count=0;
    for(int i=0; i<m_nLen; i++)
    {
        if (m_szStr[i]==c1)
        {
            count++;
            m_szStr[i]=c2;
        }
    }
    return count;
}


void CMyString::Replace(const char *str1, const char *str2)
//将本字符串中第一次出现的字符串str1用字符串str2替换
{
    int i=Find(str1);  //i为srt1在本字符串中首次出现的位置
    int j;
    if (i>=0)
    {
        int len1=strlen(str1),len2=strlen(str2);
        if (len1!=len2) //str1与str2长度不相等
        {
            int len=m_nLen-len1+len2;
            char *result=new char[len+1];
            //求出CMyString对象从str1往后的字符串将其存放与字符串temp中
            char *temp;
            temp=new char[m_nLen-i-len1+1];
            for (j=0; j<m_nLen-i-len1; j++)
            {
                temp[j]=m_szStr[i+len1+j];
            }
            temp[j]='\0';
            ///将CMyString对象中从str1往前的字符串及str2存放与result
            for(j=0; j<i; j++)
                result[j]=m_szStr[j];
            for(j=0; j<len2; j++)
                result[i+j]=str2[j];
            result[i+j]='\0';
            // 将CMyString对象从str1往后的字符串(即temp)添加到当前result(由CMyString对象从str1往前的字符串及str2构成）之后,
            strcat(result,temp);
            //用result构造新的*this
            delete []m_szStr;  //释放原有空间，新的字符串空间即result所指的空间
            m_szStr=result;
            m_nLen=len;
            delete []temp;
        }
        else    //str1与str2长度相等，直接替换即可
        {
            for(int j=0; j<len1; j++)
                m_szStr[i+j]=str2[j];
        }
    }
}


CMyString CMyString::operator+(const CMyString& str1)
//本字符串+str1的结果是将str1连在本字符串的后面，并将结果仍然存放在本字符串中
{
    int len1=str1.m_nLen;
    int len=m_nLen+len1;
    int j;
    char *result=new char[len+1];
    for(j=0; j<m_nLen; j++)
        result[j]=m_szStr[j];
    result[j]='\0';
    strcat(result,str1.m_szStr);
    delete []m_szStr;
    m_szStr=result;
    m_nLen=len;
    return *this;
}


//注意以下两个成员函数返回值必须为引用类型
char& CMyString::operator[](int i)
//设str1为CMystring类的对象，str1[i]表示str1对应的串中下标为i的字符,
{
    if (i<0||i>m_nLen-1)
    {
        cout<<"index out of range."<<endl;
        exit(1);
    }
    return m_szStr[i];
}


CMyString& CMyString::operator=(const CMyString& str1)
{
    int len1=str1.m_nLen;
    if (m_nLen!=len1)
    {
        delete []m_szStr;
        m_szStr=new char[len1+1];
        m_nLen=len1;
    }
    strcpy(m_szStr,str1.m_szStr);
    return *this;
}


int main()
{
    //所有输出信息中的字符串序列号均从0开始
    char *str="Hello!";
    /*下面分别用
    CMyString(void);
    CMyString(const char *str);
    CMyString(const CMyString& str1);
    三种方式构造字符串对象str1、str2、str3*/
    CMyString str1,str2(str),str3(str2);
    cout<<"str1 is:";
    str1.Display();
    cout<<"str2 is:";
    str2.Display();
    cout<<"str3 is:";
    str3.Display();
    
    
    cout<<"length of str2 is:"<<str2.Strlen()<<endl;
    
    
    //int Find(char c);的验证
    cout<<"'H' is the "<<str2.Find('H')+1<<" char in str2"<<endl;
    cout<<"'!' is the "<<str2.Find('!')+1<<" char in str2"<<endl;
    cout<<"'s' is the "<<str2.Find('s')+1<<" char in str2"<<endl;
    
    
    //int Find(const char *str1);的验证
    cout<<"\"ell\" is from "<<str2.Find("ell")+1<<" char in str2"<<endl;
    cout<<"\"o\" is from "<<str2.Find("o")+1<<" char in str2"<<endl;
    cout<<"\"Heli\" is from "<<str2.Find("Heli")+1<<" char in str2"<<endl;
    
    
    //int Find(const CMyString&  str1);的验证
    char *str_1=new char[20],*str_2=new char[20];
    cout<<"input a string:";
    //下面的方法用于输入一行不超过20个字符，以回车为结束的可包含空格的字符串
    //cin>>str_1;不能输入带空格的字符串
    cin.getline(str_1,20,'\n');
    cout<<"input the string to be finded:";
    cin.getline(str_2,20,'\n');
    CMyString str4(str_1),str5(str_2);
    cout<<str4.Find(str5)<<endl;
    delete[]str_1;
    delete[]str_2;
    
    
    //int Replace(char  c1, char c2);的验证
    char *str_3=new char[20];
    char c1,c2;
    cout<<"input a string:";
    cin.getline(str_3,20,'\n');
    cout<<"input c1:";
    cin>>c1;
    cout<<"input c2:";
    cin>>c2;
    CMyString str6(str_3);
    cout<<"replace "<<'\''<<c1<<'\''<<" of "<<"this string"<<" with "<<'\''<<c2<<'\''<<' ';
    cout<<str6.Replace(c1,c2)<<" times "<<endl<<"after replace the string is: ";
    str6.Display();
    delete[]str_3;
    
    
    //void Replace(const char *str1, const char *str2);的验证
    char *str_4=new char[20];
    char str_5[5],str_6[5];
    cout<<"input a string:";
    cin.getline(str_4,20,'\n');  //用于提取缓冲区中剩余的'\n'
    cin.getline(str_4,20,'\n');  //正式输入字符串
    cout<<"input the str1 in this string to be changed:";
    cin>>str_5;
    cout<<"input the str2 you want to change to:";
    cin>>str_6;
    CMyString str7(str_4);
    cout<<"replace first time of "<<"\""<<str_5<<"\""<<" in this string with "<< "\""<<str_6<<"\""<<" is ";
    str7.Replace(str_5,str_6);
    str7.Display();
    
    
    //运算符[]+=的验证
    cout<<"the 2nd charcter after replace is:"<<str7[2]<<endl;
    while(1);
    return 0;
}