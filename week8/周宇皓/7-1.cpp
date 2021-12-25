#include<bits/stdc++.h>
using namespace std;
struct sy{
	int a,b;
}f[10001];
bool compare(sy s1,sy s2){
	return s1.b<s2.b;
}
int main(){
	int n,m;
	cin>>n;
	for(int j=0;j<n;j++){
       int c=1,s=0;
		cin>>m;
		for(int i = 0; i < m; i++){
			cin>>f[i].a>>f[i].b;
		}
		sort(f,f+m,compare);
		for(int i=0;i<m;i++){
			if(f[i].a>=f[s].b)
		{
			s=i;
			c++;
		}
		}
		cout<<m-c<<endl;
	}
} 
