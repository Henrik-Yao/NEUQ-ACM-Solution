#include<bits/stdc++.h>
using namespace std;
int space[21][21],lei[21][21];
void find(int c,int d){
	space[c][d]=0;
	int p2=0;
	for(int i=c-1;i<=c+1;i++)
	for(int j=d-1;j<=d+1;j++){
		if(lei[i][j]==-2)space[c][d]++,p2=1;
	}
	if(p2) return;
	else{
		if(space[c-1][d]==-1) find(c-1,d);
		if(space[c+1][d]==-1) find(c+1,d);
		if(space[c][d-1]==-1) find(c,d-1);
		if(space[c][d+1]==-1) find(c,d+1);
		if(space[c-1][d-1]==-1) find(c-1,d-1);
		if(space[c-1][d+1]==-1) find(c-1,d+1);
		if(space[c+1][d-1]==-1) find(c+1,d-1);
		if(space[c+1][d+1]==-1) find(c+1,d+1);	
	}
}
int main(){
	int n,m,k,l,a,b,c,d,p,p3=0;
/**/	cin>>n>>m>>k>>l;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	space[i][j]=-1;
	for(int i=0;i<k;i++)
	cin>>a>>b,lei[a][b]=-2;
	for(int i=0;i<l;i++){
		cin>>c>>d;
		p=0;
		if(lei[c][d]==-2){
			p=1;break;
		}
		if(space[c][d]>=0)
			continue;	
		find(c,d);
	    for(int i1=0;i1<n;i1++){
		for(int j=0;j<m;j++)
			cout<<space[i1][j]<<" ";
		cout<<endl;
	    }
	    p3=0;
		for(int i1=0;i1<n;i1++){
			for(int j=0;j<m;j++)
			if(space[i1][j]<0){
	//			,cout<<lei[i][j]
					if(lei[i1][j]==-2)
					p=2;
					else{
						p=3;p3=1;break;
					}//	/**/
			}
	        if(p3){p=3;break;}
		}
	//	if(p==3)break;
		if(p==2){cout<<"You win"<<endl;return 0;}
	//	  else cout<<endl;
	    if(i<l-1)cout<<endl;
	}   

	if(p==1){cout<<"You lose"<<endl;return 0;}
}
