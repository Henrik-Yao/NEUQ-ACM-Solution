#include<iostream>
#include<string.h>
#include<string>
using namespace std;
char t[1000005], s[1000005];
int lent,lens;
int next1[1000005], cnt = 0;
void get_next(int nexta[])
{
	int i = 0, j = -1;
	nexta[0] = -1;
	while (i < lens)
	{
		if (j == -1 || s[i] == s[j])
		{
			i++, j++;
			nexta[i] = j;
		}
		else
		{
			j = nexta[j];
		}
	}
}
void Index_KMP(int pos)
{
	int i = pos, j = 0;
	while (i < lent)
	{
		if (j == -1 || t[i] == s[j])
		{
			//cout << "i:" << i << " j:" << j << endl;
			i++, j++;
		}
		else
			j = next1[j];
		if (j == lens)
		{
			//cout <<endl<< "before   i:" << i << " j:" << j << endl;
			//cout << "after    i:" << i << " j:" << j << endl<<endl;
			cnt++;
		} 
	}
	
}
int main()
{
	int i;
	cin >> t >> s;
    lent=strlen(t),lens=strlen(s);
	//cout << lent << " " << lens << endl;
	get_next(next1);
	//for (i = 1; i <= lens; i++)
	//	cout << next1[i] << " ";
	//cout << endl;
	Index_KMP(0);
	cout << cnt << endl;
	return 0;
}
