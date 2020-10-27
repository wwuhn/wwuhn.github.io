#include <ext\slist>
	//注意, 上一行並沒有引發警告訊息如 #include <ext\hash_set> 所引發者： 
	//...\4.9.2\include\c++\backward\backward_warning.h	
	//[Warning] ...
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
using namespace std;

namespace jj10
{
    void test_slist(long& value)
    {
        cout << "\ntest_slist().......... \n";
        
        __gnu_cxx::slist<string> c;  	
        char buf[10];
        
        clock_t timeStart = clock();								
        for(long i=0; i< value; ++i)
        {
            try {
                snprintf(buf, 10, "%d", rand());
                c.push_front(string(buf));     		
            }
            catch(exception& p) {
                cout << "i=" << i << " " << p.what() << endl;	
                abort();
            }
        }
        cout << "milli-seconds : " << (clock()-timeStart) << endl;			
    }															
}


int main()
{
    long value = 1000000;
    jj10::test_slist(value);
    
    
    while(1);
    return 0;
}
/*

*/