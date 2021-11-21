#include <cstdio>
#include <cstring>
#define N 1000001
using namespace std;
char a[N],b[N];
int next[N],lena,lenb,ans=0;
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
void kmp(){
	int p=0,q=0;
	while(p<lena){
		if(a[p]==b[q]||q==-1){
			p++;q++;
		}
		else q=next[q];
		if(q==lenb){
			ans++;q=next[q];
		}
	}
}
int main(){
	scanf("%s%s",a,b);
	lena=strlen(a);lenb=strlen(b);
	get_next();
	kmp();
//	for(int i=0;i<=lenb;i++)
//		printf("%d ",next[i]);
	printf("%d\n",ans);
	return 0;
} 
