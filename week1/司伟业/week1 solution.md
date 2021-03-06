# 7-1 sting

对每个字符串，枚举模板的每一位作为起始匹配位置，然后依次判断后面的是否相同，当然也可以用AC自动机啦，本题数据范围较小，暴力匹配即可。

~~~c++
#include<bits/stdc++.h>
#define maxn 2000001
using namespace std;
char s[maxn],T[maxn];
int n,cnt,vis[200051],ans,in[maxn],Map[maxn];
struct kkk{
    int son[26],fail,flag,ans;
    void clear(){memset(son,0,sizeof(son)),fail=flag=ans=0;}
}trie[maxn];
queue<int>q;
void insert(char* s,int num){
    int u=1,len=strlen(s);
    for(int i=0;i<len;i++){
        int v=s[i]-'a';
        if(!trie[u].son[v])trie[u].son[v]=++cnt;
        u=trie[u].son[v];
    }
    if(!trie[u].flag)trie[u].flag=num;
    Map[num]=trie[u].flag;
}
void getFail(){
    for(int i=0;i<26;i++)trie[0].son[i]=1;
    q.push(1);
    while(!q.empty()){
        int u=q.front();q.pop();
        int Fail=trie[u].fail;
        for(int i=0;i<26;i++){
            int v=trie[u].son[i];
            if(!v){trie[u].son[i]=trie[Fail].son[i];continue;}
            trie[v].fail=trie[Fail].son[i]; in[trie[v].fail]++;
            q.push(v);
        }
    }
}
void topu(){
    for(int i=1;i<=cnt;i++)
    if(in[i]==0)q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();vis[trie[u].flag]=trie[u].ans;
        int v=trie[u].fail;in[v]--;
        trie[v].ans+=trie[u].ans;
        if(in[v]==0)q.push(v);
    }
}
void query(char* s){
    int u=1,len=strlen(s);
    for(int i=0;i<len;i++)
    u=trie[u].son[s[i]-'a'],trie[u].ans++;
}
int main(){
    scanf("%d",&n); cnt=1;
    cin>>T;
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        insert(s,i);
    }getFail();
    query(T);topu();
    for(int i=1;i<=n;i++)printf("%d\n",vis[Map[i]]);
}


~~~

# 7-2 区间

首先考虑贪心，因为如果取的两段区间不能覆盖这n个数，那么将这两个区间分别向左向右延伸后的权值一定更大，故两段区间一定恰好覆盖n个数，由于数据范围 :

$$
a_{i}\leq10^{5}
$$
故只需开个桶记录每个数在区间前缀后缀是否出现即可，然后求出前缀后缀区间和权值和的最大值
$$
ans=max\{lval_{i}+rval_{i+1}\}\quad(1\leq i<n)
$$

~~~c++
#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1000005],ans,aa[100002],bb[100002];
int ans1[1000005],ans2[1000005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!aa[a[i]])
        {
            aa[a[i]]=1;
            ans1[i]=ans1[i-1]+1;
        }
        else ans1[i]=ans1[i-1];
    }
    for(int i=n;i>=1;i--)
    {
        if(!bb[a[i]])
        {
            bb[a[i]]=1;
            ans2[i]=ans2[i+1]+1;
        }
        else ans2[i]=ans2[i+1];
    }
    for(int i=1;i<n;i++)
    {
        ans=max(ans,ans1[i]+ans2[i+1]);  
    }
    cout<<ans;
    return 0;
}
~~~

#  7-3 小步点

分别以(0,0)和(2d,0)为焦点画一个椭圆，然后使椭圆不断扩大，显然第一个与上方圆的焦点即为最短路径需要经过的点，另外特判一下圆是否与x轴相交即可。

~~~c++
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double r,d,n;
int main()
{
    cin>>r>>d>>n;
    d=abs(d);n=abs(n);
    if(n<=r)
    {
        printf("%.2lf",2*d-r);
        return 0;
    }
    n-=r;
    printf("%.2lf",2*sqrt(d*d+n*n)-r);
}
~~~



#  7-4 分糖果

简单递归

~~~c++
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int ans,n;

void dfs(int x)
{
    ans++;
    if(x==1) return;
    for(int i=1;i<x;i++)
    if(x%i==0) dfs(i);
}

int main()
{
    cin>>n;
    dfs(n);
    cout<<ans;
}

~~~

# 7-5 找眼镜

简单模拟

~~~c++
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define int long long
#define maxn 100005
using namespace std;

int read()
{
	int x=1,res=0;
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

int n,m,aa,bb,pre;
int a[maxn];
char c[maxn][15];

signed main()
{
	n=read();m=read();
	for(int i=0;i<n;i++)
	{
		a[i]=read();scanf("%s",c[i]);
	}
	pre=0;
	for(int i=1;i<=m;i++)
	{
		aa=read();bb=read();
		if(aa==1)//you
		{
			if(a[pre]==1)//wai
			{
				pre=((pre-bb)%n+n)%n;
			}
			else if(a[pre]==0)//nei
			{
				pre=(pre+bb)%n;
			}
		}
		if(aa==0)//zuo
		{
			if(a[pre]==1)//wai
			{
				pre=(pre+bb)%n;
			}
			else if(a[pre]==0)//nei
			{
				pre=((pre-bb)%n+n)%n;
			}
		}
	}
	printf("%s\n",c[pre]);
    return 0;
}
~~~

#  7-6 恰早饭

水题。。。

~~~c++
#include<iostream>
using namespace std;

int n,t,aa,bb,ans=-2000000000;

int main()
{
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>aa>>bb;
        if(bb<=t)ans=max(ans,aa);
        else ans=max(ans,aa+t-bb);
    }
    cout<<ans;
}
~~~

