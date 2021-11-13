// 角色装备武器

/*
仅设计了一个非常简单的使用武器的规则
当攻击对方时，自己涨血数等于自己武器的威力，同时对方失去等量血
对方失血变为0或负后，死去
欢迎游戏者，按你的想像扩充
*/
#include <iostream>
using namespace std;
class Weapon
{
public:
    Weapon(string wnam, int f);
    int getForce();
private:
    string wname;   //名称
    int force;       //威力
};
Weapon::Weapon(string wnam, int f):wname(wnam),force(f) {}
int Weapon::getForce()
{
    return force;
}
class Role
{
public:
    Role(string nam, int b, string wnam, int f); //构造函数
    ~Role(); //析构函数
    void eat(int d); //吃东西，涨d血
    void attack(Role &r); //攻击别人，自己涨血，同时失血
    bool isAlived(); //是否活着
    void show(); //显示
private:
    string name;
    int blood;
    Weapon weapon;
    bool life;
};
Role::Role(string nam, int b, string wnam, int f):name(nam),blood(b),weapon(wnam,f)
{
    if(blood>0)
        life=true;
    else
        life=false;
}
Role::~Role()
{
    cout<<name<<"退出江湖..."<<endl;
}
void Role::eat(int d) //吃东西，涨d血
{
    if(isAlived())
        blood+=d;
}
void Role::attack(Role &r) //攻击别人，涨1血
{
    if(isAlived())
    {
        blood+=weapon.getForce();
        r.blood-=weapon.getForce();
        if(r.blood<=0)
            r.life=false;
    }
}

bool Role::isAlived() //是否活着
{
    return life;
}

void Role::show() //显示
{
    cout<<name<<" has "<<blood<<" blood, it is ";
    if(isAlived())
        cout<<"alived.";
    else
        cout<<"dead.";
    cout<<endl;
}
int main( )
{
    Role mary("Mary", 500, "TuLong",200);
    Role jack("Jack", 10, "YiTian", 180);
    cout<<"---begin---"<<endl;
    mary.show();
    jack.show();
    cout<<"---1st round---"<<endl;
    jack.attack(mary);
    mary.show();
    jack.show();
    cout<<"---2nd round---"<<endl;
    mary.attack(jack);
    mary.show();
    jack.show();
    cout<<"---end---"<<endl;
    return 0;
}