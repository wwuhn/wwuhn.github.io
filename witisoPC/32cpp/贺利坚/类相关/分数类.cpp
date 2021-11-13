#include<iostream>  // 分数类
#include<Cmath>
using namespace std;
enum OutStyle{original, simplified, mixed, approximate};
int gcd(int m, int n);
class CFraction
{
private:
    int nume;  // 分子
    int deno;  // 分母
public:
    CFraction(int nu=0,int de=1);   //构造函数，初始化用
    void set(int nu=0,int de=1);    //置值，改变值时用
    void input();				    //按照"nu/de"的格式，如"5/2"的形式输入
    void simplify();			    //化简（使分子分母没有公因子）
    void amplify(int n);			//放大n倍，如/3放大倍为/3
    void output(OutStyle style=original);	
};

CFraction::CFraction(int nu,int de) //构造函数，初始化用
{
    if (de!=0)
    {
        nume=nu;
        deno=de;
    }
    else
    {
        cerr<<"初始化中发生错误，程序退出\n";
        system("pause");
        exit(0);
    }
}

void CFraction::set(int nu,int de)    //置值，改变值时用
{
    if (de!=0) //如果不合适，改变值操作无效
    {
        nume=nu;
        deno=de;
    }
}

void CFraction::input()				//按照"nu/de"的格式，如"5/2"的形式输入
{
    int nu,de;
    char c;
    while(1)
    {
        cout<<"输入分数(m/n): ";
        cin>>nu>>c>>de;
        if(c!='/')
            cout<<"输入格式错误！\n ";
        else if (de==0)
            cout<<"分母不能为零！\n ";
        else
            break;
    }	
    nume=nu;
    deno=de;
}

// 分数化简，使分子分母没有公因子
void CFraction::simplify()
{
    int n=gcd(deno, nume);
    deno/=n;     // 化简
    nume/=n;
}

// 求m，n的最大公约数
int gcd2(int m, int n)
{
    while(n!=0)  // 求m，n的最大公约数
    {
        int r = m%n;
        m=n;
        n=r;
    }
    return m;
}
// 求m，n的最大公约数
int gcd(int m, int n)
{
    int r;
    //if (m<n){r=m;m=n;n=r;}
    while(r=m%n)  // 求m，n的最大公约数
    {
        m=n;
        n=r;
    }
    return n;
}
void CFraction::amplify(int n)  //放大n倍，如/3放大倍为/3
{
    nume*=n;
}

//输出分数：以8/6为例
//style为original时，原样输出：8/6；
//style为simplified时，输出化简的形式：4/3；
//style为mixed时，用带分数形式输出：1(1/3)，表示一又三分之一；
//style为approximate时，输出用实数表示的似近值：1.33333
//不给出参数时，默认方式为original
void CFraction::output(OutStyle style)
{
    int n,nu,de;
    switch(style)
    {
    case original:
        cout<<"原样:" <<nume<<'/'<<deno<<endl; 
        break;
    case simplified:
        n=gcd(deno, nume);
        cout<<"化简形式: "<<nume/n<<'/'<<deno/n<<endl;     //输出化简形式，并不是要化简
        break;
    case mixed:
        n=gcd(deno, nume);
        nu=nume/n; 
        de=deno/n;
        cout<<"带分数形式:" <<nu/de<<'('<<nu%de<<'/'<<de<<')'<<endl; 
        break;
    case approximate:
        cout<<"近似值:" <<nume/double(deno)<<endl; 
        break;
    default:
        cout<<"默认原样:" <<nume<<'/'<<deno<<endl;	
    }
}

int main()
{
    CFraction c1,c2(8,6);
    
    cout<<"关于c1: "<<endl;
    c1.output(original);
    
    cout<<"改变c1: "<<endl;
    c1.set(2,7);
    c1.output();
    
    cout<<"输入c1: "<<endl;
    c1.input();
    c1.output(original);
 c1.output(simplified);   
     c1.output(original);
    cout<<"关于c2: "<<endl;
    c2.output(original);
    c2.output(simplified); 
    c2.output(mixed); 
    c2.output(approximate);
    
    cout<<"将c2化简: "<<endl;
    c2.simplify();
    c2.output(original);
    
    cout<<"将c2放大倍: "<<endl;
    c2.amplify(5);
    c2.output(original);
    c2.output(mixed); 
    
    system("pause");
    return 0;
}

/*

任务2拓展2（思考）：这个思考题吊一下大家的胃口：设定义了两个分数类的对象，
如CFraction c1, c2。如果定义了int i，我们能用cin>>i;在键盘上输入i的值，
是否期望用cin>>c1>>c2;输入分数呢？同理，用cout<<c1<<c2;进行输出，可以吗？
进一步，用c1+c2得到新的一个分数，用c1/c2实现两个分数的除法，以及其他加、减、比较、
求倒数等也是理所当然的。实际上，要自定义分数类，这些直观的基本运算应该要实现，
这叫运算符的重载。本任务中用amplify()给出了“放大”运算的一种实现方案，更多内容值得期待地。




*/















