#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int i,j,flag=0;
	int a,b;
	int flag_su[10000];
	flag_su[0]=0;
	flag_su[1]=0;
	while(scanf("%d %d",&a,&b)!=EOF){
		flag = 0;
		for(int i=0; i<=b; i++){
			flag_su[i]=1;
		}
		for(int i=2; i<=b; i++){
			if(flag_su[i]){
				for(int j=2*i;j<=b;j+=i)
					flag_su[j] = 0;
			}
		}
		for(int i=a; i<=b; i++) 
			if(flag_su[i]){
				if(flag) printf(" ");
				printf("%d",i);
				flag++;
			}
		printf("\n");
	}

	return 0;
} 
