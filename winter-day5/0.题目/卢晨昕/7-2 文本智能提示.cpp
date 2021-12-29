#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
ll n,m,k;
struct node
{
	ll num;
	ll asc;
	string s;
}e[10005];
struct cmpp
{
	bool operator() (node a, node b) 
    {
    	if(a.num<b.num)return true;
    	else if(a.num>b.num)return false;
    	else
    	{
    		return a.s>b.s;
		}
    }
};
ll asc[10005];
map<string,ll>q;
map<string,ll>qq;
bool cmp(node a,node b)
{
	if(a.s<b.s)return true;
	else if(a.s>b.s)return false;
	else
	{
		return a.num>b.num;
	}
}
int search(string x,node e[])//找到第一个大于等于x的字符 
{
	int l=1,r=n;
	int ans=n+1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(e[mid].s>=x)
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
int main()
{
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		cin>>e[i].s;
		if(a>q[e[i].s])
		{
			q[e[i].s]=a;
		}
		e[i].num=q[e[i].s];
	}
	sort(e+1,e+1+n,cmp);//以字符串顺序排序 
	while(m--)
	{
		priority_queue< node ,vector<node>, cmpp >w;
		qq.clear();
		ll time=0;
		string x;
		cin>>x;
		int be=search(x,e);
		for(ll i=be;i<=n;i++)//将符合前缀的字符串加入大根堆（以频次为比较） 
		{
			if(strstr(e[i].s.c_str(),x.c_str())!=(e[i].s.c_str()))break;
			if(!qq[e[i].s])
			{
				w.push(e[i]);
				qq[e[i].s]=1;
			}
		}
		while(!w.empty())
		{
			node a=w.top();
			w.pop();
			if(strstr(a.s.c_str(),x.c_str())==(a.s.c_str())&&a.s.length()!=x.length())
			{
				cout<<a.s<<endl;
				time++;
			}
			if(time==k)break;
		}
		if(!time)
		{
			cout<<"no suggestion"<<endl;
		}
		if(m)cout<<endl;
	}
	return 0;
}

