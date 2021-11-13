#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;
// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
// Assumes max - min <= RAND_MAX
char rni(int min, int max)
{
    double fraction = 1.0 / (RAND_MAX + 1.0);
    // evenly distribute the random number across our range
    return min + (double)((max - min + 1) * (rand() * fraction));
}
double rnd(int min, int max)
{
    double fraction = 1.0 / (RAND_MAX + 1.0);
    // evenly distribute the random number across our range
    return min + (double)((max - min + 1) * (rand() * fraction));
}
int main()
{
    FILE* fp;
    fp = fopen("score.txt","w+");
    if(fp==NULL)
    {
        printf("file open error!");
    }
    srand(time(0));
    for(int j=0; j<100; j++)
    {
        for(int i=0;i<18;i++)
        {
            printf("%d",rni(0,9));
            fprintf(fp,"%d",rni(0,9));
        }
        printf(" %c%c%c ",rni(65,90),rni(97,122),rni(97,122));
        fprintf(fp," %c%c%c ",rni(65,90),rni(97,122),rni(97,122));
        printf("%5.2lf %5.2lf %5.2lf\n",rnd(0,99),rnd(0,99),rnd(0,99));
        fprintf(fp,"%5.2lf %5.2lf %5.2lf\n",rnd(0,99),rnd(0,99),rnd(0,99));
    }
    fclose(fp);
    //printf("%c%c\n",65,97);
    
restart:   
    
    
    goto restart;
    return 0;
}
/*

*/