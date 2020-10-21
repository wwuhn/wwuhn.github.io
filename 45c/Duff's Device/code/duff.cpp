#include <stdio.h>
#include <malloc.h>
#include <ctime>
int test (int count)
{
    int i = 0;
    int n = (count + 7) /8 ; // 假设count > 0
	// 要达到i++执行count次，如果count<8時，如果不+7，n=0，会执行8次i++，而不是7次
    switch(count % 8)
    {
	    case 0: do{ i++;
        case 7:     i++;
        case 6:     i++;
        case 5:     i++;
        case 4:     i++;
        case 3:     i++;
        case 2:     i++;
        case 1:     i++;
                }while(--n > 0);
    }
    return i;
}

typedef unsigned char           uint8_t;
typedef unsigned short int      uint16_t;
void send1(uint8_t* to, uint8_t* from, uint16_t count)
{
    uint16_t n = (count + 7) /8 ; // 假设count > 0
    switch(count % 8)
    {
        case 0: do{ *to = *from++;
        case 7:     *to = *from++;
        case 6:     *to = *from++;
        case 5:     *to = *from++;
        case 4:     *to = *from++;
        case 3:     *to = *from++;
        case 2:     *to = *from++;
        case 1:     *to = *from++;
                }while(--n > 0);
    }
}

void send2(uint8_t* to, uint8_t* from, uint16_t count)
{
    do{ 
        *to = *from++; // 假设count > 0
    }while(--count > 0);
}

void send3(uint8_t* to, uint8_t* from, uint16_t count)
{
    uint16_t n = count / 8 ; // 假设count > 0，且是8的倍数
    do{ *to = *from++;
        *to = *from++;
        *to = *from++;
        *to = *from++;
        *to = *from++;
        *to = *from++;
        *to = *from++;
        *to = *from++;
    }while(--n > 0);
}

void send(uint8_t* to, uint8_t* from, uint16_t count)
{
    uint16_t n = count / 8 ; // 假设count > 0
    do{ *to = *from++;
        *to = *from++;
        *to = *from++;
        *to = *from++;
        *to = *from++;
        *to = *from++;
        *to = *from++;
        *to = *from++;
    }while(--n > 0);

    n = count % 8 ;
    while(--n > 0)
        *to = *from++;
}

int test2(unsigned n,unsigned *m)
{
	clock_t start = clock();
	unsigned sum=0;
	n-=7;
	for(unsigned i=0;i<n;i++)
		(sum)++;
	*m=sum;
	return (clock()-start);
}

int test3(int n,unsigned *m)
{
	clock_t start = clock();
	unsigned sum=0;
	n-=7;
	for(unsigned i=0;i<n;i+=8)  // 要避免陷入死循环，所以n-=7;
	{
		sum++;
		sum++;
		sum++;
		sum++;

		sum++;
		sum++;
		sum++;
		sum++;
    }
	*m=sum;
	return (clock()-start);
}
int main()
{
	printf("%d\n", test (20)); 

	uint16_t count = 8;
    uint8_t* to = (uint8_t*)malloc(sizeof(uint8_t)*2);
	to[1] = '\0';
	uint8_t from[9] = "abcdefgh";
	send1(to,from,count);
	printf("%s\n",to);     // h

	send2(to,from,count);
	printf("%s\n",to);     // h

	send3(to,from,count);
	printf("%s\n",to);     // h

	unsigned n = -1; // 4294967295 0xffffffff
	unsigned sum = 0;
	// 在debug模式下运行，如果在release下运行，时间接近0秒
    printf("%d\n",test2(n,&sum)); 
	printf("%u\n",sum); 
	sum = 0;
    printf("%d\n",test3(n,&sum)); 
	printf("%u\n",sum); 

	getchar();
    return 0;
}
/*
20
h
h
h
24875
4294967288
21745
4294967288
*/