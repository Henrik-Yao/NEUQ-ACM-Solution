#include<iostream>
using namespace std;
bool a[100001]={1,1};
int b[100001];
int k; 
int main()
{
	int s,t;
	for(int i=2;i<=100001;i++)
	{
		if (a[i]==0)	b[++k]=i;	 
		for(int j=1;j<=k;j++)
		{
			if(i*b[j]>100001)break;
			a[i*b[j]]=1;
			if(i%b[j]==0)break;
		}	
	}
	
	while(cin>>s>>t){
    int ans[10010];int temp=0;
	for(int ss=s;ss<=t;ss++)
	{
		if(!a[ss]){
			ans[temp++]=ss;
		} 
	}
        for(int ll=0;ll<temp-1;ll++)
        {
            cout<<ans[ll]<<" ";
        }
        cout<<ans[temp-1];
        cout<<endl;
		}
return 0;
 } 
