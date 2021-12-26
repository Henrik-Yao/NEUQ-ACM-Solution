#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & (-x))
typedef long long var;
const int N = 1000010;
var read()
{
	var a = 0, s = 0, c = getchar();
	while (!isdigit(c)) s |= c == '-', c = getchar();
	while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
	return s ? -a : a;
}
int main()
{
   string partten;
   cin>>partten;
   int l = 0, r = 0;
   for (int i=0;i<partten.size();++i)
   {
        if(partten[i] == '(')
            l=i;
        if(partten[i] == ')')
            r=i;
   }//±éÀúÒ»±éÕÒÀ¨ºÅ 
   for (int i=0;i<partten.size();++i)//·­Òë 
   {
        if(partten[i]=='A')
            cout<<"sae";
        else if (partten[i]=='B')
            cout<<"tsaedsae";
        else if(partten[i] == '(')
		{
            cout<<partten[i+1];
    		for (int j=r-1;j>=l+2;--j)
			{
            	cout<<partten[j];
            	cout<<partten[i+1];
        	}
        	i = r;
    	}
   }
}
