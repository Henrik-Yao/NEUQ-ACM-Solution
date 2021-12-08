#include<bits/stdc++.h>
using namespace std;
long long n,a[1000010],ans,flag=0,pan[1000010],x,y,maxx,cun;
queue<pair<int,int> >que;
void bfs(int xx){
	que.push(make_pair(xx,0));
	pan[xx]=1;
	while(que.size()){
		x=que.front().first;
		y=que.front().second;
		que.pop();
		maxx=-1;
		cun=0;
		//cout<<x<<' '<<y<<endl;
		for(int i=1;i<=a[x]&&x+i<=n;i++){
			maxx--;
			if(a[x+i]>=maxx){
				maxx=a[x+i];
				cun=x+i;
			}
		}
		if(cun==n){
			ans=y+1;
			break;
		}
		else que.push(make_pair(cun,y+1));
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	a[n]=1e15; 
	bfs(1);
	printf("%lld",ans);
	return 0;
}
