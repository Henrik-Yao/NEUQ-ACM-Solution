#include<iostream>
#include<cmath>
using namespace std;

int flag_su[10000100];

int main(){
	int i,j,flag=0;
	int a,b;
	int n;
	int sum=0;
	scanf("%d",&n);

	flag_su[0]=0;
	flag_su[1]=0;
		flag = 0;
		for(int i=0; i<=n; i++){
			flag_su[i]=1;
		}
		for(int i=2; i<=n; i++){
			if(flag_su[i]){
				for(int j=2*i;j<=n;j+=i)
					flag_su[j] = 0;
			}
		}
		for(int i=2; i<=n; i++) {
			if(flag_su[i]){
			sum++;
			}
		}
	printf("%d",sum);	
			

	return 0;
} 
