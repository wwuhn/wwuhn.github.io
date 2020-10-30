

#if 1
//位运算结合union输出int和float的二进制位
#include <iostream>
using namespace std;

union { //用于将浮点数的二进制位解析为int位输出
	float input;
	int output;
} data;

void int2binary(unsigned n)//位运算只能用于整形
{
	unsigned b32 = 1<<31;//32位二进制，最高位是1，其它位是0
	cout<<((n&b32)>>31)<<" ";//最高位与运算，移位后最高位输出
	for(int i=1;i<32;++i)
	{
		n=n<<1;//循环左移一位，用于最高位的与运算
		cout<<((n&b32)>>31);//最高位与运算，移位后最高位输出
		if(i==7)
			cout<<" ";
		if(i>8 && (i-7)%8==0)
			cout<<" ";
	}
	cout<<"\n";
}
void float2binary(unsigned n)
{
	unsigned b32 = 1<<31;//32位二进制，最高位是1，其它位是0
	cout<<((n&b32)>>31)<<" ";//最高位与运算，移位后最高位输出
	for(int i=1;i<32;++i)
	{
		n=n<<1;//循环左移一位，用于最高位的与运算
		cout<<((n&b32)>>31);//最高位与运算，移位后最高位输出
		if(i%8==0)
			cout<<" ";
	}
	cout<<"\n";
}
void main()
{
	while(1)
	{
		int n;
		cout<<"please input a int:";
		cin>>n;
		int2binary(n);
		cout<<endl;
		cout<<"please input a float:";
		cin>>data.input;
		float2binary(data.output);
		cout<<endl;
	}
}
/*
please input a int:178
0 0000000 00000000 00000000 10110010

please input a float:178.625
0 10000110 01100101 01000000 0000000


please input a int:-178
1 1111111 11111111 11111111 01001110

please input a float:-178.625
1 10000110 01100101 01000000 0000000

please input a int:134
0 0000000 00000000 00000000 10000110

please input a float:
10110010的阶数是7，最高位总是1，直接隐藏掉；
阶码=阶数+偏移量
=阶数+2^(e-1)-1
=阶数+2^(8-1)-1
=7+127
=134(10000110)


please input a int:178		
0 0000000 00000000 00000000 10110010	正整数：原码	
		
please input a float:178.625		
0 10000110 01100101 01000000 0000000	浮点数：1符号位+8阶码(原码+移码)+23尾码	
	（尾码是舍弃了最高位1的原码）	
please input a int:-178		
1 1111111 11111111 11111111 01001110	负整数：补码（原码取反+1）	
		
please input a float:-178.625		
1 10000110 01100101 01000000 0000000		
	178.625的阶码计算：	
please input a int:134	阶码=阶数+偏移量	
0 0000000 00000000 00000000 10000110	=阶数+2^(e-1)-1	
	=阶数+2^(8-1)-1	
please input a float:	=7+127	
	=134	
		

  */
#endif





#if 0
#include <iostream>
using namespace std;
union 
{
	float input;
	int output;
} data;
char flag;
void printbin1(int val)
{
	int len=sizeof(val)*8;
	for(int i=1;i<=len;++i)
	{
		if(val&(1<<len-i))
			printf("1");
		else
			printf("0");
		if(i%4==0)
			printf(" ");
	}
	printf("\n");
}void printbin2(int val)
{
	printf("浮点数：符号位+阶码（指数位数+127）+尾数位\n");
	printf("%2s"," ");
	printf("阶码");
	printf("%6s"," ");
	printf("尾数\n");
	int len=sizeof(val)*8;
	for(int i=1;i<=len;++i)
	{
		if(val&(1<<len-i))
			printf("1");
		else
			printf("0");
		if(i==1 || i==5 || i==9 || i==12)
			printf(" ");
		if(i>12)
			if(i%4==0)
				printf(" ");
	}
	printf("\n");
}
void main()
{
	while(1)
	{
		printf("\n输入i，int转换为二进制，如178，\n");
		printf("输入f，float转换为二进制，如178.125:\n");
		scanf("%c",&flag);
		if(flag=='i')
		{
			printf("请输入一个int：");
			int i;
			scanf("%d",&i);
			printbin1(i);
		}
		if(flag=='f')
		{
			printf("请输入一个float：");
			float f;
			scanf("%f",&f);
			data.input = f;
			printbin2(data.output);
		}
		getchar();getchar();getchar();
	}
	
}

