#include <bits/stdc++.h>
using namespace std;
const int maxn=10001;
string a,b;
string S[maxn];
int main()
{
    getline(cin,a);//cin不能读入空格，getline可以 
    getline(cin,b);
    int f=0,ans=0;
    for(int i=0;i<b.length();i++)//对b进行预处理（都转化为小写格式） 
    {
		if(b[i]>='A'&&b[i]<='Z')
        {
        	b[i]+=32;
    	}
	}	
    for(int i=0;i<a.length();i++)//对a进行 
    {
        if(a[i]<'A'||a[i]>'z'||(a[i]>'Z'&&a[i]<'a'))
        {
            if(f==1)
			{
				f=0;
			}
        }    
        else 
        {
            if(a[i]>='A'&&a[i]<='Z')
            {
                a[i]+=32;
        	}
            if(f==0)
            {
                f=1;
                ans++;
            }
            S[ans]+=a[i];//存入符合标准的字符串
        }
    }
    int s=0;//输出 
    for(int i=0;i<=ans;i++)
    {
        if(S[i].find(b)!=-1)
        s++;
    }
    cout<<s;
    return 0;
}
