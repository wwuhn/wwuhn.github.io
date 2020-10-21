#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
vector<int> ::iterator iter;

int fibdp(int n)
{
	vec.push_back(1);
	vec.push_back(1);
	
	if(n>2)
		for(int i=2; i<=n; ++i)
			vec.push_back(vec[i-1]+vec[i-2]);
	return vec[n-1];
}
/*
def feibo_dp(n):
    f = []
    f.append(1)
    f.append(2)
    if n > 2:
        for i in range(2, n):
            f.append(f[i-1] + f[i-2])
    return f[n-1]
*/


int fibdp2(int n)
{
	int i, fn, fn_1, fn_2;
	if(n<=1)
		return 1;
	fn_1 = 1, fn_2 = 1;
	for ( i = 2; i<=n; ++i)
	{
		fn = fn_1 + fn_2;
		fn_2 = fn_1; 
		fn_1 = fn;
	}
	return fn;
}

int  fc(int n)
{
	if(n==0 ||n==1)
		return 1;
	else 
		return (fc(n-1)+fc(n-2));
} 

int main()
{
	int n;
	//cin>>n;
	n=11;
	fibdp(n);
	for(iter=vec.begin();iter!=vec.end();iter++)
		cout<<*iter<<" ";
    cout<<endl;
	
	cout<<fibdp2(n)<<endl;
	
	cout<<fc(n)<<endl;

	cin.get();
	return 0;
}



