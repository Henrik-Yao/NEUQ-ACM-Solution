#include<bits/stdc++.h>
using namespace std;
struct T{
	string a;
	string b;
};
int main(){
	T mu[10001];
	int flag = 0;
	string c;
	int m,n;
	cin>>m>>n;
	for(int i = 0; i < m; i++){
		cin>>mu[i].a>>mu[i].b;
	}
	while(n--){
		cin>>c;
		for(int i = 0; i < m; i++)
		if(mu[i].b==c)
		{
		cout<<mu[i].a<<endl;
		flag=1;
	}
	if(flag==0)
	cout<<"eh"<<endl;
	flag = 0;
	}
}
