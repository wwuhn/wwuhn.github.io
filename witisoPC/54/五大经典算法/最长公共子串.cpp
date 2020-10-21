#include<iostream>
#include<vector>
#include<string>
 
using namespace std;
 
int main() {
	int len1, len2;// 两个字符串的长度
	int i, j;      // 辅助变量
	string str1, str2;
	//getline(cin, str1);
	//getline(cin, str2);
	str1 = "taabcdefghi";
	str2 = "sabcdeffhia";
	len1 = str1.length();
	len2 = str2.length();
	vector<vector<int> >dp(len1, vector<int>(len2));
	// dp[i][j]表示必须以str1[i]和str2[j]结尾的公共子串的最大长度，
	// 也就是str1[i]必须等于str2[j]
	
	for (i = 0; i < len1; ++i) //计算公共子串的长度
	{
		if (str1[i] == str2[0])
			dp[i][0] = 1;
		else
			dp[i][0] = 0;
	}
	for (j = 0; j < len2; ++j) {
		if (str2[j] == str1[0])
			dp[0][j] = 1;
		else
			dp[0][j] = 0;
	}
	for (i = 1; i < len1; ++i) {
		for (j = 1; j < len2; ++j) {
			if (str1[i] != str2[j]) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}
	// 得出公共子串的最大长度，并且记录位置
	int pos, val = 0;
	for (i = 0; i < len1; ++i) {
		for (j = 0; j < len2; ++j) {
			if (val < dp[i][j]) {
				pos = i;
				val = dp[i][j];
			}
		}
	}
	// 输出结果
	for (i = pos - val + 1; i <= pos; ++i) {
		cout << str1[i]; // abcdef
	}
	cout << endl;

    getchar();
}