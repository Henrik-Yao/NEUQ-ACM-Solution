#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int a[105];
int track;
int seq[100];
int rec[105][105];
int rec_indi[105];
int main()
{
    freopen("read.in","r",stdin);
    int n = read();
    a[1] = read();
    seq[++track] = a[1], rec[track][++rec_indi[track]]=a[1];
    for(int i=2;i<=n;i++)
    {
        a[i] = read();
        if(a[i]>seq[track]) 
			seq[++track] = a[i],rec[track][++rec_indi[track]]=a[i];
        else
        {
        	bool flag = false;
            for(int j=track;j>=1;j--)
            {
                if(a[i]>seq[j])
                {
                    seq[j+1] = a[i];
                    rec[j+1][++rec_indi[j+1]]=a[i];
                    flag = true;
                    break;
                }
            }
            if(flag) continue; 
            seq[1] = a[i];
            rec[1][++rec_indi[1]] = a[i];
        }
    }
    cout<<track<<endl;
    for(int i=1;i<=track;i++)
    {
//        cout<<seq[i]<<endl;
    	if(seq[i]==1)
    	{
    		for(int j=1;j<=rec_indi[i];j++)
            cout<<rec[i][j]<<" ";
    		
		}
	}
//    cout<<endl;
//    for(int i=1;i<=track;i++)
//    {
//        for(int j=1;j<=rec_indi[i];j++)
//            cout<<rec[i][j]<<" ";
//        cout<<endl;
//    }
}
