#include <iostream>
using namespace std;
template<typename T>
//整数或浮点数皆可使用
void bubble_sort(T arr[], int len)
{
    int i, j;  T temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
        if (arr[j] > arr[j + 1])
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
}
int main()
{
    int arr[] = { 61, 17, 29, 22, 34, 60, 72 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
 
    cout << endl;
 
    float arrf[] = { 17.5, 19.1, 0.6, 1.9, 10.5 };
    len = (int) sizeof(arrf) / sizeof(*arrf);
    bubble_sort(arrf, len);
    for (i = 0; i < len; i++)
        cout << arrf[i] << ' ';
	cin.get();
    return 0;
}
/*output:
17 22 29 34 60 61 72
0.6 1.9 10.5 17.5 19.1
*/