#endif
/*

输入i，int转换为二进制，如178，
输入f，float转换为二进制，如178.125:
i
请输入一个int：1
0000 0000 0000 0000 0000 0000 0000 0001

输入i，int转换为二进制，如178，
输入f，float转换为二进制，如178.125:
f
请输入一个float：1
浮点数：符号位+阶码（指数位数+127）+尾数位
  阶码      尾数
0 0111 1111 000 0000 0000 0000 0000 0000

输入i，int转换为二进制，如178，
输入f，float转换为二进制，如178.125:
i
请输入一个int：178
0000 0000 0000 0000 0000 0000 1011 0010

输入i，int转换为二进制，如178，
输入f，float转换为二进制，如178.125:
f
请输入一个float：178.125
浮点数：符号位+阶码（指数位数+127）+尾数位
  阶码      尾数
0 1000 0110 011 0010 0010 0000 0000 0000

输入i，int转换为二进制，如178，
输入f，float转换为二进制，如178.125:
*/



#if(0) //递归
#include<stdio.h>
#include<stdlib.h>
void decToBin(int n, int base) {
	if (n>0) {
		decToBin(n/base,base);
		printf("%d", n%base);
	}
	
}
void main()
{
	decToBin(13,2);
	system("pause");
}
#endif
//1101
/*
f(13)
f(6)
f(3)
f(1)
1%2
3%2
6%2
13%2
*/

#if(0) //递归
#include<stdio.h>
#include<stdlib.h>
void dec2(unsigned long n,unsigned long base)
{
	int r;
	r=n%base; //最后一位
	if(n>=base)
		dec2(n/base,base);//递归后进先出的特点很适合倒序计算；
	printf("%d",r);
}
int main()
{
	unsigned int i=0;
	dec2(13,2);
	system("pause");
	return 0;
}
#endif
/*
//1101

int r=1
n=11
dec2(5)
int r=1
n=5
dec2(2)
int r=0
n=2
dec2(2)
int r=1
n=1
*/


#if(0) //实现栈和十进制输出其它进制
#include<iostream>
using namespace std;
#define MAX_STACK_SIZE 100 /* 栈向量大小 */
typedef int ElemType;
typedef struct sqstack
{ 
	ElemType stack_array[MAX_STACK_SIZE];
	int top;
	int bottom;
}SqStack;
SqStack Init_Stack(void)
{ 
	SqStack S;
	S.bottom=S.top=0; 
	return(S);
}
int push(SqStack &S, ElemType e) /* 使数据元素e进栈成为新的栈顶 */
{ 
	if(S.top==MAX_STACK_SIZE-1) 
		return -1; /* 栈满,返回错误标志 */
	S.top++; /* 栈顶指针加1 */
	S.stack_array[S.top]=e; /* e成为新的栈顶 */
	return 0; /* 压栈成功 */
}
int pop(SqStack &S, ElemType *e) /*弹出栈顶元素*/
{ 
	if(S.top==0 )
		return -1; /* 栈空,返回错误标志 */
	*e=S.stack_array[S.top]; 
	S.top--; 
	return 0; 
}
void conversion(int n, int d) /*将十进制整数N转换为d(2或8)进制数*/
{ 
	SqStack S;
	ElemType e;
	int k;
	S=Init_Stack();
	/* 求出所有的余数,进栈 */
	while(n>0) 
	{ 
		k=n%d; 
		push(S,k); 
		n=n/d; 
	} 
	while(S.top!=0) /* 栈不空时出栈,输出 */
	{ 
		pop(S,&e); 
		printf("%1d",e); 
	}
} 
void main()
{
	conversion(54,2);
	cout<<endl;
	conversion(54,8);
	cout<<endl;
	conversion(54,16);
	system("pause");
}
/*
110110
66
36
*/
#endif

#if(0) //利用位运算的与运算来取某一位
#include<stdio.h>
#include<stdlib.h>
void printbin1(unsigned char val)
{
	printf("%d:",val);
	for(int i=1;i<=8;++i)
		printf("%d",(val&(1<<8-i))>>(8-i));
	printf("\n");
}
void main()
{
	unsigned char i=13;
	printbin1(i);
	system("pause");
}
#endif

