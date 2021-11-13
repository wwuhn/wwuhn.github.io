#include <iostream>
#include "game.h"
using namespace std;

Role::Role(string nam, int b, Point l, Weapon w[], int n)
    :name(nam),blood(b),location(l),weaponNum(n),holdWeapon(NOWEAPON)
{
    if(blood>0)
        life=true;
    else
        life=false;
    for(int i=0; i<n; i++)
        weapons[i]=w[i];
}
Role::~Role()
{
    cout<<name<<"退出江湖..."<<endl;
}

//吃东西，涨d血(死了后吃上东西可以复活)
void Role::eat(int d) //吃东西，涨d血(死了也能吃，别人喂的，以使能复活)
{
    blood+=d;
    if(blood>0)
        life=true;
}

//攻击别人，自己涨血，同时对方被攻击失血，血量取决于当前用的武器
//在武器的攻击范围内才可以攻击
void Role::attack(Role &r)
{
    if(isAlived()&&holdWeapon>NOWEAPON&&weapons[holdWeapon].getKillRange()>this->distance(r)) //活着且在杀伤范围内
    {
        blood+=weapons[holdWeapon].getForce();
        r.beAttack(weapons[holdWeapon].getForce());
    }
}

//被别人攻击，参数f是承受的攻击力
void Role::beAttack(int f)
{
    blood-=f;
    if(blood<=0)
        life=false;
}

//返回与另一角色的距离
double Role::distance(Role &r)
{
    return location.distance(r.location);
}
//换手中的武器
void Role::changeWeapon(int wno)
{
    if(wno<weaponNum)
        holdWeapon=wno;
}
//是否活着
bool Role::isAlived()
{
    return life;
}
//移到另外一点
void Role::moveTo(int x, int y)
{
    if(isAlived())  //死了就不能动了
        location.moveTo(x,y);
}
//从当前位置移动
void Role::move(int dx, int dy)
{
    if(isAlived())
        location.move(dx,dy);
}
//显示
void Role::show()
{
    cout<<name<<" has "<<blood<<" blood, hold ";
    if(holdWeapon==NOWEAPON)
        cout<<"no weapon";
    else
        cout<<weapons[holdWeapon].getWname();
    cout<<"(";
    for(int i=0; i<weaponNum; i++)
        cout<<weapons[i].getWname()<<",";
    cout<<"\b)";
    cout<<". He is in ("<<location.getX()<<", "<<location.getY()<<") and ";
    if(isAlived())
        cout<<"alived.";
    else
        cout<<"dead.";
    cout<<endl;
}
//角色名称和初始血量
void Role::setBaseInfo(string nam, int b)
{
    name=nam;
    blood=b;
    if(blood>0)
        life=true;
}
//设置位置
void Role::setLocation(int x,int y)
{
    location.moveTo(x,y);
}
//添一件武器
void Role::addWeapon(Weapon w)
{
    if(weaponNum<N)
    {
        weapons[weaponNum]=w;
        weaponNum++;
    }
}

//返回名称
string Role::getName()
{
    return name;
}

    int Role::getWeaponNum()
    {
        return weaponNum;
    }
string Role::getCurWeapon()
{
    return weapons[holdWeapon].getWname();
}
