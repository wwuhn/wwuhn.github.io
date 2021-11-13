#include "stdio.h"
#include "malloc.h"

typedef struct node{
    int data;
    struct node *next;
}LNode,*LinkList;

LinkList GreatLinkList(int n)                   /*建立一个长度为n的链表*/
{
    LinkList pNew, rear, head = NULL;
    int elementData;
    for (int i=1;i<=n;i++){
        printf("请输入第%d个结点值（共%d）个：",i,n);
        scanf("%d",&elementData);               /*获取链表结点中的数据元素*/
        pNew=(LinkList)malloc(sizeof(LNode));   /*分配一个新的链表结点*/
        pNew->data=elementData;
        pNew->next=NULL;
        if (head == NULL) {
            head = pNew;        /*head指向第一个结点，head是头指针*/
        } else {
            rear->next = pNew;  /*将新结点连接到链表的尾部*/
        }
        rear = pNew;            /*指针r始终指向链表的最后一个结点*/
    }
    return head;                /*返回链表的头指针*/
}

void insertListInOrder(LinkList *head,int elementData)
{                           /*向按值有序(递增序列)的链表head中插入包含元素e的结点*/
    LinkList pNew, pFront, pBack;
    pFront = *head;
    pNew=(LinkList)malloc(sizeof(LNode));  /*生成一个新结点，由pNew指向它*/
    pNew->data=elementData;                /*向该结点的数据域赋值e*/
    if (*head == NULL || elementData < (*head)->data) {
        pNew->next = *head;
        *head = pNew;
    } else {
        while(pFront != NULL && e >= pFront->data) {    /*循环找到插入结点的位置*/
            pBack  = pFront;                            /*r指向q的前驱结点*/
            pFront = pFront->next;                      /*q指针向后移动*/
        }
        pNew->next  = pFront;                           /*插入新的结点*/
        pBack->next = pNew;
    }
}

void delLink(LinkList *head, LinkList q) {
    LinkList r;
    if (q == *head) {
        *head = q->next;/*如果q指向的结点即为第1个结点，则需要修改head的值*/
        free(q);/*释放被删除结点的空间*/
    } else {
        r = *head;
        while ((r->next != q)&&(r->next != NULL)) {
            r = r->next;/*通过循环找到q所指结点的前驱结点*/
        }
        if (r->next != NULL) {
            r->next = q->next;/*删除q所指向的结点*/
            free(q);/*释放被删除结点的空间*/
        }
    }
}
void deleteLinkList(LinkList *head) {
    LinkList p = *head;/*p指向第一个结点*/
    while (p != NULL) {
        *head = p ->next;/* head指向p的下一个结点 */
        free(p);/*释放掉p指向结点的内存空间*/
        p = *head;/*p再指向第一个结点*/
    }
}
void printLink(LinkList head) {
    while (head != NULL) {
        printf("%3d",head->data);/*打印出每个结点中的数据data*/
        head = head->next;
    }
    printf("\n");
}
void main() {
    int i;
    LinkList q,head = NULL;
    head = GreatLinkList(10); /*创建一个长度为10的链表*/
    printf("The elems of this linklist is\n");
    printLink(head); /*打印出链表的内容*/
    printf("插入元素3\n");
    insertListInOrder(&head,3);/*插入元素3*/
    printf("The elems of this linklist is\n");
    printLink(head); /*打印出链表的内容*/
    printf("插入元素0\n");
    insertListInOrder(&head,0);/*插入元素0*/
    printf("The elems of this linklist is\n");
    printLink(head); /*打印出链表的内容*/
    printf("插入元素11\n");
    insertListInOrder(&head,11);/*插入元素10*/
    printf("The elems of this linklist is\n");
    printLink(head); /*打印出链表的内容*/
    printf("删除链表中的第5个元素：\n");
    q=head;
    for (i=0; i<4; i++) {
        q = q->next;/*指针q指向链表中第5个元素*/
    }
    delLink(&head, q);/*删除q指向的结点*/
    printLink(head);/*打印出链表中的内容*/
    deleteLinkList(&head);/*销毁该链表*/
    if (head == NULL) {
        printf( " This Linklist have been deleted\n");
    }
    printf("\n-End-\n");
    while(1);
}
