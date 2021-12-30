#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int a[1005];
int searc(int a[],int s,int e,int x)
{
    while(s<=e)
    {
    cnt++;
    int mid=(e+s)/2;

    if(a[mid]==x)
        return mid;
    else if(a[mid]>x)
      e=mid-1;
   else
       s=mid+1;

    }
    return -1;

}
int main()
{
  int n,x;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  cin>>x;

  cout<<searc(a,0,n-1,x)<<endl;
  cout<<cnt<<endl;

  return 0;
}

