#include<bits/stdc++.h>
using namespace std;
#define N 100
typedef struct node{
    int ww;
    int length;
}node;
int main() {
    int m,n;
    while (cin>>m>>n)
    {
        vector<node> f[m];
        for(int i = 0; i < n; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            node p;
            p.ww = b;
            p.length = c;
            f[a].push_back(p);
            p.ww = a;
            f[b].push_back(p);
        }
        int max = 100000;
        int num;
        int max1;
        for(int i = 0; i < m; i++)
        {
            if(f[i].size()==m-1)
            {
                num = 0;
                for(auto it:f[i])
                {
                    num+=it.length;
                }
                if(num<max){
                    max1 = i;
                    max = num;
                }
            }
        }
        cout<<max1<<endl;
    }
    return 0;
}