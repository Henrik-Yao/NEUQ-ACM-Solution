#include<bits/stdc++.h>
using namespace std;
int n,flag,cnt;
int a[10000];
int cshu(int t);
typedef struct tree{
	int data;
	struct tree *l,*r;
}tree,*linktree;
linktree crtree(int i){
	linktree node;
	if(!a[i])node=NULL;
	else {
		node=(linktree)malloc(sizeof(tree));
		node->data=a[i];
		node->l =crtree(2*i);
		node->r =crtree(2*i+1);
	}
	return node;
}
void pr(linktree tt){
	if(tt->l!=NULL)pr(tt->l);
	if(flag==1)cout<<tt->data,flag=0;
	else if(flag==0)cout<<" "<<tt->data;
	if(tt->r!=NULL)pr(tt->r);
}
int main(){
	cin>>n;
	while(n--){
		memset(a,0,sizeof(a));
		int i;
		cin>>cnt;
		a[0]=0;
		for(i=1;i<=cnt;i++)cin>>a[i];
		for(i=cnt;a[i]==0;i--)cnt--;
		int cs=cshu(cnt);
		if(cnt==1){
			if(a[1]==0){
				cout<<"0"<<endl;
				continue;
			}
			else {
				cout<<a[1]<<endl<<"1"<<endl;
				continue;
			}
		}
		
		linktree tt=NULL;
		flag=1;
		tt=crtree(1);
	
		pr(tt);
		cout<<endl<<cs<<endl;
	}
	return 0;
}
int cshu(int t){
	int cs=0;
	for(;t>0;cs++){
		t/=2;
	}
	return cs;
}
