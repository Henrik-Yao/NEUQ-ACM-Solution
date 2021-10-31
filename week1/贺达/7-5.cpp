#include<bits/stdc++.h>
using namespace std;

string name[100005];
int a[100005];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>name[i];
    }
    int now = 0;
    int next_pos = 0;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        if((a[now] ^ x)==0) // if equal
        {
            next_pos = (now - y + n) % n;
        }else{
            next_pos = (now + y) % n;
        }
        now = next_pos;
    }
    cout<<name[next_pos]<<endl;
}
