### day05 题解
* 明天就能回家啦（划去）
### 7-1 相邻数对
一道很简单的水体。
```C++
#include <bits/stdc++.h>
using namespace std;
int a[2000];
int num;
int sum=0;
void search(int n)
{
    for(int i=n+1;i<num;i++)
    {
        if(abs(a[i]-a[n])==1)
        {
            sum++;
        }
    }
    return;
}
int main()
{
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<num;i++)
    search(i);
    cout<<sum<<endl;

    return 0;
}
### 7-3 相邻中位数
公式代换即可
```C++
#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int num;
    cin>>num;
    for(int i=0;i<num*2;i++)
    cin>>a[i];
    sort(a,a+num*2);
    cout<<(a[num]+a[num-1])/2<<endl;

    return 0;
}
```
### 7-4 二分查找
二分查找分为左闭右开型和左闭右闭型，两种注意其等号的条件，否则容易出错。
```C++
#include <bits/stdc++.h>
using namespace std;
int sum=0;
int search(int a[],int len,int tar)
{
    int left=0;
    int right=len-1;
    while(left<=right)   //左闭右开型
    {
        sum++;
        int mid=(left+right)/2;
        if(tar>a[mid])
        {
            left=mid+1;
        }
        else if(tar<a[mid])
        {
            right=mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main()
{
    int a[1000];
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    cin>>a[i];
    sort(a,a+num);
    int tar;
    cin>>tar;
    cout<<search(a,num,tar)<<endl;
    cout<<sum<<endl;
    return 0;
}
```
### 7-5 冰岛人
可以用map来进行对应模拟
可以用并查集来解
```C++
#include <bits/stdc++.h>
using namespace std;
int flag = 0;               //判断祖上有没有相同的祖先
map<string, string> people; //该人名字为指引，指向的人的名字为结果
map<string, int> sex;       // 1为男，2为女
map<string, int> visit;     //记录向上询问时找到的祖先
void judge(string surname, string name)
{
    int len = surname.size();
    if (surname[len - 4] == 's' && surname[len - 3] == 's' && surname[len - 2] == 'o' && surname[len - 1] == 'n')
    {
        string father = surname.substr(0, len - 4);
        people[name] = father;
        sex[name] = 1;
    }
    else if (surname[len - 7] == 's' && surname[len - 6] == 'd' && surname[len - 5] == 'o' && surname[len - 4] == 't' && surname[len - 3] == 't' && surname[len - 2] == 'i' && surname[len - 1] == 'r')
    {
        string father = surname.substr(0, len - 7);
        people[name] = father;
        sex[name] = 0;
    }
    else
    {
        people[name] = name; //始祖人物
    }
}
void find(string name, int n) //并查集
{
    if (n == 0)
    {
        // cout<<name<<endl;
        if (visit[name])
            flag = 1;
        else
            visit[name] = 1;
        return;
    }
    else
    {
        if (visit[name])
            flag = 1;
            visit[name]=1;
        find(people[name], n - 1);
    }
}
int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        string name;
        string surname; //名和姓
        cin >> name >> surname;
        judge(surname, name);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string name1, surname1, name2, surname2;
        cin >> name1 >> surname1 >> name2 >> surname2;
        if (people[name1].empty() || people[name2].empty())
        {
            cout << "NA" << endl;
            continue;
        }
        if (sex[name1] == sex[name2])
        {
            cout << "Whatever" << endl;
            continue;
        }
        else
        {
            flag = 0;
            find(name1,3);
            find(name2,3);
            if(flag)
            cout<<"No"<<endl;
            else
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}
```
### 7-7 愤怒的牛
运用到二分查找和贪心，实质是用二分查找去把答案试出来。
```C++
#include <bits/stdc++.h>
using namespace std;
//贪心+二分
//思路：利用二分把几乎所有可能的答案列出来，通过贪心判断该值是否满足题意，并通过反馈来修正
int cnt;//此时塞了多少牛
int map1[100000]; //农舍地图
int n,m;
bool judge(long long ans) //判断这个和答案大小关系
{
    int cnt=0;
    cnt++;//第一头牛放入
    long long last=map1[0]; //最近的节点
    for(int i=1;i<n;i++)
    {
        if(map1[i]-last>=ans)
        {
            cnt++; //该点可以！将牛塞入
            last=map1[i]; //最近节点更新
            if(cnt>=m)
            return true; //塞的牛可以达到要求值！ans可以再大一点
        }
    }
    return false; //塞的牛达不到要求，ans应该变小一点。
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>map1[i];
    }
    sort(map1,map1+n);
    long long left=0;
    long long right=map1[n-1]-map1[0];
    while(right>=left)
    {
        long long mid=(left+right)/2;
        if(judge(mid))
        {//ans可以再大一点
            left=mid+1;
        }
        else
        {//ans应该小一点
            right=mid-1;
        }
    }
    cout<<left-1;



    return 0;
}
```
