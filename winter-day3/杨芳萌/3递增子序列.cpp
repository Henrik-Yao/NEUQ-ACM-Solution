#include<bits/stdc++.h>
using namespace std;
const int N = 233;
int n,a[N],ans;
map<vector<int>,int> mp;
vector<int> b;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

int main(){
	read(n);
	for(int i=0; i<n; i++) read(a[i]);
	for(int i=0; i<(1<<n); i++) {
		bool flag = 0;
		for(int j=0; j<n; j++)
			if((i>>j)&1) b.push_back(a[j]);
		int end = b.size()-1;
		for(int j=0; j<end; j++) 
			if(b[j]>b[j+1]) {
				flag = 1;
				break;
			}
		if(flag==0&&b.size()>1&&mp[b]!=1) {
			ans++;
			mp[b] = 1;
		}
		b.clear();
	}
	printf("%d\n",ans);
    return 0;
}

