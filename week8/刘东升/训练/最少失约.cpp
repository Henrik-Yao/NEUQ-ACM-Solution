#include<bits/stdc++.h>
using namespace std;
const int M=1e6;
struct pa//�����ݴ����ڽṹ���� 
{
    int begin;
    int end;
}met[M];
bool cmp(pa n,pa m)//����һ���ж� 
{
    return n.end<m.end;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>met[i].begin>>met[i].end;
        }
        sort(met,met+n,cmp);
        int ans=1;
        int j=0;
        for(int i=1;i<n;i++)
        {
            if(met[i].begin>=met[j].end)
            {
                ans++;
                j=i;
            }
        }
        cout<<n-ans<<endl;
    }
}
