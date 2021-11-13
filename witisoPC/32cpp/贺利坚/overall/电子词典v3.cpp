#include <fstream>
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

//定义词条类
class Word
{
public:
    void set(string e, string c, string wc);
    int compare(string);  //英语部分与给定字符串比较，等于返回，大于返回，小于返回-1
    string getChinese();
    string getWord_class();
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

int Word::compare(string k)
{
    return english.compare(k);
}

string Word::getChinese()
{
    return chinese;
}

string Word::getWord_class()
{
    return word_class;
}

//定义字典类
class Dictionary
{
public:
    Dictionary();
    void searchWord(string k);
private:
    int BinSeareh(int low, int high, string k);
    int wordsNum;
    Word words[8000]; //用于保存词库
};

Dictionary::Dictionary()
{
    string e,c,wc;
    wordsNum=0;
    //将文件中的数据读入到对象数组中
    ifstream infile("dictionary1.txt",ios::in);  //以输入的方式打开文件
    if(!infile)       //测试是否成功打开
    {
        cerr<<"dictionary open error!"<<endl;
        exit(1);
    }
    while (!infile.eof())
    {
        infile>>e>>c>>wc;
        words[wordsNum].set(e, c, wc);
        ++wordsNum;
    }
    infile.close();
}

int Dictionary::BinSeareh(int low, int high, string key)
{
    int mid;
    while(low<=high)
    {
        mid=(low + high) / 2;
        if(words[mid].compare(key)==0)
        {
            return mid; //查找成功返回
        }
        if(words[mid].compare(key)>0)
            high=mid-1; //继续在w[low..mid-1]中查找
        else
            low=mid+1; //继续在w[mid+1..high]中查找
    }
    return -1; //当low>high时表示查找区间为空，查找失败
}

void Dictionary::searchWord(string key)
{
    int low=0,high=wordsNum-1;  //置当前查找区间上、下界的初值
    int index=BinSeareh(low, high, key);
    if(index>=0)
        cout<<key<<"--->"<<words[index].getWord_class()+"\t"<<words[index].getChinese();
    else
        cout<<"查无此词";
    cout<<endl<<endl;
}

int main( )
{
    Dictionary dict;
    string key;
    
    do
    {
        cout<<"请输入待查询的关键词（英文）,0000结束："<<endl;
        cin>>key;
        if (key!="0000")
        {
            dict.searchWord(key);
        }
    }
    while(key!="0000");
    cout<<"欢迎再次使用！"<<endl<<endl;
    while(1);
    return 0;
}