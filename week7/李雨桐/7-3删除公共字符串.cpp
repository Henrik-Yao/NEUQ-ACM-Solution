#include<bits/stdc++.h>
using namespace std;
string a, b;
int visit[300]={0};
void shanchu()
{
	int len_a = a.size();
	for (int i=0;i<len_a;i++)
	{
		if (visit[a[i]] == 0)
            cout<<a[i];
	}
	cout << endl;
}
int main()
{
	while (getline(cin, a))
	{
		getline(cin, b);
		int len_b = b.size();

		for (int i=0;i<len_b;i++)
			visit[b[i]] = 1;

		shanchu();
		memset(visit,0,sizeof(visit));

	}
	return 0;
}
