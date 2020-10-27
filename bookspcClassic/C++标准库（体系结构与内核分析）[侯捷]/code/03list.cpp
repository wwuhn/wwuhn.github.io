#include <list>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <algorithm> //find()
#include <iostream>
#include <ctime> 
#include <string.h> // memcpy()
using namespace std;

//以下 MyString 是為了測試 containers with moveable elements 效果.  
class MyString { 
public: 
    static size_t DCtor;  	//累計 default-ctor 的呼叫次數 
    static size_t Ctor;  	//累計 ctor      的呼叫次數 
    static size_t CCtor;  	//累計 copy-ctor 的呼叫次數 
    static size_t CAsgn;  	//累計 copy-asgn 的呼叫次數 
    static size_t MCtor;  	//累計 move-ctor 的呼叫次數 
    static size_t MAsgn;  	//累計 move-asgn 的呼叫次數 		    
    static size_t Dtor;	//累計 dtor 的呼叫次數 
private:     
    char* _data; 
    size_t _len; 
    void _init_data(const char *s) { 
        _data = new char[_len+1]; 
        memcpy(_data, s, _len); 
        _data[_len] = '\0'; 
    } 
public: 
    //default ctor
    MyString() : _data(NULL), _len(0) { ++DCtor;  }
    
    //ctor
    MyString(const char* p) : _len(strlen(p)) { 
        ++Ctor; 
        _init_data(p); 
    } 
    
    // copy ctor
    MyString(const MyString& str) : _len(str._len) { 
        ++CCtor;  	  
        _init_data(str._data); 	//COPY
    } 
    
    //move ctor, with "noexcept"
    MyString(MyString&& str) noexcept : _data(str._data), _len(str._len)  {  
        ++MCtor;    
        str._len = 0; 		
        str._data = NULL;  	//避免 delete (in dtor) 
    }
    
    //copy assignment
    MyString& operator=(const MyString& str) { 
        ++CAsgn;  	 
        if (this != &str) { 
            if (_data) delete _data;  
            _len = str._len; 
            _init_data(str._data); 	//COPY! 
        } 
        else {
            // Self Assignment, Nothing to do.   
        }
        return *this; 
    } 
    
    //move assignment
   	MyString& operator=(MyString&& str) noexcept { 	 
        ++MAsgn;   	
        if (this != &str) { 
            if (_data) delete _data; 
            _len = str._len; 
            _data = str._data;	//MOVE!
            str._len = 0; 
            str._data = NULL; 	//避免 deleted in dtor 
        } 
        return *this; 
    }
    
    //dtor
    virtual ~MyString() { 	
        ++Dtor;	      	  	    
        if (_data) {
            delete _data; 	
        }
    }   	
    
    bool 
        operator<(const MyString& rhs) const	//為了讓 set 比較大小  
    {
        return std::string(this->_data) < std::string(rhs._data); 	//借用事實：string 已能比較大小. 
    }
    bool 
        operator==(const MyString& rhs) const	//為了讓 set 判斷相等. 
    {
        return std::string(this->_data) == std::string(rhs._data); 	//借用事實：string 已能判斷相等. 
    }	
    
    char* get() const { return _data; }
}; 
size_t MyString::DCtor=0;  	
size_t MyString::Ctor=0;  	 
size_t MyString::CCtor=0;
size_t MyString::CAsgn=0;
size_t MyString::MCtor=0;
size_t MyString::MAsgn=0;
size_t MyString::Dtor=0;

