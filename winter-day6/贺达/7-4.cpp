#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;

#define lowbit(x) (x & -x)   //取一个二进制最低位的一与后边的0组成的数
ll c[N],a[N],n;
vector<ll> b;
//lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
int fin(int x)
{
	return lower_bound(b.begin(),b.end(),x)-b.begin();//返回下标
}

void update(int x,int v)
{
	for(int i=x;i<=n;i+=lowbit(i)) c[i] += v;
}

int ask(int x)
{
	int res = 0;
	for(int i=x;i;i-=lowbit(i)) res += c[i];
	return res;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],b.push_back(a[i]);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());//去重
    for(int i=1;i<=n;i++) a[i] = fin(a[i])+1;
    ll ans = 0;
    //每插入一个统计比它小的数量
    for(int i=n;i>=1;i--)
    {
    	ans += ask(a[i] - 1);
    	update(a[i],1);
	}
	cout<<ans;
    return 0;
}
