#include<bits/stdc++.h>
using namespace std;
vector<int>ax[100005];
bool vis[100005];
char sex[100005];
int n,m;
int flag;
void dfs(int name,int num){
   if(num>=4)return;
   for(int i=0;i<ax[name].size();i++){
   	if(!vis[ax[name][i]]){
   		vis[ax[name][i]]=1;
   		dfs(ax[name][i],num+1);
	   }
       else{
           flag=0;
           return;
       }
   }
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int name;
        cin>>name;
        cin>>sex[name];
        int father;
        cin>>father;
        int mother;
        cin>>mother;
        if(father!=-1){
            sex[father]='M';
        ax[name].push_back(father);
        }
        if(mother!=-1){
            sex[mother]='F';
        ax[name].push_back(mother);
    }
    }
    cin>>m;
    while(m--){
    	memset(vis,0,sizeof(vis));
    	flag=1;
    	int a;
    	int b;
    	cin>>a>>b;
        
    	if(sex[a]==sex[b])cout<<"Never Mind";
    	else{
    		dfs(a,0);
    		dfs(b,0);
    		if(flag==1)cout<<"Yes";
    		else cout<<"No";
		}
		if(m!=0)cout<<endl;
	}
}

