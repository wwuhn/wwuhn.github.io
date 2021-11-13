#include<stdio.h>       // 链表通信录
#include<string.h>
#include<stdlib.h>
typedef struct          //通讯录结点类型
{
    char num[5];        //编号
    char name[9];       //姓名
    char sex[3];        //性别
    char phone[13];     //电话
    char addr[31];      //地址
} DataType;

typedef struct node     //结点类型定义
{
    DataType data;      //结点数据域
    struct node * next; //结点指针域
} ListNode;

typedef ListNode * LinkList;
LinkList head;
ListNode *p;

//函数说明
int menu_select();
LinkList CreateList();
void InsertNode(LinkList head,ListNode *p);
ListNode *ListFind(LinkList head);
void DelNode(LinkList head);
void PrintList(LinkList head);

//主函数
int main()
{
    for(;;)
    {
        switch(menu_select())
        {
        case 1:
            printf("****************************************\n");
            printf("*          通讯录链表的建立            *\n");
            printf("****************************************\n");
            head=CreateList();
            break;
        case 2:
            printf("****************************************\n");
            printf("*            通讯者信息的添加          *\n");
            printf("****************************************\n");
            printf("*编号(4) 姓名(8) 性别 电话(11) 地址(31)*\n");
            printf("****************************************\n");
            p=(ListNode *)malloc(sizeof(ListNode));    //申请新结点
            scanf("%s%s%s%s%s",p->data.num,p->data.name,
                p->data.sex,p->data.phone,p->data.addr);
            InsertNode(head,p);
            break;
        case 3:
            printf("****************************************\n");
            printf("*          通讯录信息的查询            *\n");
            printf("****************************************\n");
            p=ListFind(head);
            if(p!=NULL)
            {
                printf("*编 号  姓 名  性 别  联系电话  地 址  *\n");
                printf("----------------------------------------\n");
                printf("%s\t%s\t%s\t%s\t%s\n",p->data.num,p->data.name,
                    p->data.sex,p->data.phone,p->data.addr);
                printf("----------------------------------------\n");
            }
            else
                printf("没有查到要查询的通读者！\n");
            break;
        case 4:
            printf("****************************************\n");
            printf("*          通讯录信息的删除            *\n");
            printf("****************************************\n");
            DelNode(head);    //删除结点
            break;
        case 5:
            printf("****************************************\n");
            printf("*          通讯录链表的输出            *\n");
            printf("****************************************\n");
            PrintList(head);
            break;
        case 0:
            printf("\t 再  见！ \n");
            return 0;
        }
    }
}

/**********************************/
/*       菜单选择函数程序         */
/**********************************/
int menu_select()
{
    int sn;
    printf("==============================\n");
    printf("   通讯录管理系统\n");
    printf("==============================\n");
    printf("   1.通讯录链表的建立\n");
    printf("   2.通讯者结点的插入\n");
    printf("   3.通讯者结点的查询\n");
    printf("   4.通讯者结点的删除\n");
    printf("   5.通讯录链表的输出\n");
    printf("   0.退出管理系统\n");
    printf("==============================\n");
    for(;;)
    {
        scanf(" %d",&sn);
        if(sn<0||sn>5)
            printf("\n\t输入错误，重选0-5");
        else
            break;
    }
    return sn;
}

/***********************************/
/*  用尾插法建立通讯录链表函数     */
/***********************************/
LinkList CreateList()
{
    //尾插法建立带头结点的通讯录链表算法
    LinkList head=(ListNode*)malloc(sizeof(ListNode)); //申请表头结点
    ListNode *p,*rear;
    int flag=0;        //结束标志置0
    rear=head;         //尾指针初始指向头结点
    while(flag==0)
    {
        p=(ListNode*)malloc(sizeof(ListNode));    //申请新结点
        printf("编号(4) 姓名(8) 性别  电话(11)  地址(31) \n");
        printf("-----------------------------------------\n");
        scanf(" %s%s%s%s%s",p->data.num,p->data.name,p->data.sex,
            p->data.phone,p->data.addr);
        rear->next=p;               //新结点连接到尾结点之后
        rear=p;                     //尾指针指向新结点
        printf("结束建表吗？ (1结束/0继续):");
        scanf(" %d",&flag);         //读入一个标志数据
    }
    rear->next=NULL;                //终端结点指针域置空
    return head;
}

/*****************************************/
/*   在通讯录(顺序)链表head中插入结点    */
/*****************************************/
void InsertNode(LinkList head,ListNode *p)
{
    ListNode *pAfter,*pCurr;
    pAfter=head;
    pCurr=pAfter->next;
    while(pCurr!=NULL && strcmp(pCurr->data.num,p->data.num)<0)
    {
        pAfter=pCurr;         //p1指向刚访问过的结点
        pCurr=pCurr->next;    //p2指向表的下一个结点
    }
    pAfter->next=p;           //插入p所指向的结点
    p->next=pCurr;            //连接表中剩余部分
}

/*****************************************/
/*        有序通讯录链表上的查找         */
/*****************************************/
ListNode * ListFind(LinkList head)
{
    //有序通讯录链表上的查找
    ListNode *p;
    char num[5];
    char name[9];
    int xz;
    printf("=================\n");
    printf("  1.按编号查询   \n");
    printf("  2.按姓名查询   \n");
    printf("=================\n");
    printf("请选择:");
    p=head->next;    //假定通讯录表带关结点
    scanf("%d",&xz);
    fflush(stdin);
    if(xz==1)
    {
        printf("请输入要查找者的编号：");
        scanf("%s",num);
        fflush(stdin);
        while(p&&strcmp(p->data.num,num)<0)
        {
            p=p->next;
        }
        if(p==NULL||strcmpi(p->data.num,num)>0)
        {
            p=NULL;        //没有查到要查找的通讯者
        }
    }
    else
    {
        if(xz==2)
            printf("请输入要查找者的姓名：");
        scanf("%s",name);
        fflush(stdin);
        while(p&&strcmp(p->data.name,name)!=0)
            p=p->next;
    }
    return p;
}

/*****************************************/
/*        通讯录链表上结点的删除         */
/*****************************************/
void DelNode(LinkList head)
{
    char jx;
    ListNode *p,*q;
    p=ListFind(head);    //调用查找函数
    if(p==NULL)
    {
        printf("没有查到要删除的通讯者");
        return;
    }
    printf("真的要删除该结点吗?(y/n):");
    scanf("%c",&jx);    //注意在%c前加上一空格可以处理掉输入缓冲区
    fflush(stdin);        //用这个函数也可以清除输入缓冲区
    if(jx=='y'||jx=='Y')
    {
        q=head;
        while(q!=NULL && q->next!=p)
            q=q->next;
        q->next=p->next;    //删除结点
        free(p);            //释放被删除的结点空间
        printf("通讯者已被删除\n");
    }
}

/*****************************************/
/*        通讯录链表上输出函数         */
/*****************************************/
void PrintList(LinkList head)
{
    ListNode *p;
    p=head->next;            //因为链表带头结点，使p指向链表开始结点
    printf("编号  姓名  性别  联系电话  地址\n");
    printf("------------------------------------------\n");
    while(p!=NULL)
    {
        printf("%s%s%s%s%s\n",p->data.num,p->data.name,
            p->data.sex,p->data.phone,p->data.addr);
        printf("------------------------------------------\n");
        p=p->next;            //后移一个结点
    }
}