namespace std 	//必須放在 std 內 
{
    template<> 
        struct hash<MyString> 	//這是為了 unordered containers 
    {
        size_t 
            operator()(const MyString& s) const noexcept
        {  return hash<string>()(string(s.get()));  }  
        //借用現有的 hash<string> (in ...\include\c++\bits\basic_string.h)
    };
}
//-----------------
//以下 MyStrNoMove 是為了測試 containers with no-moveable elements 效果.  
class MyStrNoMove { 
public: 
    static size_t DCtor;  	//累計 default-ctor 的呼叫次數 
    static size_t Ctor;  	//累計 ctor      的呼叫次數 
    static size_t CCtor;  	//累計 copy-ctor 的呼叫次數 
    static size_t CAsgn;  	//累計 copy-asgn 的呼叫次數 
    static size_t MCtor;  	//累計 move-ctor 的呼叫次數 
    static size_t MAsgn;  	//累計 move-asgn 的呼叫次數 		    
    static size_t Dtor;	    //累計 dtor 的呼叫次數 
private:     
    char* _data; 
    size_t _len; 
    void _init_data(const char *s) { 
        _data = new char[_len+1]; 
        memcpy(_data, s, _len); 
        _data[_len] = '\0'; 
    } 
public: 
    //default ctor
    MyStrNoMove() : _data(NULL), _len(0) { 	++DCtor; _init_data("jjhou"); }
    
    //ctor
    MyStrNoMove(const char* p) : _len(strlen(p)) { 
        ++Ctor;  _init_data(p); 
    } 
    
    // copy ctor
    MyStrNoMove(const MyStrNoMove& str) : _len(str._len) { 
        ++CCtor;  	 
        _init_data(str._data); 	//COPY
    } 
    
    //copy assignment
    MyStrNoMove& operator=(const MyStrNoMove& str) { 
        ++CAsgn;
        
        if (this != &str) { 
            if (_data) delete _data;  
            _len = str._len; 
            _init_data(str._data); 	//COPY! 
        } 
        else {
            // Self Assignment, Nothing to do.   
        }
        return *this; 
    } 
    
    //dtor
    virtual ~MyStrNoMove() { 	   
        ++Dtor;		  	    
        if (_data) {
            delete _data; 	
        }
    }   	
    
    bool 											
        operator<(const MyStrNoMove& rhs) const		//為了讓 set 比較大小 
    {
        return string(this->_data) < string(rhs._data);  //借用事實：string 已能比較大小. 
    }  	
    
    bool 											
        operator==(const MyStrNoMove& rhs) const	//為了讓 set 判斷相等. 
    {
        return string(this->_data) == string(rhs._data);  //借用事實：string 已能判斷相等. 
    } 
    
    char* get() const { return _data; }	
}; 
size_t MyStrNoMove::DCtor=0;  	
size_t MyStrNoMove::Ctor=0;  
size_t MyStrNoMove::CCtor=0;
size_t MyStrNoMove::CAsgn=0;
size_t MyStrNoMove::MCtor=0;
size_t MyStrNoMove::MAsgn=0;
size_t MyStrNoMove::Dtor=0;

namespace std 	//必須放在 std 內 
{
    template<> 
        struct hash<MyStrNoMove> 	//這是為了 unordered containers 
    {
        size_t 
            operator()(const MyStrNoMove& s) const noexcept
        {  return hash<string>()(string(s.get()));  }  
        //借用現有的 hash<string> (in ...\4.9.2\include\c++\bits\basic_string.h)
    };
}

#include <typeinfo>  //typeid()
template<typename T>
void output_static_data(const T& myStr)
{
	cout << typeid(myStr).name() << " -- " << endl; 
	cout << " CCtor=" << T::CCtor 	
		 << " MCtor=" << T::MCtor 
	     << " CAsgn=" << T::CAsgn 		 
		 << " MAsgn=" << T::MAsgn 
		 << " Dtor="  << T::Dtor 
		 << " Ctor="  << T::Ctor 
		 << " DCtor=" << T::DCtor 		 
		 << endl;	
}

