#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,ans1,ans2;
signed main(){
	while(cin>>n) {
		ans1 = 0;
		for(int i=1; i<=n; i++) {
			ans2 = ans1*3 + 2;
			ans1 = ans2;
		}
		cout<<ans1<<endl;
	} 
    return 0;
}

