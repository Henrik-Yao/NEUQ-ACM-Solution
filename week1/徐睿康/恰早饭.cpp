#include<bits/stdc++.h>
using namespace std;
int a[100010],n,m,x,y,t,maxx=-1e9;
string s[100010];
char c;
int main(){
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(y>t){
			maxx=max(maxx,x-(y-t));
		}
		else maxx=max(maxx,x);
	}
	cout<<maxx;
}
