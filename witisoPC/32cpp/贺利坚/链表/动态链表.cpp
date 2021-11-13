/*
动态链表也是程序设计中的一种非常有用的数据结构。可以说，是否能够理解有关操作的原理，
决定了你是否有资格称为“科班”出身。
*/
#include<iostream>
using namespace std;
 
class Student
{                          
public:
	Student(int n,double s){num=n;score=s;next=NULL;}
	Student *next;
	int num;
	double score;
};
 
class MyList
{
public:
	MyList(){head=NULL;}
	MyList(int n,double s){head=new Student(n,s);} //以Student(n,s)作为单结点的链表
	int display();                      //输出链表，返回值为链表中的结点数
	void insert(int n,double s);        //插入：将Student(n,s)结点插入链表，该结点作为第一个结点
	void append(int n,double s);        //追加：将Student(n,s)结点插入链表，该结点作为最后一个结点
	void cat(MyList &il);               //将链表il连接到当前对象的后面
	int length();                       //返回链表中的结点数
private:
	Student *head;
};
 
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
		cout<<pt->num<<" "<<pt->score<<endl;
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
	cout<<"input 三个元素（学号 分数）: "<<endl;  //输入head1链表
	for(int i=0;i<3;i++)
	{
		cin>>n>>s;
		head1.insert(n,s);                      //通过“插入”的方式
	}
	cout<<"head1: "<<endl;                      //输出head1
	head1.display();
 
	MyList head2(1001,98.4);    //建立head2链表
	head2.append(1002,73.5);    //通过“追加”的方式增加结点
	head2.append(1003,92.8);
	head2.append(1004,99.7);
	cout<<"head2: "<<endl;      //输出head2
	head2.display();
 
	head2.cat(head1);                   //反head1追加到head2后面
	cout<<"length of head2 after cat: "<<head2.length()<<endl;
	cout<<"head2 after cat: "<<endl;    //显示追加后的结果
	head2.display();
 
	system("pause");
	return 0;
}

/*

任务扩展一（选做）】
　　任务中的结点只处理包含包含学号和分数的学生信息。如何将之用于其他应用，
一种办法是修改Student类，增加学生的姓名、年龄……。Students类也可换作描述其他事物的类。
请设计建立一个动态链表，其中有5个结点，分别描述5个三角形，从头结点开始，
逐个输出三角形的信息。

【任务扩展二（选做）】

　　上面的处理，仍然不够抽象，所以，只能就事论事地做，这是设计的大忌。
实际上，结点的类型可以定义为以下模板类：

template <class T>
class Node
{     
public:
	Node *next;
	T data;
};
　　这样，“一劳永逸”地解决了data的类型，只要在定义类时，对T进行实例化即可。
在这里，T类型中也不需要涉及有关链表中指针的内容。
　　请按这种思路重写程序，为了测试，在main()函数中建立一个MyArray<double>型对象进行测试。
另外，再建立一个MyArray<Triangle>型对象进行测试（Triangle为自定义三角形类）。
【任务扩展三（选做）】

　　本任务实现的是最简单的单向链表中的最基本的操作。从链表的类型上，
还可以有双向链表（有头结点和尾结点，方便从前往后和从后往前的访问）、十字链表等，
类似的方法可以构造二叉树、多叉树、图（例如，计算机网络结构可以抽象描述为图，
社交网络中用户的关系也是图，顶有用的结构）。从操作角度，单链表在插入时，
可以让结点保持有序；可以从链表中查找元素；
很多的应用中涉及的算法需要借助于数据结构和算法的设计获得最佳的处理性能。
关于这方面的内容不再以具体任务的形式给出，在后续的专业基础课中将会逐渐引出。
另外，有程序设计基础，同学们是可以自己往前走一走，
找相关的教材和书籍（数据结构、算法类）看一看，是否能依靠自己的力量往前走一走了。

  */