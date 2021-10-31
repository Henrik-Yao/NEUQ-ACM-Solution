#include<bits/stdc++.h>
using namespace std;

void guibingsort2(int *a,int s,int m,int e){
    int t[e-s+1];
    int p1=s;
    int p2=m+1;
    int p=0;
    while(p1<=m&&p2<=e)
    {
        if(a[p1]<=a[p2])
        {
            t[p++]=a[p1++];
        }
        else
        {
            t[p++]=a[p2++];
        }
    }
    while(p1<=m)
    {
        t[p++]=a[p1++];
    }
    while(p2<=e)
    {
        t[p++]=a[p2++];
    }
    for(int i=0;i<p;i++)
    {
        a[i+s]=t[i];
    }
}

void guibingsort1(int *a,int s,int e)
{
    if(s>=e){
        return ;
    }
    int m=(s+e)/2;
    guibingsort1(a,s,m);
    guibingsort1(a,m+1,e);
    guibingsort2(a,s,m,e);

}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
	guibingsort1(a,0,n-1);
	for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
	return 0;
}
