#include<bits/stdc++.h>
using namespace std;
int a[100000];
int n,m;
bool judge(int num){
	int cow=1;
	int pre=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[pre]>=num){
		cow++;
		pre=i;
        }
	}
  return cow>=m;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int l=1;
    int r=a[n];
    while(l<r){
    	int mid=(l+r+1)/2;
    	if(judge(mid))l=mid;
    	else r=mid-1;
	}
	printf("%d",l);
	return 0;
}
