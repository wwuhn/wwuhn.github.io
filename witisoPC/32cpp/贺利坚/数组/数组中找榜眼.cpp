/*
数组中找榜眼
*/
#if 1  // 一次“扫描”找出次大值


//编写一个函数，找出一个整型数组data中的第二大的数。
#include <iostream>
using namespace std;

int find_sec_max(int data[] , int n);

int main ()
{
    int a[10]= {99,6,12,2,4,98,14,11,76,1};
    cout<<"a数组中的第二大数为："<<find_sec_max(a,10)<<endl;
    return 0;
}


int find_sec_max(int data[] , int n)
{
    int max1;  //最大
    int max2;  //次大
    if (data[0]>data[1])
        max1=data[0], max2=data[1];
    else
        max1=data[1], max2=data[0];
    for(int i=1; i<n; i++)
    {
        if(data[i] > max1)  //比最大的都大
        {
            max2 = max1;    // 最大值沦为老二
            max1 = data[i]; // 更新最大值
        }
        else if(data[i] > max2 && data[i] < max1)  //a[i]应该是新老二，老大不变
            max2 = data[i];
    }
    return max2;
}




#endif

#if 0  // 用类似选择排序的方法，但需要两次“扫描”
//编写一个函数，找出一个整型数组data中的第二大的数。
#include <iostream>
using namespace std;
int find_sec_max(int data[] , int n);
int main ()
{
	int a[10]={3,6,12,2,4,98,14,11,76,1};
	cout<<"a数组中的第二大数为："<<find_sec_max(a,10)<<endl;
	return 0; 
}
 
 
int find_sec_max(int data[] , int n)
{
	int k=0,i,t;  
	for(i=1; i<n; i++)  
	{  
		if(data[i] > data[k])
		{  
			k=i;  //用k记录最大值的下标
		}  
	}
	t=data[0];data[0]=data[k];data[k]=t;   //通过交换，data[0]中将是最大值
	//次大元将是data[1]到data[n-1]中的最大元素
	k=1;
	for(i=2; i<n; i++)  
	{  
		if(data[i] > data[k])
		{  
			k=i;  //用k记录最大值的下标
		}  
	}
	return data[k];
}

#endif

#if 0  // 更像选择排序了

//编写一个函数，找出一个整型数组data中的第二大的数。
#include <iostream>
using namespace std;
int find_sec_max(int data[] , int n);
int main ()
{
	int a[10]={3,6,12,2,4,98,14,11,76,1};
	cout<<"a数组中的第二大数为："<<find_sec_max(a,10)<<endl;
	return 0; 
}
 
 
int find_sec_max(int data[] , int n)
{
	int k=0,i,j,t;
	for(j=0;j<2;++j)  //就循环两次，如果照着排序做，出力不讨好了
	{
		k=j;
		for(i=j+1; i<n; i++)  
		{  
			if(data[i] > data[k])
			{  
				k=i;  //用k记录最大值的下标
			}  
		}
		if(j!=k)
		{
			t=data[j];
			data[j]=data[k];
			data[k]=t;   //通过交换，data[j]中将是最大值
		}
	}
	return data[1];   //次大元放在data[1]中
}
#endif


/*

*/