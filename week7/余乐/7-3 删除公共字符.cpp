#include <cstdio>
#include <cstring>
#define N 100001
using namespace std;
char a[N],b[N];
int lena,lenb,u[N];
int main(){
	while(1){
		lena=lenb=0;
		char ch;
		while(scanf("%c",&ch)&&ch!='\n'){
			a[lena++]=ch;
		}
		if(lena==0) break;
		while(scanf("%c",&ch)&&ch!='\n'){
			b[lenb++]=ch;
		}
//		printf("ch=%c\n",ch);
		for(int i=0;i<lenb;i++) u[b[i]]=1;
//		for(int i=0;i<lenb;i++) printf("%d ",b[i]);
		for(int i=0;i<lena;i++)
			if(!u[a[i]])
				printf("%c",a[i]);
		for(int i=0;i<lenb;i++) u[b[i]]=0;
		printf("\n");
	}
	return 0;
}
