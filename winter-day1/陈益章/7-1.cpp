#include<iostream>
using namespace std;
int n,q,l,r,k;
int lowbit(int x)
{
    return x&-x;
}
void add(int a[],int i,int x){
	while(i<=n)
	{
		a[i]+=x;
		i+=lowbit(i);
	}
}
int sum(int a[],int x){
	int sum=0;
	while(x>0){
		sum+=a[x];
		x-=lowbit(x);
	}
	return sum;
}
int main(){
	cin>>n>>q;
	int a[n];
	for (int i=1;i<=n;i++)
	{
	cin>>r;
	add(a,i,r);
}
	for (int i=0;i<q;i++){
		cin>>k>>l>>r;
		if(k==1){
			add(a,l,r); 
		}
		else{
		 	cout<<sum(a,r)-sum(a,l)<<endl;
		}
	}	
}
