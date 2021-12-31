#include<bits/stdc++.h>
using namespace std;

struct node{
	int a, z;
	int w;
}gra[20020];

int cmp(const void* a, const void* b)
{
	node* c=(node*)a;
	node* d=(node*)b;
	if(c->a!= d->a)
		return c->a-d->a;
    else
		return c->z-d->z;
}

int main(void)
{
	int n, e, tot, s[20020]={0};
	cin>>n>>e;
	for(int i=0; i<e; i++)
	{
		cin>>gra[i].a>>gra[i].z>>gra[i].w;
		s[gra[i].a]++;
	}
	
	qsort(gra, e, 12, cmp);
	for(int i=0; i<e; i+=tot)
	{
		tot=s[gra[i].a];
		cout<<gra[i].a<<':';
		for(int j=i; j<tot+i; j++)
			printf("(%d,%d,%d)", gra[j].a, gra[j].z, gra[j].w);
		cout<<endl;
	}
	
	return 0;
}