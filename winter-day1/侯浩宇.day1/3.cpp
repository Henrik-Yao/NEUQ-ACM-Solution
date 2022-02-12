#include<bits/stdc++.h>
using namespace std;
int n,m,k,nextt[1001],head[1001],p=0;
int nex(int n1,int n2){
	for(int i=1;i<n2;i++)
	n1=nextt[n1];
	return n1;
}
int hea(int n1,int n2){
	for(int i=1;i<n2;i++)
	n1=head[n1];
	return n1;	
}
void f1(int number);
void f2(int number);
int main(){ 
	cin>>n>>m>>k;
//	for(int i=1;i<=n;i++)
//	a[i]=i;
	nextt[1]=n;
	for(int i=n;i>1;i--)
	nextt[i]=i-1;
	head[n]=1;
	for(int i=1;i<n;i++)
	head[i]=i+1;
	f1(1);
	return 0;
}
void f1(int number){
	int ans;
	ans=nex(number,m);
	cout<<ans<<" ";p++;
	nextt[head[ans]]=nextt[ans];
	head[nextt[ans]]=head[ans];
	if(p<n)f2(nextt[ans]);
}
void f2(int number){
	int ans;
	ans=hea(number,k);
	cout<<ans<<" ";p++;
	nextt[head[ans]]=nextt[ans];
	head[nextt[ans]]=head[ans];
	if(p<n)f1(head[ans]);
}
