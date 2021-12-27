#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>v;
	int n,i,m,k;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++){
		v.push_back(i);
	}
	int a=1;
	while(v.size()>1){
		a=a-m+1;
		while(a<=0)a+=v.size();
		while(a>v.size())a-=v.size();
		//cout<<"a="<<a<<endl;
		cout<<v[a-1]<<" ";
		v.erase(v.begin()-1+a);
		a--;
	//	cout<<"后"<<a<<endl; 
		if(a==0)a=v.size();
		if(v.size()==1)break;
		a=(a+k-1)%v.size();
		if(a==0)a=v.size();
	//	cout<<"a="<<a<<endl;
		cout<<v[a-1]<<" ";
		v.erase(v.begin()-1+a);
		//a++;
	//	cout<<"后"<<a<<endl;
		if(a==v.size()+1)a=1;
	}
	cout<<v[0]<<" "<<endl;
	return 0;
}
