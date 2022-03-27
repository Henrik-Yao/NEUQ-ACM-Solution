#include <cstdio>
#include <cstring>
using namespace std;
char a[10001];
int main(){
	scanf("%s",a);
	int len=strlen(a);
	for(int i=0;i<len;i++){
		if(a[i]=='A') printf("sae");
		if(a[i]=='B') printf("tsaedsae");
		if(a[i]=='('){
			int t=i+2;
			while(1){
				if(a[t]==')') break;
				t++;
			}
			t--;
			while(t>i+1){
				printf("%c%c",a[i+1],a[t]);
				t--;
			}
			printf("%c",a[i+1]);
		}
	}
	printf("\n");
	return 0;
}
