#include<iostream>
using namespace std;
int n,a[1000001];
void qsort(int l,int r)//应用二分思想
{
	if(l>=r)return;
    int mid=a[l];//中间数
    int i=l,j=r;
    while(i<j){
        while(i<j&&a[j]>mid){
            j--;
        }
        while(i<j&&a[i]<=mid){
            i++;
        }
        swap(a[i],a[j]);
    }
    swap(a[l],a[i]);
    for(int i=1;i<=n;i++)
    	cout<<a[i]<<" ";
    	cout<<endl;
    qsort(l,i-1);qsort(j+1,r);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    qsort(1,n);
    for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
}
