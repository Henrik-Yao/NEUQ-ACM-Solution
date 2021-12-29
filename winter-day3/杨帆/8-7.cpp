#include<bits/stdc++.h>
using namespace std;
struct Node{
    int a;
    int b;
    int cost;
};
int fa[55];

bool cmp(Node a, Node b)
{
    return a.cost<b.cost;
}

int find(int x)
{
    int a = x ;
    while(x!=fa[x]){
        x=fa[x];
    }
    return x;
}

int main()
{
    int n,v,e;
    while(cin>>n>>v>>e)
    {
        Node s[e];
        for(int i=0;i<55;i++){
            fa[i]=i;
        }
        for(int i=0;i<e;i++){
            cin>>s[i].a>>s[i].b>>s[i].cost;
        }
        sort(s,s+e,cmp);
        int cnt=0,num,sum;
        num = sum = cnt;
        for(int i=0;i<e;i++){
            if(s[i].a==v||s[i].b==v){
                int ta=find(s[i].a);
                int tb=find(s[i].b);
                if(cnt<2 && ta!=tb){
                    cnt++;
                    num++;
                    sum+=s[i].cost;
                    fa[ta]=tb;
                }
            }
            else if(s[i].a!=v && s[i].b!=v){
                int ta=find(s[i].a);
                int tb=find(s[i].b);
                if(ta!=tb){
                    num++;
                    sum+=s[i].cost;
                    fa[ta]=tb;
                }
            }
            if(num == n-1){
                break;
            }  
        }
        if(num==n-1){
            cout<<sum<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}
