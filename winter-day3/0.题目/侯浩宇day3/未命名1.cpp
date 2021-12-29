#include<bits/stdc++.h>
using namespace std;
struct node{
	int t;
	int w;
	int y;
};
struct node a[20010];
int s[21010]={0};
int cmp(const void *a,const void *b){
	struct node *c = (node *)a;
    struct node *d = (node *)b;
    if(c->t!= d->t) return c->t-d->t;
    else return c->w-d->w;
}
int main(){
	int n,e,sum;
	cin>>n>>e;
    for(int i =0; i<e; i++)
    { 
    	a[i].t = -1;
        a[i].w = -1;
        a[i].y = -1;
    }
	for(int i= 0;i<e;i++){
		cin>>a[i].t>>a[i].w>>a[i].y;
		s[a[i].t]++;
	}
	qsort(a,e,sizeof(a[0]),cmp);
	int i = 0;
	while(i<e){
		sum = s[a[i].t];
		printf("%d:",a[i].t);
		for(int j = i;j<sum+i;j++){
			printf("(%d,%d,%d)",a[j].t,a[j].w,a[j].y);
		}
		i = i+sum;
		printf("\n");
	}
	return 0; 
}
