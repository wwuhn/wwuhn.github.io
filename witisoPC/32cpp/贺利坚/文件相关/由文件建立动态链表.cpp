/*   由文件建立动态链表
链表的关键在于理解如何移动，如何连接，通常head指针保持不动，临时指针不断迭代（更新），不断移动
尾插：  需要三个指向节点的指针：head, pNew, pMove，指针做左值，表示指向和移动，如
        head = pNew; pMove = pNew;
        指向节点的指针的成员指针next做左值时表示连接，如
        pMove->next = pNew;
遍历：  需要两个指针：head, pMove
        移动：pMove = pMove->next;
删除：  需要4个指针：head, pRear, pFront, pPend
        pPend = pFront; // 待删除指针后暂存
        pFront = pFront->next; // 移
        pRear->next = pFront;  // 连
        没有删除时，两个指针都移动
        pRear = pFront; // pRear = pRear->next  //先移动尾部指针
        pFront = pFront->next;
        


*/
#if 0

#include  <iostream>
#include  <fstream>
#include <cstdlib>  //在codeblocks下，exit(1)需要这个头文件
using namespace std;
struct Student
{
    char num[13]; //尽管都是由数字构成，但看作为字符更合适。
    char name[10]; //每个汉字占两个字节，中国人的名字，5个汉字够用
    int cpp;
    int math;
    int english;
    int grade;
    struct Student *next;   //指向下一节点的指针
};

int main( )
{
    Student *head=NULL,*newNode,*pMove;
    int stuNum=0,i;
    int sum=0,ave;   //用于求平均
    ifstream infile("score.txt",ios::in); 	//以输入的方式打开文件
    if(!infile)   				//测试是否成功打开
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    //下面从文件中读取数据，同时建立动态链表，并为求总分之和
    stuNum=0;
    while(!infile.eof())
    {
        newNode = new Student;
        infile>>newNode->num>>newNode->name>>newNode->cpp>>newNode->math>>newNode->english;
        newNode->grade = newNode->cpp + newNode->math + newNode->english;
        sum+=newNode->grade;
        newNode->next=NULL;
        if (stuNum==0)
            head=newNode;   //是第一个节点
        else
            pMove->next=newNode;   //用q记录刚刚产生的结点，如果有下一个，需要q将之连起来
        ++stuNum;
        pMove=newNode;
    }
    infile.close();
    
    //求平均成绩
    ave=sum/stuNum;
    cout<<"总分平均为："<<ave<<endl;
    
    //依次输出所有总分高于平均总分且没有挂科的同学的学号、姓名、总分。
    cout<<"总分高于平均总分且没有挂科的同学有："<<endl;
    pMove=head;
    i=1;
    while(pMove!=NULL)
    {
        if(pMove->grade>=ave&&pMove->cpp>=60&&pMove->math>=60&&pMove->english>=60)
        {
            cout<<i<<" "<<pMove->num<<" "<<pMove->name<<" "<<pMove->grade<<endl;
            i++;
        }
        pMove=pMove->next;
    }
    cout<<i<<endl;
    while(1);
    return 0;
}

#else

//这个程序在一位热心读者提供的代码基础上做了修改。
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
using namespace std;
struct node
{
    char num[15];
    char name[10];
    int cpp;
    int math;
    int english;
    int score;
    node* pnext;
};
int main()
{
    node *head=NULL, *p,*q, *k;
    int num=0;
    float sum=0,ave;
    ifstream readfile("score.txt",ios::in);
    if(!readfile)
    {
        cerr<<"the score.txt can't be read!"<<endl;
        exit(1);
    }
    while(!readfile.eof())
    {
        p=new node;
        readfile>>p->num>>p->name>>p->cpp>>p->math>>p->english;
        p->score=p->cpp+p->english+p->math;
        sum+=p->score;
        p->pnext=NULL;
        if(num==0)
            head=p;
        else
            q->pnext=p;
        num++;
        q=p;
    }
    readfile.close();
    ave=sum/num;
    cout<<"总体平均分是：   "<<ave<<endl<<endl;
    //将总分低于总均总分的节点删除
    while(head!=NULL&&head->score<ave)//首先，将头部该删除的删除掉
    {
        q=head;
        head=head->pnext;
        delete(q);
    }
    //通过下面q、p一后一前两个指针，删除掉需要删除的节点
    q=head;
    p=head->pnext;
    while(p!=NULL)
    {
        if(p->score < ave )    //删除p
        {
            k=p;            //p该删除，由k标记住
            p=p->pnext;     //下一步要考察的，是pnext指向的
            q->pnext=p;     //这个很关键，要被删除的k，就这样脱离了链接
            delete(k);      //释放空间
        }
        else  //保留，p和q都往后移
        {
            //q=p;
            q = q->pnext;
            p = p->pnext;
        }
    }
    //输出剩余的结点，便于观察结果
    p=head;
    cout<<"总分高于平均总分的同学有： "<<endl<<endl;
    while(p!=NULL)
    {
        cout<<setw(10)<<p->num<<setw(10)<<p->name<<setw(10)<<p->score<<endl;
        p=p->pnext;
    }
    
    while(1);
    return 0;
}


#endif

#if 0


#endif
/*

*/