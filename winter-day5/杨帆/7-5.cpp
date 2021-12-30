#include<bits/stdc++.h>
using namespace std;

struct node{
	int sex;
	string f;
};

map<string,node>map_;
int check(string s1,string s2);

int main()
{
	int n,t;
	string s1,s11,s2,s22;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		int len=s2.size();
		if(s2[len-1]=='f')
		map_[s1].sex=2;
		else if(s2[len-1]=='m')
		map_[s1].sex=1;
		else if(s2[len-1]=='n')
		{
			map_[s1].sex=1;
			string temp=s2.substr(0,len-4);
			map_[s1].f=temp;
		}
		else if(s2[len-1]=='r')
		{
			map_[s1].sex=2;
			string temp=s2.substr(0,len-7);
			map_[s1].f=temp;
		}
	}
	cin>>t;
	while(t--)
	{
		cin>>s1>>s11>>s2>>s22;
		if(map_.find(s1)==map_.end()||map_.find(s2)==map_.end())
		{
			cout << "NA" << endl; 
		}
		else if(map_[s1].sex==map_[s2].sex)
		{
			cout << "Whatever" << endl;
		}
		else 
		{
			if(check(s1,s2)){
                cout << "Yes" << endl;
            }
			else{
                cout << "No" << endl;
            }
		}
	} 
	return 0;
 } 

int check(string s1,string s2){
	int fa=1,fb=1;
	for(string sa=s1;!sa.empty();sa=map_[sa].f,fa++)
	{
		fb=1;
		for(string sb=s2;!sb.empty();sb=map_[sb].f,fb++)
		{
			if(fa>=5&&fb>=5)return 1;
			if(sa==sb&&(fa<5||fb<5))
			{
				return 0;
			}
		} 
	}
	return 1;
}

