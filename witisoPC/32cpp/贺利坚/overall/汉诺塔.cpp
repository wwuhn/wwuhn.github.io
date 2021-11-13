#include <iostream>  // ººÅµËþ
using namespace std;
const int discCount=3;
void move(int, char, char,char);
void han(int n,char A,char B,char C);
int main()
{ 
	move(discCount,'A','B','C');
    han(discCount,'A','B','C');
    while(1);
	return 0;
}
 
void han(int n,char A,char B,char C)
{
    if(n==1)
        printf("%d %c¡ú%c *\n",n,A,C);
    else
    {
        han(n-1,A,C,B);
        printf("%d %c¡ú%c\n",n,A,C);
        han(n-1,B,A,C);
    }
}
void move(int n, char A, char B,char C)
{
	if(n==1)
	{
		cout<<A<<"¡ú"<<C<<endl;
		return;
	}
	else
	{
		move(n-1,A,C,B);
		cout<<A<<"¡ú"<<C<<endl;
		move(n-1,B,A,C);
		return;
	}
}