//随机数发牌游戏的C语言实现：
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initial(int* p)//初始化一付牌
{
    int i;
    for(i=0;  i<52;  i++)
        p[i]=(i/13+3)*100+i%13+1;
}
void shuffle(int *p)//洗牌
{
    int i,x,y;
    int t;
    srand((int)time(0));
    for(i=0;  i<200;  i++)
    {
        x=rand()%52;
        //52中一个数
        y=rand()%52;
        //52中一个数
        if(x!=y)
        {
            t=p[x];
            p[x]=p[y];
            p[y]=t;
        }
    }
}
void dealCard(int* p,int* p1,int* p2,int* p3,int* p4)//发牌
{
    int i;
    for(i=0;  i<13;  i++)
    {
        p1[i]=p[4*i];
        p2[i]=p[4*i+1];
        p3[i]=p[4*i+2];
        p4[i]=p[4*i+3];
        
    }
}
void sort(int* p)//排序
{
    int i,j;
    int t;
    for(i=0;  i<13;  i++)
        for(j=0;  j<13-i-1;  j++)  //感谢徐心雨同学报告并协助灭掉此处的一个bug
        {
            if(p[j]>p[j+1])
            {
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
}
void display(int *p)
{
    int i;
    int f,d;
    for(i=0;  i<13;  i++)
    {
        f=p[i]/100;//301~313,401~413,501~513,601~613
        d=p[i]%100;//1~13
        switch(f)
        {
        case 3:
            printf("黑桃");
            break;
        case 4:
            printf("红桃");
            break;
        case 5:
            printf("梅花");
            break;
        case 6:
            printf("方块");
            break;
        }
        if(d<10&&d>1)
        {
            printf("%c ", (d+'0'));
        }
        else if(d==1)
            printf("A ");
        else if(d==11)
            printf("J ");
        else if(d==12)
            printf("Q ");
        else if(d==13)
            printf("K ");
        else if(d==10)
            printf("10 ");
        
    }
    printf("\n");
}
int main()
{
    int pai[52],player1[13],player2[13],player3[13],player4[13];
    initial(pai);
    shuffle(pai);
    dealCard(pai,player1,player2,player3,player4);
    sort(player1);
    sort(player2);
    sort(player3);
    sort(player4);
    display(player1);
    display(player2);
    display(player3);
    display(player4);
    while(1);
    return 0;
}