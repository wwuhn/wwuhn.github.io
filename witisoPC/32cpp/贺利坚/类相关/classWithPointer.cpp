#if 0 //例程1
#include <iostream>
using namespace std;
class IntArray
{
public:
    IntArray(){arr_point=NULL; arr_len=0;}
    IntArray(int a[], int n);
    void showArray();
private:
    int *arr_point;  //数组的首地址
    int arr_len;
};

IntArray::IntArray(int a[], int n)
{
    arr_point=a;  //这是灾难的源头
    arr_len=n;
}

void IntArray::showArray()
{
    for (int i=0; i<arr_len; ++i)
        cout<<*(arr_point+i)<<' '; //或cout<<arr_point[i]<<' '
    cout<<endl;
    return;
}

int main()
{   
    int x[]={1,2,3,4,5};
    IntArray arr(x,5);
    arr.showArray();  // 输出1 2 3 4 5
    system("pause");
    return 0;
}

#endif

#if 0
//例程2
#include <iostream>
using namespace std;
class IntArray
{
public:
	IntArray(){arr_point=NULL; arr_len=0;}
	IntArray(int a[], int n);
	void showArray() const;
private:
	int *arr_point;  //数组的首地址
	int arr_len;
};
 
 
IntArray::IntArray(int a[], int n)
{
	arr_point=a; 
	arr_len=n;
}
 
 
void IntArray::showArray() const
{
	for (int i=0; i<arr_len; ++i)
		cout<<*(arr_point+i)<<' '; //或cout<<arr_point[i]<<' '
	cout<<endl;
	return;
}
 
 
int main2()
{   
	int x[]={1,2,3,4,5};
	const IntArray arr(x,5);
	arr.showArray();  //输出1 2 3 4 5
	x[3]=999;
	arr.showArray();  //输出的是1 2 3 999 5 ！！！！！！
	system("pause");
        return 0;
}

//例程3
 
……//类的定义与例程2完全相同
 
int main()
{   
	int *x=new int[5];
	for (int i=0; i<5; ++i)
		x[i]=i+1;  //x是通过动态分配空间获得的，后面的释放从机制上是合法的
	const IntArray arr(x,5);
	arr.showArray();  //输出1 2 3 4 5
	delete [] x;      //释放x，x可以由操作系统分配作其他用途（很正常，main中不再用局部变量x，及早释放，可以挪作他用。如果x数组很大，效益可观）
	arr.showArray();  //这是灾难发生的部位：输出结果不可预料，可能导致生产线停车、火车驶上了不该行驶的车道、火箭失控……
	system("pause");
        return 0;
}
#endif

#if 1
//例程4
#include <iostream>
using namespace std;
class IntArray
{
public:
	IntArray(){arr_point=NULL; arr_len=0;}
	IntArray(int a[], int n);
	~IntArray();
	void showArray() const;
 
private:
	int *arr_point;  //数组的首地址
	int arr_len;
};
 
IntArray::IntArray(int a[], int n)
{
	arr_point=new int[n];  //arr_point指向了属于自己的新空间
	for (int i=0; i<n; ++i) 
		*(arr_point+i)=*(a+i);   //将数组a中元素逐个赋值
	arr_len=n;
}
 
IntArray::~IntArray() //由于在类中涉及动态分配存储空间，在析构函数中将对应空间释放
{
	if (!arr_point) // 等同于if (arr_point!=NULL) 
		delete [] arr_point; //释放在类的生命周期中分配的，arr_point指向的空间
}
 
void IntArray::showArray() const
{
	for (int i=0; i<arr_len; ++i)
		cout<<*(arr_point+i)<<' '; //或cout<<arr_point[i]<<' '
	cout<<endl;
	return;
}
 
int main()
{   
	int *x=new int[5];
	for (int i=0; i<5; ++i)
		x[i]=i+1;
	const IntArray arr(x,5);
	arr.showArray();   // 输出1 2 3 4 5
	x[3]=999;
	arr.showArray();   // 输出1 2 3 4 5, arr使用专属的存储空间！
	delete [] x;
	arr.showArray();   // 输出1 2 3 4 5, arr使用专属的存储空间！！
	system("pause");
    return 0;
}
#endif