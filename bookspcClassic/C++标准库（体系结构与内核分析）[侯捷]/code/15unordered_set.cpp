#include <iostream>
#include <unordered_set>
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

namespace jj15
{
void test_unordered_set(long& value)
{
	cout << "\ntest_unordered_set().......... \n";
     
unordered_set<string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
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
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "unordered_set.size()= " << c.size() << endl;	
	cout << "unordered_set.max_size()= " << c.max_size() << endl;  //357913941
	cout << "unordered_set.bucket_count()= " << c.bucket_count() << endl;	
	cout << "unordered_set.load_factor()= " << c.load_factor() << endl;	
	cout << "unordered_set.max_load_factor()= " << c.max_load_factor() << endl;	
	cout << "unordered_set.max_bucket_count()= " << c.max_bucket_count() << endl;			
  	for (unsigned i=0; i< 20; ++i) {
    	cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
  	}			
	
string target = get_a_target_string();	
	{
    timeStart = clock();
auto pItem = find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}
 
 	{
    timeStart = clock();		
auto pItem = c.find(target);		//比 std::find(...) 快很多							
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}	
}															 
}


int main()
{
    long value=100000;
    jj15::test_unordered_set(value);
    cout<< 1 <<endl;

    while(1);
    return 0;
}
/*

test_unordered_set().......... 
milli-seconds : 126953
unordered_set.size()= 99980
unordered_set.max_size()= 768614336404564650
unordered_set.bucket_count()= 107897
unordered_set.load_factor()= 0.926624
unordered_set.max_load_factor()= 1
unordered_set.max_bucket_count()= 768614336404564650
bucket #0 has 2 elements.
bucket #1 has 0 elements.
bucket #2 has 0 elements.
bucket #3 has 0 elements.
bucket #4 has 0 elements.
bucket #5 has 3 elements.
bucket #6 has 1 elements.
bucket #7 has 0 elements.
bucket #8 has 2 elements.
bucket #9 has 2 elements.
bucket #10 has 2 elements.
bucket #11 has 0 elements.
bucket #12 has 1 elements.
bucket #13 has 2 elements.
bucket #14 has 0 elements.
bucket #15 has 2 elements.
bucket #16 has 1 elements.
bucket #17 has 0 elements.
bucket #18 has 2 elements.
bucket #19 has 0 elements.
target (0~2147483647): 256
std::find(), milli-seconds : 13354
not found! 
c.find(), milli-seconds : 2
not found! 
1

*/