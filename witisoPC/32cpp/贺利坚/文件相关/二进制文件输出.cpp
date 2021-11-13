#include<iostream>
#include<iomanip>
#include <fstream>
#include<cstdlib>
using namespace std;
 
int main( )
{
    char c[16];
    char f[100];
    cout<<"请输入文件名：";
    cin>>f;
    ifstream infile(f,ios::in|ios::binary);
    if(!infile)
    {
        cerr<<"open error!";
        exit(1);
    }
    while(!infile.eof())
    {
        infile.read(c,16);
        if(!infile.eof())
        {
            for(int i=0; i<16; ++i)
                cout<<setfill('0')<<setw(2)<<hex<<int((unsigned char)(c[i]))<<" ";
            cout<<'\t';
            for(i=0; i<16; ++i)
                cout<<(c[i]?c[i]:'.');
            cout<<endl;
        }
    }
    while(1);
    return 0;
}