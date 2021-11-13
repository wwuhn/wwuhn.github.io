#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "game.h"
using namespace std;
/*
（1）对象数组，自动生成了很多个“玩家”（角色类的对象），自动玩；（2）使用文件：武器要
从文件中读，玩的过程，写入到了文件。
不足（待改进之处）：（1）产生随机数时，没有避免重复，以致于会有自己攻击自己的情况——
好在加了血又减去了，没有变化，还有同样的武器会有多件——都是棍，但带两条棍，也行；（2
）只是让自动产生的角色玩起来了，自己没有参与，其实，指定对象数组中第0个对象就是自己（
随机选取动作者时，随机数最小为1），加个菜单，选择动作，即可。
*/
void initializeRoles(Role roles[]);     //初始化角色，由计算机随机产生
int readWeaponInfo(Weapon WeaponBase[]);//从文件中读取武器信息
int randBetween(int low, int high);     //产生一定范围内的随机数
void play(Role roles[], int n);

//主函数
int main( )
{
    srand(time(0));
    Role roles[M];
    initializeRoles(roles);
    play(roles, 1000);
    while(1);
    return 0;
}

//初始化角色
void initializeRoles(Role roles[])
{
    Weapon weaponBase[SIZE];                    //存储系统中可以用到的武器库数组
    int weaponNum = readWeaponInfo(weaponBase); //从文件中读取武器信息到武器库数组，并返回武器种类数
    char cno[5];            //人物序号
    int wn;                 //要加的武器数
    int wno;                //要加入的武器的编号(weaponBase中的下标)
    for(int i=0; i<M; i++)  //产生M个角色对象，即游戏中的人物
    {
        itoa(i,cno,10);
        roles[i].setBaseInfo(string("Soldier")+cno,randBetween(10, 100));
        roles[i].setLocation(randBetween(0,1000),randBetween(0, 1000));
        wn=randBetween(1,N);
        for(int j=0; j<wn; j++) //添加wn件武器
        {
            wno=randBetween(0,weaponNum);
            roles[i].addWeapon(weaponBase[wno]);
        }
        roles[i].changeWeapon(randBetween(0,wn));//当前持什么武器
    }
}

//初始化武器库
int readWeaponInfo(Weapon WeaponBase[])
{
    ifstream infile("weapon.txt",ios::in);
    int n=0;
    string wn;
    int wf;
    double wr; //分别代表武器名、杀伤力、杀伤范围
    if(!infile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    while(infile>>wn>>wf>>wr)
    {
        WeaponBase[n++].setWeapon(wn,wf,wr);
    }
    infile.close();
    return n;
}
//产生一定大于等于low，小于high范围内的随机数
int randBetween(int low, int high)
{
    return low+rand()%(high-low);
}

//玩n轮游戏，每一轮有一个角色行动
//行动可以是攻击、移动、换武器、吃
//所有的结果，保存到log.txt文件中
void play(Role roles[], int n)
{
    int i;
    int rno,rno2; //选中的游戏者
    int action; //行动0-攻击，1-移动，2-换武器，3-吃东西
    int newx, newy, newWeapon, eatd;
    ofstream outfile("log.txt",ios::out);  //创建输出流对象
    if(!outfile)                    //如果打开失败，outfile返回0值
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }

    cout<<"开始前...."<<endl;
    for(i=0; i<M; i++)
        roles[i].show();
    cout<<"开始游戏，请到日志文件中看过程...."<<endl<<endl;
    for(i=0; i<n; i++)
    {
        rno=randBetween(0,M);
        outfile<<"第"<<i<<"轮: "<<roles[rno].getName();
        action=randBetween(0,4);
        switch(action)
        {
        case 0: //攻击
            rno2=randBetween(0,M);
            outfile<<"攻击"<<roles[rno2].getName();
            roles[rno].attack(roles[rno2]);
            break;
        case 1: //移动
            newx=randBetween(0,1000);
            newy=randBetween(0, 1000);
            outfile<<"移动到("<<newx<<","<<newy<<")";
            roles[rno].moveTo(newx,newy);
            break;
        case 2: //换武器
            newWeapon=randBetween(0,roles[rno].getWeaponNum());
            roles[rno].changeWeapon(newWeapon);
            outfile<<"将武器换为: "<<roles[rno].getCurWeapon();
            break;
        case 3: //吃
            eatd=randBetween(0,100);
            roles[rno].eat(eatd);
            outfile<<"吃了: "<<eatd;
            break;
        }
        outfile<<". "<<endl;
    }
    outfile<<endl;
            outfile.close();
    cout<<"游戏结束后...."<<endl;
    for(i=0; i<M; i++)
        roles[i].show();

}


