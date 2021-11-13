// 银行储蓄系统

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
#define upNum 2000 //系统最多容纳的用户数
 
int user[upNum][3];  //账号、密码、状态
char name[upNum][10];   //用户名
double balance[upNum];  //账户余额
//以上相同行下标，描述同一人的信息
int N;  //实际的用户数目
 
int pass();  //业务员登录
void readData();  //开始前从文件中读数据，存在数组中
void writeData();   //程序结束前，将数组中的数据写入到文件中
void work();  //业务驱动
int chooseInMenu(); //显示菜单并由业务员选择
void openAccount(); //开户
void cancelAccount();  //注销账户
void save();   //存款
void withdraw();   //取款
void showAccount(); //查询余额
void transferAccounts();  //转账
void reportLoss();  //挂失
void cancelLoss();  //解除挂失
void updatePassword();   //更改密码
int inputPassword();   //返回键盘输入的密码
int search(int);  //根据账号找到用户数据对应的下标
 
/*主函数：*/
int main()
{
    printf("+----------------------+\n");
    printf("+    欢迎光临CSDN银行  +\n");
    printf("+----------------------+\n");
    if (pass())
    {
        readData();
        work();
        writeData();
    }
    return 0;
}
 
/*
功能：验证用户密码
返回值：密码正确，返回1；
        不能通过密码验证，返回0
*/
int pass()
{
    char sNameInFile[20];   //由文件中读出的业务员用户名
    char sPassInFile[20];  //文件中保存的密码，这一版本中，用字符保存密码
    char sName[20];   //业务员登录时输入的用户名
    char sPass[20];  //业务员登录时输入的密码
    char ch;
    int iTry=3;   //进入系统时尝试的次数
    int right = 0;  //要返回的结果：0-不正确 1-正确
    FILE *fp;  //用于文件操作
    //密码保存在文件中，先取出
    if ((fp=fopen("worker.txt", "r"))==NULL)
    {
        printf("password file cannot open!");
        exit(0);
    }
    fscanf(fp, "%s %s", sNameInFile, sPassInFile);  //从文件中读业务员用户名和密码密码
    fclose(fp);
 
    //进入系统，密码三次不对将退出
    do
    {
        printf("请输入业务员用户名:");
        scanf("%s", sName);
        printf("请输入密码:");
        int i=0;
        while((ch=getch())!='\r')  //getch在接受输入后，不在屏幕上显示
        {
            sPass[i++]=ch;
            putchar('*');   //接受任何字符，屏幕上只显示*
        }
        sPass[i]='\0';
        fflush(stdin);
        printf("\n");
        if(strcmp(sPass,sPassInFile)==0&&strcmp(sName,sNameInFile)==0)
        {
            right = 1;
            break;
        }
        else
        {
            iTry--;
            if(iTry>0)
                printf("超过3次将退出，你还可以尝试%d次！\n", iTry);
            else
            {
                printf("对不起，你不能进入系统\n");
            }
        }
    }
    while(iTry);
    return right;
}
 
/*
关于getch()的一点说明：
所在头文件：conio.h
函数用途：从控制台读取一个字符，但不显示在屏幕上
函数原型：int getch(void)
返回值：读取的字符
在不同平台，输入回车，getch()将返回不同数值，而getchar()统一返回10(即\n)
1)windows平台下ENTER键会产生两个转义字符 \r\n，因此getch返回13(\r)。
2)unix、 linux系统中ENTER键只产生 \n ，因此getch返回10(\n)。
3)MAC OS中ENTER键将产生 \r ，因此getch返回13(\r)。
为避免键盘缓存区中未读出的字符影响程序，用fflush(stdin);清除输入缓存区
*/
 
/*
功能：办理业务
*/
void work()
{
    int iChoice;   //用于选择系统功能
    //办理业务
    do
    {
        iChoice = chooseInMenu();  //从菜单中获得功能代码
        switch(iChoice)
        {
        case 1:
            openAccount(); //开户
            break;
        case 2:
            cancelAccount();  //注销账户
            break;
        case 3:
            save();  //存款
            break;
        case 4:
            withdraw();   //取款
            break;
        case 5:
            showAccount(); //查询余额
            break;
        case 6:
            transferAccounts();  //转账
            break;
        case 7:
            reportLoss();  //挂失
            break;
        case 8:
            cancelLoss();  //解除挂失
            break;
        case 9:
            updatePassword();   //更改密码
            break;
        case 0:
            printf("欢迎您再来. \n");
        }
    }
    while(iChoice);
}
 
