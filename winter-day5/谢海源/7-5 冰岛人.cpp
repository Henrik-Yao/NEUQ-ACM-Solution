#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
map<string, pair<bool, string>> record;//建立映射//名->性别和姓氏
bool find(string a,string b)//匹配a和b
{
	int sum1=1,sum2=1;
	string x=a,y=b;
	//record[x].second
	while(x!="")
	{
		y=b;//初始化
		sum2=1;
		while(y!="")
		{
			if(sum1>4&&sum2>4) return 1;
			if(x==y) return 0;
			y=record[y].second;
			sum2++;//b的辈分
			//cout<<sum1<<" "<<sum2<<endl;
		}
		sum1++;//a的辈分
		x=record[x].second;
	}
	return 1;
}
int main()
{
	int n,m;
	cin>>n;
	string a,b,c,d;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(b.back()=='m') record[a].first=0;//标记为楠
		else if(b.back()=='f') record[a].first=1;
		else if(b.back()=='n')//维京男
		{
			record[a]={0,b.substr(0,b.size()-4)};
		}
		else if(b.back()=='r')//维京女
		{
			record[a]={1,b.substr(0,b.size()-7)};
		}
	}
	cin>>m;
	while(m--)
	{
		cin>>a>>b>>c>>d;
		if(!record.count(a)||!record.count(c)) cout<<"NA"<<endl;//查无此人
		else if(record[a].first==record[c].first) cout<<"Whatever"<<endl;
		else
		{
			if(find(a,c)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}