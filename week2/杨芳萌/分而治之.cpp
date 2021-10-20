#include<bits/stdc++.h>
using namespace std;
const int N = 12345;
int n,m,k,first[12345],cnt;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

struct edge{
	int end,nxt;
}bian[123456];

void addedge(int s,int e){
	cnt++;
	bian[cnt].end = e;
	bian[cnt].nxt = first[s];
	first[s] = cnt;
} 

int main() {
    read(n),read(m);
    for(int i=1; i<=m; i++) {
    	int a1,a2;
    	read(a1),read(a2);
    	addedge(a1,a2);
    	addedge(a2,a1);
	}
	read(k);
    while(k--) {
    	int num,tmp,vis[N];
    	memset(vis,0,sizeof(vis));
    	read(num);
    	for(int i=1; i<=num; i++) {
    		read(tmp);
    		vis[tmp] = 1;
		}
		bool flag = 0;
		for(int i=1; i<=n; i++) 
			for(int j=first[i]; j>0; j=bian[j].nxt)
				if(vis[i]!=1&&vis[bian[j].end]==0) {
					flag = 1;
					break;
				}
    	if(flag==1) printf("NO\n");
    	else printf("YES\n");
	}
    return 0;
}