/*
功能：从文件中读取储户数据
*/
void readData()
{
    FILE *fp;  //用于文件操作
    int i = 0;
    //从文件中取出余额
    if ((fp=fopen("account.dat", "r"))==NULL)
    {
        printf("data file cannot open!");
        exit(0);
    }
    while(fscanf(fp,"%d %s %d %lf %d",&user[i][0], name[i], &user[i][1], &balance[i],&user[i][2] ) != EOF)
    {
        i++;
    }
    N = i; //用全局变量存储用户的总人数
    fclose(fp);
    return;
}
 
/*
功能：将用户数据保存到文件中
*/
void writeData()
{
    FILE *fp;  //用于文件操作
    int i=0;
    //保存余额
    if ((fp=fopen("account.dat", "w"))==NULL)
    {
        printf("data file cannot open!");
        exit(0);
    }
    for(i=0; i<N; i++)
        fprintf(fp,"%d %s %d %f %d\n",user[i][0], name[i], user[i][1], balance[i],user[i][2]);
    fclose(fp);
}
 
/*
功能：显示菜单并由业务员选择
返回值：用户选择的功能，范围0-9
*/
int chooseInMenu()
{
    int i;
    while(1)
    {
        printf("\n");
        printf("+----------------------------+\n");
        printf("+ 1 开户    2 销户    3 存款 +\n");
        printf("+ 4 取款    5 查询    6 转账 +\n");
        printf("+ 7 挂失    8 解挂    9 改密 +\n");
        printf("+                     0 退出 +\n");
        printf("+----------------------------+\n");
        printf("请输入操作指令:");
        scanf("%d", &i);
        if(i>=0 && i<=9)
            break;
        else
            printf("请重新选择功能\n\n");
    }
    return i;
}
 
/*
功能：开户
说明：在进入系统时，在读入数据过程中，已经记录了用户数为N，在数组中对应下标为0~N-1
  开户时要增加一个用户，只要为下标为N的数组元素置值，并在成功之后令N++即可。
  这样做顺序增加简单，但遗留的后患是，在查询账户时，不得不用顺序查找，这在效率上是不划算的。
  改进的手段（1）：开户时，根据账号，将数据插入到数组中，使按账号有序，这样做插入时麻烦，但有利于以后要频繁的查询操作
  改进的手段（2）：账号由系统自动生成，保证其连续，这样在顺序增加的时候，就保证了其有序。
*/
void openAccount()
{
    if(N==upNum)
    {
        printf("银行用户数已经达到上限，不能再开户");
        return;
    }
    //下面正常办理开户业务
    printf("正在开户\n");
    printf("账号：");
    scanf("%d", &user[N][0]);
    printf("户主姓名：");
    scanf("%s", name[N]);
    int iPass1, iPass2;
    printf("密码：");
    iPass1=inputPassword();  //输入密码1
    printf("确认密码：");
    iPass2=inputPassword();  //输入密码2
    if(iPass1==iPass2)
    {
        user[N][1]=iPass1;
        user[N][2]=0; //账户状态为“正常”
        printf("存入金额：");
        scanf("%lf", &balance[N]);
        N++; //正式用户数增加1，确认了新用户已经加入
        printf("成功开户！\n");
    }
    else
    {
        printf("两次密码不一致，未成功开户！\n"); //没有N++，则读入的值无效
    }
}
 
/*
功能：注销账户
说明：找到账户，并将其状态改为2-注销即可。
注销前应该检查余额，应该先取款再注销
*/
void cancelAccount()
{
    int id;   //用于输入的账号
    int who;  //查找到该账号在数组中对应的下标
    int iPass;
    printf("待销户账号：");
    scanf("%d", &id);
    who = search(id);  //根据账号查询用户，返回用户的下标
    if(who<0)   //说明id账户不存在
    {
        printf("该用户不存在，销户失败！\n");
    }
    else
    {
        printf("户主姓名：%s\n", name[who]);
        printf("密码：");
        iPass=inputPassword();
        if(iPass==user[who][1])
        {
            printf("余额：%.2f 元\n", balance[who]);
            printf("确认销户（y/n）？");
            if(tolower(getchar())=='y')
            {
                balance[who]=0;  //取款后余额变0
                user[who][2]=2;  //状态变为注销
                printf("取款 %.2f 元，销户成功！\n", balance[who]);
            }
            else
            {
                printf("你取消了操作，销户失败！\n");
            }
            fflush(stdin);  //清除了getchar()时在键盘缓存中的遗留，以免影响后续操作
        }
        else
        {
            printf("输入的密码错误，销户失败！\n");
        }
    }
}
 
