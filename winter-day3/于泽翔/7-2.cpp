#include<bits/stdc++.h>
using namespace std;
map<int,map<int,int> > M;

int main(void)
{
    int n, e, k, a, z, w;
    cin>>n>>e;
    for(int i=0;i<e;i++)
	{
        cin>>a>>z>>w;
        M[a][z]=w;
    }
    cin>>k;
    while(k--)
    {
    	cin>>a>>z;
        M[a].erase(z);
	}
    for(auto i:M)
	{
        int a=i.first;
        string s="";
        for(auto j:i.second)
            s+="(" + to_string(a) + "," + to_string(j.first) + "," + to_string(j.second) + ")";
        if(s!="")
		cout<<a<<":"<<s<<endl;
    }
    return 0;
}