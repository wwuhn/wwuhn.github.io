#include <iostream>
#include <vector>
using namespace std;
class Animal{
public:
	virtual void talk() = 0;
};
class Cat :public Animal{
public:
	virtual void talk(){cout<<"Miao\n";}
};
class Developer: public Animal{
public: 
	virtual void talk(){cout<<"Hello world\n";}
};
void LetAnimalTalk(Animal* pa){
	pa->talk(); 
}
int main(){
	Developer* pd = new Developer();
	Cat* pc = new Cat();
	LetAnimalTalk(pd);
	LetAnimalTalk(pc);
	vector<Animal*> va;
	va.push_back(pd);
	va.push_back(pc);
    system("pause");
	return 0;
}
/*
Hello world
Miao
*/