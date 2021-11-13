#include<stdio.h>// 文件输入输出及数据处理
struct Stuff
{
    int num;
    float pay;
    float PRP;    //Performance Related Pay;
    float total;
};

int main()
{
    FILE *fp;
    fp = fopen("salary1.txt", "r");
    if (fp == NULL)
    {
        printf("cannot open file salary.txt.\n");
        return 0;
    }
    struct Stuff s[100];
    int i;
    //（1）从文件中读取数据，求总工资，并在屏幕上显示；
    for (i=0; i<100; i++)
    {
        fscanf(fp,"%d %f %f",&s[i].num,&s[i].pay,&s[i].PRP);
        s[i].total=s[i].pay+s[i].PRP;
        printf("%d %.2f %.2f %.2f\n", s[i].num,s[i].pay,s[i].PRP,s[i].total);
    }
    fclose(fp);
    //（2）将完整的工资单保存到文件salary2.txt中。
    FILE *fp2 = fopen("salary2.txt", "w");
    if (fp == NULL)
    {
        printf("cannot open file salary2.txt.\n");
        return 0;
    }
    for (i=0; i<100; i++)
    {
        fprintf(fp2,"%d %.2f %.2f %.2f\n", s[i].num,s[i].pay,s[i].PRP,s[i].total);
    }
    fclose(fp2);
    //（3）将总工资超过5000元的员工的工号保存到文件rich.txt中。
    FILE *fp3 = fopen("rich.txt", "w");
    if (fp == NULL)
    {
        printf("cannot open file rich.txt.\n");
        return 0;
    }
    for (i=0; i<100; i++)
    {
        if(s[i].total>=5000)
            fprintf(fp3,"%d\n", s[i].num);
    }
    fclose(fp3);
    //（4）在屏幕上显示工资最高的员工的工资信息
    float max = s[0].total;
    int h=0;
    for (i=1; i<100; i++)
    {
        if(max<s[i].total)
        {
            max=s[i].total;
            h=i;
        }
    }
    printf("收入最高的是: ");
    printf("%d %.2f %.2f %.2f\n", s[h].num,s[h].pay,s[h].PRP,s[h].total);
    while(1);
    return 0;
}