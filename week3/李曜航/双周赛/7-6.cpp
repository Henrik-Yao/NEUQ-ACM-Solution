#include <bits/stdc++.h>
using namespace std;
string n;
char a[20];
char cp[100000][15];
int len;
int cnt;
void dfs(int step,char save[],bool vis[])
{
	if(step==len)
	{
		cout<<save<<endl;	
		return;
	}
	for(int i=0;i<len;i++)
	{
		if(vis[i]==0)
		{
			save[step] = a[i];
			vis[i] = true;
			dfs(step+1,save,vis);
			save[step] = 0;
			vis[i] = false;
		}
	}	
}
int main()
{
	// freopen("r.out","w",stdout);
	cin>>n;
//	n = "aabcsdeg";
	len = n.length();
	for(int i=0;i<len;i++)
		a[i] = n[i];
	sort(a,a+len);
	// cout<<a;
	
	// cout<<a<<endl<<endl;
	char save[20] = {0};
	bool vis[20] = {false};
	for(int i=0;i<len;i++)
	{
		vis[i] = true;
		save[0] = a[i];
		dfs(1,save,vis);
		vis[i] = false;
		save[0] = 0;
	}
    return 0;
}

