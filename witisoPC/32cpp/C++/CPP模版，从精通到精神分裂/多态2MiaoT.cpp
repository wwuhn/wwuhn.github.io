#include <iostream>
#include <vector>
using namespace std;
template< typename T>
class Animal{
 public:
	 T id_;
	 Animal(T t){id_ = t;};
	 virtual void talk() = 0;
};
template<typename T>
class Cat :public Animal<T>{
 public:
	 Cat(T t):Animal<T>(t){};
	 virtual void talk(){cout<<"Miao, I am "<<Animal<T>::id_ <<"\n";}
};
template<typename T>
class Developer: public Animal<T>{
 public: 
	 Developer(T t):Animal<T>(t){};
	 virtual void talk()
	 {
		 cout<<"Hello world, I am "<<Animal<T>::id_ <<"\n";}
};
template<typename T>
void LetAnimalTalk(Animal<T>* pa){
	pa->talk(); 
}
int main()
{
	Developer<string>* pd = new Developer<string>("Yan");
	Cat<string>* pc = new Cat<string>("Fluffy");
	LetAnimalTalk(pd);
	LetAnimalTalk(pc);
	vector<Animal<string>*> va;
	va.push_back(pd);
	va.push_back(pc);

    system("pause");
	return 0;
}

/* vc6 no ,cpp.sh ok
Hello world, I am Yan
Miao, I am Fluffy
*/