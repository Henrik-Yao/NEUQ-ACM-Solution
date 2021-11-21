#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
char sex[maxn];
int maid[maxn];
int baid[maxn];
int check[maxn];
int num,n,k;
int flag;
void dfs(int bh,int dai){
	if(bh==-1||dai>5||bh==0) return;
	if(check[bh]) flag=1;
	check[bh]=1;
	dfs(baid[bh],dai+1);
	dfs(maid[bh],dai+1);
	return;
}
int main(){
	cin>>n;
	while(n--){
	cin>>num;
	cin>>sex[num];
	cin>>baid[num];
	cin>>maid[num];
	sex[baid[num]]='M';
	sex[maid[num]]='F';
	}
	cin>>k;
	while(k--){
	int nan,nu;
	cin>>nan>>nu;
	if(sex[nan]==sex[nu]){
	cout<<"Never Mind"<<endl;
	continue;
}
	memset(check,0,sizeof(check));
	flag=0;
	dfs(nan,1);
	dfs(nu,1);
	if(flag==0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	}
}
