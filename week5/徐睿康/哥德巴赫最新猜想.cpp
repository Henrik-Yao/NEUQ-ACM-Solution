#include<bits/stdc++.h>
using namespace std;
int x,flag,n;
int main(){
	cin>>n;
	while(n--){
		scanf("%d",&x);
		if(x%2==0){
			printf("2\n");
			continue;
		}
		flag=0;
		for(int i=2;i<=sqrt(x);i++){
			if(x%i==0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			printf("1\n");
			continue;
		}
		else{
			flag=0;
			for(int i=2;i<=sqrt(x-2);i++){
				if((x-2)%i==0){
					flag=1;
					break;
				}
			}
			if(flag==0)
				printf("2\n");
			else printf("3\n");
		}
	}
	return 0;
}
