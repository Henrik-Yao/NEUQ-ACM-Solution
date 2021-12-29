#include<bits/stdc++.h>
using namespace std;
int n,e,vi[20000];
typedef struct bian{
	int bb;
	int cc;
	struct bian *next;
}bian,*linkbian;
linkbian crbian(int b,int c){
	linkbian node;
	node =(linkbian)malloc(sizeof(bian));
	node->bb =b;
	node->cc =c; 
	node->next=NULL;
	return node;
}
int main(){
	cin>>n>>e;
	int a,b,c,i=e;
	linkbian t[n];
	while(i--){
		cin>>a>>b>>c;
		if(!vi[a]){
			t[a]=(linkbian)malloc(sizeof(bian));
			t[a]->next=crbian(b,c);
			vi[a]++;
		}
		else if(vi[a]){
			linkbian p=t[a];
			for(int cnt=1;cnt<=vi[a];cnt++){
				linkbian q=p;
				p=p->next;
				if(p->bb <b){
					if(p->next==NULL||p->next->bb >b){
						linkbian qq=p->next ;
						p->next =crbian(b,c);
						p->next->next =qq;
						break;
					}
				continue;
				}
				q->next=crbian(b,c);
				q->next->next=p;
				break;
			}
			vi[a]++;
		}
	}
	for(i=0;i<n;i++){
		if(vi[i]){
			cout<<i<<":";
			linkbian p=t[i];
			for(int cnt=1;cnt<=vi[i];cnt++){
				p=p->next;
				cout<<"("<<i<<","<<p->bb <<","<<p->cc <<")";
			}
			cout<<endl;
		}
	}
	return 0;
}
