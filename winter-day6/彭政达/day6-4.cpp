/*
7-4 最接近神的人
破解了符文之语，小FF开启了通往地下的道路。当他走到最底层时，发现正前方有一扇巨石门，
门上雕刻着一幅古代人进行某种活动的图案。而石门上方用古代文写着“神的殿堂”。
小FF猜想里面应该就有王室的遗产了。但现在的问题是如何打开这扇门……
仔细研究后，他发现门上的图案大概是说：古代人认为只有智者才是最容易接近神明的。
而最聪明的人往往通过一种仪式选拔出来。仪式大概是指，
即将隐退的智者为他的候选人写下一串无序的数字，并让他们进行一种操作，
即交换序列中相邻的两个元素。而用最少的交换次数使原序列变成不下降序列的人即是下一任智者。
小FF发现门上同样有着n个数字。
于是他认为打开这扇门的秘诀就是找到让这个序列变成不下降序列所需要的最小次数。
但小FF不会……只好又找到了你，并答应事成之后与你三七分……
输入格式:
第一行为一个整数n，表示序列长度
第二行为n个整数，表示序列中每个元素。
输出格式:
一个整数ans，即最少操作次数。
输入样例:
4
2 8 0 3
输出样例:
3
说明/提示:
对于30的数据1≤n≤10^4。
对于100的数据1≤n≤5*10^5；
maxlongint≤A[i]≤maxlongint。
样例说明：开始序列为2803，目标序列为0238，可进行三次操作的目标序列：
1．Swap (8,0):2  0  8  3
2．Swap (2,0):0  2  8  3
3．Swap (8,3):0  2  3  8
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[500005],tree[500005];
struct Node{
   int value,id;
}in[500005];
ll lowbit(int x){
	return (x&(-x));
}
ll f(int x){
    ll temp=0;
    for(int i=x;i;i-=lowbit(i)) temp+=tree[i];
    return temp;
}
bool cmp(Node a ,Node b){
    return a.value<b.value;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>in[i].value;
        in[i].id=i;
    }
    sort(in+1,in+n+1,cmp);
    for(int i=1;i<=n;i++) a[in[i].id]=i;
    memset(tree,0,sizeof(tree));
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=a[i];j<=n;j+=lowbit(j)) tree[j]++;
        ans+=i-f(a[i]);
    }
    cout<<ans;
}
