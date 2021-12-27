#include<bits/stdc++.h>
#include<stack>
using namespace std;
int gen[1000],pre[1000],x;
int main()
{
    int T;
    scanf("%d",&T);
	stack<int>s;
    while(T--)
    {
    	int A,B,i,n=0;
        scanf("%d",&i);
        gen[i]=n++;
        s.push(i);
        while(!s.empty())
        {
        	scanf("%d",&i);
        	if(i)
        	{
        		pre[i]=s.top();
        		gen[i]=n++;
        		s.push(i);
			}
			else
			{
				s.pop();
				n--;
			}
		}
		scanf("%d",&i);
        scanf("%d%d",&A,&B);
        if(gen[A]>gen[B])
		{
            x=gen[A]-gen[B];
            while(x--)
			{
                A=pre[A];
            }
        }
        else
		{
            x=gen[B]-gen[A];
            while(x--)
			{
                B=pre[B];
            }
        }
        while(pre[A]!=pre[B])
		{
            A=pre[A];
            B=pre[B];
        }
        printf("%d\n",pre[A]);
	}
    return 0;	
}
