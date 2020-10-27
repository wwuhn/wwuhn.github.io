#include <forward_list>
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

namespace jj04
{
    void test_forward_list(long& value)
    {
        cout << "\ntest_forward_list().......... \n";
        
        forward_list<string> c;  	
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
        cout << "forward_list.max_size()= " << c.max_size() << endl;  //536870911
        cout << "forward_list.front()= " << c.front() << endl;	
        
        
        string target = get_a_target_string();	
        timeStart = clock();			
        auto pItem = find(c.begin(), c.end(), target);	
        cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
        
        if (pItem != c.end())
            cout << "found, " << *pItem << endl;
        else
            cout << "not found! " << endl;	
        
        timeStart = clock();		
        c.sort();						
        cout << "c.sort(), milli-seconds : " << (clock()-timeStart) << endl;		
        
        c.clear();	 
    }											 
}


int main()
{
    long value = 1000000;
    jj04::test_forward_list(value);
    
    while(1);
    return 0;
}
/*

test_forward_list().......... 
milli-seconds : 705918
forward_list.max_size()= 1152921504606846975
forward_list.front()= 429357853
target (0~2147483647): 13456
std::find(), milli-seconds : 45235
not found! 
c.sort(), milli-seconds : 3900342

*/