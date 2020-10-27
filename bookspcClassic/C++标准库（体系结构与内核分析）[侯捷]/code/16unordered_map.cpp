#include <unordered_map>
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

namespace jj16
{
    void test_unordered_map(long& value)
    {
        cout << "\ntest_unordered_map().......... \n";
        
        unordered_map<long, string> c;  	
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
        cout << "unordered_map.size()= " << c.size() << endl;	//357913941
        cout << "unordered_map.max_size()= " << c.max_size() << endl;	
        
        long target = get_a_target_long();		
        timeStart = clock();	
        //! auto pItem = find(c.begin(), c.end(), target);	//map ²»ßmÓÃ std::find() 			
        auto pItem = c.find(target);
        
        cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
        if (pItem != c.end())
            cout << "found, value=" << (*pItem).second << endl;
        else
            cout << "not found! " << endl;		
    }															 
}

int main()
{
    long value=100000;
    jj16::test_unordered_map(value);
    cout<<1<<endl;
    while(1);
    return 0;
}

/*

  test_unordered_map().......... 
  milli-seconds : 92371
  unordered_map.size()= 100000
  unordered_map.max_size()= 768614336404564650
  target (0~2147483647): 1235
  c.find(), milli-seconds : 11
  found, value=359147515
  1
*/