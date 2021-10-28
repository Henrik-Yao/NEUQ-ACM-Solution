#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}
int n,m,pos=1,a,b;
struct ll{
	int pos;
	char p[101];
}d[100001];

int main() { 
	read(n),read(m);
	for(int i=1;i<=n;i++) scanf("%d%s",&d[i].pos,d[i].p);	
	for(int i=1;i<=m;i++) {
  		scanf("%d%d",&a,&b);
  		if(a==d[pos].pos) {
			pos=(pos-b+n-1)%n+1;
			continue;
		}
  		if(a!=d[pos].pos) {
			pos=(pos+b-1)%n+1;
			continue;
		}
	}
	cout<<d[pos].p;
	return 0;
}

