/*
在互联网中使用的IP地址占4字节，可以用四段法表示，每段值的范围为0-255，中间用“.”隔开
，例如202.194.116.97。其实，也可以看看一个有4字节的无符号整型值3401741409。
现设计一个IP地址类，用于保存IP地址，并实施在IP地址上的一些操作。
*/
#if 1

#include <iostream>
using namespace std;
class IP
{
private:
    union
    {
        struct
        {
            unsigned char seg0;
            unsigned char seg1;
            unsigned char seg2;
            unsigned char seg3;
        };                      //IP地址共4字节，或者看成结构体所指4部分
        unsigned int address;   //或者看成一个整体
    };
public:
    IP(int=0,int=0,int=0,int=0);    //构造函数
    void showIP();                  //用四段法显示IP地址
    bool sameSubnet(const IP &ip, const IP &mark);  //判断是否处于同一子网
    char whatKind();                                //返回属于哪一类网络
};

IP::IP(int s0,int s1,int s2,int s3)
{
    //下面赋值的顺序，涉及整型数据存储结构，参考[《整型数据在内存中如何存储？》](http://blog.csdn.net/sxhelijian/article/details/51015706)
    seg3=s0;
    seg2=s1;
    seg1=s2;
    seg0=s3;
}

void IP::showIP()
{
    //显示结果，是给人看的，分4段合适
    cout<<int(seg3)<<"."<<int(seg2)<<"."<<int(seg1)<<"."<<int(seg0)<<endl;
    return;
}

bool IP::sameSubnet(const IP &ip, const IP &mark)
{
    //与子网掩码按位与，是计算机内部的操作，直接以一个整体操作更方便
    unsigned int i1, i2;
    i1=   address & mark.address;   //和子网掩码作逻辑与运算
    i2=ip.address & mark.address;   //和子网掩码作逻辑与运算
    return (i1==i2);                //与子网掩码的逻辑与运算结果相同，则属于同一子网
}

char IP::whatKind()
{
    //IP地址的类型，请到百度百科中搜索《IP地址》
    if(seg3<128)
        return 'A';
    else if(seg3<192)
        return 'B';
    else if(seg3<224)
        return 'C';
    else if(seg3<240)
        return 'D';
    else
        return 'E';
}

int main()
{
    IP ip1(202,194,116,97), ip2(202,194,119,102), mark(255,255,248,0);
    cout<<"ip1: ";
    ip1.showIP();
    cout<<"ip2: ";
    ip2.showIP();
    if(ip1.sameSubnet(ip2,mark))
        cout<<"两个IP在同一子网"<<endl;
    else
        cout<<"两个IP不在同一子网"<<endl;
    cout<<"ip1属于"<<ip1.whatKind()<<"类网络"<<endl;
    return 0;
}

#else

#include <iostream>
using namespace std;
class IP
{
private:
    union
    {
        unsigned char seg[4]; //IP地址共4字节，或者看成无符号字符数组所指4部分
        unsigned int address; //或者看成一个整体
    };
public:
    IP(int=0,int=0,int=0,int=0);
    void showIP();
    bool sameSubnet(const IP &ip, const IP &mark);
    char whatKind();
};

IP::IP(int s0,int s1,int s2,int s3)
{
    //下面赋值的顺序，涉及整型数据存储结构，参考[《整型数据在内存中如何存储？》](http://blog.csdn.net/sxhelijian/article/details/51015706)
    seg[0]=s3;
    seg[1]=s2;
    seg[2]=s1;
    seg[3]=s0;
}

void IP::showIP()
{
    //显示结果，是给人看的，分4段合适
    cout<<int(seg[3])<<"."<<int(seg[2])<<"."<<int(seg[1])<<"."<<int(seg[0])<<endl;
    return;
}

bool IP::sameSubnet(const IP &ip, const IP &mark)
{
    //与子网掩码按位与，是计算机内部的操作，直接以一个整体操作更方便
    unsigned int i1, i2;
    i1=address&mark.address; //和子网掩码作逻辑与运算
    i2=ip.address&mark.address; //和子网掩码作逻辑与运算
    return (i1==i2); //与子网掩码的逻辑与运算结果相同，则属于同一子网
}

char IP::whatKind()
{
    //IP地址的类型，请到百度百科中搜索《IP地址》
    if(seg[3]<128)
        return 'A';
    else if(seg[3]<192)
        return 'B';
    else if(seg[3]<224)
        return 'C';
    else if(seg[3]<240)
        return 'D';
    else
        return 'E';
}

int main()
{
    IP ip1(202,194,116,97), ip2(202,194,119,102), mark(255,255,248,0);
    cout<<"ip1: ";
    ip1.showIP();
    cout<<"ip2: ";
    ip2.showIP();
    if(ip1.sameSubnet(ip2,mark))
        cout<<"两个IP在同一子网"<<endl;
    else
        cout<<"两个IP不在同一子网"<<endl;
    cout<<"ip1属于"<<ip1.whatKind()<<"类网络"<<endl;
    return 0;
}


#endif

#if 0


#endif
/*
    printf("\n-End-\n");
    while(1);
    return 0;
*/