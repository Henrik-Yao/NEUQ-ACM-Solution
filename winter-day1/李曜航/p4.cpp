#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
list<int> fil;
list<int> odd;
list<int> even;
int main()
{
    // freopen("read.in","r",stdin);
    int a;
    while(cin>>a)
        fil.push_back(a);
    fil.sort();
    

    for(list<int>::iterator it=fil.begin();it!=fil.end();it++)
    {
        if(it==fil.begin())
            printf("%d",*it);
        else printf("->%d",*it);

        if(*it%2) odd.push_back(*it);
        else even.push_back(*it);
    }
    printf("\n");

    for(list<int>::iterator it=odd.begin();it!=odd.end();it++)
    {
        if(it==odd.begin())
        {
            printf("%d",*it);
            continue;
        }
        printf("->%d",*it);
    }
    printf("\n");
    for(list<int>::iterator it=even.begin();it!=even.end();it++)
    {
        if(it==even.begin())
        {
            printf("%d",*it);
            continue;
        }
        printf("->%d",*it);
    }    

    

}