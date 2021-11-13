#include <stdio.h>
#include "liqueue.h"

int main()
{
    ElemType e;
    LiQueue *q;
    printf("(1)初始化链队q\n");
    InitQueue(q);
    printf("(2)依次进链队元素a,b,c\n");
    enQueue(q,'a');
    enQueue(q,'b');
    enQueue(q,'c');
    printf("(3)链队为%s\n",(QueueEmpty(q)?"空":"非空"));
    if (deQueue(q,e)==0)
        printf("队空,不能出队\n");
    else
        printf("(4)出队一个元素%c\n",e);
    printf("(5)链队q的元素个数:%d\n",QueueLength(q));
    printf("(6)依次进链队元素d,e,f\n");
    enQueue(q,'d');
    enQueue(q,'e');
    enQueue(q,'f');
    printf("(7)链队q的元素个数:%d\n",QueueLength(q));
    printf("(8)出链队序列:");
    while (!QueueEmpty(q))
    {
        deQueue(q,e);
        printf("%c ",e);
    }
    printf("\n");
    printf("(9)释放链队\n");
    DestroyQueue(q);
    while(1);
    return 0;
}
