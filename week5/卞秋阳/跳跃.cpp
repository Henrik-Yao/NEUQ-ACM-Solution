#include<bits/stdc++.h>
using namespace std;
long long n,flag=0;
bool v[1000001]={};
long long int m[5*10000+10];
void dfs(int start){
	if(flag==1||v[start]==1) return;
	v[start]=1; 
	if(m[start]==0){
		flag=1;return;
	} 
	
	if(start+m[start]<n&&start+m[start]>=0&&v[start+m[start]]==0) {dfs(start+m[start]);}
    if(start-m[start]<n&&start-m[start]>=0&&v[start+m[start]]==0) {dfs(start-m[start]);}
	}

int main()
{  long long start;
   memset(v,0,sizeof(v));
    cin>>n;
    for(int i=0;i<=n-1;i++){
    	cin>>m[i];
	}
	cin>>start;
	dfs(start);
	if(flag==0) cout<<"False";
	else cout<<"True";
    return 0;
}


