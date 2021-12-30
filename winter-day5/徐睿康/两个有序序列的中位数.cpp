#include<bits/stdc++.h>
using namespace std;
int x,n,cnt=0;
multiset<int>st;
int main(){
	cin>>n;
	for(int i=1;i<=n*2;i++){
		cin>>x;
		st.insert(x);
	}
	n=st.size();
	for(auto i=st.begin();i!=st.end();i++){
		cnt++;
		if(cnt==(n+1)/2){
			cout<<*i;
			return 0;
		}
	}
	return 0;
}
