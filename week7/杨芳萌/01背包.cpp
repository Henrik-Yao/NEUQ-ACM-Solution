#include<bits/stdc++.h>
using namespace std;
const int N = 2333;
int f[N],T,M,v[N],t[N];
int main(){
	while(cin>>M>>T) {
		for(int i=1; i<=M; i++) t[i] = v[i] = f[i] = 0;
		for(int i=1; i<=M; i++) cin>>t[i];
		for(int i=1; i<=M; i++) cin>>v[i];
		for(int i=1; i<=M; i++)
			for(int j=T; j>=t[i]; j--)
				f[j] = max(f[j],f[j-t[i]]+v[i]);
		cout<<f[T]<<endl;
	}
	return 0;
}
