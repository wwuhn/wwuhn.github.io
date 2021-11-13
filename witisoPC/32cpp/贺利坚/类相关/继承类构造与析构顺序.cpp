#include <iostream>
using namespace std;  // 继承类构造与析构顺序
class Part  //部件类
{
public:
    Part();
    Part(int i);
    ~Part();
private:
    int val;
};

class Whole: public Part
{
public:
    Whole();
    Whole(int,int,int,int);
    ~Whole();
private:
    Part one;
    Part two;
    int data;
};

Part::Part()
{
    val=0;
    cout<<"The default constructor of part was called "<<val<<endl;
}

Part::Part(int i)
{
    val=i;
    cout<<"The constructor of part was called "<<val<<endl;
}

Part::~Part()
{  
    cout<<"The destructor of part was called "<<val<<endl;
}

Whole::Whole()
{
    data=0;
    cout<<"The default constructor of whole was called "<<data<<endl;
}

Whole::Whole(int p, int i,int j,int k):Part(p),two(i),one(j),data(k)
{
    cout<<"The constructor of whole was called "<<data<<endl;
}

Whole::~Whole()
{  
    cout<<"The destructor of whole was called "<<data<<endl;
}

void f()
{
    Whole w1;
    Whole w2(1,2,3,4);
}

int main()
{
    f();
    system("pause");
    return 0;
}