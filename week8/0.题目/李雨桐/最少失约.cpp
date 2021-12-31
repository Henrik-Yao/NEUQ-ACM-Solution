#include<bits/stdc++.h>
using namespace std;

struct activ{
    int a;
    int b;
}p[110];

bool comp(activ s1, activ s2)
{
    return s1.b<s2.b;
}

int main()
{
    int T,n;
    cin>>T;
    for(int m=0;m<T;m++)
        {
        cin >> n;
        for(int j=0;j<n;j++)
        {
            cin>>p[j].a>>p[j].b;
        }

        sort(p,p+n,comp);
        int j=0,num=1;

        for(int i=1;i<n;i++)
        {
            if(p[i].a>=p[j].b)
            {
                j=i;
                num++;
            }
        }
        cout<<n-num<<endl;
    }
    return 0;
}
