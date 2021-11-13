#include <stdio.h>
#include <windows.h>
void show(int m);
int main()
{ 
    unsigned int x = 0x1, y = 0x10;
    while(1)
    {
        show(x);
        x = (x << 2) | (x >> (30));
        show(y);
        y = (y << 2) | (y >> (30));
        Sleep(5150);
        system("cls");
    }
    return 0;
}
void show(int m)
{
    int i;
    for (i=0; i<32; ++i)
    {
        if (m%2==0)
            printf("¡ð");
        else
            printf("¡ñ");
        m/=2;
    }
    printf("\n");
}