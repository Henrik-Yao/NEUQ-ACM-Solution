#include<bits/stdc++.h>
using namespace std;
int p[1501],ans,maxx,n,q[1501],p3,p2,nextt[1501];
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
struct node{
	int t;
	int w;
	int y;
	int nex;
	bool operator<(const node&t)const{
	        return y<t.y;
	    }
};struct node a[20010];
void f(int x){

}
int main(){
	int e;
	while(cin>>n>>e){
		p3=0;p2=1;
		int sum=0;
    for(int i=0;i<1500;i++)
        p[i]=0;
    for(int i=1;i<=n;i++)
    p[i]=i;    
	for(int i= 0;i<e;i++){
		cin>>a[i].t>>a[i].w>>a[i].y;
	}
	sort(a,a+e);
	ans=0;
	    for(int i=0;i<e;i++){
	    	a[i].nex=a[i].w;
        int q1=find(a[i].t),q2=find(a[i].w),q3=a[i].y;
        if(q1!=q2){
            p[q1]=q2;
            ans=q3;
        }
        else a[i].nex=0;
    }
		for(int i=0;i<e;i++){
			if(a[i].y<=ans) sum+=a[i].y;
			else break;
		}
		for(int i=1;i<n;i++)
		q[i]=0;q[0]=1;
		for(int i=0;i<e;i++){
			q[a[i].nex]=1;
		}
		for(int i=0;i<n;i++){
			cout<<i<<" "<<q[i]<<endl; 
			if(!q[i]){p3=0;cout<<"There is no minimum spanning tree."<<endl;break;}
		}
		if(p3)cout<<sum<<endl;
		for(int i= 0;i<e;i++){
			a[i].t=a[i].w=a[i].y=0;
		}	
	}
	return 0; 
}
