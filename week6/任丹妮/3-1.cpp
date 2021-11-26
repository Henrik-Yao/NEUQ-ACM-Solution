#include <bits/stdc++.h>
#define maxn 1000001
using namespace std;
void getNext(int l,char *a,int *next){
    next[1]=0;
    int k=0,i=1;
    while(i<=l){
        if(k==0||a[i]==a[k]){
            i++;k++;
            next[i]=k;
        }
        else k=next[k];
    }
}
int KMP(char *T,char *P,int *b){
    int ans=0;
    int i=1,j=1;
    int len1=strlen(T)-1;
    int len2=strlen(P)-1;
    while(i<=len1&&j<=len2){
        if(j==0||T[i]==P[j])
        {
            i++;j++; 
            if(j>len2) {
                ans++;
                i--;
                j=b[j-1];
            }
        }
        else j=b[j];
    }
    return ans;
}
int main(){
    char t[maxn],p[maxn];
    int next[maxn],i=1,j=1,num=0;
    char c;
    t[0]=' ';
    p[0]=' ';
    while((c=getchar())!='\n')
        t[i++]=c;
    t[i]='\0';
    while((c=getchar())!='\n')
        p[j++]=c;
    p[j]='\0';
    next[0]=0;
    getNext(j-1,p,next);
    num=KMP(t,p,next);
    cout<<num<<endl;
    return 0;
}
