#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N];
int func(int l,int r,int s){
    if(l>r) return -1;
    int t = 0;
	while(l<=r){
        t++;
		int mid = l+r>>1;
		if(a[mid]>=s) r = mid-1;
		else l = mid+1;
	}
    if(a[l]!=s) cout<<"-1"<<endl;
	else cout<<l<<endl;
    return t;
}
int main(){
	int n,s;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cin>>s;
    cout<<func(0,n-1,s);
}
