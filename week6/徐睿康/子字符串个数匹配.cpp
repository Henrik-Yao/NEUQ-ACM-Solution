#include<bits/stdc++.h>
using namespace std;
char a[1010][1010],b[1010],c;
int len[1010],lenb,top=1,cnt=0,flag,ans=0;
int main(){
	while(c=getchar()){
		if(!isalpha(c)){
			if(cnt!=0){
				len[top]=cnt;
				cnt=0;
				top++;
			}
			if(c=='\n')break;
		}
		else{
			if(c-'a'<0)c+=32;
			a[top][cnt]=c;
			cnt++;
		}
	}
	cin>>b;
	lenb=strlen(b);
	for(int i=0;i<lenb;i++)if(b[i]-'a'<0)b[i]+=32;
	for(int i=1;i<=top;i++){
		for(int j=0;j<len[i];j++){
			if(a[i][j]==b[0]){
				flag=0;
				for(int k=0;k<lenb;k++){
					if(a[i][j+k]!=b[k]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					ans++;
					break;
				}
			}
		}
	}
	//for(int i=1;i<=top;i++)cout<<a[i]<<endl;
	printf("%d",ans);
	return 0;
}
