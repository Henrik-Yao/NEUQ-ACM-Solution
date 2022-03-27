# 7-1 词典

利用map建立英语单词和外语单词之间的映射，每次查询判断有无映射关系即可。

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
int read()
{
    int res=0,x=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
        x=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        res=res*10+(c-'0');
        c=getchar();
    }
    return res*x;
}
int n,m;
map<string,string>q;
map<string,int>s;
int main()
{
    string a,b;
    n=read();m=read();
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        q[b]=a;
        s[b]=1;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a;
        if(s[a]==0) puts("eh");
        else cout<<q[a]<<endl;
    }
    return 0;
}
~~~

# 7-2 神秘密码 

根据题意模拟，可以开一个栈来保存左括号和右括号，每次读到左括号压入栈，读到右括号将此位置到上一个入栈的左括号之间的字符解压缩即可。

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define int long long 
#define maxn 100555
using namespace std;

int read()
{
	int res=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

int cnt,len,ans[maxn];
string a,b[maxn];

signed main()
{
	cin>>a;
	len=a.size();
	for(int i=0;i<len;i++)
	{
		if(cnt==0&&a[i]!='[') cout<<a[i];
		else if(a[i]=='[')
		{
			cnt++;
			if(a[i+1]>='0'&&a[i+1]<='9'&&a[i+2]>='0'&&a[i+2]<='9')
			{
				ans[cnt]=(a[i+1]-'0')*10+a[i+2]-'0';
				i++;
			}
			else ans[cnt]=(a[i+1]-'0');
			i++;
		}
		else if(a[i]==']')
		{
			cnt--;
			while(ans[cnt+1]--)
			{
				b[cnt]=b[cnt]+b[cnt+1];
			}
			b[cnt+1].clear();
			if(cnt==0)
			{
				cout<<b[0];
				b[0].clear();
			}
		}
		else if(cnt!=0)
		{
			b[cnt]=b[cnt]+a[i];
		}
	}
	return 0;
}

~~~

# 7-3 删除公共字符

利用map存储待删除的字符，然后将原字符串待删除字符依次删除即可。

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
using namespace std;

int read()
{
	int res=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

map<string,int>q;
int len1,len2;

int main()
{
	string a,b,c;
	while(getline(cin,a))
	{
		q.clear();
		getline(cin,b);
		len1=a.size();len2=b.size();
		for(int i=0;i<len2;i++)
		{
			c=b[i];
			q[c]=1;
		}
		for(int i=0;i<len1;i++)
		{
			c=a[i];
			if(q[c]) continue;
			else cout<<a[i];
		}
		puts("");
	}
	return 0;
}

~~~

# 7-4 最长有序子序列 

设dp[i]表示以i结尾的最长上升子序列长度。则：
$$
dp[i]=max\{dp[i],dp[j]+1\}~~~({1}\leq{j}<i)
$$

~~~c++
#include<iostream>
using namespace std;
int f[10005],a[1050];
int main()
{
    int t,n,ans,tot=0;
    cin>>t;
    while(t--)
    {
        ans=0;    tot++;
        cin>>n;
        for(int i=1;i<=n;i++)
        {          
            cin>>a[i];
            f[i]=1;            
         }
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(a[i]>a[j])
                f[i]=max(f[i],f[j]+1);
            }
            ans=max(ans,f[i]);
        }
        if(tot==1)
        cout<<ans;
        else cout<<endl<<endl<<ans;
    }
}

~~~

# 7-5 0-1背包问题 

简单0-1背包问题，设dp[i]表示体积为i时的最大价值。则:
$$
dp[i]=max\{dp[i],dp[i-w[i]]+v[i]\}~~~(w[i]\leq i)
$$
由于每件物品只能选一次，倒序循环背包体积即可。

~~~c++
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int w[2005],v[2005];
int f[2005],ans,n,c;
int main()
{
    while(cin>>n>>c)
    {
        memset(f,0,sizeof(f));ans=0;
        for(int i=1;i<=n;i++)
            cin>>w[i];
        for(int i=1;i<=n;i++)
            cin>>v[i];
        for(int i=1;i<=n;i++)
            for(int j=c;j>=w[i];j--)
            {
                f[j]=max(f[j],f[j-w[i]]+v[i]);
                ans=max(ans,f[j]);
            }
        cout<<ans<<endl;
    }
}
~~~

