#include<iostream>
using namespace std;

#define Maxsize 100
typedef char ElemType;

typedef  struct SqQueue{
  ElemType base[Maxsize]; //一维数组存储，也可以设置指针动态分配空间
  int front,rear; //头指针,尾指针
}DuQueue;

//初始化
void InitQueue(DuQueue &Q)//注意使用引用参数，否则出了函数，其改变无效
{
	Q.front=Q.rear=0; //头指针和尾指针置为零，队列为空
}
//判队空
 bool isEmpty(DuQueue Q)
 {
     if(Q.front==Q.rear)
        return true;
     else
        return false;
 }
 //判队满
 bool isFull(DuQueue Q)
 {
     if((Q.rear+1)%Maxsize==Q.front) //尾指针后移一位等于头指针，表明队满
		return true;
     else
        return false;
 }
 //头进
bool push_front(DuQueue &Q,ElemType e)
{
    if(isFull(Q))
        return false;
    Q.front=(Q.front-1+Maxsize)%Maxsize;//先向前移动一位
    Q.base[Q.front]=e; //后放入
    return true;
}
//头出
bool pop_front(DuQueue &Q,ElemType &x)
{
    if(isEmpty(Q))
        return false;
    x=Q.base[Q.front]; //取数据
    Q.front=(Q.front+1)%Maxsize;//向后移动一位
    return true;
}
 //尾进
bool push_back(DuQueue &Q,ElemType e)
{
    if(isFull(Q))
        return false;
    Q.base[Q.rear]=e; //先放入
    Q.rear=(Q.rear+1)%Maxsize;//向后移动一位
    return true;
}
//尾出
bool pop_back(DuQueue &Q,ElemType &x)
{
    if(isEmpty(Q))
        return false;
    Q.rear=(Q.rear-1+Maxsize)%Maxsize;//向前移动一位
    x=Q.base[Q.rear]; //取数据
    return true;
}
//取队头
bool get_front(DuQueue Q,ElemType &x)
{
    if(isEmpty(Q))
        return false;
    x=Q.base[Q.front]; //取队头数据;
    return true;
}
//取队尾
bool get_back(DuQueue Q,ElemType &x)
{
    if(isEmpty(Q))
        return false;
    x=Q.base[(Q.rear-1+Maxsize)%Maxsize];
    return true;
}
//求长度
int length(DuQueue Q)
{
    return (Q.rear-Q.front+Maxsize)%Maxsize;
}
//从头到尾输出整个队列元素（遍历）
void traverse(DuQueue Q)
{
    if(isEmpty(Q))
    {
       cout<<"DuQueue is empty"<<endl;
       return ;
    }
    int temp=Q.front;//设置一个暂存变量，头指针未移动
    while(temp!=Q.rear)
    {
       cout<<Q.base[temp]<<"\t";
       temp=(temp+1)%Maxsize;
     }
     cout<<endl<<"traverse is over!"<<endl;
}

int main()
{
    DuQueue DuQ;
    ElemType e,x;
    cout<<"1. 初始化\n";
	cout<<"2. 头进\n";
	cout<<"3. 头出\n";
	cout<<"4. 尾进\n";
	cout<<"5. 尾出\n";
	cout<<"6. 取队头\n";
	cout<<"7. 取队尾\n";
	cout<<"8. 求长度\n";
	cout<<"9. 遍历队列\n";
	cout<<"0. 退出\n";
	int choose=-1;
	while (choose!=0)
	{
        cout<<"请选择:";
		cin>>choose;
		switch(choose)
		{
		    case 1://初始化
		        cout << "双端队列初始化..." << endl;
		        InitQueue(DuQ);
		        break;
		     case 2://头进
		         cout << "从前端进队（头进）..." << endl;
		         cout << "请输入一个字符:" << endl;
		         cin>>e;
		         push_front(DuQ,e);
                 break;
            case 3://头出
                cout <<"从前端出队（头出）..."<< endl;
                pop_front(DuQ,x);
                cout << "出队元素为" <<x<< endl;
                break;
            case 4://尾进
                cout << "从后端进队（尾进）..." << endl;
		        cout << "请输入一个字符:" << endl;
                cin>>e;
                push_back(DuQ,e);
                break;
            case 5://尾出
                 cout <<"从后端出队（尾出）..."<< endl;
                pop_back(DuQ,x);
                cout << "出队元素为" <<x<< endl;
                break;
             case 6://取队头元素
                cout <<"取队头元素..."<< endl;
                get_front(DuQ,x);
                cout << "队头元素为" <<x<< endl;
                break;
            case 7://取队尾元素
                cout <<"取队尾元素..."<< endl;
                get_back(DuQ,x);
                cout << "队尾元素为" <<x<< endl;
                break;
            case 8://求队长
                cout << "双端队列长度："<<length(DuQ)<<endl;
                break;
            case 9://遍历
                traverse(DuQ);
                break;
        }
	}
    return 0;
}
