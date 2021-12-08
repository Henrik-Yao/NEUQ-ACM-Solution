/*
 * @Author: ComplexPug
 * @Email: 3010651817@qq.com
 * @Date: 2021-12-05 23:26:26
 * @LastEditTime: 2021-12-05 23:32:02
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e6+7;
const int oo=0x3f3f3f3;
int read() {
	int x=0,f=1;char s=getchar();
	for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
	for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
	return x*f;
}
int n,a[_];
int main() {
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	int ans=0;
	for(int i=1;i<n;) {
		ans++;
		int l=i,r=min(i+a[i],n);
		if(r==n) break;
		++i;
		for(int j=l+1;j<=r;++j)
			if(i+a[i]<j+a[j]) i=j;
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5
1 2 3 2 1 
*/