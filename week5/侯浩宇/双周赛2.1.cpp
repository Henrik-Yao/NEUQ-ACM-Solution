#include<bits/stdc++.h>
using namespace std;
int fa[100100],fb[100100],p=0;
int s[100100];
bool f[100100];
int flag;
void dfs(int k,int x){
	if(k<=0) return ;
	if(f[x]){
		flag=1;
		return ;
	}
	f[x]=true;
	if(fa[x]>0)  dfs(k-1,fa[x]);
	if(fb[x]>0)  dfs(k-1,fb[x]); 
}
int main(){
	int n,a,b,d,m;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c>>b>>d;
		fa[a]=b;
		fb[a]=d;
		if(c=='F')
		s[a]=1;
		else
		s[a]=2;
		s[b]=2;
		s[d]=1;
	}
	cin>>m;
    int m1=m;
	while(m--){	
	    int x,y;
		memset(f,false,sizeof(f));
		cin>>x>>y;
        if(s[x]==s[y]){
            cout<<"Never Mind";p++;if(p<m1)cout<<endl;
        }       
        else{
		    flag=0;
        	dfs(5,x);
        	dfs(5,y);
        	if(flag){
                cout<<"No";p++;if(p<m1)cout<<endl;
            }   	
        	else{
                cout<<"Yes";p++;if(p<m1)cout<<endl;
            }	
		}	
	}
    return 0;
}
