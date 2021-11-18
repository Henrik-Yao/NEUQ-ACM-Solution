#include <bits/stdc++.h>
using namespace std;
map <string,bool> used;
map <string,int> hashs;
map <string,string> pass;
int n;
char type;
int txt[205];
string user,password;

void init()
{
	for (char i = '0';i <= '9'; i++)
		txt[i - 0] = i - '0';
	for (char i = 'a';i <= 'z'; i++)
	{
		txt[i - 0] = i - 'a' + 10;
	}
	for (char i = 'A';i <= 'Z'; i++)
	{
		txt[i - 0] = i - 'A' + 10;
	}
	return;
}
int calc(string s)
{
	int ans = 0;
	int block[4],num[4];
	int t = (int)s.size() / 4;
	int k = (int)s.size() % 4;
	for (int i = 0;i < 4; i++)
	{
		if (k > 0)
		{
			block[i] = t + 1;
			k--;
		} else block[i] = t;
	}
	
	memset(num,0,sizeof(num));
	int sum = -1;
	for (int i = 0;i < 4; i++)
	{
	//	cout << sum + 1 << " " << sum + block[i] << endl;
		for (int j = sum + 1;j <= sum + block[i]; j++)
		{
			num[i] = (num[i] + txt[s[j] - 0]) % 36;
		}
		sum += block[i];
	}
	for (int i = 0;i < 4; i++)
	{
		ans += pow(36,3 - i) * num[i];
	}
	return ans;
}
int main()
{
	init();
	cin >> n;
	for (int i = 1;i <= n; i++)
	{
		cin >> type >> user >> password;
		if (type == 'L')
		{
			if (!used[user]) 
			{
				cout << "Failed!" << endl;
				continue;
			}
			if (pass[user] == password)
			{
				cout << "Success!" << endl;
				continue;
			}
			
			if (hashs[user] == calc(password))
			{
				cout << "Attention!" << endl;
			} else {
				cout << "Failed!" << endl;
			}
		} else {
			if (used[user]) cout << "Repeated!" << endl;
			else {
				used[user] = true;
				hashs[user] = calc(password);
				pass[user] = password;
				cout << "Signed!" << endl;
			}
		}
	}
	
}

