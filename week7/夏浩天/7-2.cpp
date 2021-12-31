#include <iostream>
using namespace std;
int len, en;
int cd[100000];
string a, lsz[100000];
int main() 
{
	cin >> a;
	len = a.length();//原字符串长度
	lsz[0] = "";//处理后字符串
	for (int i = 0; i < len; ) 
	{
		if (a[i] == '[') 
		{
			en++;
			lsz[en] = "";
			i++;
			for (cd[en] = 0; a[i]<='9'&&a[i]>='0'; i++)
				cd[en] = cd[en] * 10 + a[i] - 48;
		}
		else if (a[i] == ']') 
		{
			for (int j = 1; j <= cd[en];j++) 
				lsz[en - 1] += lsz[en];
			en--;
			i++;
		}
		else 
		{
			lsz[en] += a[i];
			i++;
		}
	}
	cout << lsz[0];
	return 0;
}