#include<iostream>
#include<vector>
using namespace std;
vector<int>v;
bool find_ans(int x)
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
    int a[100001],b[100001],c[200001],n,ai=0,bi=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=1;i<2*n;i++)
        if(a[ai]<=b[bi])
        {
            v.push_back(a[ai]);
            ai++;
        }
        else
        {
            v.push_back(b[bi]);
            bi++;
        }
    cout<<v[(v.size()-1)/2];///////////////
}
