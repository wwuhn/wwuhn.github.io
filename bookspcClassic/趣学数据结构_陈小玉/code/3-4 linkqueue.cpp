#include<iostream>
using namespace std;

typedef  struct Qnode{
  int data;
  struct Qnode *next;
}Qnode,*Qptr;

typedef struct{
  Qnode *front;
  Qnode *rear;
}LinkQueue;

// 链队的初始化
void InitQueue(LinkQueue &Q)        // 注意使用引用参数，否则出了函数，其改变无效
{
	Q.front=Q.rear=new Qnode;       // 创建头结点，头指针和尾指针指向头结点
	Q.front->next=NULL;
}

// 链队列的入队
void EnQueue(LinkQueue &Q,int e)    // 将元素e放入队尾
{
	Qptr s;
	s=new Qnode;
	s->data=e;
	s->next=NULL;
	Q.rear->next=s; // 新元素插入队尾
	Q.rear=s;       // 队尾指针后移
}

// 链队列的出队
bool DeQueue(LinkQueue &Q,int &e) // 删除Q的队头元素，用e返回其值
{
	Qptr p;
	if(Q.front==Q.rear)         // 队空
		return false;
	p=Q.front->next;
	e=p->data;                  // 保存队头元素
	Q.front->next=p->next;
	if(Q.rear==p)               // 若队列中只有一个元素，删除后需要修改队尾指针
        Q.rear=Q.front;
	delete p;
	return true;
}

// 取循环队列的队头元素
int GetHead(LinkQueue Q)        // 返回Q的队头元素，不修改队头指针
{
	if (Q.front!=Q.rear)        // 队列非空
		return Q.front->next->data;
    return -1;
}

int main()
{
	LinkQueue Q;
	int n,x;
	InitQueue(Q);               // 初始化队列(一定要初始化，否则后面存储出错)
	cout<<"请输入元素个数n："<<endl;
	cin>>n;
	cout<<"请依次输入n个整型数，依次入队："<<endl;
    while(n--)
    {
       	cin>>x;
		EnQueue(Q,x);//入队
    }
    cout<<"队头元素："<<GetHead(Q)<<endl;
	cout<<"元素依次出队："<<endl;
	while(true)                 // 如果栈不空，则依次出栈
    {
        if(DeQueue(Q,x))
            cout<<x<<"\t";      // 出队元素
        else
            break;
    }
    cout<<endl;
	return 0;
}
