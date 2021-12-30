#include <bits/stdc++.h>
using namespace std;
struct per
{
	char gen;
	string fa;
};
map<string,per>mp;
bool check(string a,string b)
{
	int i = 1;int j;
    for(string aa = a;!aa.empty();i++)
	{
        j = 1;
        for(string bb = b;!bb.empty();j++)
		{
            if(i >= 5 && j >= 5){return 1;}
			
            
            if((i < 5 || j < 5) && aa == bb){return 0;}
            
            bb = mp[bb].fa;
        }
        aa = mp[aa].fa;
    }
    return 1;
}
int main()
{
	int n;
	scanf("%d",&n);
	string fna,lna;
	for(int i=0;i<n;i++)
	{
		cin>>fna>>lna;
		if(lna.back()=='n'){mp[fna]={'m',lna.substr(0,lna.size()-4)};}
		else if(lna.back()=='r'){mp[fna]={'f',lna.substr(0,lna.size()-7)};}
		else{mp[fna].gen=lna.back();}
	}
    
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		string a,b,s;
		cin>>a>>s>>b>>s;
		if(mp.find(a)==mp.end()|| mp.find(b) == mp.end()){printf("NA\n");}
		else if(mp[a].gen == mp[b].gen){printf("Whatever\n");}
		else{printf("%s\n",check(a,b)? "Yes" : "No");}
	
	}
	return 0;
}
