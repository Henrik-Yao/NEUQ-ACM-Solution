#include<bits/stdc++.h>
using namespace std;
int a[100001],n;

int main(){
int n;
while(cin>>n){
for(int i = 0; i < n; i++){
	cin>>a[i];
}	
	int j;
	for(int i = 1; i < n; i++){
		int tmp = a[i];
		for( j = i - 1;j>=0&&tmp<a[j];j--){
		a[j+1]=a[j];	
		}
		a[j+1]=tmp;
		for(int i = 0; i < n-1; i++)
cout<<a[i]<<" ";
        cout<<a[n-1];
cout<<endl;
	}
}
} 
