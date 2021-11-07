#include<bits/stdc++.h>

using namespace std;

void y(int c[][2],int c2,int c1)
{

        if(c2==c1)return;
        int a=c[c2][0];
        int b=c[c2][1];
        int z=0;
        for(int j=a;j<=b;j++)
        {
            int t=0;
            for(int k=2;k<=j/2;k++)
            {
                if(j%k==0)t=1;
            }

            if(t==0&&z==0)
            {
                cout<<j;
                z++;
            }
            else if(t==0)cout<<' '<<j;

        }
        cout<<endl;
        c2++;
        y(c,c2,c1);
}

int main()
{
    int a;
    int b;
    int c[10000][2];
    int c1=0;
    while(cin>>a)
    {
        cin>>b;
        c[c1][0]=a;
        c[c1++][1]=b;

    }
    y(c,0,c1);
    return 0;
}
