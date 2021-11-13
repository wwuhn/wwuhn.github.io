#include "linklist.h"
int main()
{
    LinkList *L;
    InitList(L);
    ListInsert(L, 1, 15);
    ListInsert(L, 1, 10);
    ListInsert(L, 1, 5);
    ListInsert(L, 1, 20);
    DispList(L);
    DestroyList(L);
    return 0;
}