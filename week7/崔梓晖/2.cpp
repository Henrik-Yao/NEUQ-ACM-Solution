#include <bits/stdc++.h>
using namespace std;
int sum,n;
int s[105],e;
string a,b,now;
int main()
{
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='[')         
        {
            s[++sum]=i;
        }
    }
    for(int i=sum;i;i--) 
	{   
        e=2;
		n=0;
		b.clear();
		now.clear();     
        for(int j=s[i]+1;a[j]!=']';j++)
        {
            if(a[j]>='0'&&a[j]<='9')     
            {
                n=n*10+a[j]-'0';
            }
            else
            {
                b=b+a[j];
            }
            e++;        
        }
        for(int j=1;j<=n;j++)         
        {
            now=now+b;
        }
        a.erase(s[i],e);        
        a.insert(s[i],now);         
    }
    cout<<a;
    return 0;
}

