#define snprintf _snprintf
using namespace std;
const long ASIZE  =   500000L;

long get_a_target_long();
int compareLongs(const void* a, const void* b);
string get_a_target_string();
int compareStrings(const void* a, const void* b);

long get_a_target_long()
{
long target=0;

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	return target;
}

int compareLongs(const void* a, const void* b)
{
  return ( *(long*)a - *(long*)b );
}

string get_a_target_string()
{
long target=0;
char buf[10];

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	snprintf(buf, 10, "%d", target);
	return string(buf);
}


int compareStrings(const void* a, const void* b)
{
  if ( *(string*)a > *(string*)b )
     	return 1;
  else if ( *(string*)a < *(string*)b )
     	return -1;  
  else      	
        return 0;  
}