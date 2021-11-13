#include<iostream>
using namespace std;
bool isPalindrome(int);
int main()
{
    int m,n;
    cout<<"求多少以内的回文数？"<<endl;
    cin>>m;
    for(n=1;n<=m;++n)
        if(isPalindrome(n))
            cout<<n<<" ";
        return 0;
}

bool isPalindrome(int n)
{
    int a[20]; //用于存储n中的各位数
    int i=0;
    //下面的循环，使a数组中依次存放个、十、百……位数
    while(n>0)
    {
        a[i++]=n%10;
        n/=10;
    }
    //退出循环，可以知道n为i位数
    int j=0,k=i-1;
    while(a[j]==a[k]&&j<k)  //只要两边的数相等，齐往中间“看”
        j++,k--;
    if(j>=k) 
        return true;        //前后两端对应的数字都比较过了，都相等，是回文数
    else 
        return false;
}