/*
功能：存款
说明：需要保证账户存在，且处于正常状态
*/
void save()
{
    int id, who;
    double money;
    printf("账号：");
    scanf("%d", &id);
    who = search(id);  //根据账号查询用户，返回用户的下标
    if(who<0)   //说明id账户不存在
    {
        printf("该用户不存在，存款失败！\n");
    }
    else
    {
        if(user[who][2]==0)
        {
            printf("户主姓名：%s\n", name[who]);
            printf("输入存款额：");
            scanf("%lf", &money);
            balance[who]+=money;
            printf("存款后，您有%.2f元. \n",balance[who]);
        }
        else if(user[who][2]==1)
        {
            printf("该用户处于挂失状态，存款失败！\n");
        }
        else
        {
            printf("该用户已经销户，存款失败！\n");
        }
    }
    return;
}
 
/*
功能：取款
说明：需要保证账户存在，且处于正常状态，另外，余额要足够取
*/
void withdraw()
{
    int id, who;
    int iPass;
    double money;
    printf("账号：");
    scanf("%d", &id);
    who = search(id);  //根据账号查询用户，返回用户的下标
    if(who<0)   //说明id账户不存在
    {
        printf("该用户不存在，取款失败！\n");
    }
    else
    {
        if(user[who][2]==0)
        {
            printf("户主姓名：%s\n", name[who]);
            printf("密码：");
            iPass=inputPassword();
            if(iPass!=user[who][1])
            {
                printf("输入密码错误，取款失败！\n");
            }
            else
            {
                printf("输入取款额：");
                scanf("%lf", &money);
                if(money>balance[who])  //亲，不玩透支
                {
                    printf("余额不足，取款失败！\n");
                }
                else
                {
                    balance[who]-=money;
                    printf("取款后，还有%.2f元. \n",balance[who]);
                }
            }
        }
        else if(user[who][2]==1)
        {
            printf("该用户处于挂失状态，取款失败！\n");
        }
        else
        {
            printf("该用户已经销户，取款失败！\n");
        }
    }
    return;
}
 
/*
功能：查询账户
说明：显示账户信息
*/
void showAccount()
{
    int id, who;
    int iPass;
    printf("账号：");
    scanf("%d", &id);
    who = search(id);  //根据账号查询用户，返回用户的下标
    if(who<0)   //说明id账户不存在
    {
        printf("该用户不存在，查询完毕！\n");
    }
    else
    {
        printf("户主姓名：%s\n", name[who]);
        printf("密码：");
        iPass=inputPassword();
        if(iPass!=user[who][1])
        {
            printf("输入密码错误，不能继续查询其他信息！\n");
        }
        else
        {
            printf("余额：%.2f元. \n",balance[who]);
            printf("状态：");
            if(user[who][2]==0)
            {
                printf("正常\n");
            }
            else if(user[who][2]==1)
            {
                printf("挂失\n");
            }
            else
            {
                printf("已经销户\n");
            }
        }
    }
    return;
}
 
/*
功能：转账
说明：需要保证两个账户都存在，且处于正常状态，另外，转出账户的余额要足够
*/
void transferAccounts()
{
    int id, whoout, whoin;
    int iPass;
    double money;
    printf("输入转出账号：");
    scanf("%d", &id);
    whoout = search(id);  //根据账号查询用户，返回用户的下标
    if(whoout<0)   //说明id账户不存在
    {
        printf("该用户不存在，转账失败！\n");
    }
    else
    {
        if(user[whoout][2]==0)
        {
            printf("户主姓名：%s\n", name[whoout]);
            printf("密码：");
            iPass=inputPassword();
            if(iPass!=user[whoout][1])
            {
                printf("输入密码错误，转账失败！\n");
            }
            else
            {
                printf("输入转账金额：");
                scanf("%lf", &money);
                if(money>balance[whoout])  //亲，不玩透支
                {
                    printf("余额不足，转账失败！\n");
                }
                else
                {
                    printf("输入转入账号：");
                    scanf("%d", &id);
                    whoin = search(id);  //根据账号查询用户，返回用户的下标
                    if(whoin<0)
                    {
                        printf("转入账户不存在，转账失败！\n");
                    }
                    else
                    {
                        if(user[whoin][2]>0)
                        {
                            printf("转入账户异常，转账失败！\n");
                        }
                        else
                        {
 
                            balance[whoout]-=money;
                            balance[whoin]+=money;
                            printf("取款后，您还有%.2f元. \n",balance[whoout]);
                        }
                    }
                }
            }
        }
        else
        {
            printf("该账户异常，转账失败！\n");
        }
    }
    return;
}
 
