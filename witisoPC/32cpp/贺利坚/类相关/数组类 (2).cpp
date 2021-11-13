#include <iostream.h>
#include <cstdlib>   // 数组类

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
    int GetSize(void) const;	//取数组大小；
    void Resize(int sz);        //修改数组的大小，如果sz大于数组的原大小，增加的元素初始为；如果sz大于数组的原大小，舍弃后面的元素【选做】
};
 
//构造函数，指定数组类对象的元素个数，其元素全部初始化为 0
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
 
//由一个内置类型的数组初始化
MyArray::MyArray(int a[],int sz)
{
    if(sz<=0)
    {
        cout<<"invalid Array Size";
        exit(1);
    }
    size=sz;//将元素个数赋值给变量size
    arr=new int[size];//动态分配内存，将size个int类型的元素空间分配出来
    for(int i=0; i<size; ++i)
        *(arr+i)=*(a+i);
}
 
//析构函数
MyArray::~MyArray(void)
{
    if (!arr)
        delete [] arr;
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
    int *srcptr=A.arr;//X.arr是对象A的数组首地址
    int *destptr=arr;//arr是本对象中的数组首地址
    while(n--)
    {
        *destptr=*srcptr;
        destptr++;
        srcptr++;
    }
}
 
//重载赋值运算'='
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
 
    //从rhs向当前对象复制元素
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
 
//重载[]，用于通过下标将元素取出来
int &MyArray::operator[](int n)
{
    if(n<0||n>size-1)
    {
        cout<<"index Out Of Range"<<endl;
        exit(1);
    }
    return arr[n];
}
 
bool MyArray::operator == (MyArray& A)
{
    bool eq=true;
    int n=A.size;	//取A数组的大小
    if (size!=n)    //大小不一致，数组一定不相等
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
                eq=false;     //其中有一个元素不相等，则数组也不相等
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
    if (size!=n)   //大小不一致不能相加
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
    int *newlist=new int[sz];  //为改变大小后的新数组分配空间
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
    delete []arr; //释放原数组占用的空间
    arr=newlist;  //设置重新分配后的新数组
    size=sz;
}
 
int main()
{
    int a[10]= {1,2,3,4,5,6,7,8,9,10};
    int b[10]= {4,5,6,7,8,9,10,11,12,13};
    MyArray arr1(a,10);  //测试用内置的数组初始化新定义的数组对象
    MyArray arr2(b,10);
    MyArray arr3(10);   //测试只指定大小的新数组对象的初始化
    cout<<arr3;    //测试对<<的重载
    arr3 = arr1 +arr2;  //测试对+运算，以及赋值=运算的重载
    cout<<arr3;
    arr3.Resize(20);  //测试扩大数组大小的功能
    cout<<arr3;
    arr3.Resize(5);   //测试缩小数组大小的功能
    cout<<arr3;
    cout<<"The size of new array is: "<<arr3.GetSize()<<endl;   //测试GetSize()成员函数
    cout<<"The first element of new array is: "<<arr3[0]<<endl;  //测试[]运算的重载
    cout<<"arr1 "<<(arr1==arr2?"=":"!=")<<" arr2. "<<endl;   //测试==运算符的重载
    cout<<"\n__End__"<<endl;
    while(1);
    return 0;
}
