#include <iostream>
#include <string.h>
using namespace std;
struct infor
{
    char sex;
    int f;
    int m;
}r[100010];
int visit[200010];
int flag;
void f(int a,int sum)
{
    if(sum>5||a==-1||a==0)
        return ;//如果超过五代或者没有父亲或母亲返回
    visit[a]++;//遍历次数
    if(visit[a]>=2)//说明五代以内有重叠的亲人
        flag=0;
    f(r[a].f,sum+1);
    f(r[a].m,sum+1);
    return ;
}
int main()
{
    int n;
    int myid,fid,mid;
    char c;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>myid>>c>>fid>>mid;
        r[myid].sex=c;
        r[myid].f=fid;
        r[myid].m=mid;
        r[fid].sex='M';
        r[mid].sex='F';
    }//初始化
    int m;
    int data1,data2;
    cin>>m;
    while(m--)
    {
        flag=1;
        memset(visit,0,sizeof(visit));
        cin>>data1>>data2;
        if(r[data1].sex==r[data2].sex)
        {
            cout<<"Never Mind"<<endl;
            continue;
        }//判断是不是同性
        f(data1,1);
        f(data2,1);
        if(flag)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }

    }
    return 0;
}

