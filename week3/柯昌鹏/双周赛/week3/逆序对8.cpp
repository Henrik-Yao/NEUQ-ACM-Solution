#include <iostream>
using namespace std;

const int N=1e6+10;
int q[N],temp[N];
int n;

int mer(int l,int r,long long sum)
{
	if(l>=r) return 0;
	int mid=(r+l)/2;
	long long L=mer(l,mid,0),R=mer(mid+1,r,0);
	int i=l,j=mid+1,k=0;
	while(i<=mid&&j<=r)
	{
		if(q[i]<=q[j]) {
			temp[k++]=q[i++];
		} 
		else {
			temp[k++]=q[j++];
			sum+=mid-i+1;
		}
	}
	while(i<=mid) temp[k++]=q[i++];
	while(j<=r)   temp[k++]=q[j++];
	for(int a=l,b=0;a<=r;a++,b++) {
		q[a]=temp[b];
	}
	return L+R+sum;
	
  }
  
  int main ()
  {
  	cin>>n;
  	for(int i=0;i<n;i++)
  	{
  		cin>>q[i];
	  }
	  long long res=mer(0,n-1,0);
	  cout<<res;
	  return 0;
  }
