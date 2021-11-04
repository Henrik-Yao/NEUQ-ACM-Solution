#include <iostream>
using namespace std;
int n,a[10001],sum=0,s=0;
void qiuhe(int l,int r)
{
	if(l==r-1) return;
	int s1=0,s2=0,s3=0;
	for(int i=1;i<=l;i++) s1+=a[i];
	for(int i=r+1;i<=n;i++) s3+=a[i];
	s2=s-s1-s3;
	sum=max(sum,s1);sum=max(sum,s2);sum=max(sum,s3);
	qiuhe(l,r-1);qiuhe(l+1,r);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	qiuhe(1,n);
	cout<<sum;
	return 0;
}