#if(0) //利用位运算的与运算来取某一位
#include<stdio.h>
#include<stdlib.h>
void printbin1(int val)
{
	printf("%d:",val);
	int len=sizeof(val)*8;
	for(int i=1;i<=len;++i)
		printf("%d",(val&(1<<len-i))>>(len-i));
	printf("\n");
}
void main()
{
	int i=256+13;
	printbin1(i);
	system("pause");
}
#endif


#if(0) //利用位运算的与运算来取某一位
#include<stdio.h>
#include<stdlib.h>
void printbin1(short int val)
{
	printf("%d:",val);
	int len=sizeof(val)*8;
	for(int i=1;i<=len;++i)
		//printf("%d",(val&(1<<len-i))>>(len-i));
		if(val&(1<<len-i))
			printf("1");
		else
			printf("0");
	printf("\n");
}
void main()
{
	short int i=256+64+13;
	printbin1(i);

	system("pause");
}
//输出：333:0000000101001101
#endif

#if 0
#include <iostream>
using namespace std;
void main()
{
	while(1)
	{
		int n;
		cin>>n;//最好有边界检查
		int h=1;
		h=h<<31;//32位，最高位1，其它位是0
		
		for(int i=1;i<=32;i++)
		{
			if((n&h)==0)
				cout<<0;
			else cout<<1;
			n=n<<1; //左移一位，右位补0
			if(i%4==0)
				cout<<" ";
		}
		cout<<endl;
	}
 system("pause");
}
/*
43
0000 0000 0000 0000 0000 0000 0010 1011
-43
1111 1111 1111 1111 1111 1111 1101 0101
*/
#endif

#if 0
#include <iostream>
using namespace std;
union 
{
	float input;
	int output;
} data;
void main()
{
	data.input = 178.125;
	int h=1;
		h=h<<31;
		for(int i=1;i<=32;i++)
		{
			if((data.output&h)==0)
				cout<<0;
			else cout<<1;
			data.output<<=1;
			if(i%4==0)
				cout<<" ";
		}
		cout<<endl;
 system("pause");
}
//0100 0011 0011 0010 0010 0000 0000 0000
#endif



#if 0  //memcopy
#include <iostream>
#include <string.h>
using namespace std;

void main()
{
	float data;
	unsigned long buff;
	char s[34];
	data = (float)0.75;//字面浮点数默认是按double处理
	memcpy(&buff,&data,4);//把浮点数编码的二进制位复制给用整数编码的地址
	for(int i=33;i>=0;i--)//按位处理整数的二进制位
	{
		if(i==1 || i==10)
			s[i]=' ';
		else
		{
			if(buff%2==1)
				s[i] = '1';
			else
				s[i] = '0';
			buff/= 2;
		}
	}
	s[34] = '\0';
	cout<<s;	//0 01111110 10000000000000000000000
    system("pause");
}

#endif

#if 0
	unsigned short a;
	printf("请输入一个整型数");
	scanf("%u",&a);
	int b = 1<<15;
	printf("%u=",a);
	for(int i =1;i<=16;i++)
	{
		putchar(a&b?'1':'0');
		a<<=1;
		if(i%4==0)
			putchar(',');
	}
	printf("\bB\n");
#endif

#if 0
	//union结合bitset输出浮点数的二进制位
#include <iostream>
#include <bitset>
using namespace std;

union { //用于将浮点数的二进制位解析为int位输出
	float input;
	int output;
} data;


void float2binary(unsigned n)
{
	unsigned b32 = 1<<31;//32位二进制，最高位是1，其它位是0
	cout<<((n&b32)>>31)<<" ";//最高位与运算，移位后最高位输出
	for(int i=1;i<32;++i)
	{
		n=n<<1;//循环左移一位，用于最高位的与运算
		cout<<((n&b32)>>31);//最高位与运算，移位后最高位输出
		if(i%8==0)
			cout<<" ";
	}
	cout<<"\n";
}
void main()
{
	while(1)
	{
		cout<<"please input a float:";
		cin>>data.input;
		bitset<32> bs(data.output);//将整数放到一个32位的位容器内
		cout<<bs<<endl;
	}
}
#endif