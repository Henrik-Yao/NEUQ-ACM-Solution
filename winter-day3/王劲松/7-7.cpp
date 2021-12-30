#include<bits/stdc++.h>
using namespace std;
int n,v,e,fa[100];
struct tu{
	int a,b,c;
};
tu t[100];
bool cmp(tu a,tu b){
	return a.c <b.c ; 
}
int bcj(int t){
	if(t==fa[t])return t;
	else {
		fa[t]=bcj(fa[t]);
		return fa[t];
	}
}
int main(){
    int flag=0;
	while(cin>>n>>v>>e){
        if(flag)cout<<endl;
        else flag=1;
		memset(fa,0,sizeof(fa));
		int a,b,c,i,cnt=0,cntv=0,sum=0;
		for(i=0;i<n;i++)fa[i]=i;
		for(i=0;i<e;i++){
			cin>>a>>b>>c;
			t[i]={a,b,c};
		}
		sort(t,t+e,cmp);
		for(i=0;i<e&&cnt<n-1;i++){
			int aa=bcj(fa[t[i].a ]),bb=bcj(fa[t[i].b ]);
		//	cout<<"i="<<i<<"cnt="<<cnt<<endl;
			if(aa!=bb){
				if(cntv==2&&(t[i].a ==v||t[i].b ==v))continue;
				sum+=t[i].c ;
				cnt++;
				fa[aa]=bb;
				if(t[i].a ==v)cntv++;
				if(t[i].b ==v)cntv++;
			}
		}
		if(cnt<n-1)cout<<"-1";
		else cout<<sum;
	}
	return 0;
}
