#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,c[20], k,k1,p;
	string a[20],b;
	cin>>n>>b;
	for(int i=0;i<n;i++)
	    cin>>a[i],c[i]=0;
	for(int i=0;i<n;i++){
		k=0;k1=0;
		while(k<b.length()){
			k=k1;
			for(int j=0;j<a[i].length();j++){
				if(a[i][j]==b[k]){
					p=1;k++;
				}
				else{
					p=0;break;
				}
			}
			if(p) c[i]++;
			k1++;//cout<<k1;cout<<k;
		}	
	}			
	for(int i=0;i<n;i++)
	cout<<c[i]<<endl;
	return 0;
}
