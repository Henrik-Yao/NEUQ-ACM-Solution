#include<bits/stdc++.h>
using namespace std;
int cnt[1010][1010];
int ans[1010][1010];
char tu[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int n,m,s=1,cntt[100000];
void f(int i,int j);
int main(){
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;i++){
			cin>>tu[i];
	}
	while(m--){
		cin>>i>>j;
		if(cntt[ans[i-1][j-1]]!=0){
			cout<<cntt[ans[i-1][j-1]];
		}else {
		cntt[s]=0;
		f(i,j);
		cout<<cntt[s];
		}
        if(m>0)cout<<endl;
        s++;
	}
	return 0;
}
void f(int i,int j){
	int a;
	ans[i-1][j-1]=s;
	cnt[i-1][j-1]=1;
	cntt[s]++;
	for(a=0;a<4;a++){
		int xx=i+dx[a];
		int yy=j+dy[a];
		if(xx<1||xx>n||yy<1||yy>n)continue;
		if(tu[i-1][j-1]!=tu[xx-1][yy-1]&&cnt[xx-1][yy-1]==1){
			
		}
		if(tu[i-1][j-1]!=tu[xx-1][yy-1]&&cnt[xx-1][yy-1]==0){
			f(xx,yy);
		}
	}
}
