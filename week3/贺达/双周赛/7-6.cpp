#include<bits/stdc++.h>
using namespace std;

int vis[9];
char a[9];
void dfs(int x,int l,string str)
{
    if(x>l)
    {
        for(int i=1;i<=l;i++)
        {
           cout<<a[i];
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=l;i++)
    {
        if(vis[i]==0)
        {
            a[x]=str[i-1];
            vis[i]=1;
            dfs(x+1,l,str);
            vis[i]=0;
        }
    }
}

int main()
{
    string str;
    cin>>str;//排序
    int l=str.length();
    for(int i=0;i<l;i++){
        for(int j=0;j<l-i-1;j++){
            if(str[j]>str[j+1]){
                char c=str[j];
                str[j]=str[j+1];
                str[j+1]=c;
            }
        }
    }
    dfs(1,l,str);
    return 0;
}
