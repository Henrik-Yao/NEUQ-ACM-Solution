#include<bits/stdc++.h>
using namespace std;
string text,pattern;
int ans=0;
void getnext(int next[]){
      int i=0,j=1;
      next[0]=-1;
      next[1]=0;
      while(j<pattern.size()){
         if(i==-1||pattern[i]==pattern[j]) next[++j]=++i;
         else{
             i=next[i];
         }
         if(pattern[j]==pattern[next[j]]){
             next[j]=next[next[j]];
         }
      }

}
int main(){
    cin>>text>>pattern;
    int next[1000010];
    getnext(next);
       int i=0,j=0;
       while(i<text.size()){
         if(j==-1||text[i]==pattern[j]){
         	j++;
         	i++;
		 }
         else{
             j=next[j];
         }
         if(j==pattern.size()){
		  ans++;}//不用重置i和j，因为储存了next[j]也就是整个pat的next位置，下一次循环会自动更新j；
      }
    cout<<ans<<endl;

    return 0;
}