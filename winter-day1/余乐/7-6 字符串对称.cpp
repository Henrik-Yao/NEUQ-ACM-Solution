#include <cstdio>
#include <cstring>
using namespace std;
char a[10001];
int main(){
	scanf("%s",a);
	int len=strlen(a);
	for(int i=0;i<len/2;i++)
		if(a[i]!=a[len-i-1]){
			printf("no");return 0;
		}
	printf("yes");
	return 0;
} 
