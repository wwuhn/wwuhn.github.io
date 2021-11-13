#ifndef LIQUEUE_H_INCLUDED
#define LIQUEUE_H_INCLUDED

typedef char ElemType;
typedef struct qnode
{
    ElemType data;
    struct qnode *next;
} QNode;        //链队数据结点类型定义

typedef struct
{
    QNode *front;
    QNode *rear;
} LiQueue;          //链队类型定义

void InitQueue(LiQueue *&q);    //初始化链队
void DestroyQueue(LiQueue *&q); //销毁链队
bool QueueEmpty(LiQueue *q);    //判断链队是否为空
int QueueLength(LiQueue *q);    //返回队列中数据元素个数
void enQueue(LiQueue *&q,ElemType e);   //入队
bool deQueue(LiQueue *&q,ElemType &e);  //出队

#endif // LIQUEUE_H_INCLUDED
