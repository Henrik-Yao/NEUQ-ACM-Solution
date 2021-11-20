#include<bits/stdc++.h>
using namespace std;
int k,flag=0;
bool pd[100005];
struct ren{
	
	int fi=-1;
	int mi=-1;
	char x;
	
}r[100005];

void gene(int h,int d){
	if(d>5) return;
	if(pd[h]) flag=1;
	pd[h]=1;
	if(r[h].fi!=-1){
		gene(r[h].fi,d+1);
	}
	if(r[h].mi!=-1)
	gene(r[h].mi,d+1);
	
} 
int main(){
	memset(pd,0,sizeof(pd));
	int n;int t,y;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int e;cin>>e;
		cin>>r[e].x;
		cin>>r[e].fi;
		cin>>r[e].mi;
		t=r[e].fi;
		y=r[e].mi;
		r[t].x='M';
		r[y].x='F';
	}
	cin>>k;int q,w;
	while(k--){
		cin>>q>>w;
		if(r[q].x==r[w].x )
		{
		cout<<"Never Mind"<<endl;
	    }
	    else
		{
	    gene(q,1);
		gene(w,1);
		if(flag==1) cout<<"No";
		if(flag==0) cout<<"Yes";
	    if(k) cout<<endl;
		}
		flag=0;
		memset(pd,0,sizeof(pd));
	    
	
	
}
	
}
