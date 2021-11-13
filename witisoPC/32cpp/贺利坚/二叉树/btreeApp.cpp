#include <stdio.h>
#include "btree.h"

int main()
{
    BTNode *b,*p,*lp,*rp;;
    printf("  (1)创建二叉树:");
    CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("\n");
    printf("  (2)输出二叉树:");
    DispBTNode(b);
    printf("\n");
    printf("  (3)查找H节点:");
    p=FindNode(b,'H');
    if (p!=NULL)
    {
        lp=LchildNode(p);
        if (lp!=NULL)
            printf("左孩子为%c ",lp->data);
        else
            printf("无左孩子 ");
        rp=RchildNode(p);
        if (rp!=NULL)
            printf("右孩子为%c",rp->data);
        else
            printf("无右孩子 ");
    }
    else
        printf(" 未找到！");
    printf("\n");
    printf("  (4)二叉树b的深度:%d\n",BTNodeDepth(b));
    printf("  (5)释放二叉树b\n");
    DestroyBTNode(b);
    printf("end!");
    while(1);
    return 0;
}