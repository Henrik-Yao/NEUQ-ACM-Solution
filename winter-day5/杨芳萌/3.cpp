#include<bits/stdc++.h>
using namespace std;
const int MIN = -0x7fffffff;
const int N = 23333;
int n,cnt;
map<int,bool> vis;
priority_queue <int,vector<int>,greater<int> > q;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

int main(){
	read(n);
	for(int i=1; i<=n+n; i++) {
		int tmp;
		read(tmp);
		if(vis[tmp]) { cnt++; continue;	}
		vis[tmp] = 1;
		q.push(tmp);
	}
	int tot = n+n-cnt;
	tot = (tot+1)/2 - 1;	
	while(tot--) q.pop();
	printf("%d\n",q.top());	
    return 0;
}

