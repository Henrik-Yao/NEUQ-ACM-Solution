#include <cstdio>
#include <cstring>
using namespace std;
char a[10001];
int b,c,d;
int main(){
	scanf("%s",a);
	int len=strlen(a);
	for(int i=0;i<len;i++){
		if(a[i]=='(') b++;
		if(a[i]==')') b--;
		if(a[i]=='[') c++;
		if(a[i]==']') c--;
		if(a[i]=='{') d++;
		if(a[i]=='}') d--;
		if(b<0||c<0||d<0){
			printf("no");
			break;
		}
	}
	if(d>0||b>0||c>0) printf("no");
	else printf("yes");
	return 0;
}
