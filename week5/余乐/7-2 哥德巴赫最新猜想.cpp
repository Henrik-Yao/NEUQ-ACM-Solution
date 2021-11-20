#include <cstdio>
using namespace std;
int T;
int y(int a){
	for(int i=2;i*i<=a;i++)
		if(a%i==0) return 0;
	return 1;
}
int main(){
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		int b;
		scanf("%d",&b);
		if(b%2==0) printf("2\n");
		else{
			if(y(b)) {
				printf("1\n");
				continue;
			}
			if(y(b-2)) printf("2\n");
			else printf("3\n");
		}
	}
	return 0;
} 
