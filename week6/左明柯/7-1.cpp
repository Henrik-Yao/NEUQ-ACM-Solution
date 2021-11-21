#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int ans=0;
void getnext(string P,int next[]){
	int j=0,k=-1;
	next[0]=-1;
	while(j<P.length()-1){
		if(k==-1||P[j]==P[k]){
			j++;k++;
			next[j]=k;
		}
		else k=next[k];
	}
} 
void kmp(string T,string P){
    int next[maxn];
	getnext(P,next);int i=0;int j=0;
	while(i<T.length()){
		if(j==-1||T[i]==P[j]){
			i++;
			j++;
		}
		else j=next[j];
		if(j==P.length()){
			ans++;i--;
            j=next[j-1];
		}
	}
	
}
int main(){
string T,P;
cin>>T>>P;
kmp(T,P);
cout<<ans<<endl;


return 0;

}

