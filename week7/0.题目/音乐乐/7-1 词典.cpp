#include<bits/stdc++.h>
using namespace std;
int mod=1e8+7;
int base=13331;
int arr[100000010];
int n,m;
map<int,string>mp;


int main()
{
	cin>>n>>m;
	int i,j;
	while(n--)
	{
		//cout<<"1"<<endl;
		string word,key;
		cin>>word>>key;
		int ha=0;
		for(i=0;i<key.size();i++)
		{
			ha=(1ll*ha*base%mod+key[i]-'a'+1+mod)%mod;
		}
		arr[ha]++;
		mp.insert(pair<int,string>(ha,word));
	}
	while(m--)
	{
		//cout<<"2"<<endl;
		string s;
		cin>>s;
		int hashh=0;
		for(i=0;i<s.size();i++)
		{
			hashh=(1ll*hashh*base%mod+s[i]-'a'+1+mod)%mod;
		}
		if(arr[hashh])
		cout<<mp[hashh]<<endl;
		else
		cout<<"eh"<<endl;
	}
	return 0;
}
