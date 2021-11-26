#include <bits/stdc++.h>
using namespace std;
const long long maxn=1000005;
bool flag=false;
int n,ans; 
string a,b;
string c[100010];
void prefix_table(string pattern,int prefix[],int n){
	prefix[0]=0;
	int len=0,i=1;
	while(i<n){
		if(pattern[i]==pattern[len]){
			len++;
			prefix[i]=len;
			i++;
		}
		else if(len>0) len=prefix[len-1];
		else{
			prefix[i]=len;
			i++;
		}
	}
} 
void move_prefix_table(int prefix[],int n){
	for(int i=n-1;i>0;i--)
		prefix[i]=prefix[i-1];
	prefix[0]=-1;
}
void kmp_search(string pattern,string text){
	int n=pattern.size();
	int m=text.size();
	int * prefix=(int*)malloc(sizeof(int) * n);
	prefix_table(pattern,prefix,n);
	move_prefix_table(prefix,n);
	int i=0,j=0;
	while(i<m){
		if(j==n-1 && text[i]==pattern[j]){
			flag=true;
			j=prefix[j];
		}
		if(text[i]==pattern[j]){
			i++;j++;
		}
		else{
			j=prefix[j];
			if(j==-1){
				i++;j++;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	getline(cin,a);getline(cin,b);
	int lena=a.size(),lenb=b.size();
	for(int i=0;i<lenb;i++) 
		if(b[i]>='A' && b[i]<='Z')
			b[i]=b[i]-'A'+'a';
	for(int i=0;i<lena;i++)
		if(a[i]<'A' || (a[i]>'Z' && a[i]<'a') || a[i]>'z')
			if(flag) flag=0;
		else{
			if(!flag){
				n++;flag=1;
			}
			if(a[i]>='A' && a[i]<='Z')
				a[i]=a[i]-'A'+'a';
			c[n]+=a[i];
		}
	for(int i=0;i<=n;i++){
		kmp_search(b,c[i]);
		if(falg)
			ans++;
	}
	cout<<ans;
    return 0;
}
