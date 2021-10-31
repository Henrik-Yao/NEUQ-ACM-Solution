#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
void pai(int n,int len,char s[]);
char a[8],s[8];
int b[8];
int main()
{
    cin>>a;
    int len=strlen(a),i;
    for(i=0;i<len;i++)
        b[a[i]]++;
    sort(a,a+len);
    
    pai(1,len,s);
}

void pai(int n,int len,char s[])
{
	
    if(n>len)
    {
    	for(int i=0;i<len;i++)
    	cout<<s[i];
        cout<<endl;
        return;
    }
    else
    {
        for(int i=0;i<len;i++)
        {
            if(b[i]==0)
            {
            	b[i]=1;
            	n++;
            	s[n-1]=b[i];
            	pai(n,len,s);
            	n--;
            	b[i]=0;
			}
        }
        
    }
	return;
}
