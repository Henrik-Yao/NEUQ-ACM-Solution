#include<bits/stdc++.h>
using namespace std;

int a[100005];
int n,m;
//���þ����Ƿ����
bool check(int x)
{
    int cnt=1;
    int last=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]-a[last]>=x)
        {
            cnt++;
            last=i;  //����ǰһ��
        }
    }
    if(cnt>=m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int mi=0x3f3f3f3f;
    for(int i=1;i<=n;i++) //�ҳ���С���
    {
        mi=min(a[i]-a[i-1],mi);
    }
    int l=mi;
    int r=a[n]-a[1];   //�����
    int ans=r;
    //���ֲ���
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;//���������ͼ�¼
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
