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
string a[9999];
string mat;
int kmp[1000010];
int ans;
void get_m()
{
    kmp[0] = -1;
    int i = 0, j =-1;
    while(i<mat.length())
    {
        if(j==-1 || mat[i]==mat[j]) kmp[++i] = ++j;
        else j = kmp[j];
    }
}
void match(int x)
{
    int i = 0, j = 0;
    while (i < a[x].length()) 
    {
        while ( j != -1 && a[x][i] != mat[j])j = kmp[j];
        i++;
        j++;
        if (j >= mat.length()) 
        {
            ans++;
            j = kmp[j];
            break;
        }
    }
}
int cnt = 1;bool flag;

int main()
{
    // freopen("read.in","r",stdin);
    char c;
    while((c=getchar())!='\n')
    {
        // if(c=='\n') break;
        if(c>='a'&&c<='z')
        {
            flag = true;
            c -= 'a' - 'A';
            a[cnt]+=c;
        }
        else if(c>='A'&&c<='Z')
        {
            flag = true;
            a[cnt]+=c;
        }
        else
        {
            if(flag)
            {
                flag = false;
                // cout<<a[cnt]<<endl;
                cnt++;
            }
        }
    }

    cin>>mat;
    for(int i=0;i<mat.length();i++)
    {
        if(mat[i]>='a'&&mat[i]<='z')
            mat[i] -= 'a' - 'A';
    }
    get_m();

    for(int i=1;i<=cnt;i++)
        match(i);

    cout<<ans;
    // for(int i=1;i<=mat.length();i++)
    // {
    //     // printf("kmp %d:%d\n",i,kmp[i]);
    //     printf("%d ",kmp[i]);
    // }
    // cout<<endl;


}