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
int n;
struct per
{
    bool sex; //0 boy, 1 girl
    int mo;//老妈id
    int fa;//老爸id
}p[100001];
bool flag = false, is = false;//is:是否是兄妹
void judge(int x, int y, int step)
{
    if(x==-1||y==-1||flag) return; //已经有-1了，返回，这个不搜
    if(step==4){return;}//4级搜完判断

    // printf("x:%d ,y:%d\n",x,y);//debug可以打印输出一下搜了哪些

    if(p[x].fa!=-1&&(p[x].fa==p[y].fa) || p[x].mo!=-1&&(p[x].mo==p[y].mo))//同父异母也是近亲结婚。。。无语了我怎么连这个都不知道
        {is = true; flag = true; return;}
    else
    {
        //四个判断：双方父亲，双方母亲，男方父亲和女方母亲，男方母亲和女方父亲
        judge(p[x].fa,p[y].fa,step+1);
        judge(p[x].mo,p[y].mo,step+1);
        judge(p[x].fa,p[y].mo,step+1);
        judge(p[x].mo,p[y].fa,step+1);
    }
}
int main()
{
    freopen("read.in","r",stdin);
    n = read();
    for(int i=1;i<=n;i++)
    {
        int id = read();
        char sex; scanf("%c",&sex);
        if(sex=='M') p[id].sex = 0;
        else p[id].sex = 1;
        p[id].fa = read();
        p[id].mo = read();
        
        //以下尊听玄神教诲，爸妈也会被判断，这里之前被卡了
        p[p[id].fa].sex = 0;//老爸记录性别
        p[p[id].mo].sex = 1;//老妈记录性别

        //如果爸妈没记录过那么fa/mother就是-1
        if(p[p[id].fa].fa==0) p[p[id].fa].fa=-1;
        if(p[p[id].fa].mo==0) p[p[id].fa].mo=-1;
        if(p[p[id].mo].fa==0) p[p[id].mo].fa=-1;
        if(p[p[id].mo].mo==0) p[p[id].mo].mo=-1;
    }
    int query = read();
    int a,b;
    while(query--)
    {
        flag = false; is = false;
        a = read(), b = read();
        if((p[a].sex^p[b].sex)==0){printf("Never Mind\n");continue;}//异或：判断你们是否是男酮。。。
        judge(a,b,0);
        if(is){printf("No\n");continue;}
        else{printf("Yes\n");continue;}
    }

    
}