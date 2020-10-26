/***KMP算法***/
#include<iostream>
#include<cstring>
using namespace std;

#define Maxsize 100

typedef char SString[Maxsize+1];//0号单元存放串的长度

bool StrAssign(SString &T,char *chars)//生成一个其值等于chars的串T
{
	int i;
	if(strlen(chars)>Maxsize)
		return false;
	else
    {
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
        {
            T[i]=*(chars+i-1);
            cout<<T[i]<<"  ";
        }
        cout<<endl;
		return true;
	}
}

int Index_BF(SString S,SString T,int pos) // BF算法
{ 	// 求T在主串S中第pos个字符之后第一次出现的位置
	// 其中，T非空，1≤pos≤s[0],s[0]存放S串的长度
	int i=pos,j=1,sum=0;
	while(i<=S[0]&&j<=T[0])
    {
        sum++;
        if(S[i]==T[j]) // 如果相等，则继续比较后面的字符
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+2; // i退回到上一轮开始比较的下一个字符
			j=1;     // j退回到第1个字符
		}
    }
	cout<<"一共比较了"<<sum<<"次"<<endl;
	if(j>T[0])      // 匹配成功
		return i-T[0];
	else
		return 0;
}


void get_next(SString T,int next[]) //计算next函数值
{
	int j=1,k=0;
	next[1]=0;
	while(j<T[0])      // 动态规划
	{
	    if(k==0||T[j]==T[k])
            next[++j]=++k;
		else
			k=next[k]; // 下标k的回退
	}
    cout<<"-----next[]-------"<<endl;
    for(j=1;j<=T[0];j++)
        cout<<next[j]<<"  ";
    cout<<endl;
}

void get_next2(SString T,int next[]) // 计算next函数值改进算法
{
	int j=1,k=0;
	next[1]=0;
	while(j<T[0])
	{
	    if(k==0||T[j]==T[k])
        {
            j++;
            k++;
            if(T[j]==T[k])
                next[j]=next[k];
            else
                next[j]=k;
        }
		else
			k=next[k];
	}
    cout<<"-----next[]-------"<<endl;
    for(j=1;j<=T[0];j++)
        cout<<next[j]<<"  ";
    cout<<endl;
}

int Index_KMP(SString S,SString T,int pos,int next[]) // KMP算法
{ 	// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
	// 其中，T非空，1≤pos≤StrLength(S)
	int i=pos,j=1,sum=0;
	while(i<=S[0]&&j<=T[0])
    {
        sum++;
        if(j==0||S[i]==T[j]) // 继续比较后面的字符
		{
			i++;
			j++;
		}
		else
			j=next[j];       // 模式串向右移动
    }
	cout<<"一共比较了"<<sum<<"次"<<endl;
	if(j>T[0])               // 匹配成功
		return i-T[0];
	else
		return 0;
}

int main()
{
	SString S,T;
	char str[100];
    cout<<"串S："<<"  ";
    cin>>str;        // abaabaabeca
	StrAssign(S,str);// 可以修改程序，自己输入字符串 
    cout<<"串T："<<"  ";
    cin>>str;        // abaabe
	StrAssign(T,str);
	int *p=new int[T[0]+1]; // 生成T的next数组
	cout<<endl;
	cout<<"BF算法运行结果："<<endl;
	cout<<"主串和子串在第"<<Index_BF(S,T,1)<<"个字符处首次匹配\n";
	cout<<endl;
	cout<<"KMP算法运行结果："<<endl;
	get_next(T,p);
	cout<<"主串和子串在第"<<Index_KMP(S,T,1,p)<<"个字符处首次匹配\n";
	cout<<endl;
	cout<<"改进的KMP算法运行结果："<<endl;
    get_next2(T,p);
	cout<<"主串和子串在第"<<Index_KMP(S,T,1,p)<<"个字符处首次匹配\n";
	cin.get();cin.get();
	return 0;
}
/*
串S：  abaabaabeca
a  b  a  a  b  a  a  b  e  c  a
串T：  abaabe
a  b  a  a  b  e

BF算法运行结果：
一共比较了15次
主串和子串在第4个字符处首次匹配

KMP算法运行结果：
-----next[]-------
0  1  1  2  2  3
一共比较了10次
主串和子串在第4个字符处首次匹配

改进的KMP算法运行结果：
-----next[]-------
0  1  0  2  1  3
一共比较了10次
主串和子串在第4个字符处首次匹配

*/