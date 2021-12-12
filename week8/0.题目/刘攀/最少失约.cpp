#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int b;
};
node c[1000];
int t,n;
int cou=1;
bool f(node c1,node c2){
	return c1.b<c2.b;
}
int main(){
	cin>>t;
	while(t--){
		cou=1;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>c[i].a>>c[i].b;
		}
		sort(c,c+n,f);
		int j=0;
		for(int i=1;i<n;i++){
			if(c[i].a>=c[j].b){
				j=i;
				cou++;
			}
		}
		cout<<n-cou<<endl;
	}
}
