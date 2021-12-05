//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
// #include <vector>
//#include <queue>
#include <cstdlib>
using namespace std;
#define qaq 1003
//#define FILE_IO
int s[qaq],w[qaq],v[qaq];
int main( )
{
	#ifdef FILE_IO 
	freopen("testdata.in","r",stdin); 
	freopen("compress.out","w",stdout); 
	#endif	
	int T,M,i,j;
    while(cin>>M)
    {
        cin>>T;
        memset(w,0,sizeof(w));
        memset(v,0,sizeof(v));
        memset(s,0,sizeof(s));
        for(i=1;i<=M;i++)
            scanf("%d",&w[i]);
        for(i=1;i<=M;i++)
            scanf("%d",&v[i]);
        
        for(i=1;i<=M;i++)
        {
            for(j=T;j>=0;j--)//权值+ 
            {
                if(j>=w[i])
                {
                    s[j] = max(s[j],s[j-w[i]]+v[i]);
                }
            }
        }
        
        printf("%d\n",s[T]);

    }
	
	
	
	
	#ifdef FILE_IO 
	fclose(stdin);
	fclose(stdout);
 	#endif	
	return 0;
}