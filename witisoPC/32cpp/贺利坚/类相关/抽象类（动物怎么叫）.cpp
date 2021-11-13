#include "iostream" // 抽象类（动物怎么叫）
#include<string>
using namespace std;

class Animal
{
protected:
    string name; //类族中的数据成员放在这儿
public:
    Animal(string nam):name(nam){} //基类的构造函数
    virtual void cry()=0;
};

class Mouse : public Animal
{
public:
    Mouse(string nam):Animal(nam){}  //派生类的构造函数要这样写
    virtual void cry() {cout<<"我叫"<<name<<"，是一只老鼠，我的叫声是：吱吱吱！"<<endl;}
};

class Cat : public Animal
{
public:
    Cat(string nam):Animal(nam){}
    virtual void cry() {cout<<"我叫"<<name<<"，是一只猫，我的叫声是：喵喵喵！"<<endl;}
};

class Dog : public Animal
{
public:
    Dog(string nam):Animal(nam){}
    virtual void cry() {cout<<"我叫"<<name<<"，是一条狗，我的叫声是：汪汪汪！"<<endl;}
};

class Giraffe : public Animal
{
public:
    Giraffe(string nam):Animal(nam){}
    virtual void cry() {cout<<"我叫"<<name<<"，是长颈鹿，我的脖子太长，发不出声音来！"<<endl;}
};

int main( )
{
    Animal *p;
    //p = newAnimal(); p->cry();       //抽象类不能实例化对象了！！！
    Mouse m("Jerry");  p=&m; p->cry(); //输出: 我叫Jerry，是一只老鼠，我的叫声是：吱吱吱！
    Cat c("Tom");      p=&c; p->cry(); //输出: 我叫Tom，是一只猫，我的叫声是：喵喵喵！
    Dog d("Droopy");   p=&d; p->cry(); //输出: 我叫Droopy，是一条狗，我的叫声是：汪汪汪！
    Giraffe g("Gill"); p=&g; p->cry(); //输出: 我叫Gill，是长颈鹿，我的脖子太长，发不出声音来！
    system("pause");
    return 0;
}