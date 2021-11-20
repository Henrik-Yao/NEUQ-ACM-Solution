#include<bits/stdc++.h>
using namespace std;
int lena,lenb,kmp[1000010],ans=0;
char a[1000010],b[1000010];
int main(){
	scanf("%s %s",a+1,b+1);
	lena=strlen(a+1);
	lenb=strlen(b+1);
	//for(int i=1;i<=lena;i++)cout<<a[i];
	//for(int i=1;i<=lenb;i++)cout<<b[i];
	int j=0;
	for(int i=2;i<=lenb;i++){
		while(j!=0&&b[i]!=b[j+1])j=kmp[j];
		if(b[i]==b[j+1])j++;
		kmp[i]=j;
	}
	j=0;
	for(int i=1;i<=lena;i++){
		while(j!=0&&a[i]!=b[j+1])j=kmp[j];
		if(a[i]==b[j+1])j++;
		if(j==lenb){
			//cout<<i<<endl;
			ans++;
			j=kmp[j];
		}
	}
	printf("%d\n",ans);
	return 0;
}
