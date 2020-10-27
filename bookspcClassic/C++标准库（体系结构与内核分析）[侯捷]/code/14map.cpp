#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
using namespace std;

long get_a_target_long()
{
    long target=0;
    
    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
    return target;
}

namespace jj14
{
    void test_map(long& value)
    {
        cout << "\ntest_map().......... \n";
        
        map<long, string> c;  	
        char buf[10];
        
        clock_t timeStart = clock();								
        for(long i=0; i< value; ++i)
        {
            try {
                snprintf(buf, 10, "%d", rand());
                c[i] = string(buf);  					
            }
            catch(exception& p) {
                cout << "i=" << i << " " << p.what() << endl;	
                abort();
            }
        }
        cout << "milli-seconds : " << (clock()-timeStart) << endl;	
        cout << "map.size()= " << c.size() << endl;	
        cout << "map.max_size()= " << c.max_size() << endl;		//178956970
        
        long target = get_a_target_long();		
        timeStart = clock();		
        auto pItem = c.find(target);								
        cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
        if (pItem != c.end())
            cout << "found, value=" << (*pItem).second << endl;
        else
            cout << "not found! " << endl;			
        
        c.clear();					
    }															 
}


int main()
{
    long value = 10000;
    jj14::test_map(value);
    cout<< 1 <<endl;
    
    while(1);
    return 0;
}
/*

  test_map().......... 
  milli-seconds : 19240
  map.size()= 10000
  map.max_size()= 384307168202282325
  target (0~2147483647): 1235
  c.find(), milli-seconds : 12
  found, value=359147515
  1
  
*/