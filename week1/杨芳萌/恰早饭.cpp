#include<bits/stdc++.h>
using namespace std;
int n,T,t,v,ans = -99999999;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

int main(){
	read(n),read(T);
	for(int i=1; i<=n; i++) {
		int tmp;
		read(v),read(t);
		if(t>T) tmp = v-t+T;
		else tmp = v;
		ans = max(ans,tmp);
	}
	printf("%d\n",ans);
    return 0;
}

