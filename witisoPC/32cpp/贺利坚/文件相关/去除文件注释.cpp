/*
编写C++程序，读comments.txt，去除其中所有的注释，并保存到文件nocomments.txt中。
  文件：
 ask patches [set pcolor green ]
; check　GRASS? switch.
; if it istrue, then grass grows and the sheep eat it. if it false, then the sheep don'tneed to eat
  if grass? [
    ask patches[
      setcountdown random grass-regrowth-time ; initialize grass grow clocks randomly
      set pcolorone-of [green brown]
    ]
  ]
*/
#if 0

//符合任务的最低要求的程序：去除注释，如果注释单独占一行，保留空行；
#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
	ifstream sourceFile;
	ofstream targetFile;
	char ch[100];
	int i;
	sourceFile.open("comments.txt", ios::in);
	targetFile.open("nocomments.txt", ios::out);
	while (!sourceFile.eof())
	{	
		sourceFile.getline(ch,100,'\n');
		i=0;
		while(ch[i]!='\0' && ch[i]!=';')
		{
			targetFile.put(ch[i]);
			++i;
		}
		targetFile.put('\n');
	}
	sourceFile.close();
	targetFile.close();
	cout << "Finish!" << endl;
	system("pause");
	return 0;
}

#else

//符合任务的较高要求的程序：当注释单独占一行时，去除注释后，空行将不再保留。
#include <iostream>
#include <fstream>
using namespace std;
bool isCommentLine(char[]);
int main() 
{
	ifstream sourceFile;
	ofstream targetFile;
	char ch[100];
	int i;
	sourceFile.open("WolfSheep.nls", ios::in);
	targetFile.open("WS_nocomment.nls", ios::out);
	while (!sourceFile.eof())
	{	
		sourceFile.getline(ch,100,'\n');
		if(!isCommentLine(ch))   //如果是独立的注释行，该行将不再写入目标文件
		{
			i=0;
			while(ch[i]!='\0' && ch[i]!=';')
			{
				targetFile.put(ch[i]);
				++i;
			}
			targetFile.put('\n');
		}
	}
	sourceFile.close();
	targetFile.close();
	cout << "Finish!" << endl;
	system("pause");
	return 0;
}
 
bool isCommentLine(char line[]) //判断是否为独立的注释行
{
	int i=0;
	bool is = false;
	char c=line[i];
	while(c!='\0' && c!=';' && (c==' ' || c=='\t'))
	{
		c=line[++i];
	}
	if (c==';') is=true;
	return is;
}


#endif
/*

*/