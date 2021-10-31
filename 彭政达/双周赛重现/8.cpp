
#include <bits/stdc++.h>
using namespace std;
int num[1000001];
int f(int* A,int x,int y,int v){
	int m;
	while(x<y){
		m=x+(y-x)/2;
		if(A[m]>=v) y=m;
		else x=m+1;
	}
	return x;
}
int main(){
	int n,m;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(size_t i=0;i<n;i++)
		cin>>num[i];
	if(num[n-1]>=m) cout<<f(num,0,n-1,m)+1<<endl;
	else cout<<++n<<endl;
	return 0;
}
