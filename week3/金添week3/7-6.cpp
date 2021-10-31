#include <bits/stdc++.h>
using namespace std;
char ch[100];
char ans[100];
bool flag[1000] = {0};
void generate(int n);
int main()
{
	cin >> ch+1;
	int a=strlen(ch+1);
	sort(ch+1,ch+a+1);
	generate(1);
	return 0;
}
void generate(int n)
{
	int max = strlen(ch+1);
	if (n > max)
	{
		for (int i = 1; i <= max; i++)
		{
			cout << ans[i];
		}
		cout << endl;
		return;
	}
	else
	{
		for (int i = 1; i <= max; i++)
		{
			if (flag[ch[i]] == 0){
			
				ans[n] = ch[i];
			flag[ch[i]] = 1;
			generate(n + 1);
			flag[ch[i]] = 0;
		}
		}
	}
}
