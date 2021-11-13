/*  数组类
数组是几乎所支持的组织数据的方法。C和C++对数组类型提供了内置支持，
使我们利用数组实现软件中需要的各种实用的功能。但是，这种支持仅限于用来读写单个元素的机制。
C++不支持数组的抽象abstraction，也不支持对整个数组的操作。
例如：把一个数组赋值给另外一个数组，对两个数组进行相等比较或者想知道数组的大小size，等等。
对C++而言，数组是从C语言中继承来的，它反映了数据与对其进行操作的算法的分离，
有浓厚的过程化程序设计的特征。数组并不是C++语言的一等公民。
所以在实际项目中，对一个C++程序员，更多的是使用标准库中提供的Vector类型实现数组功能。
这个任务也将从面向对象角度重新审视和理解数组，进而扫清自学Vector等标准类中可能存在的障碍。
*/
#include <iostream.h> 
#include <stdlib.h>
class MyArray
{
private:
    int *arr;		//用于存放动态分配的数组内存首地址
    int size;		//数组大小
public:
    MyArray(int sz=50);
    MyArray(int a[],int sz);	//由一个内置类型的数组初始化
    MyArray(const MyArray &A);	//复制构造函数
    ~MyArray(void);				//析构函数，注意释放空间
    MyArray&operator =(const MyArray &A);   //重载“=”使得数组对象可以整体赋值
    int& operator[](int i);		            //重载[]，使得Array对象也可以如C++普通数组一样，用a[i]形式取出值【选做】
    bool operator == (MyArray& A);	        //重载==，使得Array对象能整体判断两个数组是否相等（size相等且对应元素相等）
    MyArray operator + (MyArray& A);	    //重载+，使两个Array对象可以整体相加（前提大小相等）【选做】
    friend ostream& operator << (ostream& out,MyArray& A);	//重载<<，输出数组
    int GetSize(void)const;	                //取数组大小；
    void Resize(int sz);	                //修改数组的大小，如果sz大于数组的原大小，增加的元素初始为；如果sz大于数组的原大小，舍弃后面的元素【选做】
};

//以下为类成员函数的定义

//构造函数
MyArray::MyArray(int sz)
{
    if(sz<=0)
    {
        cout<<"invalid Array Size!";
        exit(1);
    }
    size=sz;    		//将元素个数赋值给变量size
    arr=new int[size];  //动态分配内存，将size个int类型的元素空间分配出来
    for(int i=0; i<size; ++i)
        *(arr+i)=0;
}

MyArray::MyArray(int a[],int sz)
{
    if(sz<=0)
    {
        cout<<"invalidArraySize";
        exit(1);
    }
    size=sz;            //将元素个数赋值给变量size
    arr=new int[size];  //动态分配内存，将size个int类型的元素空间分配出来
    for(int i=0; i<size; ++i)
        *(arr+i)=*(a+i);
}

//析构函数
MyArray::~MyArray(void)
{
    delete []arr;
}

//复制构造函数
MyArray::MyArray(const MyArray& A)
{
    //从对象A取得数组大小，并赋给当前对象成员
    int n=A.size;
    size=n;
    //为对象申请内存并进行出错检测
    arr=new int[n];
    //从对象A复制数组元素到本对象
    int *srcptr=A.arr;  //A.arr是对象A的数组首地址
    int *destptr=arr;   //arr是本对象中的数组首地址
    while(n--)
    {
        *destptr=*srcptr;
        destptr++;
        srcptr++;
    }
}

//重载'='
MyArray& MyArray::operator =(const MyArray &A)
{
    int n=A.size;//取A数组的大小
    //如果本对象中的数组大小和A不同，则删除数组原有的内存，然后重新分配
    if (size!=n)
    {
        delete []arr;
        arr=new int[n];
        size=n;
    }
    
    //从rhs向本对象复制元素
    int* destptr=arr;
    int* srcptr=A.arr;
    while(n--)
    {
        *destptr=*srcptr;
        destptr++;
        srcptr++;
    }
    return *this;//返回当前对象的引用
}

//重载[]
int &MyArray::operator[](int n)
{
    if(n<0||n>size-1)             // 加入了边界检查
    {
        cout<<"indexOutOfRange"<<endl;
        exit(1);
    }
    return arr[n];
}

bool MyArray::operator == (MyArray& A)
{
    bool eq=true;
    int n=A.size;	//取A数组的大小
    if (size!=n)    //大小是否一致
    {
        eq=false;
    }
    else
    {
        int* destptr=arr;
        int* srcptr=A.arr;
        while(n--)
        {
            if(*destptr!=*srcptr)
            {
                eq=false;
                break;
            }
            destptr++;
            srcptr++;
        }
    }
    return eq;//返回当前对象的引用
}

MyArray MyArray::operator + (MyArray& A)
{
    int n=A.size;	//取A数组的大小
    if (size!=n)    //大小不一致不能相加
    {
        cout<<"not same size for add!"<<endl;
        exit(1);
    }
    MyArray a(n);  //指定size的数组
    
    for (int i = 0; i < size; i++)
    {
        a[i]=arr[i]+A[i];
    }
    return a;//返回当前对象的引用
}

ostream& operator << (ostream& out, MyArray& A)
{
    for (int i = 0; i < A.size; i++)
    {
        out<<A[i]<<'\t';
    }
    out<<endl;
    return out;
}

//取当前数组大小
int MyArray::GetSize(void)const
{
    return size;
}

//将数组大小修改为sz
void MyArray::Resize(int sz)
{
    if(sz<=0)
    {
        cout<<"invalidArraySize"<<endl;
        exit(1);
    }
    if(sz==size)
        return;
    int *newlist=new int[sz];
    for (int i = 0; i < sz; i++)
    {
        *(newlist+i)=0;
    }
    int n=(sz<=size)?sz:size;
    int *srcptr=arr;
    int *destptr=newlist;
    while(n--)
    {
        *destptr=*srcptr;
        destptr++;
        srcptr++;
    }
    delete []arr;
    arr=newlist;
    size=sz;
}

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int b[10]={4,5,6,7,8,9,10,11,12,13};
    MyArray arr1(a,10);
    MyArray arr2(b,10);
    MyArray arr3(10);
    cout<<arr3;
    arr3 = arr1 +arr2;
    cout<<arr3;
    arr3.Resize(20);
    cout<<arr3;
    arr3.Resize(5);
    cout<<arr3;
    system("pause");
    return 0;
} 

/*
【任务扩展一（选做）】规定MyArray只能处理元素为整型的数据未免太弱了，请设计成模板类，
使之适应各种类型（事实上，C++增加的标准类对些类情况均设计成了模板类）。
【任务扩展二（选做）】可以施加于数组的操作还有很多，例如最经典的排序，
还有求最大、最小、查找某一元素、截取其中的片段（取从第5个互第10个之间的所有元素，
可以形成新的数组对象）、向量乘法，……。将这些操作构造为类的成员函数，开始拓展之旅吧！
*/