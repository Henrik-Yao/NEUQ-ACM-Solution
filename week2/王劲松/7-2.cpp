#include<stdio.h>
int main(){
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	int lj[m][2],p[n+1];
	for(i=0;i<=n;i++){
		p[i]=0;
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&lj[i][0],&lj[i][1]);
	}
	int k;
	
	scanf("%d",&k);
	for(i=0;i<k;i++){
		int nb=0;
		for(j=0;j<m;j++){
			p[lj[j][0]]=1;
			p[lj[j][1]]=1;
		}
		int ml;
		scanf("%d",&ml);
		for(j=0;j<ml;j++){
			int t;
			scanf("%d",&t);
			p[t]=0;
		}
		//for(j=1;j<=n;j++){
		//	printf("%d",p[j]);
		//}
		for(j=0;j<m;j++){
			if(p[lj[j][0]]==1&&p[lj[j][1]]==1){
				nb=1;
				break;
			}
		}
		if(nb==0)printf("YES\n");
		else printf("NO\n");
		
	}
	return 0;
}
