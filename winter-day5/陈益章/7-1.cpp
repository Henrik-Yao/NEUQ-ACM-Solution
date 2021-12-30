#include<iostream>
#include<cstring>
using namespace std;
bool a[10001];bool find_ans(int x)
{
	int a[132],n;
    int m,cnt=m,temp=a[1]+x;
    cnt--;
    for(int i=2;i<=n;i++)
    {
        if(temp<=a[i])
        {
            cnt--;
            temp=a[i]+x;
        }
    }
    if(cnt<=0) return 1;
    else return 0;
}

int main()
{
    memset(a,0,sizeof(a));
    int n,x;
    cin>>n;///////////////////////
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(a[x]==0) a[x]=1;
    }
    x=0;
    for(int i=1;i<=10000;i++)
        if(a[i]==1 && a[i-1]==1) x++;
    cout<<x;
}
