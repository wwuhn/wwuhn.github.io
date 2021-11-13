#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <string>
using namespace std;
const int N=5;          //每个角色最多拥有的武器
const int M=30;         //游戏人物的最大数
const int NOWEAPON=-1;  //表示手中无武器
const int SIZE=100;     //将从文件是读取武器信息，最多100种武器

class Point     //Point类声明
{
public:         //外部接口
    Point(int x=0, int y=0);
    int getX();
    int getY();
    double distance(const Point &p);//返回与另外一点p之间的距离
    void moveTo(int x, int y);      //移到另外一点
    void move(int dx, int dy);      //从当前位置移动
private:
    int x, y;  //座标
};

class Weapon
{
public:
    Weapon(){};
    Weapon(string wnam, int f, double k);
    Weapon(const Weapon&);
    string getWname();
    int getForce();         //返回杀伤力
    double getKillRange();  //返回杀伤距离
    void setWeapon(string,int,double);
private:
    string wname;       //名称
    int force;          //杀伤力
    double killRange;   //杀伤距离
};

class Role
{
public:
    Role():weaponNum(0),holdWeapon(NOWEAPON){};
    Role(string nam, int b, Point l, Weapon w[], int n); //构造函数
    ~Role(); //析构函数
    void eat(int d);            //吃东西，涨d血(死了后吃上东西可以复活)
    void attack(Role &r);       //攻击别人，自己涨血，同时对方被攻击失血。血量取决于当前用的武器
    void beAttack(int f);       //被别人攻击，参数f是承受的攻击力
    double distance(Role &r);   //返回与另一角色的距离
    bool isAlived();            //是否活着
    void moveTo(int x, int y);  //移到另外一点
    void move(int dx, int dy);  //从当前位置移动
    void changeWeapon(int wno); //换手中的武器
    void show();                //显示
    void setBaseInfo(string, int);  //角色名称和初始血量
    void setLocation(int,int);      //设置位置
    void addWeapon(Weapon);         //添一件武器
    string getName();
    int getWeaponNum();
    string getCurWeapon();
private:
    string name;    //角色名称
    int blood;      //当前血量
    bool life;      //是否活着
    Point location;  //位置
    Weapon weapons[N];  //武器
    int weaponNum;      //武器数目
    int holdWeapon;     //现在手持哪一件武器(空手为NOWEAPON，初始时空手)
};

#endif // GAME_H_INCLUDED
