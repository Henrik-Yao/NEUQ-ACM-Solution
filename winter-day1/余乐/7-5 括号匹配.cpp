#include <cstdio>
#include <cstring>
using namespace std;
char a[100001];
int main(){
	while(~scanf("%s",a)){
		int len=strlen(a),sum=0,ansl=0;
		for(int i=0;i<len;i++){
			if(a[i]=='(') sum++;
			else sum--;
			if(ansl>sum) ansl=sum;
		}
		if(ansl==0&&sum==0) printf("Match");
		else{
			printf("%d\n",-2*ansl+sum);
			for(int i=1;i<=-ansl;i++)
				printf("(");
			for(int i=0;i<len;i++)
				printf("%c",a[i]);
			for(int i=1;i<=sum-ansl;i++)
				printf(")");
		}
		printf("\n");
	}
	return 0;
}
