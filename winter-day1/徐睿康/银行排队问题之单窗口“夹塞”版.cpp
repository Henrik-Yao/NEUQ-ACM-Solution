#include<bits/stdc++.h>
using namespace std;
double sum=0;
int n,m,flag,x,y,pan[10010],t;
string s;
struct node{
	string name;
	int start,len;
}a[10010];
bool cmp(node a,node b){
	return a.start<b.start;
}
map<string,int>mp;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>flag;
		for(int j=1;j<=flag;j++){
			cin>>s;
			mp[s]=i;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>s>>x>>y;
		if(y>60)y=60;
		a[i].name=s;
		a[i].start=x;
		a[i].len=y;
		if(mp[s]==0)mp[s]=-i;
	}
	t=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(pan[i]==0){
			pan[i]=1;
			cout<<a[i].name<<endl;
			if(t<a[i].start)t=a[i].start;
			sum+=t-a[i].start;
			t+=a[i].len;
			for(int j=i+1;j<=n;j++){
				if(a[j].start>=a[i].start&&a[j].start<=t&&mp[a[j].name]==mp[a[i].name]){
					pan[j]=1;
					cout<<a[j].name<<endl;
					sum+=t-a[j].start;
					t+=a[j].len;
				}
			}
		}
	}
	//cout<<sum<<endl;
	printf("%.1lf\n",sum/double(n));
	return 0;
}
