#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,l,s;
	cin>>n;
	int a[10000],b[10000];
	int c[20000];
	while(n--){
		cin>>s;
		for(int i = 0; i < s; i++)
		{
		cin>>a[i];
		c[i]=a[i];
	}
	cin>>l;
		for(int i = s;i < s+l;i++){
			cin>>b[i];
			c[i]=b[i];
		}
		sort(c,c+l+s);
		for(int i = 0; i < s+l-1;i++)
		cout<<c[i]<<" ";
		cout<<c[s+l-1]<<endl;
	} 
}
