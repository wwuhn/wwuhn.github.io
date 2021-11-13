#include <iostream> // 4个数字相加
using namespace std; // 4个数字不相同的判断
/*
     d
    cd
   bcd
+ abcd
________________
  2008

  */

void cal(int n) // 未优先前的代码  
{ 
	int a,b,c,d,s;//变量这样取，比有些题解上用i,j,p,q之类的要清晰得多
	for(a=1;a<3;a++)
		for(b=0;b<10;b++)
			for(c=0;c<10;c++)
				for(d=0;d<10;d++)
					if((a-b)*(a-c)*(a-d)*(b-c)*(b-d)*(c-d)!=0)//一个技巧：表示两两不同可以这样做
					{
						s=4*d+3*c*10+2*b*100+a*1000;
						if(n==s) 
							cout<<a<<b<<c<<d<<endl;
					}
}  

void cal_1(int n)
{
    int a,b,c,d,s;
    for(a=1;a<3;a++)
        for(b=0;b<10;b++)
        {
        if(a==b) continue;//“a”和“b”的取值如果相同了，将不再考虑另外两字的取值，效果可观
            for(c=0;c<10;c++)
            {
                if(c==b||c==a) continue;  //理由同上
                    for(d=0;d<10;d++)
                    if((a-d)*(b-d)*(c-d)!=0)
                    {
                        s=4*d+3*c*10+2*b*100+a*1000;
                        if(n==s)
                            cout<<a<<b<<c<<d<<endl;
                    }
            }
    }
}
int main()
{
    cal(2008);
    for(int i=2000;i<2050;i++)
    {
        cout<<"-----"<< i <<endl;
        cal_1(i);
    }
    
    while(1);
    return 0;
}