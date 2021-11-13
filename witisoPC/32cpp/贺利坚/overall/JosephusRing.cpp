#include <iostream>   // JosephusRing
using namespace std;
//链表结点kid,其中number为这个人的编号
struct kid
{
    int number;
    kid *next;
};
 
//约瑟夫环类
class joseph_ring
{
private:
    int n;      //用于存放人数
    int m;      //用于存放间隔
    kid *head;  //链表的头结点
public:
    joseph_ring(int nn, int mm);    //创建nn个孩子，间隔为mm的约瑟夫环
    ~joseph_ring();
    void show();                    //运算并输出的成员函数
};
//创建nn个孩子，间隔为mm的约瑟夫环
joseph_ring::joseph_ring(int nn, int mm)
{
    n=nn;                   //构造函数,把成员变量赋初值
    m=mm;
    kid *pNew,*pMove;       //定义2个临时指针
    for(int i=1; i<=n; i++) //for循环用于初始化环
    {
        pNew=new kid;
        pNew->number=i;     //编号
        if(i==1)            //如果当前链表为空,头指针指向第一个人
        {
            head=pNew;
            pMove=pNew;
        }
        else                //否则,pMove永远指向尾结点,新建立的结点都插入到pMove之后
        {
            pMove->next=pNew;
            pMove=pNew;
        }
    }
    pMove->next=head;//把链表连成一个循环链表
}
 
joseph_ring::~joseph_ring()
{
    delete head;
    head=NULL;
}
 
void joseph_ring::show()        //执行出圈操作
{
    kid *pCurr,*pBack,*pPendDel;
    int count;
    pCurr=head;
    for(int i=1; i<=n-1; i++)   //有n个人,所以执行n-1次循环，删除n-1个人
    {
        count=1;  //用count定位到第m个人,循环后,pCurr指向这个人,pBack指向这个人的上一个人
        while(count<m)
        {
            pBack=pCurr;  //pBack指向前一个
            pCurr=pCurr->next;
            count++;
        }
        cout<<pCurr->number<<" ";  //这指向的是当前要删除人
        pPendDel=pCurr;             //p指向当前这个人
        pBack->next=pCurr->next;    //将当前出圈人的直接前驱和直接后继连接起来
        pCurr=pCurr->next;          //下次从当前人的下一个人开始数
        delete pPendDel;            //释放内存
    }
    cout<<endl;
    cout<<"The last one is No. "<<pCurr->number<<endl;
    head=pCurr;                    //环中只剩下了一个结点
}
 
int main()
{
    int n,m;
    cout<<"n个小孩，n=";
    cin>>n;
    cout<<"隔m个小孩，m=";
    cin>>m;
    joseph_ring j(n,m);
    j.show();
    while(1);
    return 0;
}