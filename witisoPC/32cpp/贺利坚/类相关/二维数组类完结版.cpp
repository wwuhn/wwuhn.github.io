#include <iostream>   // 二维数组类完结版
using namespace std;
class Douary
{
public:
	Douary(int m, int n);//构造函数：用于建立动态数组存放m行n列的二维数组（矩阵）元素，并将该数组元素初始化为
	Douary(const Douary &d);//构造函数：用于建立动态数组存放m行n列的二维数组（矩阵）元素，并将该数组元素初始化为
	~Douary(); //析构函数：用于释放动态数组所占用的存储空间
	friend istream &operator>>(istream &input, Douary &d);//重载运算符“>>”输入二维数组，其中d为Dousry类对象；
	friend ostream &operator<<(ostream &output, Douary &d);//重载运算符“<<”以m行n列矩阵的形式输出二维数组，其中d为Douary类对象。
	friend Douary operator+(const Douary &d1,const Douary &d2);//两个矩阵相加，规则：对应位置上的元素相加
	friend Douary operator-(const Douary &d1,const Douary &d2);//两个矩阵相减，规则：对应位置上的元素相减
	bool operator==(const Douary &d);//判断两个矩阵是否相等，即对应位置上的所有元素是否相等
private:
	int * Array;      //Array 为动态数组指针。
	int row;          //row  为二维数组的行数。
	int col;          //col   为二维数组的列数。
};
 
Douary::Douary(int m, int n) //构造函数：用于建立动态数组存放m行n列的二维数组（矩阵）元素，并将该数组元素初始化为
{
	row=m;
	col=n;
	Array = new int[m*n]; //Array只能指向一维数组，将m*n个元素的一维数组当作m行n列的数组看待了
	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			Array[i*col+j]=0; //关键是给出各个元素地址的计算办法，此处还可以写作*(Array+i*col+j)=0; 
}
 
Douary::Douary(const Douary &d)
{
	row=d.row;
	col=d.col;
	Array = new int[row*col];
	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			Array[i*col+j]=d.Array[i*col+j]; //注意地址求法
}
 
Douary::~Douary() //析构函数：用于释放动态数组所占用的存储空间
{
	delete [] Array;
}
 
istream &operator>>(istream &input, Douary &d)//重载运算符“>>”输入二维数组，其中d为Dousry类对象
{
	for(int i=0; i<d.row; ++i)
		for(int j=0; j<d.col; ++j)
			cin>>d.Array[i*d.col+j];//注意地址求法
	return input;
}
 
ostream &operator<<(ostream &output, Douary &d)//重载运算符“<<”以m行n列矩阵的形式输出二维数组，其中d为Douary类对象
{
	for(int i=0; i<d.row; ++i)
	{
		for(int j=0; j<d.col; ++j)
			cout<<d.Array[i*d.col+j]<<"\t"; //注意地址求法
		cout<<endl;
	}
	cout<<endl;
	return output;
}
 
Douary operator+(const Douary &d1,const Douary &d2)//两个矩阵相加，规则：对应位置上的元素相加
{
	//在此可以先判断d1和d2的行列是否相同，如果不相同可以报错退出，不做运算。本参考解答忽略了这一前提
	Douary d(d1.row,d1.col);
	for(int i=0; i<d1.row; ++i)
	{
		for(int j=0; j<d1.col; ++j)
			d.Array[i*d1.col+j]=d1.Array[i*d1.col+j]+d2.Array[i*d1.col+j];
	}
	return d;
}
 
Douary operator-(const Douary &d1,const Douary &d2)//两个矩阵相减，规则：对应位置上的元素相减
{
	//在此可以先判断d1和d2的行列是否相同，如果不相同可以报错退出，不做运算。本参考解答忽略了这一前提
	Douary d(d1.row,d1.col);
	for(int i=0; i<d1.row; ++i)
	{
		for(int j=0; j<d1.col; ++j)
			d.Array[i*d1.col+j]=d1.Array[i*d1.col+j]-d2.Array[i*d1.col+j];
	}
	return d;
}
bool Douary::operator ==(const Douary &d)//判断两个矩阵是否相等，即对应位置上的所有元素是否相等
{
	if(row!=d.row||col!=d.col) return false;
	bool eq = true;
	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
			if (Array[i*col+j]!=d.Array[i*col+j]) 
			{
				eq=false;
				break;
			}
			if (!eq) break;
	}
	return eq;
}
 
int main()
{
	Douary d1(2,3),d2(2,3);
	cout<<"输入d1(2,3):"<<endl;
	cin>>d1;
	cout<<"输入d2(2,3):"<<endl;
	cin>>d2;
	cout<<"d1="<<endl;
	cout<<d1;
	cout<<"d2="<<endl;
	cout<<d2;
	cout<<"d1+d2="<<endl;
	Douary d3=(d1+d2);
	cout<<d3;
	cout<<"d1-d2="<<endl;
	cout<<(d1-d2);
	cout<<"d1"<<((d1==d2)?"==":"!=")<<"d2"<<endl;
	system("pause");
	return 0;
}