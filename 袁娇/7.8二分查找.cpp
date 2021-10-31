#include<iostream>
using namespace std;
int erfen(int v,int a[],int n ){
if(v > a[n -1]){
            return n+1;
        }
        int left = 0;
        int right = n-1;
        int mid = (left + right ) / 2;
        while(left < right){
            if(a[mid] >= v){
                right = mid;
            }else{
                left =mid+1;
            }
            mid = left + (right - left)/2;
        }
        return mid+1;}

int main(){int a[1000001];int n,m;
cin>>n;cin>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
}
cout<<erfen(m,a,n);
	
}
