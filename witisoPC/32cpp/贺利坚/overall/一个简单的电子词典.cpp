/*

一个简单的电子词典。

　　在文件dictionary.txt中，保存的是英汉对照的一个词典，词汇量近8000个，
英文、中文释义与词性间用’\t’隔开。建一个表示词条的类Words，Words类的一个对象可以描述一个词，
类对象数组可以存储词库。将文件中的内容读到对象数组中，由用户输入英文词，显示中文释义。

　　提示：文件中的词汇已经排序，故在查找时，用二分查找法提高效率。

　　拓展1：允许用户运行程序后，连续地查词典，直到输入”0000”结束。

　　拓展2：试着做一个窗口版的电子词典。

　　拓展3：使这个词典，读入一篇文章，输出其中的所有名词（或动词，或全部实词）。——搜索引擎用类似的功能，并不是所有词都值得索引。

  */


#if 0

#include <fstream>
#include<iostream>
#include<string>
using namespace std;

//定义词类
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
    cout<<english<<'\t'<<word_class<<'\t'<<chinese<<endl<<endl;
}

int Word::compare(string k)
{
    return english.compare(k);
}

int BinSeareh(int low, int high, Word *w, string k);

int main( )
{
    Word words[8000]; //用于保存词库
    string e,c,wc;    
    string key;      //查询关键词
    int wordsNum=0;  //词库中词数
    
    //将文件中的数据读入到对象数组中
    ifstream infile("dictionary.txt",ios::in);  //以输入的方式打开文件
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
    
    //输入待查关键词并用二分查找法进行查询
    do
    {
        cout<<"请输入待查询的关键词（英文）："<<endl;
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
    system("pause");
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

#else

#include <iostream>
using namespace std;
#include <fstream>
#include <string>

class Word
{
public:
	void get_cixing(string cixing);
	void get_chinese(string english);
	void get_english(string chinese);
	friend void find_word(Word *t,string word);
	friend void input_word(Word *t);
	friend void output_word(Word *t);
 
private:
	string cixing;
	string english;
	string chinese;
};
void Word::get_cixing(string cixing)
{
	this->cixing = cixing;
}
void Word::get_chinese(string english)
{
	this->english = english;
}
void Word::get_english(string chinese)
{
	this->chinese = chinese;
}
void input_word(Word *t)
{
	string cixing;
	string english;
	string chinese;
	int i;
	ifstream inFile("dictionary.txt",ios::in);
	if(!inFile)
	{
		cerr<<"open error!"<<endl;
		exit(1);
	}
	for(i=0;i<8000;++i)
	{
		inFile>>chinese;
		t[i].get_chinese(chinese);
 
		inFile>>cixing;
		t[i].get_cixing(cixing);
 
		inFile>>english;
		t[i].get_english(english);
	}	
 
	inFile.close();
 
}
void output_word(Word *t)
{
	string cixing;
	string english;
	string chinese;
	ofstream outFile("dic.txt",ios::out);
	if(!outFile)
	{
		cerr<<"open dic.txt error!"<<endl;
		exit(1);
	}
	for(int i=0;i<8000;++i)
	{
		outFile<<t[i].chinese;
 
		outFile<<t[i].english;
 
		outFile<<t[i].cixing;
	}		
	outFile.close();
 
}
 
void find_word(Word *t,string word)
{	
	int  f=0;
	int  s=7999;
	int mid=(f+s)/2;
 
 
	while(f<s&&t[mid].english!=word)
	{
		if(t[mid].english<word) f=mid+1;
		if(t[mid].english>word) s=mid-1;
		mid=f+(s-f)/2;
		if(t[mid].english==word)
		{
			cout<<t[mid].chinese<<endl;
			cout<<t[mid].cixing<<endl;
		}	
 
	}
	if(t[mid].english!=word)
		cout<<"没有查到"<<endl;
}
int main()
{
	Word t[8000];
	input_word(t);
	string word;
	do{
		cin>>word;
		find_word(t,word);
	}while(word!="0000");
	output_word(t);
	system("pause");
	return 0;
}


#endif