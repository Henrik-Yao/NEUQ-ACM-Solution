#include<bits/stdc++.h>
using namespace std;
int v[10001],w[10001];
int fl[10001];
int main(){
	int m,n;
while(cin>>m>>n){
for(int i = 0;i < m;i++)
cin>>v[i];
for(int i = 0; i < m ;i++)
cin>>w[i];
for(int i = 0; i < m; i++){
	for(int j = n; j>=v[i];j--)
	fl[j]=max(fl[j],fl[j-v[i]]+w[i]);
	
}
cout<<fl[n]<<endl;
memset(v,0,sizeof(v));
memset(w,0,sizeof(w));
memset(fl,0,sizeof(fl));

}
}
