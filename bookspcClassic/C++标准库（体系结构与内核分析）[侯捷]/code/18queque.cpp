//---------------------------------------------------
#include <queue>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
#include <vector>
#include <set>
#include <list>

#define snprintf _snprintf
using namespace std;
namespace jj18
{
void test_queue(long& value)
{
	cout << "\ntest_queue().......... \n";
     
queue<string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.push(string(buf));    			 		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "queue.size()= " << c.size() << endl;
	cout << "queue.front()= " << c.front() << endl;	
	cout << "queue.back()= " << c.back() << endl;		
	c.pop();
	cout << "queue.size()= " << c.size() << endl;
	cout << "queue.front()= " << c.front() << endl;	
	cout << "queue.back()= " << c.back() << endl;	
	
	
	{
queue<string, list<string> > c;		//以 list 為底層 
    for(long i=0; i< 10; ++i) {
    		snprintf(buf, 10, "%d", rand());
        	c.push(string(buf));    			 		
	}
	cout << "queue.size()= " << c.size() << endl;
	cout << "queue.front()= " << c.front() << endl;	
	cout << "queue.back()= " << c.back() << endl;		
	c.pop();
	cout << "queue.size()= " << c.size() << endl;
	cout << "queue.front()= " << c.front() << endl;	
	cout << "queue.back()= " << c.back() << endl;	
    }	
	
	{
queue<string, vector<string> > c;	//以 vector 為底層 
    for(long i=0; i< 10; ++i) {
    		snprintf(buf, 10, "%d", rand());
        	c.push(string(buf));    			 		
	}
	cout << "queue.size()= " << c.size() << endl;
	cout << "queue.front()= " << c.front() << endl;	
	cout << "queue.back()= " << c.back() << endl;		
	//!c.pop();  //[Error] 'class std::vector<std::basic_string<char> >' has no member named 'pop_front'
	cout << "queue.size()= " << c.size() << endl;
	cout << "queue.front()= " << c.front() << endl;	
	cout << "queue.back()= " << c.back() << endl;	
    }	

	{
//queue<string, set<string> > c;		//以 set 為底層 
/*!
    for(long i=0; i< 10; ++i) {
    		snprintf(buf, 10, "%d", rand());
        	c.push(string(buf));    			 		
	}
	cout << "queue.size()= " << c.size() << endl;
	cout << "queue.front()= " << c.front() << endl;	
	cout << "queue.back()= " << c.back() << endl;		
	c.pop();
	cout << "queue.size()= " << c.size() << endl;
	cout << "queue.front()= " << c.front() << endl;	
	cout << "queue.back()= " << c.back() << endl;
//[Error] 'class std::set<std::basic_string<char> >' has no member named 'push_back'
//[Error] 'class std::set<std::basic_string<char> >' has no member named 'front'
//[Error] 'class std::set<std::basic_string<char> >' has no member named 'pop_front'
*/		
    }
    
//! queue<string, map<string>> c5;	//以 map 為底層, [Error] template argument 2 is invalid
//! queue<string>::iterator ite1;  	//[Error] 'iterator' is not a member of 'std::queue<std::basic_string<char> >'	
}															
}


int main()
{
    long value = 300000;
    jj18::test_queue(value);
    printf("finished");

    while(1);
    return 0;
}
/*

test_queue()..........
milli-seconds : 1134
queue.size()= 300000
queue.front()= 41
queue.back()= 25087
queue.size()= 299999
queue.front()= 18467
queue.back()= 25087
queue.size()= 10
queue.front()= 20051
queue.back()= 8271
queue.size()= 9
queue.front()= 1834
queue.back()= 8271
queue.size()= 10
queue.front()= 6258
queue.back()= 31310
queue.size()= 10
queue.front()= 6258
queue.back()= 31310
finished
*/