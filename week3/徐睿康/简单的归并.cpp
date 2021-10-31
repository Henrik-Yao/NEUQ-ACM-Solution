#include<bits/stdc++.h>
using namespace std;
int t,a[310],x,y;
int main(){
	cin>>t;
	while(t--){
		scanf("%d",&x);
		for(int i=1;i<=x;i++){
			scanf("%d",a+i);
		}
		scanf("%d",&y);
		for(int i=x+1;i<=x+y;i++){
			scanf("%d",a+i);
		}
		sort(a+1,a+x+y+1);
		for(int i=1;i<=x+y;i++){
			if(i==1)printf("%d",a[i]);
			else printf(" %d",a[i]);
		}
		puts("");
	}
	return 0;
}
