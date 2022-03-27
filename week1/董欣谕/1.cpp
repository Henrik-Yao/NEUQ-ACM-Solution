#include <bits/stdc++.h>
using namespace std;
int main() {
	string str,str1;
	int i,n,ans,cnt;
	cin>>n;
	cin>>str;
	while (n--) {
		cin>>str1;
		ans=0;
		int j=0;
		for (i=0; i<str.size(); i++) {
			int cnt=0;
			for (j=0; j<str1.size(); j++) {
				if (str[i+cnt]==str1[j]) cnt++;
				else {
					cnt=0;
					break;
				}
				if (cnt==str1.size()) ans++,cnt=0;
			}
		}
		if (n!=0) cout<<ans<<endl;
		else cout<<ans;
	}
	return 0;
}
