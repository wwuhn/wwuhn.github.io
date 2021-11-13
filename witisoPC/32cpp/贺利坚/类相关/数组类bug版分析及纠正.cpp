#if 0    // 有问题的动态数组类版本
/*
，比较明显的是第115行的a[i]=arr[i]+A[i];有些别扭。a和A是MyArray类的对象，
而arr是当前对象的一个成员（我想起一条胳膊和一个人要加起来，哪能这样！）
修改为a.arr[i]=arr[i]+A.arr[i];

看41行开始的拷贝构造函数MyArray::MyArray(const MyArray &A) 的定义，
为this->arr成员分配了空间，并将形参对象中指向的数据一一进行复制，
惟独没有做的，是为 this->size 赋值！我们需要在这个函数中，增加一行代码：size = A.size;。


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
    MyArray(const MyArray &A);	//拷贝构造函数
    ~MyArray(void);				//析构函数，注意释放空间
    MyArray&operator =(const MyArray &A); //重载“=”使得数组对象可以整体赋值
    int& operator[](int i);		//重载[]，使得Array对象也可以如C++普通数组一样，用a[i]形式取出值【选做】
    bool operator == (MyArray& A);	//重载==，使得Array对象能整体判断两个数组是否相等（size相等且对应元素相等）
    MyArray operator + (MyArray& A);	//重载+，使两个Array对象可以整体相加（前提大小相等）【选做】
    friend ostream& operator << (ostream& out,MyArray& A);	//重载<<，输出数组
    int GetSize(void)const;	//取数组大小；
    void Resize(int sz);	//修改数组的大小，如果sz大于数组的原大小，增加的元素初始为；sz小于数组的原大小，舍弃后面的元素【选做】
};
MyArray::MyArray(int sz)
{
    size = sz;
    arr = new int[size];
    for( int i = 0; i < size; i++ )
    {
        *(arr + i) = 0;
    }
}

MyArray::MyArray(int a[],int sz)	//由一个内置类型的数组初始化
{
    size = sz;
    arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        *(arr + i) = *(a + i);
    }
}

MyArray::MyArray(const MyArray &A)	//拷贝构造函数
{
    arr = new int[A.size];
    for(int i = 0; i < A.size; i++)
    {
        *(arr + i) = *(A.arr + i);
    }
    //????????????????????????????????????????????
    
}

MyArray::~MyArray(void)				//析构函数，注意释放空间
{
    delete[]arr;
}
MyArray& MyArray::operator =(const MyArray &A) //重载“=”使得数组对象可以整体赋值
{
    int n = A.size;
    if( size != n )
    {
        delete[]arr;
        arr = new int[n];
        size = n;
    }
    int* destptr=arr;  
    int* srcptr=A.arr;  
    while(n--)  
    {  
        *destptr=*srcptr;  
        destptr++;  
        srcptr++;  
    }  
    return *this;
}

int& MyArray::operator[](int i)		//重载[]，使得Array对象也可以如C++普通数组一样，用a[i]形式取出值【选做】
{
    return arr[i];
}
bool MyArray::operator == (MyArray& A)	//重载==，使得Array对象能整体判断两个数组是否相等（size相等且对应元素相等）
{
    bool m;
    m = true;
    if( A.size != size )
    {
        m = false;
    }
    else
    {
        for( int i = 0; i < size; i++ )
            
            if( *(A.arr + i) != *(arr + i) )
            {
                m = false;
                break;
            }
            
    }
    return m;
}


MyArray MyArray::operator + (MyArray& A)  
{  
    int n=A.size;   //取A数组的大小  
    if (size!=n)   //大小不一致不能相加  
    {  
        cout<<"not same size for add!"<<endl;  
        exit(1);  
    }  
    MyArray a(n);  //指定size的数组  
    
    for (int i = 0; i < size; i++)  
    {  
        a[i]=arr[i]+A.arr[i];  //?????????????????????????????????
    }  
    return a;//返回当前对象的引用  
}  



ostream& operator << (ostream& out,MyArray& A)	//重载<<，输出数组
{
    for( int i = 0; i < A.size; i++)
    {
        out << A[i] << " ";
    }
    out << endl;
    return out;
    
}
int MyArray::GetSize(void)const	//取数组大小；
{
    return size;
}

void MyArray::Resize(int sz)	//修改数组的大小，如果sz大于数组的原大小，增加的元素初始为；sz小于数组的原大小，舍弃后面的元素【选做】
{
    int *m = new int(sz);
    for( int i = 0; i < sz; i++)
    {
        *m = 0;
    }
    int n = ( sz <= size )?sz:size;
    for(int j = 0; j < n; j++)
    {
        *(m + j) = *(arr + j);
    }
    delete[]arr;
    arr = m;
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
    //	arr3.Resize(20);
    //	cout<<arr3;
    //	arr3.Resize(5);
    //	cout<<arr3;
    system("pause");
    return 0;
} 

#endif

#if 1
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
    MyArray(const MyArray &A);	//拷贝构造函数
    ~MyArray(void);				//析构函数，注意释放空间
    MyArray&operator =(const MyArray &A); //重载“=”使得数组对象可以整体赋值
    int& operator[](int i);		//重载[]，使得Array对象也可以如C++普通数组一样，用a[i]形式取出值【选做】
    bool operator == (MyArray& A);	//重载==，使得Array对象能整体判断两个数组是否相等（size相等且对应元素相等）
    MyArray operator + (MyArray& A);	//重载+，使两个Array对象可以整体相加（前提大小相等）【选做】
    friend ostream& operator << (ostream& out,MyArray& A);	//重载<<，输出数组
    int GetSize(void)const;	//取数组大小；
    void Resize(int sz);	//修改数组的大小，如果sz大于数组的原大小，增加的元素初始为；sz小于数组的原大小，舍弃后面的元素【选做】
};
MyArray::MyArray(int sz)
{
    size = sz;
    arr = new int[size];
    for( int i = 0; i < size; i++ )
    {
        *(arr + i) = 0;
    }
}

MyArray::MyArray(int a[],int sz)	//由一个内置类型的数组初始化
{
    size = sz;
    arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        *(arr + i) = *(a + i);
    }
}

MyArray::MyArray(const MyArray &A)	//拷贝构造函数
{
    arr = new int[A.size];
    for(int i = 0; i < A.size; i++)
    {
        *(arr + i) = *(A.arr + i);
    }
    
    size = A.size;               //?????????????????????????????????
}

MyArray::~MyArray(void)				//析构函数，注意释放空间
{
    delete[]arr;
}
MyArray& MyArray::operator =(const MyArray &A) //重载“=”使得数组对象可以整体赋值
{
    int n = A.size;
    if( size != n )
    {
        delete[]arr;
        arr = new int[n];
        size = n;
    }
    int* destptr=arr;  
    int* srcptr=A.arr;  
    while(n--)  
    {  
        *destptr=*srcptr;  
        destptr++;  
        srcptr++;  
    }  
    return *this;
}

int& MyArray::operator[](int i)		//重载[]，使得Array对象也可以如C++普通数组一样，用a[i]形式取出值【选做】
{
    return arr[i];
}
bool MyArray::operator == (MyArray& A)	//重载==，使得Array对象能整体判断两个数组是否相等（size相等且对应元素相等）
{
    bool m;
    m = true;
    if( A.size != size )
    {
        m = false;
    }
    else
    {
        for( int i = 0; i < size; i++ )
            
            if( *(A.arr + i) != *(arr + i) )
            {
                m = false;
                break;
            }
            
    }
    return m;
}


MyArray MyArray::operator + (MyArray& A)  
{  
    int n=A.size;   //取A数组的大小  
    if (size!=n)   //大小不一致不能相加  
    {  
        cout<<"not same size for add!"<<endl;  
        exit(1);  
    }  
    MyArray a(n);  //指定size的数组  
    
    for (int i = 0; i < size; i++)  
    {  
        a[i]=arr[i]+A[i];      //??????????????????????????????????????????
    }  
    return a;//返回当前对象的引用  
}  



ostream& operator << (ostream& out,MyArray& A)	//重载<<，输出数组
{
    for( int i = 0; i < A.size; i++)
    {
        out << A[i] << " ";
    }
    out << endl;
    return out;
    
}
int MyArray::GetSize(void)const	//取数组大小；
{
    return size;
}

void MyArray::Resize(int sz)	//修改数组的大小，如果sz大于数组的原大小，增加的元素初始为；sz小于数组的原大小，舍弃后面的元素【选做】
{
    int *m = new int(sz);
    for( int i = 0; i < sz; i++)
    {
        *m = 0;
    }
    int n = ( sz <= size )?sz:size;
    for(int j = 0; j < n; j++)
    {
        *(m + j) = *(arr + j);
    }
    delete[]arr;
    arr = m;
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
    //	arr3.Resize(20);
    //	cout<<arr3;
    //	arr3.Resize(5);
    //	cout<<arr3;
    system("pause");
    return 0;
} 

#endif