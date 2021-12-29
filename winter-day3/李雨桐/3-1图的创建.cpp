#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pir;
map<int, int> Map[20005];

int n,e;
int a,b,c;

int main()
{

	cin>>n>>e;
	for(int i=0;i<e;i++)
    {
		cin>>a>>b>>c;
		Map[a].insert(pir(b, c));
	}
	for(int i=0;i<n;i++)
	{
		bool flag = false;
		for(auto it : Map[i])
		{
			if(flag==0)
			cout << i << ":";
			flag = true;
			cout<<"("<<i<<","<<it.first<<","<<it.second<<")";
		}
		if(flag==1)
		cout << endl;
	}
}
