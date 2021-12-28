#include<bits/stdc++.h>
using namespace std;
int n,i,cs=1;
string hx,zx,thx,tzx;
map<char,int>ph,pz;
int find(int z,int y);
typedef struct tree{
	char data;
	struct tree *l,*r;
}tree,*linktree;
linktree createtree(int z,int y){
	char a=find(z,y);
	linktree node;
	if(a=='#'){
		node=NULL;
	}
	else {
		node =(linktree)malloc(sizeof(tree));
		node->data =a;
		node->l=createtree(z,pz[a]-1);
		node->r=createtree(pz[a]+1,y);
	}
	return node;
}
void pr(linktree tt){
	cout<<tt->data ;
	if(tt->l!=NULL)pr(tt->l);
	if(tt->r!=NULL)pr(tt->r);
}
void sf(linktree tt){
	if(tt->l !=NULL)sf(tt->l);
	if(tt->r !=NULL)sf(tt->r);
	tt=NULL;
}
void th(linktree tt,int m){
	if(m>cs)cs=m;
	if(tt->l!=NULL)th(tt->l,m+1);
	if(tt->r!=NULL)th(tt->r,m+1);
	thx+=tt->data ;
}
void tz(linktree tt){
	if(tt->l!=NULL)tz(tt->l);
	tzx+=tt->data ;
	if(tt->r!=NULL)tz(tt->r);
}
int main(){
	while(cin>>hx>>zx){
		//getchar();
		//cin>>zx;
		//getchar();
		n=hx.size();
		for(i=0;i<n;i++)ph[hx[i]]=i,pz[zx[i]]=i;
		linktree tt=NULL;
		tt=createtree(0,n-1);
		tz(tt),th(tt,1);
		if(hx!=thx||zx!=tzx){
			for(i=0;i<n;i++)thx.erase(0),tzx.erase(0);
			cout<<"INVALID"<<endl;
			continue;
		}
		for(i=0;i<n;i++)thx.erase(0),tzx.erase(0);
		cout<<cs-1<<endl;
		pr(tt);
		cout<<endl;
		sf(tt);
		cs=1;
	}
	return 0;
}
int find(int z,int y){
	if(z==y)return zx[z];
	if(z>y)return '#';
	int cnt=-1;
	char max;
	for(int j=z;j<=y;j++){
		if(ph[zx[j]]>cnt)cnt=ph[zx[j]],max=zx[j];
	}
	return max;
}
