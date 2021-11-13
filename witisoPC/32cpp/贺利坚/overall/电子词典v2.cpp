#include <fstream>
#include<iostream> // 电子词典v2
#include<string>
#include<cstdlib>
using namespace std;

//
class Word
{
public:
    void set(string e, string c, string wc);
    int compare(string);  //英语部分与给定字符串比较，等于返回，大于返回，小于返回-1
    void display();
private:
    string english;
    string chinese;
    string word_class;
};

void Word::set(string e, string c, string wc)
{
    english=e;
    chinese=c;
    word_class=wc;
}

void Word::display()
{
    cout<<'\n'<<english<<'\t'<<word_class<<'\t'<<chinese<<endl<<endl;
}

int Word::compare(string k)
{
    return english.compare(k);
}

int BinSeareh(int low, int high, Word *w, string k);

int main( )
{
    Word words[800]; //用于保存词库
    string e,c,wc;
    string key;      //查询关键词
    int wordsNum=0;  //词库中词数
    
    //将文件中的数据读入到对象数组中
    ifstream infile("dict.txt",ios::in);  //以输入的方式打开文件
    if(!infile)       //测试是否成功打开
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    while (!infile.eof())
    {
        infile>>e>>c>>wc;
        words[wordsNum].set(e, c, wc);
        ++wordsNum;
    }
    for(int i=0;i<wordsNum;i++)
    {
        words[i].display();
    }
    //输入待查关键词并用二分查找法进行查询
    do
    {
        cout<<"提示：文件需要排序，一行三个字符串，以空格分隔，可以用Excel处理一下。\n"<<endl;
        cout<<"请输入待查询的关键词（英文）,0000结束："<<endl;
        cin>>key;
        if (key!="0000")
        {
            int low=0,high=wordsNum-1;  //置当前查找区间上、下界的初值
            int index=BinSeareh(low, high, words, key);
            if (index == -1)
                cout<<"查无此词！"<<endl<<endl;
            else
                words[index].display();
        }
    }
    while(key!="0000");
    cout<<"欢迎再次使用！"<<endl<<endl;
    return 0;
}

int BinSeareh(int low, int high, Word *w, string k)
{
    int mid;
    while(low<=high)
    {
        mid=(low + high) / 2;
        if(w[mid].compare(k)==0)
        {
            return mid; //查找成功返回
        }
        if(w[mid].compare(k)>0)
            high=mid-1; //继续在w[low..mid-1]中查找
        else
            low=mid+1; //继续在w[mid+1..high]中查找
    }
    return -1; //当low>high时表示查找区间为空，查找失败
}