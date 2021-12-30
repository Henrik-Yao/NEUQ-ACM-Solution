#include<bits/stdc++.h>
using namespace std;
typedef pair <int,int> pir;
pir a[1005];

unordered_map <int,int> mp;
int main()
{
	int n,val;
    int cnt=0,ans=0;
	cin >> n;
	for(int i=0;i<n;i++)
    {
		cin>>val;
		mp[val]++;
	}

	for(auto iter = mp.begin();iter != mp.end();iter++)
	{
		cnt++;
		if(mp.count(iter->first+1))
		ans += mp[iter->first+1];
	}

	cout<<ans<<endl;

    return 0;
}

