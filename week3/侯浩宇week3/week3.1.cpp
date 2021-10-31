#include<bits/stdc++.h>
using namespace std;
int k,b1[101],b2[101],road[101],safe[51],ans=2,d;
int find(int beginn){
	for(int i=0;i<k;i++){
		if(b1[i]==beginn) 
		    if(safe[b2[i]]&&!road[b2[i]]) road[b1[i]]=1,ans=find(b2[i]);
		if(b2[i]==beginn)
		    if(safe[b1[i]]&&!road[b1[i]]) road[b2[i]]=1,ans=find(b1[i]);//cout<<ans<<endl;
			if(beginn==d) return 1;
			if(ans==1) return 1;
	}
	if(ans!=1) return 0;
}
int main(){
	int m,n,a[51],s;
/**/  int p=0;
	cin>>m>>n>>k;
	for(int i=0;i<=51;i++)
	safe[i]=0;
	for(int i=0;i<n;i++)
	cin>>a[i],safe[a[i]]=1;
	for(int i=0;i<k;i++)
	cin>>b1[i]>>b2[i],road[i]=0;
	cin>>s>>d;
	for(int i=0;i<n;i++)
	if(a[i]==d) p=1;
	if(!p){
	printf("The city %d is not safe!",d);
	return 0;
    }
	ans=find(s);
	if(ans) printf("The city %d can arrive safely!",d);
	else printf("The city %d can not arrive safely!",d);
	return 0;
}
