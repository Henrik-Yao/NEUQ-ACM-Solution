#include<iostream>
#include<map>//y1s1map感觉像python里面的字典
using namespace std;
int n;
map<string, string> dic;

int hashh(string a) 
{
	int ls[1000001], a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	int ca = a.length();
	for (int i = 0; i < ca; i++)
	{
		if (a[i] >= '0' && a[i] <= '9') ls[i] = a[i] - '0';
		if (a[i] >= 'a' && a[i] <= 'z') ls[i] = a[i] - 'a' + 10;
		if (a[i] >= 'A' && a[i] <= 'Z') ls[i] = a[i] - 'A' + 10;
	}
	int l[4], m = ca % 4;//分段
	for (int i = 0, j = m; i < 4; i++, j--) 
	{
		if (j > 0) l[i] = ca / 4 + 1;
		else l[i] = ca / 4;
		if (i) l[i] += l[i - 1];
	}
	for (int i = 0; i < l[0]; i++) a1 += ls[i]; a1 %= 36;
	for (int i = l[0]; i < l[1]; i++) a2 += ls[i]; a2 %= 36;
	for (int i = l[1]; i < l[2]; i++) a3 += ls[i]; a3 %= 36;
	for (int i = l[2]; i < l[3]; i++) a4 += ls[i]; a4 %= 36;
	return ((a1 * 36 + a2) * 36 + a3) * 36 + a4;
}

int main() 
{
	cin >> n;
	for(int j=0;j<n;j++)
	{
		char cz;
		string na, ma;
		cin >> cz >> na >> ma;
		if (cz == 'R') 
		{
			if (dic[na] == "") //该用户不存在
			{
				dic[na] = ma;
				cout << "Signed!" << endl;
			}
			else cout << "Repeated!" << endl;
		}
		else 
		{
			if (dic[na] == ma) cout << "Success!" << endl;
			else 
			{
				int ysmm = hashh(dic[na]);//预设密码hash值
				int srmm = hashh(ma);//输入密码hash值
				if (srmm == ysmm) cout << "Attention!" << endl;
				else cout << "Failed!" << endl;
			}
		}
	}
}