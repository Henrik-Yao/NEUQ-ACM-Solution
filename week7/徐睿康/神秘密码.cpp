#include<bits/stdc++.h>
using namespace std;
char c,a[20010];
long long stac[20010],top,len,cun[20010],temp;
long long i=0;
string s;
int main(){
	cin>>s;
	for(i=0;i<s.length();i++){
		c=s[i];
		if(c!='[')cout<<c;
		else{
			top=1;
			len=0;
			memset(stac,0,sizeof(stac));
			memset(a,0,sizeof(a));
			while(1){
				i++;
				c=s[i];
				if(isdigit(c)){
					stac[top]*=10;//���� 
					stac[top]+=c-'0';
					cun[top]=len;
				}
				if(isalpha(c))a[++len]=c;
				if(c=='[')top++;
				if(c==']'){
					temp=len-cun[top];
					for(long long t=1;t<=stac[top];t++)
					for(long long i=cun[top]+(t*temp)+1;i<=cun[top]+((t+1)*temp);i++)a[i]=a[i-temp];
					len=cun[top]+((stac[top])*temp);
					stac[top]=0;//����յĻ���Ҫ��գ���Ҫ�����Ÿ��� 
					top-=1;//ǰ�����stac��û�����������ã���һ���������в������������ŵ������stac���ص�
					if(top==0){
						for(long long i=1;i<=len;i++)cout<<a[i];
						break;
					}
				}
			}
		}
	}
	//cout<<endl;
	return 0;
}
