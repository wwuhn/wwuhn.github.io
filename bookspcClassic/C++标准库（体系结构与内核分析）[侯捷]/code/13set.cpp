#include <iostream>
#include <set>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
#include <algorithm>
using namespace std;

string get_a_target_string()
{
    long target=0;
    char buf[10];
    
    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
    snprintf(buf, 10, "%d", (int)target);
    return string(buf);
}

namespace jj13
{
    void test_set(long& value)
    {
        cout << "\ntest_set().......... \n";
        
        set<string> c;  	
        char buf[10];
        
        clock_t timeStart= clock();								
        for(long i=0; i< value; ++i)
        {
            try {
                snprintf(buf, 10, "%d", rand());
                c.insert(string(buf));     					
            }
            catch(exception& p) {
                cout << "i=" << i << " " << p.what() << endl;	
                abort();
            }
        }
        cout << "milli-seconds: " << (clock()-timeStart) << endl;		
        cout << "set.size()= " << c.size() << endl;
        cout << "set.max_size()= " << c.max_size() << endl;	   //214748364
        
        string target= get_a_target_string();	
        {
            timeStart= clock();
            auto pItem= find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多	
            cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
            if (pItem != c.end())
                cout << "found, " << *pItem << endl;
            else
                cout << "not found! " << endl;	
        }
        
        {
            timeStart= clock();		
            auto pItem= c.find(target);		//比 std::find(...) 快很多							
            cout << "c.find(), milli-seconds: " << (clock()-timeStart) << endl;		 
            if (pItem != c.end())
                cout << "found, " << *pItem << endl;
            else
                cout << "not found! " << endl;	
        }							
    }															 
}


int main()
{
    long value;
    jj13::test_set(value);
    cout<<1<<endl;
    
    while(1);
    return 0;
}
/*

  test_set().......... 
  milli-seconds: 3
  set.size()= 0
  set.max_size()= 461168601842738790
  target (0~2147483647): 1235
  std::find(), milli-seconds : 7
  not found! 
  c.find(), milli-seconds: 1
  not found! 
  1
  
*/

