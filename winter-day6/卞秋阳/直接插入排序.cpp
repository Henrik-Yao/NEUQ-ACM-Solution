#include<bits/stdc++.h>
using namespace std;
int a[1100];
int n;
int main()
{
	
 while(cin>>n){
	for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
	for(int i=1;i<n;i++){
			int key=a[i];
		for(int j=i-1;j>=0;j--){
			if(key<a[j]){
				a[j+1]=a[j];
				a[j]=key;
				}
			}

		for(int j=0;j<n-1;j++) cout<<a[j]<<" ";
		cout<<a[n-1]<<endl;
		}
	}
	return 0;
} 



