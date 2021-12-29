#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
    int p1,p2;
    int w;
};
int father[105];
edge e[105];
int _rank[105];
bool cmp(edge e1,edge e2){
    if(e1.w!=e2.w) return e1.w<e2.w;
    else return e1.p1>e2.p2;
}
int find_father(int x){
     return father[x]==x?x:father[x]=find_father(father[x]);
}
void Merge(int f1,int f2){
	if(_rank[f1]<_rank[f2]) father[f1]=f2;
	else if(_rank[f2]<_rank[f1]) father[f2]=f1;
	else{
	    father[f1]=f2;
	    _rank[f2]++;
	}
}
int main(){
    int vertices,edges,brokencity;
    while(cin >> vertices >> brokencity >> edges){
        int n1,n2,n3;
		for(int i=0;i<105;i++){
			father[i]=0;_rank[i]=0;e[i]={0,0,0};
		}
        for(int i=0;i<edges;i++){
            cin >> e[i].p1 >> e[i].p2 >> e[i].w;
	        father[e[i].p1]=e[i].p1;
	        father[e[i].p2]=e[i].p2;
	        _rank[e[i].p1]=1;
	        _rank[e[i].p2]=1;
	    }
	    sort(e,e+edges,cmp);
	    int in_line=0;
		int NumConnecttoBrokenCity=0;
	    int sum=0;
	    for(int i=0;i<edges;i++){
	        int f1=find_father(e[i].p1);
	        int f2=find_father(e[i].p2);
	        if(f1!=f2){
				if((e[i].p1==brokencity||e[i].p2==brokencity)&&NumConnecttoBrokenCity<2){
					Merge(f1,f2);
					NumConnecttoBrokenCity++;
					sum+=e[i].w;
					in_line++;
				}
				if(e[i].p1!=brokencity&&e[i].p2!=brokencity){
					Merge(f1,f2);
					sum+=e[i].w;
					in_line++;
				}
				if(in_line==vertices-1) break;
        	}
	    }
	    if(in_line==vertices-1) cout << sum << endl;
		else cout << -1 <<endl;
	}
}