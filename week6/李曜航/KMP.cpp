#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
string a;
string mat;
int kmp[1000010];
void get_m(int len)
{
    kmp[0] = -1;
    int i = 0, j =-1;
    while(i<len)
    {
        if(j==-1 || mat[i]==mat[j]) kmp[++i] = ++j;
        else j = kmp[j];
    }
}
void match()
{
    int i = 0, j = 0, ans = 0;
    while (i < a.length()) 
    {
        while ( j != -1 && a[i] != mat[j])
            j = kmp[j];
        i++;
        j++;
        if (j >= mat.length()) 
        {
            ans++;
            printf("%d\n",i-j+1);
            j = kmp[j];
        }
    }
    cout<<ans;

}
int main()
{
    // freopen("read.in","r",stdin);
    cin>>a>>mat;
    get_m(mat.length());

    match();

    for(int i=1;i<=mat.length();i++)
    {
        // printf("kmp %d:%d\n",i,kmp[i]);
        printf("%d ",kmp[i]);
    }
    // cout<<endl;
    

    

}