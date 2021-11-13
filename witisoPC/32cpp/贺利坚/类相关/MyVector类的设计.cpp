//MyVector类的设计
#include <iostream.h>

class MyVector  //定义向量类
{
public:
    MyVector(){
        num=0;
        Array=NULL;
    }
    MyVector(int m);                //构造函数，共有m个元素的向量，元素值预置为0
    MyVector(const MyVector &v);    //复制构造函数
    ~MyVector();                    //析构函数：释放动态数组所占用的存储空间
    friend istream &operator>>(istream &input, MyVector &d);
    friend ostream &operator<<(ostream &output, const MyVector &d);
    friend MyVector operator+(const MyVector &d1,const MyVector &d2);//向量相加，对应位置上的元素相加
    friend MyVector operator-(const MyVector &d1,const MyVector &d2);//向量相减，对应位置上的元素相减
    bool operator==(const MyVector &d); //判断两个矩阵是否相等，即对应位置上的所有元素是否相等
    int operator[](int i);              //返回向量中的第i个元素的值
private:
    int *Array;       //Array 为动态数组指针，指向向量占用内存的起始地址
    int num;          //向量中元素个数
};
 
MyVector::MyVector(int m)
{
    num = m;
    Array = new int[num];
    for(int i=0; i<num; ++i)
        Array[i]=0;
}
 
MyVector::MyVector(const MyVector &d)
{
    num=d.num;
    if(Array!=NULL)                 //////////////////1111
        delete []Array;
    Array = new int[num];
    for(int i=0; i<num; ++i)
        Array[i]=d.Array[i];
}
 
MyVector::~MyVector() //析构函数：用于释放动态数组所占用的存储空间
{
    delete [] Array;
}
 
istream &operator>>(istream &input, MyVector &d)
{
    cout<<d.num<<"个元素的向量: ";
    for(int i=0; i<d.num; ++i)
        input>>d.Array[i];
    return input;
}
 
ostream &operator<<(ostream &output, const MyVector &d)
{
    cout<<"(";
    if(d.num>0)
        output<<d.Array[0];
    for(int i=1; i<d.num; ++i)
       output<<", "<<d.Array[i];
    output<<")";
    return output;
}
 
MyVector operator+(const MyVector &d1,const MyVector &d2)
{
    //在此可以先判断d1和d2的元素数是否相同，如果不相同可以报错退出，不做运算。本参考解答忽略了这一前提
   
    if(d1.num != d2.num)
    {
        cout<<"the SIZE of two array is not the same!"<<endl;
        return -1;
    }
    MyVector d(d1.num);
    for(int i=0; i<d1.num; ++i)
    {
        d.Array[i]=d1.Array[i]+d2.Array[i];
    }
    return d;
}
 
MyVector operator-(const MyVector &d1,const MyVector &d2)
{
    if(d1.num != d2.num)
    {
        cout<<"the SIZE of two array is not the same!"<<endl;
        return -1;
    }
    MyVector d(d1.num);
    for(int i=0; i<d1.num; ++i)
    {
        d.Array[i]=d1.Array[i]-d2.Array[i];
    }
    return d;
}
 
bool MyVector::operator ==(const MyVector &d)//判断两个矩阵是否相等，即对应位置上的所有元素是否相等
{
    if(num!=d.num) return false;
    bool eq = true;
    for(int i=0; i<num; ++i)
    {
        if (Array[i]!=d.Array[i])
        {
            eq=false;
            break;
        }
        if (!eq) break;
    }
    return eq;
}
 
int MyVector::operator[](int i)
{
    return Array[i];  //未实施越界保护
}
 
int main()
{
    MyVector d1(5),d2(5);
    cout<<"输入d1——";
    cin>>d1;
    cout<<"输入d2——";
    cin>>d2;
    cout<<"d1="<<d1<<endl;
    cout<<"d2="<<d2<<endl;
    cout<<"d1+d2="<<d1+d2<<endl;
    cout<<"d1-d2="<<d1-d2<<endl;
    cout<<"d1"<<((d1==d2)?"==":"!=")<<"d2"<<endl;
    cout<<"d1[2]="<<d1[2]<<endl;
    while(1);
    return 0;
}