/*
功能：挂失账户
*/
void reportLoss()
{
    int id, who;
    int iPass;
    printf("账号：");
    scanf("%d", &id);
    who = search(id);  //根据账号查询用户，返回用户的下标
    if(who<0)   //说明id账户不存在
    {
        printf("该用户不存在，不能挂失！\n");
    }
    else
    {
        printf("户主姓名：%s\n", name[who]);
        printf("密码：");
        iPass=inputPassword();
        if(iPass!=user[who][1])
        {
            printf("输入密码错误，不能继续操作！\n");
        }
        else
        {
            if(user[who][2]==0)
            {
                user[who][2]=1;
                printf("挂失成功\n");
            }
            else if(user[who][2]==1)
            {
                printf("该账户已经处于挂失状态\n");
            }
            else
            {
                printf("该账户已销户，不能挂失\n");
            }
        }
    }
    return;
}
 
/*
功能：解除挂失
*/
void cancelLoss()
{
    int id, who;
    int iPass;
    printf("账号：");
    scanf("%d", &id);
    who = search(id);  //根据账号查询用户，返回用户的下标
    if(who<0)   //说明id账户不存在
    {
        printf("该用户不存在，解除挂失失败！\n");
    }
    else
    {
        printf("户主姓名：%s\n", name[who]);
        printf("密码：");
        iPass=inputPassword();
        if(iPass!=user[who][1])
        {
            printf("输入密码错误，不能继续操作！\n");
        }
        else
        {
            if(user[who][2]==0)
            {
                printf("该账户处于正常状态，不需要解除挂失\n");
            }
            else if(user[who][2]==1)
            {
                user[who][2]=0;
                printf("解除挂失成功\n");
            }
            else
            {
                printf("该账户已销户，操作无效\n");
            }
        }
    }
    return;
}
 
/*
功能：改密码
*/
void updatePassword()
{
    int id, who;
    int iPass, iPass1, iPass2;
    printf("账号：");
    scanf("%d", &id);
    who = search(id);  //根据账号查询用户，返回用户的下标
    if(who<0)   //说明id账户不存在
    {
        printf("该用户不存在，修改密码失败！\n");
    }
    else
    {
        printf("户主姓名：%s\n", name[who]);
        printf("密码：");
        iPass=inputPassword();
        if(iPass!=user[who][1])
        {
            printf("输入密码错误，不能继续操作！\n");
        }
        else
        {
            printf("新密码：");
            iPass1=inputPassword();  //输入密码1
            printf("确认密码：");
            iPass2=inputPassword();  //输入密码2
            if(iPass1==iPass2)
            {
                user[who][1]=iPass1;
                printf("修改成功！\n");
            }
            else
            {
                printf("两次输入不同，修改失败！\n");
            }
        }
    }
    return;
}
 
/*
功能：输入密码
返回值：整型的密码值
技术说明：
（1）此功能在多个模块中都要用到且功能单一，故分离出来，单独作业一个函数
（2）为了便于在输入中只显示*，接受输入时以字符形式输入，而后转为对应的整型数
（3）规定密码由不全为0的6位数字构成（当开头是'0'时，实际不足6位），一旦输入错误将重新输入
附：在实际的系统中，密码通常用字符串描述，即使只允许出现数字字符
*/
int inputPassword()
{
    char ch;  //接收字符形式密码
    int iPass=0;   //要转换为数字
    int i;
    while(1)
    {
        for(i=0; i<6; i++)
        {
            ch=getch();  //输入但不显示
            putchar('*');   //输出*
            if(isdigit(ch))
                iPass=iPass*10+(ch-'0');
            else
            {
                iPass=0;
                break;  //退出for循环后，再次接受
            }
        }
        fflush(stdin); //清除键盘缓存区中已经有的输入
        printf("\n");
        if(iPass==0)  //此条件成立可能由两种情况引起：输入了非数字字符被直接重置为0，或6位全0后正常退出for循环
        {
            printf("密码要求全为数字，且不能全0！\n");
            printf("请重新输入密码: ");
        }
        else
            break;
    }
    return iPass;
}
 
/*
功能：根据账号查询用户，返回用户的下标
入口参数：要查询用户的账号
返回值：如果该用户存在，返回该用户在数组中的下标，否则，返回一个负数（-1）
说明：
  由于不能保证在user数组中按账号有序，本模块不得不采用顺序查找，这是一个效率很低的算法
  如果在开户模块中保证了按账号有序，本函数可以选择更快的算法（见开户模块的说明）
*/
int search(int id)
{
    int index=-1;
    int i;
    for(i=0; i<N; i++)
    {
        if(user[i][0]==id)
        {
            index=i;
            break;   //找到了，立即退出循环
        }
    }
    return index; //若找到，其值在0~N-1间，否则，保持-1
}