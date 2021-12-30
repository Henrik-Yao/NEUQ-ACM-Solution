/*
7-7 愤怒的牛
农夫约翰建造了一座有n间牛舍的小屋，牛舍排在一条直线上，第i间牛舍在xi的位置，
但是约翰的m头牛对小屋很不满意，因此经常互相攻击。约翰为了防止牛之间互相伤害，
因此决定把每头牛都放在离其它牛尽可能远的牛舍。也就是要最大化最近的两头牛之间的距离。
牛们并不喜欢这种布局，而且几头牛放在一个隔间里，它们就要发生争斗。为了不让牛互相伤害。
John 决定自己给牛分配隔间，使任意两头牛之间的最小距离尽可能的大，那么，这个最大的最小距离是多少呢？
输入格式:
第一行用空格分隔的两个整数n和m，n，m<=10^5;第二行为n个用空格隔开的整数,表示位置xi.xi<MAXINT
输出格式:
输出仅一个整数，表示最大的最小距离值。
输入样例:
5 3
1 2 8 4 9
输出样例:
3
*/
#include <bits/stdc++.h>
using namespace std;
int n,m,a[100010];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    n=unique(a+1,a+n+1)-a-1;
    int l=1,r=1e7+10;
    while(l<r){
        int mid=l+((r-l)/2),pre=1,cnt=1;
    	for(int i=2;i<=n;i++)
    		if(a[i]-a[pre]>=mid) cnt++,pre=i;
        if(cnt>=m)) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
}
