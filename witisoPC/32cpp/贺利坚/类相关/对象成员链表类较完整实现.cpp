#include<iostream> // 对象成员链表类较完整实现
using namespace std;

class Student  //结点类
{
public:
    Student(int n,double s)
    {
        num=n;
        score=s;
        next=NULL;
    }
    ~Student()
    {
        if(!next)
            delete next;
        next=NULL;
    };
    Student *next;   //指向下一个结点
    int num;
    double score;
};

class MyList  //链表类
{
public:
    MyList()
    {
        head=NULL;
    }
    MyList(int n,double s); //以Student(n,s)作为单结点的链表
    ~MyList();
    int display();  //输出链表，返回值为链表中的结点数
    void insert(int n,double s);  //插入：将Student(n,s)结点插入链表，该结点作为第一个结点
    void append(int n,double s);  //追加：将Student(n,s)结点插入链表，该结点作为最后一个结点
    void cat(MyList &il); //将链表il连接到当前对象的后面
    int length();  //返回链表中的结点数
private:
    Student *head;   //链表的头结点
};

MyList::MyList(int n,double s)
{
    head=new Student(n,s);
}

MyList::~MyList()
{
    Student *p=head, *q;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
    head = NULL;
}

int MyList::display()
{
    if(head==NULL)
    {
        cout<<"empty\n";
        return 0;
    }
    int cnt=0;
    Student *pt=head;
    while(pt)
    {
        ++cnt;
        cout<<pt->num<<", "<<pt->score<<endl;
        pt=pt->next;
    }
    return cnt;
}

void MyList::insert(int n, double s)
{
    Student * pt=new Student(n,s);
    pt->next =head;
    head=pt;
}

void MyList::append(int n,double s)
{
    Student * pt=new Student(n,s);
    if(head==NULL)
        head=pt;
    else
    {
        Student *pts=head;
        Student *pte=pts->next;
        while(pte)
        {
            pts=pte;
            pte=pts->next;
        }
        pts->next=pt;
    }
}

void MyList::cat(MyList& il)
{
    Student *pt=il.head;
    while(pt)
    {
        append(pt->num,pt->score);
        pt=pt->next;
    }
}

int MyList::length()
{
    int cnt=0;
    Student *pt=head;
    while(pt)
    {
        ++cnt;
        pt=pt->next ;
    }
    return cnt;
}

int main()
{
    int n;
    double s;
    MyList head1;
    cout<<"input head1: "<<endl;  //输入head1链表
    for(int i=0; i<3; i++)
    {
        cin>>n>>s;
        head1.insert(n,s);  //通过“插入”的方式
    }
    cout<<"head1: "<<endl; //输出head1
    head1.display();
    
    MyList head2(1001,98.4);  //建立head2链表
    head2.append(1002,73.5);  //通过“追加”的方式增加结点
    head2.append(1003,92.8);
    head2.append(1004,99.7);
    cout<<"head2: "<<endl;   //输出head2
    head2.display();
    
    head2.cat(head1);   //把head1追加到head2后面
    cout<<"length of head2 after cat: "<<head2.length()<<endl;
    cout<<"head2 after cat: "<<endl;   //显示追加后的结果
    head2.display();
    while(1);
    return 0;
}