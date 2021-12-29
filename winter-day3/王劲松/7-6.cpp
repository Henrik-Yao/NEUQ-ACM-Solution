#include<bits/stdc++.h>
using namespace std;
int n,e,vi[2000];
typedef struct tu{
	int a;
	int b;
	int w; 
}tu;
tu t[2000];
int find();
int main(){
	int a,b,c,q,i;
	while(cin>>n>>e){
		memset(vi,0,sizeof(vi));
		int sum=0,cnt=0; 
		for( i=1;i<=e;i++){
			cin>>a>>b>>c;
			t[i]={a,b,c};
		}int aa,bb;
		for(q=110,i=1;i<=e;i++){
			if(t[i].w  <q){
				q=t[i].w ;
				aa=t[i].a ;
				bb=t[i].b ;
			}
		}vi[aa]=1,vi[bb]=1;
	//	cout<<"a="<<t[i].a <<"b="<<t[i].b <<endl;
	//	cout<<"#"<<endl;
		sum+=q,cnt++;
		while(1){
			q=find();
			if(q==111)break;
			cnt++,sum+=q;
		}
		if(cnt==n-1)cout<<sum<<endl;
		else cout<<"There is no minimum spanning tree."<<endl;
	}
	return 0;
}//用vi判断在过程中是否有环，不断找最小的权，找完后若vi存在0，不存在最小支撑树 
int find(){
	int q=111,aa,bb;
	for(int i=1;i<=e;i++){
		if((vi[t[i].a ]==1&&vi[t[i].b ]==0)||(vi[t[i].a ]==0&&vi[t[i].b ]==1)){
			if(t[i].w <q){
				q=t[i].w;
				if(vi[t[i].a ]){
					aa=t[i].a ;
					bb=t[i].b ;
				}
				else {
					bb=t[i].a ,aa=t[i].b ;
				}
			}
		}
	}
	vi[bb]=1;
	//cout<<"a="<<aa<<"b="<<bb<<endl;
	return q;
}
