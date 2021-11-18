#include<bits/stdc++.h>
using namespace std;
struct xx{
	int bb;
	int mm;
	string xb;
}id[100005];
int vi[100005];
int flag=0;
void f(int m,int deep);
int main(){
	int n,i;
	cin>>n;
	for(i=0;i<n;i++){
		int j;
		cin>>j;
		cin>>id[j].xb >>id[j].bb >>id[j].mm ;
	//	id[id[j].bb ].xb ="F",id[id[j].mm ].xb ="M";
		if(id[j].bb ==-1) id[j].bb =100000;
		if(id[j].mm ==-1) id[j].mm =100000;	
		id[id[j].bb ].xb ="M",id[id[j].mm ].xb ="F";
	}
	id[100000].bb =100000,id[100000].mm =100000;
	int k;
	cin>>k;
	for(i=0;i<k;i++){
		memset(vi,0,sizeof(vi));
		int m,t;
		cin>>m>>t;
		if(id[m].xb ==id[t].xb ){
			cout<<"Never Mind"<<endl;
			continue;
		}
		else f(m,0),flag=0,f(t,0);//cout<<flag;
		if(flag==0)cout<<"Yes";
		else cout<<"No";
		if(i!=k-1)cout<<endl;
		//cout<<endl<<flag<<endl;
	}
	return 0;
}
void f(int m,int deep){
	if(vi[m]==1&&m!=100000&&m!=0){
		flag=1;
		return;
	}
	if(m==0)return;
	vi[m]=1;
	if(deep<4)f(id[m].bb ,deep+1),f(id[m].mm ,deep+1);
	else {
	return;
	}
}
