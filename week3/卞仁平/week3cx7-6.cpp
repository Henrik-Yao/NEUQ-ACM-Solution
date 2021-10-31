#include <bits/stdc++.h>
using namespace std;
char a[9];
char s[9];
bool f[9];
int l;
void qpl(int zz);
int main()
{
    scanf("%s",a);
    l=strlen(a);
    sort(a,a+l);
    for(int i=0;i<l;i++)
	{
		f[i]=1;
		s[1]=a[i];
		qpl(1);
		f[i]=0;
	}
    return 0;
    
}

void qpl(int zz)
{
    if(zz==l)
    {
        for(int i=1;i<=l;i++)
        {
            cout<<s[i];
        }
        cout<<endl;
        return ;
    }
    for(int i=0;i<l;i++)
    {
        if(f[i]) continue;
        f[i]=1;
		s[zz+1]=a[i];
		qpl(zz+1);
		f[i]=0;
    }
    return ;

}