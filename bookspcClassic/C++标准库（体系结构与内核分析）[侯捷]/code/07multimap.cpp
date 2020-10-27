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

namespace jj07
{
    void test_multimap(long& value)
    {
        cout << "\ntest_multimap().......... \n";
        
        multimap<long, string> c;  	
        char buf[10];
        
        clock_t timeStart = clock();								
        for(long i=0; i< value; ++i)
        {
            try {
                snprintf(buf, 10, "%d", rand());
                //multimap 不可使用 [] 做 insertion 
                c.insert(pair<long,string>(i,buf));   						
            }
            catch(exception& p) {
                cout << "i=" << i << " " << p.what() << endl;	
                abort();
            }
        }
        cout << "milli-seconds : " << (clock()-timeStart) << endl;	
        cout << "multimap.size()= " << c.size() << endl;
        cout << "multimap.max_size()= " << c.max_size() << endl;	//178956970	
        
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
    long value = 100000;
    jj07::test_multimap(value);

    printf("finished");
    while(1);
    return 0;
}
/*

test_multimap().......... 
milli-seconds : 185345
multimap.size()= 100000
multimap.max_size()= 384307168202282325
target (0~2147483647): 1235
c.find(), milli-seconds : 8
found, value=359147515
*/