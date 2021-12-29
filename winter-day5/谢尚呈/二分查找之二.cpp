#include<iostream>
using namespace std;

int list[1000];
 
int search(int x, int n)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int middle=(left+right)/2;
        if(x==list[middle]) return middle;
        if(x>list[middle]) left=middle+1;
        else right=middle-1;
    }
    return -1;
} 
 
int main()
{
    int n,x;
    while(cin>>n)
    {
	    for(int i=0; i<n; i++)
	    {
	    	int a;
	    	cin>>a;
	    	for(int j=0; j<=i; j++)
	    	if(j==i)	list[i]=a;
	    	else if(list[j]>a)
	    	{
	    		for(int k=i; k>j; k--)	list[k]=list[k-1];
	    		list[j]=a;
	    		break;
			}
		}
		
		for(int i=0; i<n; i++)
		{
			if(i)	cout<<" ";
			cout<<list[i];
		}
	    cout<<endl;
	    
	    cin>>x;
	    for(int i=0; i<x; i++)
	    {
	    	if(i)	cout<<" ";
	    	int re;
	    	cin>>re;
	    	cout<<search(re, n)+1;
		}
		cout<<endl;
		
		for(int i=0; i<n; i++)	list[n]=0;
	}
    return 0;
 
}
