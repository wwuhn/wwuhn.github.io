#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void lcs(char* charA , char* charB)
{
    int i,j;
    int lenA    = strlen(charA);
    int lengthB = strlen(charB);
    
    // 动态二维数组cell[][]
    int** cell=(int **)malloc(sizeof(int *) * lenA+1);
    if(cell==NULL)
    {
        printf("cell is null");
        exit(1);
    }
    for(i=0;i<lenA+1;i++)
    {
        cell[i]=(int*)malloc(sizeof(int)*lengthB+1);
        if(cell[i]==NULL)
            exit(1);
    }
    for(i=0;i<lenA+1;i++) // 动态二维数组对角线数据初始化为0
        for(j=0;j<lengthB+1;j++)
            cell[i][j]=0;

    int maxLength = 0;
    int end = 0;
    for(i = 1; i<lenA;i++){
        for ( j= 1; j <lengthB; j++) {
            if (charA[i]==charB[j]){   // 如果两个字母相同
                cell[i][j]=cell[i-1][j-1]+1;

            }
            if(maxLength<cell[i][j]){  // 得出最大的公共子串
                maxLength=cell[i][j];
                end=i;
            }
        }
    }
    printf("最长字串:");

    for(i=end-maxLength+1;i<maxLength+1;i++)//由于循环是从1开始，所以需要加1
        printf("%c",charA[i]);
    
    printf(" 长度%d:\n",maxLength);
    
}

void main() {
    //测试数据
    char* a = "fishers";
    char* b = "ohisher";
    char* c = "vista";
    lcs(a,b);
    lcs(c,a);
    
    getchar();
}
/*output:
最长字串:isher 长度5:
最长字串:is 长度2:
*/