#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int a[100];
int b[100];
int cou=1;
int len=0;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=0;
	}
	while(cou<=n){
		for(int i=0;i<n;i++){
			if(!b[i]&&a[i]){
				q.push(a[i]);
				len++;
				cou++;
				b[i]=1;
				break;
			}
		}
	for(int i=0;i<n;i++){
		if(a[i]<q.back()&&!b[i]){
			q.push(a[i]);
			b[i]=1;
			cou++;
		}
	}
	if(len==1){
	while (!q.empty()){
		cout<<q.front();
	q.pop();
	if(!q.empty()) cout<<" ";
}
cout<<endl;
}
else{
while (!q.empty())
q.pop();
}
}
cout<<len<<endl;
}
