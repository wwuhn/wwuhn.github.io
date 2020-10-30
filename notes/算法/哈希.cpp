#if 0 // 标准库的映射字典

#include <iostream>
#include <map>  // 红黑树映射，映射也叫字典，不是哈希映射
#include <string>
using namespace std;

int main()
{
	map<string,int> m;
	m["bill"] = 98;
	m["Tom"] = 67;
	m["Mary"] = 100;
	// ……
	cout<< m["Tom"] <<endl;
    system("pause");
	return 0;
}
#endif

#if 0 // 自定义线性映射
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename Key, typename Value>
class LinearMap
{
public:
	LinearMap(int size=101) : arr(size)
	{
		currentSize = 0;
	}
	void Put(const Key& k, const Value& v)
	{
		arr[currentSize] = DataEntry(k,v);
		++currentSize;
	}
	Value Get(const Key& k)
	{
		for(size_t i=0; i<currentSize; ++i)
		{
			if(arr[i].key == k)
				return arr[i].value;
		}
		return Value();
	}
private:
	struct DataEntry{
		Key key;
		Value value;
		DataEntry(const Key& k = Key(),
			const Value& v = Value()):
		key(k),value(v){}
	};
	std::vector<DataEntry> arr;
	int currentSize;
};
int main()
{
	
	LinearMap<string, int> lm;
	lm.Put("Bill",99);
	lm.Put("Tom",88);
	lm.Put("Mary",77);
	cout<<lm.Get("Tom")<<endl;
    system("pause");
	return 0;
}

#else  // 自定义哈希映射

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename Key, typename Value>
class HashMap // 将字符串通过哈希函数映射为数据下标
{
public:
	HashMap(int size=101) : arr(size)
	{
		currentSize = 0;
	}
	void Put(const Key& k, const Value& v)
	{
		int pos = myhash(k);
		arr[pos] = DataEntry(k,v);
		++currentSize;
	}
	Value Get(const Key& k)
	{
		int pos = myhash(k);
		if(arr[pos].key == k)
			return arr[pos].value;
		else
			return Value();
	}

	unsigned hash(const Key& k) const
	{
		unsigned int hashVal = 0;
		//const char* keyp = reinterpret_cast<const char*>(&k);
		for(size_t i=0; i<sizeof(k); i++)
			hashVal = 37 * hashVal + k[i];
		return hashVal;
	}
	int myhash(const Key& k) const
	{
		unsigned hashVal = hash(k);
		hashVal %= arr.size();
		return hashVal;
	}
private:
	struct DataEntry{
		Key key;
		Value value;
		DataEntry(const Key& k = Key(),
			const Value& v = Value()):
		key(k),value(v){}
	};
	vector<DataEntry> arr;
	int currentSize;
};
int main()
{

	HashMap<string, int> hm;
	cout<<hm.hash("wwu")<<endl;
	cout<<hm.myhash("wwu")<<endl;
	hm.Put("Bill",99);
	hm.Put("Tom",88);
	hm.Put("wwu",66);
	hm.Put("Mary",77);
	cout<<hm.Get("wwu")<<endl;
    system("pause");
	return 0;
}
#endif