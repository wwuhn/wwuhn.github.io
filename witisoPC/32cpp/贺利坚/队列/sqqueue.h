#ifndef SQQUEUE_H_INCLUDED
#define SQQUEUE_H_INCLUDED

#define MaxSize 5
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front,rear;     /*队首和队尾指针*/
} SqQueue;


void InitQueue(SqQueue *&q);  //初始化顺序环形队列
void DestroyQueue(SqQueue *&q); //销毁顺序环形队列
bool QueueEmpty(SqQueue *q);  //判断顺序环形队列是否为空
int QueueLength(SqQueue *q);   //返回队列中元素个数，也称队列长度
bool enQueue(SqQueue *&q,ElemType e);   //进队
bool deQueue(SqQueue *&q,ElemType &e);  //出队

#endif // SQQUEUE_H_INCLUDED
