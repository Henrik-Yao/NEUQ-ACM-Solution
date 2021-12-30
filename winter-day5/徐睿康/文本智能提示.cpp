#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,x,top=0,cnt=0;
string s[10010],ss;
map<string,ll>mp;
map<string,ll>mpan;
bool check(string x,string y){
	ll lenx=x.length();
	ll leny=y.length();
	if(lenx==leny)return false;
	string span(y,0,lenx);
	if(span==x)return true;
	else return false;
}
struct node{
	ll pl;
	string s;
}a[10010];
bool cmp(node x,node y){
	if(x.pl==y.pl)return x.s<y.s;
	else return x.pl>y.pl;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++){
		cin>>x>>s[i];
		mp[s[i]]=max(mp[s[i]],x);
	}
	for(ll i=1;i<=n;i++){
		if(!mpan[s[i]]){
			mpan[s[i]]=1;
			a[++top].pl=mp[s[i]];
			a[top].s=s[i];
		}
	}
	sort(a+1,a+top+1,cmp);
	//for(ll i=1;i<=top;i++)cout<<a[i].s<<' '<<a[i].pl<<endl;
	for(ll i=1;i<=m;i++){
		cin>>ss;
		cnt=0;
		if(k!=0)
		for(ll j=1;j<=top;j++){
			if(check(ss,a[j].s)){//
				cnt++;
				cout<<a[j].s<<endl;
				if(cnt==k)break;
			}
		}
		if(cnt==0&&k!=0)cout<<"no suggestion"<<endl;
		if(i!=m)
		cout<<endl;
	}
	return 0;
}
