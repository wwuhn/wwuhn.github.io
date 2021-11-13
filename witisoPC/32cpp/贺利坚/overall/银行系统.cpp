#include<iostream>   
#include<fstream>
using namespace std; 
//用全局变量存储各个帐户的相关信息，便于各函数间共享数据（是一种解决办法）
//直接用变量并不是好方案，后面将引入数组解决
//直接在程序中存储并不是好方案，这些信息要存入文件
const int NUM=100;      //暂时最多支持100个用户，其实，可以很多
int account[NUM];       //帐户
int pwd[NUM];           //密码
double balance[NUM];    //余额
int accountNum;         //实际用户数，由读文件决定
int accountIndex;       //用全局变量保存当前登录的帐户对应的下标
int currentAccount;     //用全局变量保存当前登录的帐户

//声明自定义函数
int checkStatus();
int seekUser(int);
void work();
void showbalance();
void drawmoney();
void deposit();
void transferAccounts();
void updatePassword();
void getInformation();  //用于读取帐户数据
void saveInformation(); //退出前保存数据

int main()  
{  
    int status;
    char ch;
    cout<<"贺家银行欢迎您光临……（需要看bank.dat中的数据确定，这本是银行中的绝密数据！）"<<endl;
    getInformation();   //用于读取开户数据
    while(1)            //支持用户多次登录办理业务
    {
        status=checkStatus();
        switch(status)
        {
        case 1:         //密码正确 
            work();
            break;
        case 2:         //自行终止登录
            cout<<"欢迎下次光临……"<<endl;
            break;
        case 3:
            cout<<"请确认帐号后再来……"<<endl;
            break;
        case 4:
            cout<<"吞卡，请联系就近网点解决……"<<endl;
        }
        cout<<"=====要退出系统，请按键Q，其他键继续下一位用户登录======"<<endl;
        fflush( stdin );  //清空输入缓冲区，否则getchar()自动获得
        ch=getchar();
        if(ch=='q'||ch=='Q')break;
    }
    saveInformation();
    return 0;
}

/*检验密码
 *返回值约定:
 * 1 - 用户名、密码正确，可以进一步工作
 * 2 - 用户名放弃登录正常退出
 * 3 - 用户名不对退出
 * 4 - 三次登录失败吞卡后退出
 */
int checkStatus()
{
    int iStatus=4;		    //默认吞卡的结局
    int iPass;
    int num=1;
    char goOn;
    cout<<"请输入帐户";
    cin>>currentAccount;    //currentAccount是全局变量
    accountIndex=seekUser(currentAccount);
    if(accountIndex < 0)    //根据seekUser的定义，这表示找不到这个客户
        iStatus=3; 
    else
    {		
        do
        {	
            if(num==1)
                cout<<"请输入密码";
            else
            {
                cout<<"温情提示：这是您第"<<num<<"次输入密码，三次不对将吞卡。"<<endl;
                cout<<"还要继续尝试吗（继续输入Y，退出输入N，之后回车）：";
                cin>>goOn;
                if('Y'==goOn||'y'==goOn)
                    cout<<"请再次输入密码";
                else
                {
                    iStatus=2; //用户放弃登录
                    break;
                }
            }
            cin>>iPass;
            num++;
            if(iPass==pwd[accountIndex])    //帐户
            {
                iStatus=1;                  //密码对了
                break;
            }
        }while(num<4);                      //密码不正确且次数在允许范围内循环
        //如果在循环因为num==4为真而退出，iStatus的值还保持初始3，代表吞卡
    }
    return iStatus; //返回状态
}	

//查找是否存在这个客户，
//如果存在，返回其对应的下标
//如果不存在，返回-1(查找败)
int seekUser(int iAccount)
{
    int i;
    for(i=0;i<accountNum;++i)//用了顺序查找，实际系统中确保account[]有序，进行二分查找
    {
        if(iAccount==account[i])
            break;
    }
    if(i>=accountNum)
        i=-1;  //代表找不到这样的用户
    return i;
}

