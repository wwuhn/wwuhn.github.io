#include <stdio.h>  // 输出了52张扑克牌
int main( )
{
    char c[4]= {'H','S','D','C'}; //Spade, Heart, Diamond, Club
    int v[13]= {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int i,j;
    for(i=0; i<4; i++) {
        for(j=0; j<13; j++) {
            printf("%c",c[i]);
            if(v[j]==1)
                printf("A");
            else if(v[j]==11)
                printf("J");
            else if(v[j]==12)
                printf("Q");
            else if(v[j]==13)
                printf("K");
            else
                printf("%d",v[j]);
            printf(" ");
        }
        printf("\n");
    }
    while(1);
    return 0;
}