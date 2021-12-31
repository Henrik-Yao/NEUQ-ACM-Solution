#include<bits/stdc++.h>
using namespace std;
const int MAXN=110;
int mp[MAXN][MAXN];
int main(){
    int n,e;
    //用scanf的话需要加一个~，按位取反
    while(cin>>n>>e){
        memset(mp,0x3f3f3f,sizeof(mp));
        for(int i=1;i<=e;i++){
            int i1,i2,powe;
            scanf("%d %d %d",&i1,&i2,&powe);
            i1++;
            i2++;
            if(i1==i2)mp[i1][i2]=0;//他自己路径就为0；
            else{
                mp[i1][i2]=powe;
                mp[i2][i1]=powe;
            }
        }
        //输入处理

        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(mp[i][j]>mp[i][k]+mp[k][j])
                    mp[i][j]=mp[i][k]+mp[k][j];
                }
            }
        }
        //floyed，循环得到每一个点到其他点的最小路径

        int dis[MAXN]={0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j) dis[i]=dis[i]+mp[i][j];
            }
        }
        //暴力计算每一个城市到其他城市的路径和

        int ans=0x3f3f3f3f;
        int p=1;//记录城市
        for(int i=1;i<=n;i++){
            if(dis[i]<ans) ans=dis[i],p=i;
        }
        p--;//注意加加处理过，减去1；
        printf("%d\n",p);


    }

    return 0;
}