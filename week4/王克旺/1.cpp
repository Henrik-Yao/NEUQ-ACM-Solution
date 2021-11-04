#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
	    int i,j,flag=1;
	    for(i=a;i<=b;i++)
	    {
	    	for(j=2;j<=sqrt(i);j++)
	    	{
	    		if(i%j==0)
	    		{
	    			break;
				}
			}
			if(j>sqrt(i))
		    {
		    	if(flag==1)
		    	{
		    		cout<<i;
		    		flag=0;
				}
				else
				{
					cout<<" "<<i;
				}
		    }
		}		
		cout<<endl;
	}
	return 0;
}
