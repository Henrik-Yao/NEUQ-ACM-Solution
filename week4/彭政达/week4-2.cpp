#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll a[41];
int solution(int n){
	if(n==1) return 1;
	if(n==2) return 2;
	if(n>=3) return solution(n-1)+solution(n-2);
}
int main(){
	int t;
	ios::sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    a[1]=0,a[2]=1,a[3]=2;
    for(int i=4;i<=40;i++)
        a[i]=a[i-1]+a[i-2];
	cin>>t;
	while(t--){
        int n;
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
}
