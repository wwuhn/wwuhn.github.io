
// 找出两个字符串的最长公共连续子串的长度

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
 
int longest_common_substring(char *str1, char *str2)
{
    int i,j,k,len1,len2,max,x,y;
    len1 = strlen(str1);
    len2 = strlen(str2);
    int **c = new int*[len1+1];
    for(i = 0; i < len1+1; i++)
        c[i] = new int[len2+1];
    for(i = 0; i < len1+1; i++)
        c[i][0]=0;        // 第0列都初始化为0
    for(j = 0; j < len2+1; j++)
        c[0][j]=0;        // 第0行都初始化为0 
    max = -1;
    for(i = 1 ; i < len1+1 ; i++)
    {
        for(j = 1; j < len2+1; j++)
        {
            if(str1[i-1]==str2[j-1])     //只需要跟左上方的c[i-1][j-1]比较就可以了
                c[i][j]=c[i-1][j-1]+1;
            else //不连续的时候还要跟左边的c[i][j-1]、上边的c[i-1][j]值比较，这里不需要

                c[i][j]=0;
            if(c[i][j]>max)
            {
                max=c[i][j];
                x=i;
                y=j;
            }
        }
    }
 
    //输出公共子串
    char s[1000];
    k=max;
    i=x-1,j=y-1;
    s[k--]='\0';
    while(i>=0 && j>=0)
    {
        if(str1[i]==str2[j])
        {
            s[k--]=str1[i];
            i--;
            j--;
        }
        else       //只要有一个不相等，就说明相等的公共字符断了，不连续了
            break;
    }
    printf("最长公共子串为：");
    puts(s);
    for(i = 0; i < len1+1; i++)         //释放动态申请的二维数组
        delete[] c[i];
    delete[] c;
    return max;
}
 
int main(void)
{
    char str1[1000],str2[1000];
    //printf("请输入第一个字符串：");
    //gets(str1);
    strcpy(str1,"aabbccddefbbaacc");
    //printf("请输入第二个字符串：");
    //gets(str2);
    strcpy(str2,"sdefbt");
    int len = longest_common_substring(str1, str2);
    printf("最长公共连续子串的长度为：%d\n",len);
    system("pause");
    return 0;
}