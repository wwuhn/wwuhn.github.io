#include <stdio.h>
#include <math.h>
#include <malloc.h>

void nQueens(int *x, int n);        /*求解n皇后问题*/
int place(int *x, int k);           /*判断是否可以在第k行第x[k]列摆放皇后*/
void printSolution(int *x, int n);  /*输出求解结果*/

int main()
{
    int queens;
    int *solution;                                  /*存放求解结果的数组首地址*/
    printf("请输入皇后数量queens，如输入8，就是8皇后问题：");
    scanf("%d", &queens);
    solution=(int*)malloc(sizeof(int)*(queens+1));  /*动态分配数组空间， x[0]空闲*/
    nQueens(solution, queens);
    while(1);
    return 0;
}

/*如果一个皇后能放在第row行第arr[row]列，则返回真(1)，否则返回假(0)*/
int place(int arr[], int row)
{
    for(int i=1; i<row; i++)  /*对前row-1行，逐行考察*/
    {       /*如果前row-1行中有某行的皇后与第row行的在同一列或同一斜线，返回0*/
        if((arr[i]==arr[row])||(fabs(arr[i]-arr[row])==fabs(i-row)))
            return 0;
    }       /*能执行下一句，说明在第k行第x[k]列摆放皇后，不会互相攻击*/
    return 1;
}

int solutions = 0;          /*解的数量*/
void nQueens(int *solution, int n) /*求解在n×n的棋盘上，放置n个皇后，使其不能互相攻击*/
{
    int curRow = 1;         /*curRow是当前行*/
    solution[curRow] = 0;   /*solution[curRow]是当前列，进到循环中，立刻就会执行solution[curRow]++，而选择了第1列*/
    while(curRow>0)         /*由后面的回溯步curRow--，当将所有可能的解尝试完后，curRow将变为0，结束求解过程*/
    {
        solution[curRow]++;             /*移到下一列*/
        while(solution[curRow]<=n && !place(solution,curRow))  /*逐列考察，找出能摆放皇后的列x[k]*/
            solution[curRow]++;
        if(solution[curRow]<=n)         /*找到一个位置可以摆放皇后*/
        {
            if(curRow==n)               /*是一个完整的解，输出解*/
            {
                solutions++;
                printf("第%d个解：\n",solutions);
                printSolution(solution, n);
            }
            else                        /*没有完成最后一行的选择，是部分解，转向下一行*/
            {
                curRow++;               /*接着考察下一行*/
                solution[curRow]=0;     /*到循环开始执行solution[curRow]++后，下一行将从第1列开始考察*/
            }
        }
        else                /*对应x[k]>n的情形，这一行已经没有再试的必要，回溯到上一行*/
            curRow--;        /*到循环开始执行x[k]++后，上一行在原第x[k]列的下1列开始考察*/
    }
}

/*输出求解结果*/
void printSolution(int *x, int n)
{
    int i, j;
    for (i = 1; i <= n; i++)  /*输出第i行*/
    {
        for (j=1; j<=n; j++)
        {  
            if (j == x[i])   /*第x[i]列输出Q，其他列输出*号 */
                printf(" Q");
            else
                printf(" *");
        }
        printf("\n");
    }
    printf("\n");
}