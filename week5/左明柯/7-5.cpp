#include <stdio.h>
const int maxn=1e5+10;
int n;int a[maxn];int start;int vis[maxn];int flag;
bool dfs(int now){
	int next1,next2;
	vis[now]=1;
	if(!a[now]) return true;
	next1=now+a[now];
	next2=now-a[now];
	if(next1<n&&!vis[next1]) 
        if(dfs(next1)) return true;
	if(next2>=0&&!vis[next2]) 
	    if(dfs(next2)) return true;
	    
	    return false;
}
int main(){
scanf("%d",&n);
for(int i=0;i<n;i++){
	scanf("%d",&a[i]);
}
scanf("%d",&start);
if(dfs(start)==true) printf("True");
else printf("False");


return 0;
}
