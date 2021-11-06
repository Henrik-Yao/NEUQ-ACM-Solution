#include <bits/stdc++.h>
using namespace std;
int fun(int M){
	if(M==1) return 0;
	if(M==2) return 1;
	if(M==3) return 2;
	return fun(M-1)+fun(M-2);
}
int main(){
	int n,m;
cin>>n;
while(n--){
	cin>>m;
	cout<<fun(m)<<endl;
}


return 0;

}
