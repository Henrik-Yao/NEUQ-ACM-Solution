#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

bool judge(int k){
	int tot=1; 
	int now=1; 
	for(int i=2;i<=n;i++){
		if(a[i]-a[now]>=k)
			tot++, now=i;  
	}
	if(tot>=m) return true;
	else return false;
}

int binarySearch(int l, int r){
	int ans=0;
	while(l<=r){
		int mid= (l + r) >> 1 ;
		if(judge(mid)) l=mid+1 , ans=mid;
		else r=mid-1;
	}
	return ans;
}

int main(){
	read(n);read(m);
	for(int i=1;i<=n;i++)
		read(a[i]);
	sort(a+1,a+n+1);
	int ans=binarySearch(1,a[n]-a[1]);
	cout<<ans<<"\n";
	return 0;
}
