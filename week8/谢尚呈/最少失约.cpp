#include<bits/stdc++.h>
using namespace std;
int T, n;
struct act{
    int be;
    int en;
}acti[105];

bool fit(act x, act y)
{
    return x.en<y.en;
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
	{
        cin>>n;
        for(int j=0; j<n; j++)    cin>>acti[j].be>>acti[j].en;
        sort(acti, acti+n, fit);
        int las=0;
        int tot=1;
        for(int j=1; j<n; j++)
		{
            if(acti[j].be>=acti[las].en)
			{
                las=j;
                tot+=1;
            }
        }
        cout<<n-tot<<endl;
    }
}