#include <ctime>  //clock_t, clock()
template<typename M, typename NM>	
void test_moveable(M c1, NM c2, long& value)
{ 	
char buf[10];
			
	//測試 move 
	cout << "\n\ntest, with moveable elements" << endl;			
	typedef typename iterator_traits<typename M::iterator>::value_type  V1type; 	
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	snprintf(buf, 10, "%d", rand());    		
        auto ite = c1.end();
        c1.insert(ite, V1type(buf));	
	}
	cout << "construction, milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "size()= " << c1.size() << endl;		
	output_static_data(*(c1.begin()));

	timeStart = clock();	
M c11(c1);						
	cout << "copy, milli-seconds : " << (clock()-timeStart) << endl;	

	timeStart = clock();	
M c12(std::move(c1));						
	cout << "move copy, milli-seconds : " << (clock()-timeStart) << endl;
		
	timeStart = clock();	
	c11.swap(c12);						
	cout << "swap, milli-seconds : " << (clock()-timeStart) << endl;		

	
	
	//測試 non-moveable 	
	cout << "\n\ntest, with non-moveable elements" << endl;		
	typedef typename iterator_traits<typename NM::iterator>::value_type  V2type; 				
    timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	snprintf(buf, 10, "%d", rand());    		
        auto ite = c2.end();
        c2.insert(ite, V2type(buf));	
	}

	cout << "construction, milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "size()= " << c2.size() << endl;			
	output_static_data(*(c2.begin()));

	timeStart = clock();	
NM c21(c2);						
	cout << "copy, milli-seconds : " << (clock()-timeStart) << endl;	

	timeStart = clock();	
NM c22(std::move(c2));						
	cout << "move copy, milli-seconds : " << (clock()-timeStart) << endl;
		
	timeStart = clock();	
	c21.swap(c22);						
	cout << "swap, milli-seconds : " << (clock()-timeStart) << endl;			
}	

string get_a_target_string()
{
long target=0;
char buf[10];

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	snprintf(buf,10, "%d", (int)target);
	return string(buf);
}



namespace jj03
{
    void test_list(long& value)
    {
        cout << "\ntest_list().......... \n";
        
        list<string> c;  	
        char buf[10];
        
        clock_t timeStart = clock();							
        for(long i=0; i< value; ++i)
        {
            try {
                sprintf(buf, "%d", rand());
                c.push_back(string(buf));    	
            }
            catch(exception& p) {
                cout << "i=" << i << " " << p.what() << endl;	
                abort();
            }
        }
        cout << "milli-seconds : " << (clock()-timeStart) << endl;		
        cout << "list.size()= " << c.size() << endl;
        cout << "list.max_size()= " << c.max_size() << endl;    //357913941
        cout << "list.front()= " << c.front() << endl;	
        cout << "list.back()= " << c.back() << endl;		
        
        string target = get_a_target_string();		
        timeStart = clock();
        //list<string>::iterator pItem;
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
        test_moveable(list<MyString>(),list<MyStrNoMove>(), value);								
    }	
}

int main()
{
    long int value = 1000000;
    jj03::test_list(value);

    
    while(1);
    return 0;
}
/*

test_list().......... 
milli-seconds : 416599
list.size()= 1000000
list.max_size()= 768614336404564650
list.front()= 1804289383
list.back()= 429357853
target (0~2147483647): 23456
std::find(), milli-seconds : 33408
not found! 
c.sort(), milli-seconds : 3452044


test, with moveable elements
construction, milli-seconds : 632259
size()= 1000000
8MyString -- 
 CCtor=0 MCtor=1000000 CAsgn=0 MAsgn=0 Dtor=1000000 Ctor=1000000 DCtor=0
copy, milli-seconds : 567239
move copy, milli-seconds : 2
swap, milli-seconds : 2


test, with non-moveable elements
construction, milli-seconds : 514488
size()= 1000000
11MyStrNoMove -- 
 CCtor=1000000 MCtor=0 CAsgn=0 MAsgn=0 Dtor=1000000 Ctor=1000000 DCtor=0
copy, milli-seconds : 262302
move copy, milli-seconds : 2
swap, milli-seconds : 1
*/
