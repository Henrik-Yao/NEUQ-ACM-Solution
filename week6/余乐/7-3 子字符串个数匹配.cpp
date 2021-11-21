#include <cstdio>
#include <cstring>
#define N 112501
using namespace std;
char a[N],b[N],c[N],ch;
int next[N],lena=0,lenb=0,t,ans=0;
void get_next(){
	next[0]=-1;
	int j=0,k=-1;
	while(j<lenb){
		if(k==-1||b[k]==b[j]){
			if(b[++k]==b[++j])
				next[j]=next[k];
			else next[j]=k;
		}
		else k=next[k];
	}
}
int kmp(){
	int p=0,q=0;
	while(p<t){
		if(c[p]==b[q]||q==-1){
			p++;q++;
		}
		else q=next[q];
		if(q==lenb) return 1;
	}
	return 0;
}
int main(){
	while(scanf("%c",&ch)&&ch!='\n'){
        a[lena++]=ch;
    }
    scanf("%s",b);
    lenb=strlen(b);
	for(int i=0;i<lena;i++)
		if('A'<=a[i]&&a[i]<='Z')
			a[i]+=32;
	for(int i=0;i<lenb;i++)
		if('A'<=b[i]&&b[i]<='Z')
			b[i]+=32;
//	for(int i=0;i<lenb;i++)
//			printf("%c",b[i]);
//		printf("\n");
	get_next();
	int p=0;
	while(p<lena){
		t=0;
		while(p<lena){
			if(a[p]<'a'||a[p]>'z') break;
			c[t++]=a[p++];
		}
//		for(int i=0;i<t;i++)
//			printf("%c",c[i]);
//		printf("\n");
		while(p<lena){
			if('a'<=a[p]&&a[p]<='z') break;
			p++;
		}
		ans+=kmp();
	}
	printf("%d",ans);
	return 0;
}
