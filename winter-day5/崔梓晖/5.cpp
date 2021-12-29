#include <bits/stdc++.h>
using namespace std;
int n,m;
string s1,s2,s3,s4;
int fa[100001];
struct people
{
	int sex;
	int id;
};
map<string,people>mp1;
//map<string,int>mp2;

int find(int x) 
{
	int rt = fa[x];
	if (fa[x] != x) rt = find(fa[x]);
	return rt;
}

//int find(int x)
//{
//	if(fa[x]==x)
//	{
//		return x;
//	}
//	else return fa[x]=find(fa[x]);
//}

bool pd(int x,int y)
{
	int cnt=1;
	while(x!=fa[x]&&y!=fa[y])
	{
		x=fa[x];
		y=fa[y];
		++cnt;
		if(cnt==5)
		{
		//	cout<<"cnt"<<cnt<<endl;
			return 1;
		}
		if(x==y)
		{
		//	cout<<"cnt"<<cnt<<endl;
			return 0;
		}
	}
	return 0;
}

int main()
{
	cin>>n;
	for(int i=1;i<=100005;++i)
	{
		fa[i]=i;
	}
	vector< vector<string> >a(n);
	int q=0;
	for(int i=0;i<n;++i)
	{
		cin>>s1>>s2;
		mp1[s1].id=++q;
		a[i].push_back(s1);
		a[i].push_back(s2);
	}
	for(int i=0;i<n;++i)
	{
		s1=a[i][0];
		s2=a[i][1];
		if(s2.size()>4&&s2.substr(s2.size()-4,4)=="sson")
		{
			mp1[s1].sex=1;
			fa[mp1[s1].id]=mp1[s2.substr(0,s2.size()-4)].id;
		}
		if(s2.size()>7&&s2.substr(s2.size()-7,7)=="sdottir")
		{
			mp1[s1].sex=0;
			fa[mp1[s1].id]=mp1[s2.substr(0,s2.size()-7)].id;
		}
		if(s2[s2.size()-1]=='m')
		{
			mp1[s1].sex=1;
		}
		if(s2[s2.size()-1]=='f')
		{
			mp1[s1].sex=0;
		}
	}
 	cin>>m;
 	for(int i=1;i<=m;i++)
 	{
 		cin>>s1>>s2>>s3>>s4;
 		if (!mp1[s1].id||!mp1[s3].id)
 		cout<<"NA"<<endl;
		else if(mp1[s1].sex==mp1[s3].sex)
		cout<<"Whatever"<<endl;
		else if(find(mp1[s1].id)!=find(mp1[s3].id))
		cout<<"Yes"<<endl;
		else if(pd(mp1[s1].id,mp1[s3].id))
		cout<<"Yes"<<endl;
		else 
		cout<<"NO"<<endl;
	}
	return 0;
}
