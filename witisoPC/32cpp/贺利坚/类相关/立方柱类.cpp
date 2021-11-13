#include <iostream>
using namespace std; // 立方柱类
class Bulk
{
public:
    void get_value();
    void display();
private:
    void get_volume();  //用于内部计算的，作为私有函数有利于信息隐藏
    void get_area();
    float lengh;
    float width;
    float height;
    float volume;
    float area;
};

void Bulk::get_value()
{ 
    cout<<"please input lengh, width, height:";
    cin>>lengh;
    cin>>width;
    cin>>height;
    get_volume();  //长宽高获得值以后即可以计算，也可以在display中输出前计算，但综合而言，此处更佳
    get_area();
}

void Bulk::get_volume()
{
    volume=lengh*width*height;
}

void Bulk::get_area()
{
    area=2*(lengh*width+lengh*height+width*height);
}

void Bulk::display()
{ 
    //get_volume()和get_area()也可以在此处调用，本例中计算工作在长宽高确定后立刻进行	
    cout<<"The volume is: "<<volume<<endl;
    cout<<"The surface area is: "<<area<<endl;
}

int main()
{
    Bulk b1,b2,b3;
    
    b1.get_value();
    cout<<"For bulk1: "<<endl;
    b1.display();
    
    b2.get_value();
    cout<<"For bulk2: "<<endl;
    b2.display();
    
    b3.get_value();
    cout<<"For bulk3: "<<endl;
    b3.display();
    return 0;
}