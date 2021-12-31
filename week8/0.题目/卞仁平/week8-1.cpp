#include <bits/stdc++.h>
using namespace std;
struct shijian
{
    int a;
    int b;
};
bool cmp(shijian s1,shijian s2)
{
    return (s1.b<s2.b);
}
void run()
{
    int n;
    cin>>n;
    shijian ps[n];
    int sum=1;
    for(int i=0;i<n;i++)
    cin>>ps[i].a>>ps[i].b;
    sort(ps,ps+n,cmp);
    int end=ps[0].b;
    for(int j=1;j<n;j++)
    {
        if(ps[j].a>=end)
        {
            sum++;end=ps[j].b;
        }
    }
    cout<<n-sum<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    run();
    return 0;

}