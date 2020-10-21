#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

#define N 10
#define inf 99999999
int e[N][N];  // 顶点数组
int p[N][N];  // 前驱数组

void output2Darr(int arr[N][N],int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%10d",arr[i][j]);
        }
        printf("\n");
    }
}

void outputRoute(int i,int j)
{
    stack<int> st;
    printf("点%d至点%d的最短距离为：%d，路线:",i,j,e[i][j]);
    st.push(j);
    while(p[i][j]!=i)
    {
        st.push(p[i][j]);
        j=p[i][j];
    }
    st.push(i);
    do{
        printf("%d ",st.top());
        st.pop();
    }while(!st.empty());
    printf("\n");
}

int main()
{
    int k,i,j,n,m,a,b,s;
    
    printf("读入顶点个数n，边的条数m:\n");
    scanf("%d %d",&n,&m);
    //初始化
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j) 
                e[i][j]=0;
            else e[i][j]=inf;
    printf("读入边,顶点a的编号 顶点b的编号 两个顶点的距离s,如1 2 2;\n");
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&s);
        e[a][b]=s;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(e[i][j]>0&&e[i][j]<inf)
                p[i][j]=i;
            else
                p[i][j]=-1;
    printf("初始矩阵e为：\n");
    output2Darr(e,n);
    //Floyd-Warshall算法核心语句
    for(k=1;k<=n;k++)        // 插点，k
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(e[i][j]>e[i][k]+e[k][j] )
                {
                    e[i][j]=e[i][k]+e[k][j];
                    p[i][j]=p[k][j];   // 更改j的前驱为k
                }
    printf("全部顶点之间的最短路径为:\n");
    output2Darr(e,n);
    printf("各点的前驱为:\n");
    output2Darr(p,n);
    outputRoute(4,3);
    outputRoute(3,2);

    system("pause");
    return 0;
}
/*输入（可复制）
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/

/*输出
读入顶点个数n，边的条数m:
4 8
读入边,顶点a的编号 顶点b的编号 两个顶点的距离s,如1 2 2;
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
初始矩阵e为：
         0         2         6         4
  99999999         0         3  99999999
         7  99999999         0         1
         5  99999999        12         0
全部顶点之间的最短路径为:
         0         2         5         4
         9         0         3         4
         6         8         0         1
         5         7        10         0
各点的前驱为:
        -1         1         2         1
         4        -1         2         3
         4         1        -1         3
         4         1         2        -1
点4至点3的最短距离为：10，路线:4 1 2 3
点3至点2的最短距离为：8，路线:3 4 1 2

*/