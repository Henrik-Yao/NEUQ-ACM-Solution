#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
int n,a[N],ji=-1,ou=-1;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

void out(int i, int tag) {
	if(i!=tag) printf("%d->",a[i]);
	else printf("%d\n",a[i]);
}

int main(){
	while(scanf("%d",&a[++n])!=EOF);
	n--;
	sort(a+1,a+n+1);
	for(int i=1; i<n; i++) printf("%d->",a[i]);
	printf("%d\n",a[n]);
	for(int i=n; i>0; i--) {
		if((a[i]&1) && ji<0) ji = i;
		if((!(a[i]&1)) && ou<0) ou = i;
		if(ji>0 && ou>0) break;
	}
	
	for(int i=1; i<=n; i++) if(a[i]&1) out(i,ji);
	if(ji==-1) printf("\n");
	for(int i=1; i<=n; i++) if(!(a[i]&1)) out(i,ou);
	
    return 0;
}

