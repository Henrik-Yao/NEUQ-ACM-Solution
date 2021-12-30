#include<bits/stdc++.h>
using namespace std;
int n,m,k,now=1,tmp,out,dir=1;
bool vis[2333];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

int main(){
	read(n), read(m), read(k);
	while(out<n) {
		if(vis[now]==0) tmp++;
		if((dir==1&&tmp==m) || (dir==-1&&tmp==k)) {
			vis[now] = 1;
			tmp = 1;
			dir *= -1;
			out++;
			printf("%d ",now);
		}
		now -= dir;
		if(now==n+1) now = 1;
		if(now==0) now = n;
	}
    return 0;
}

