#include <string>
#include <iostream>
using namespace std;
enum PassStatus {pass,failed,reject};	// 枚举类型定义密码状态

class DetectPass
{
public:
	DetectPass();
	~DetectPass();
	PassStatus operator() (string passstr); // 括号操作符重载
protected:
	int numOfRun; 		// 用成员数据记录输入密码的次数(对象状态)
	string getpass();	//（模拟）通过数据库获取密码
};

DetectPass::DetectPass()
{
	cout <<"构造函数对象..." <<endl;
	numOfRun=0;
}

DetectPass::~DetectPass()
{
	cout <<"析构函数对象..." <<endl;
}

PassStatus DetectPass::operator() (string passstr)
{
	cout <<"这是第" <<++numOfRun <<"次输入密码，";//状态更新
	if (numOfRun<=3)
	{
		if (passstr.compare(getpass())==0)//passstr是string类型，有compare()成员方法
		{
			cout <<"密码正确。" <<endl <<"欢迎进入系统！" <<endl;
			return pass;
		}
		else
		{
			cout <<"密码错误！" <<endl;
			return failed;
		}
	}
	else
	{
		cout <<"您已经输错密码三次！异常退出！" <<endl;
		return reject;
	}
}

string DetectPass::getpass()
{
	return string("123456");
}

using namespace std;
DetectPass password; 		//声明一个与password函数同名的对象

int main()
{
	string input;
	do
	{
		cout <<"请输入密码：";
		cin >>input;
	}while(password(input)==failed); //看起来像是调用password函数
	cin.get();cin.get();
	return 0;	
}
/*
构造函数对象...
请输入密码：123
这是第1次输入密码，密码错误！
请输入密码：456
这是第2次输入密码，密码错误！
请输入密码：123456
这是第3次输入密码，密码正确。
欢迎进入系统！
*/