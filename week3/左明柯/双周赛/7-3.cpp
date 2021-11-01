#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(int n){
	if(n==0) return 0;
	if(n==1) return 2;
	return 3*f(n-1)+2;
} 
int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
  	cout<<f(n)<<endl;
  }


return 0;

}
