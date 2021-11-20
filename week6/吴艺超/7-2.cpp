#include<bits/stdc++.h>
#define mod 100000007
using namespace std;
struct node{
	string zhang;
	string mi;
	string ha;
}b[1007];
string hash1(string mi)
	{
		string ha="0000";
		int len=mi.length();
		int a[5]={0,len/4,len/4,len/4,len/4};
		for(int i=1;i<=len%4;i++)
		a[i]++;
		int zuo=0,you=0;
		for(int j=1;j<=4;j++)
		{
			zuo=you,you=you+a[j];
			int sum=0;
			for(int i=zuo;i<you;i++)
			{
				if(mi[i]>='A'&&mi[i]<='Z')mi[i]+=32;
				if(mi[i]>='0'&&mi[i]<='9')
					sum+=mi[i]-'0';
				else sum+=mi[i]-'a'+10;
			}
			sum=sum%36;
			if(sum<10)ha[j-1]=sum+'0';
			else ha[j-1]=sum-10+'a';
		}
		return ha;
	}
int n;
map<string,pair<string,string> >q;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		cin>>b[i].zhang>>b[i].mi;
		b[i].ha=hash1(b[i].mi);
		if(x=='R')
		{
			if(q.find(b[i].zhang)!=q.end())
			cout<<"Repeated!"<<endl;
			else{
				q.insert(make_pair(b[i].zhang,make_pair(b[i].mi,b[i].ha)));
				cout<<"Signed!"<<endl;
			}
		}
		if(x=='L')
		{
			if(q.find(b[i].zhang)==q.end())
			{
				cout<<"Failed!"<<endl;
				continue;
			}
			if(q[b[i].zhang].first==b[i].mi)
			{
				cout<<"Success!"<<endl;
				continue;
			}
			if((q[b[i].zhang].first!=b[i].mi) && (q[b[i].zhang].second!=b[i].ha))
			{
				cout<<"Failed!"<<endl;
				continue;
			}
			if((q[b[i].zhang].first!=b[i].mi) && (q[b[i].zhang].second==b[i].ha))
			cout<<"Attention!"<<endl;
		}
	}
    return 0;
}