//处理业务
void work()
{
    char cChoice;
    bool bExit = false;
    do  
    {  
        cout<<endl<<"*  您可以办理下面的业务："<<endl;  
        cout<<"*  1.查询"<<endl;  
        cout<<"*  2.取款"<<endl;  
        cout<<"*  3.存款"<<endl;
        cout<<"*  4.转账"<<endl;
        cout<<"*  5.修改密码"<<endl;
        cout<<"*  0.退出"<<endl;  
        cout<<"*  请输入（0-4）：";  
        cin>>cChoice;
        switch(cChoice)
        {
        case '1':
            showbalance();
            break;  
        case '2':
            drawmoney();
            break;  
        case '3':
            deposit();
            break;  
        case '4':
            transferAccounts();
            break;  
        case '5':
            updatePassword();
            break;  
        case '0':
            cout<<"欢迎您下次来存款. "<<endl;
            bExit=true;
        }		
    }while(!bExit);  
    return;
}

//查询余额
void showbalance()
{
    cout<<"您的当前余额是："<<balance[accountIndex]<<"元"<<endl;
}

//取款
void drawmoney()
{  
    double money;  
    cout << "请输入取款金额：";  
    cin >> money;  
    //下面不计利息了，从现在起，我们的银行只提供银行卡业务，是定期统一计息的
    if(money<=balance[accountIndex])
    {
        balance[accountIndex]-=money; //取款成功
        cout<<"取款后，您的余额是："<<balance[accountIndex]<<"元。"<<endl;
    }
    else
    {
        cout<<"您的余额不足，取款失败。"<<endl;
    }
}	
//存款
void deposit()
{
    double money;  
    cout << "请输入存款金额：";  
    cin >> money;  
    //下面不计利息了，从现在起，我们的银行只提供银行卡业务，是定期统一计息的
    balance[accountIndex]+=money; //取款成功
    cout<<"存款后，您的余额是："<<balance[accountIndex]<<"元。"<<endl;
}

//转帐
void transferAccounts()
{
    double money;  
    int iAccount2,iAccount2Index;
    cout << "请输入转帐金额：";
    cin >> money;  
    if(money>balance[accountIndex]) //本行不透支，不能转账
    {
        cout<<"您的余额不足，转账失败。"<<endl;
    }
    else
    {
        cout << "请输入对方帐户：";
        cin >> iAccount2; //应该判断对方帐户的有效性再转账，暂时不做，待以后改进  
        iAccount2Index=seekUser(iAccount2);
        if(iAccount2Index==-1)
            cout<<"对方帐号输入错误，转账失败。"<<endl;
        else
        {
            balance[accountIndex]-=money; //从己方转出
            balance[iAccount2Index]+=money; //转给对方
            //此处应该为对方帐户增加余额，暂时略
            cout<<"转账后，您的余额是："<<balance[accountIndex]<<"元，对方余额为"<<balance[iAccount2Index]<<"元。"<<endl;
            //实际系统中不似上行那样提示，暴露信息太多了。
        }
    }
}			
//修改密码
void updatePassword()
{
    int p1,p2;
    cout << "请输入新密码：";
    cin >> p1;  
    cout << "请确认新密码：";
    cin >> p2;  
    if(p1==p2)//两次输入相符
    {
        pwd[accountIndex]=p1;   
        cout<<"密码修改成功！"<<endl;
    }
    else
    {
        cout<<"两次输入不一致，密码修改失败。"<<endl;
    }
}

//从文件中读取数据，保存到全局数组中
void getInformation()  //用于读取帐户数据
{
    ifstream infile("bank.dat",ios::in);  //以输入的方式打开文件
    if(!infile)       //测试是否成功打开
    {
        cerr<<"不好啦，找不到储户信息了!"<<endl;
        exit(1);
    }
    int i=0;
    while(!infile.eof())
    {
        infile>>account[i]>>pwd[i]>>balance[i];
        ++i;
    }
    infile.close();
    accountNum=i;  //用户数目
    return;
}

//退出时，将变化了的数据保存到文件中，下次运行，接着上次的业务继续办下去
void saveInformation() //退出前保存数据
{
    ofstream outfile("bank.dat",ios::out);  //以输入的方式打开文件
    if(!outfile)       //测试是否成功打开
    {
        cerr<<"不好啦，储户信息保存不了了!"<<endl;
        exit(1);
    }
    int i=0;
    while(i<accountNum)
    {
        outfile<<account[i]<<'\t'<<pwd[i]<<'\t'<<balance[i]<<'\n';
        ++i;
    }
    outfile.close();
    return;
}