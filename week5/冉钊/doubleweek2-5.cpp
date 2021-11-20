#include<bits/stdc++.h>
using namespace std;
int m[100000];
bool v[100000]={0};
int start,n,flag=0;
void dfs(int now){
    if(now>n-1||now<0) return;
    v[now]=1;//必须放在前一语句后，防止now为负数错误标记；
    if(m[now]==0){
         flag=1;
         return ;
     }
     
       if(!v[now+m[now]])  dfs(now+m[now]);
       if(!v[now-m[now]])  dfs(now-m[now]);
     
}
int main(){
      cin>>n;
      for(int i=0;i<=n-1;i++){
          cin>>m[i];
      }
      cin>>start;
      dfs(start);
      if(flag==1) cout<<"True";
      else cout<<"False";
      return 0;
}