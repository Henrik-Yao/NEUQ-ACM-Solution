#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int a[1001],n;
void HeapAdjust(int a[],int s,int m){
 	int x=a[s];
 	for(int j=2*s;j<=m;j*=2){
  		if(j<m && a[j]<a[j+1]) j++;
  		if(x>=a[j])  break;
  		a[s]=a[j];
  		s=j;
 	}
 	a[s]=x;
}
void CreateHeap(int a[]){
 	for(int i=n/2;i>0;i--){
  		HeapAdjust(a,i,n);
 	}
} 

void HeapSort(int a[]){
 	CreateHeap(a);
 	for(int i=1;i<=n;i++)
  		cout<<a[i]<<" ";
 	cout<<endl;
 	for(int i=n;i>1;i--){
  		swap(a[1],a[i]);
  		HeapAdjust(a,1,i-1);	
  		for(int i=1;i<=n;i++)
   			cout<<a[i]<<" ";
  		cout<<endl;
 	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];	
 	HeapSort(a);
	return 0;
} 