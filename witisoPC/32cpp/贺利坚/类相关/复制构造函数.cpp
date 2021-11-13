#if 0
//例程2
#include <iostream.h>

class Douary
{
public:
	Douary(int m, int n);//构造函数：用于建立动态数组存放m行n列的二维数组（矩阵）元素，并将该数组元素初始化为0
	~Douary(); //析构函数：用于释放动态数组所占用的存储空间
    //Douary(const Douary &d);//复制构造函数
	friend istream &operator>>(istream &input, Douary &d);//重载运算符“>>”输入二维数组，其中d为Dousry类对象；
	friend ostream &operator<<(ostream &output, Douary &d);//重载运算符“<<”以m行n列矩阵的形式输出二维数组，其中d为Douary类对象。
	friend Douary operator+(const Douary &d1,const Douary &d2);//两个矩阵相加，规则：对应位置上的元素相加
private:
	int *Array;       //Array 为动态数组指针。
	int row;          //row   为二维数组的行数。
	int col;          //col   为二维数组的列数。
};
 
Douary::Douary(int m, int n) //构造函数：用于建立动态数组存放m行n列的二维数组（矩阵）元素，并将该数组元素初始化为
{
	row=m;
	col=n;
	Array = new int[m*n];
	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			Array[i*col+j]=0;
}
 
Douary::~Douary() //析构函数：用于释放动态数组所占用的存储空间
{
	delete [] Array;
}
 
istream &operator>>(istream &input, Douary &d)//重载运算符“>>”输入二维数组，其中d为Dousry类对象
{
	for(int i=0; i<d.row; ++i)
		for(int j=0; j<d.col; ++j)
			cin>>d.Array[i*d.col+j];
	return input;
}
 
ostream &operator<<(ostream &output, Douary &d)//重载运算符“<<”以m行n列矩阵的形式输出二维数组，其中d为Douary类对象
{
	for(int i=0; i<d.row; ++i)
	{
		for(int j=0; j<d.col; ++j)
			cout<<d.Array[i*d.col+j]<<"\t";
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
 
int main()
{
	Douary d1(2,3),d2(2,3);
	cout<<"输入d1(2,3):"<<endl;
	cin>>d1;
	cout<<"输入d2(2,3):"<<endl;
	cin>>d2;
	cout<<"d1+d2="<<endl;
	Douary d3=d1+d2;
	cout<<d3;
	while(1);
	return 0;
}

/*
1 2 3
4 5 6
9 8 7
6 5 4
*/
#endif

#if 1

#include <iostream.h>

class Douary
{
public:
    Douary(int m, int n);   //构造函数：用于建立动态数组存放m行n列的二维数组（矩阵）元素，并将该数组元素初始化为0
    ~Douary();              //析构函数：用于释放动态数组所占用的存储空间
    Douary(const Douary &d);//复制构造函数
    friend istream &operator>>(istream &input, Douary &d);      //重载运算符“>>”输入二维数组，其中d为Dousry类对象；
    friend ostream &operator<<(ostream &output, Douary &d);     //重载运算符“<<”以m行n列矩阵的形式输出二维数组，其中d为Douary类对象。
    friend Douary operator+(const Douary &d1,const Douary &d2); //两个矩阵相加，规则：对应位置上的元素相加
private:
    int *Array;       //Array 为动态数组指针。
    int row;          //row   为二维数组的行数。
    int col;          //col   为二维数组的列数。
};

Douary::Douary(int m, int n) //构造函数：用于建立动态数组存放m行n列的二维数组（矩阵）元素，并将该数组元素初始化为
{
    row=m;
    col=n;
    Array = new int[m*n];
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            Array[i*col+j]=0;
}

Douary::Douary(const Douary &d)
{
    row=d.row;
    col=d.col;
    Array = new int[row*col];
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            Array[i*col+j]=d.Array[i*col+j];
}

Douary::~Douary() //析构函数：用于释放动态数组所占用的存储空间
{
    delete [] Array;
}

istream &operator>>(istream &input, Douary &d)//重载运算符“>>”输入二维数组，其中d为Dousry类对象
{
    for(int i=0; i<d.row; ++i)
        for(int j=0; j<d.col; ++j)
            cin>>d.Array[i*d.col+j];
        return input;
}

ostream &operator<<(ostream &output, Douary &d)//重载运算符“<<”以m行n列矩阵的形式输出二维数组，其中d为Douary类对象
{
    for(int i=0; i<d.row; ++i)
    {
        for(int j=0; j<d.col; ++j)
            cout<<d.Array[i*d.col+j]<<"\t";
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

int main()
{
    Douary d1(2,3),d2(2,3);
    cout<<"输入d1(2,3):"<<endl;
    cin>>d1;
    cout<<"输入d2(2,3):"<<endl;
    cin>>d2;
    cout<<"d1+d2="<<endl;
    Douary d3=d1+d2;
    cout<<d3;
    while(1);
    return 0;
}
#endif