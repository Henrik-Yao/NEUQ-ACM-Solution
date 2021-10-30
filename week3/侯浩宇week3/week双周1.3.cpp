#include<bits/stdc++.h>
using namespace std;
long long dg(int num){
    if(num == 1)
  	return 2;
    else 
  	return 3*dg(num-1)+2;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF)
        cout<<dg(n)<<endl;
    return 0;
}
