#include<bits/stdc++.h>
using namespace std;
struct node{
	int t;
	int w;
	int y;
};
struct node a[20010];
int s[21010]={0},s1[21010]={0};
int cmp(const void *a,const void *b){
	struct node *c = (node *)a;
    struct node *d = (node *)b;
    if(c->t!= d->t) return c->t-d->t;
    else return c->w-d->w;
}
int main(){
	int n,e,sum,k,q1,q2;
	cin>>n>>e;
    for(int i =0; i<e; i++)
    { 
    	a[i].t = -1;
        a[i].w = -1;
        a[i].y = -1;
    }
	for(int i= 0;i<e;i++){
		cin>>a[i].t>>a[i].w>>a[i].y;
		s[a[i].t]++;s1[a[i].t]=s[a[i].t];
	}
	qsort(a,e,sizeof(a[0]),cmp);
/**/	cin>>k;
	for(int i=0;i<k;i++){
		cin>>q1>>q2;
		for(int j=0;j<e;j++){
			if(q1==a[j].t&&q2==a[j].w){
				a[j].w=-1;s1[a[j].t]--;
			}
		}
		
	}
	
	int i = 0;
	while(i<e){
		sum = s[a[i].t];
        if(s1[a[i].t]){
		printf("%d:",a[i].t);
		for(int j = i;j<sum+i;j++){
			if(a[j].w!=-1)
			printf("(%d,%d,%d)",a[j].t,a[j].w,a[j].y);
		}
		printf("\n");            
        }
		i = i+sum;
	}
	return 0; 
}
