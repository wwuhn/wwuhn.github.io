/***病毒检测算法***/
#include<cstring>
#include<iostream>
using namespace std;

#define Maxsize 100

typedef char SString[Maxsize+1];		//0号单元存放串的长度

bool StrAssign(SString &T, char *chars)//生成一个其值等于chars的串T
{
	int i;
	if(strlen(chars)>Maxsize)
		return false;
	else
    {
		T[0]=strlen(chars);//0号单元存放串的长度
		for(i=1;i<=T[0];i++)
        {
            T[i]=*(chars+i-1);
            cout<<T[i]<<"  ";
        }
        cout<<endl;
		return true;
	}
}

void get_next(SString T,int next[])//计算next函数值
{
	int j=1,k=0;
	next[1]=0;
	while(j<T[0])
	{

	    if(k==0||T[j]==T[k])
            next[++j]=++k;
		else
			k=next[k];
	}
}

int Index_KMP(SString S, SString T, int pos)//KMP算法
{ 	// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
	//其中，T非空，1≤pos≤StrLength(S)
	int *next=new int[T[0]+1]; // 生成T的next数组
	get_next(T,next);
	int i=pos, j=1;
	while(i<=S[0]&&j<=T[0])
    {
        if(j==0||S[i]==T[j]) // 继续比较后面的字符
		{
			i++;
			j++;
		}
		else
			j=next[j]; // 模式串向右移动
    }
	if(j>T[0]) // 匹配成功
		return i-T[0];
	else
		return 0;
}

bool Virus_detection(SString S, SString T) // 病毒检测
{
    int i,j;
    SString temp;                    // temp记录病毒变种
    for(i=T[0]+1,j=1;j<=T[0];i++,j++)// 将T串扩大一倍，T[0]为病毒长度
        T[i]=T[j];
    for(i=0;i<T[0];i++)        // 依次检测T[0]个病毒变种
    {
        temp[0]=T[0];          // 病毒变种长度为T[0]
        for(j=1;j<=T[0];j++)   // 取出一个病毒变种
            temp[j]=T[i+j];
        if(Index_KMP(S,temp,1))// 检测到病毒
            return 1;
    }
    return 0;
}

int main()
{
	SString S,T;
	char str[100];
    cout<<"患者DNA序列S："<<"  ";
    cin>>str; // eabbacab
	StrAssign(S,str);
    cout<<"病毒DNA序列T："<<"  ";
    cin>>str; //aabb
	setbuf(stdin,NULL);
	StrAssign(T,str);
	if(Virus_detection(S,T))
        cout<<"该患者已感染病毒！"<<endl;
    else
        cout<<"该患者未感染病毒！"<<endl;
	cin.get();
	return 0;
}
/*输入
eabbacab
aabb
*/
/*运行效果
患者DNA序列S：  eabbacab
e  a  b  b  a  c  a  b
病毒DNA序列T：  aabb
a  a  b  b
该患者已感染病毒！
*/