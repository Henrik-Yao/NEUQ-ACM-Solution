#include<bits/stdc++.h>
using namespace std;
bool mmap[1002][1002];
int vst[1002][1002]={0},same[1002][1002]={0},size[1002];
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//same用于上色，size用于记录个数；
int n,m,i,j,ans=1;//ans指不同类的颜色（联通块）
void bfs(int i,int j,int flag){
     
}
int main(){
   cin>>n>>m;
   while(n--){
       int i=1;
       while(n--){
       int ch,j=1;
       cin>>ch;
       if(ch='0')
       mmap[i][j++]=0;
       else
       mmap[i][j++]=1;
       }
   }
   while(m--){
      cin>>i>>j;
      if(vst[i][j]) cout<<size[same[i][j]]<<endl;
      else{


      }

   }

   return 0;
}