#include<bits/stdc++.h>
using namespace std;
int a[200001];
int n;
//int len1=0;
//int len2=0;
int f(int s,int e){
	cout << s << " " << e << endl;
	if(s==e) return a[s];
	
	int mid=(s+e)/2;
	int len1=f(s,mid);
	int len2=f(mid+1,e);
	int sum1=0;
	int sum2=0;
	int max1=-1e9;
	int max2=-1e9;
	for(int i=mid;i>=s;i--){
		sum1+=a[i];
		max1=max(sum1,max1);
	}
	for(int i=mid+1;i<=e;i++){
		sum2+=a[i];
		max2=max(sum2,max2);
	}
	
	return max(max(len1,len2),max(sum1+max(0,sum2),sum2+max(0,sum1)));
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int c=f(1,n);
	cout<<c;
}
