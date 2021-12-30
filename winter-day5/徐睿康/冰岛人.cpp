#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<string,ll>mp1;
map<ll,string>mp2;
map<string,ll>mpx;
string s,s1,s2,s3,fas1,fas2;
ll cnt=0,flag1,flag2,n,m,fa[1000010],pan[1000010],len;
void check(string s){
	if(mp1[s]==0){
		cnt++;
		mp1[s]=cnt;
		mp2[cnt]=s;
	}
}
void dfs(ll x){
	cnt++;
	pan[x]=cnt;
	if(fa[x]==x)
	return;
	else
	dfs(fa[x]);
}
void findd(ll x){
	cnt++;
	if(pan[x]!=0){
		flag1=pan[x];
		flag2=cnt;
		return;
	}
	if(fa[x]==x)return;
	else findd(fa[x]);
}
void del(ll x){
	pan[x]=0;
	if(fa[x]==x)return;
	else del(fa[x]);
}
int main(){
	cin>>n;
	for(ll i=1;i<=n*2;i++)fa[i]=i;
	for(ll i=1;i<=n;i++){
		cin>>s1>>s2;
		check(s1);
		len=s2.length();
		if(s2[len-1]=='m'){
			s3=s2.substr(0,len-1);
			mpx[s1]=1;
			check(s3);
		}
		else if(s2[len-1]=='f'){
			s3=s2.substr(0,len-1);
			mpx[s1]=2;
			check(s3);
		}
		else if(s2[len-1]=='n'){
			s3=s2.substr(0,len-4);
			mpx[s1]=1;
			check(s3);
			fa[mp1[s1]]=mp1[s3];
		}
		else if(s2[len-1]=='r'){
			s3=s2.substr(0,len-7);
			mpx[s1]=2;
			check(s3);
			fa[mp1[s1]]=mp1[s3];
		}
	}
	/*for(ll i=1;i<=n*2;i++){
		if(fa[i]==i)mpx[mp2[i]]=1;
	}
	for(ll i=1;i<=n+1;i++){
		cout<<mp2[i]<<' '<<mpx[mp2[i]]<<endl;
	}*/
	cin>>m;
	for(ll i=1;i<=m;i++){
		cin>>s1>>fas1>>s2>>fas2;
		if(mp1[s1]==0||mp1[s2]==0){
			cout<<"NA"<<endl;
		}
		else if(mpx[s1]==mpx[s2]){
			cout<<"Whatever"<<endl;
		}
		else{
			cnt=0;
			dfs(mp1[s1]);
			cnt=0;
			flag1=-1;
			flag2=-1;
			findd(mp1[s2]);
			if(flag1==-1&&flag2==-1){
				cout<<"Yes"<<endl;
			}
			else if(flag1>4&&flag2>4)
			cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
			cnt=0;
			del(mp1[s1]);
			//puts("233");
		}
	}
	return 0;
}
