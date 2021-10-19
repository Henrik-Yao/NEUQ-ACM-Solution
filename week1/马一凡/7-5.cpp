#include<iostream>
#include<cstring>
using namespace std;

int main(){
	long long n,m;
	int t,q,flag=1;
	int i;
	string a[100000];
	int b[100000];
	cin >> n >> m;
	for(i=1; i<=n; i++){
		cin >> b[i] >> a[i];
	}
	for(i=0; i<m; i++){
		cin >> t >> q;
		if(t==1){
			if(b[flag]==0)
			flag = flag+q;
			else if(b[flag]==1)
			flag = flag-q;
		}
		if(t==0){
			if(b[flag]==1)
			flag = flag+q;
			else if(b[flag]==0)
			flag = flag-q;
		}
		if(flag <= 0) flag = n+flag;
		if(flag > n) flag = flag-n;
	
	}
	cout << a[flag];
	
	
	return 0;
}
