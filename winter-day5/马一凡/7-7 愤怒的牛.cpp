#include <bits/stdc++.h>
using namespace std;
int a[100010];
int l, r;
int n,c;
 
int solve(int m)              
{
    int vs=1,last=1;    //因为第一个牛一定要占据第一个隔间（这样能使本题的答案最优），所以vs初始化为1
    for(int i=2; i <=n; i++){
        if(a[i]-a[last] >= m){
            vs++;           //如果比最近距离要大的话，那么该隔间就放牛   
            last = i;                                               
        }
    }
    if(vs >= c)
		return 1;          //如果所选取的隔间数量>=c，则说明枚举的最近距离成立，但是不够大，所以return true,继续枚举更大的距离
    return 0;
}
 
int main(){
    cin >> n >> c;
    for(int i=1; i <=n; i++)
		cin >> a[i];
    l = 1; 
	r = a[n]-a[1];           //右边界为n个隔间的总长度，最近距离一定小于等于这个数值
    sort(a+1,a+1+n);
    while(l <= r){
        int mid = (l+r)/2;
        if(solve(mid))
			l = mid+1;       //如果当前枚举的最近距离符合，那么就让l=mid,看更大的距离是否也符合（因为要求最大的最近距离）
        else
            r = mid-1;
    }
    cout << r << endl;    //由于最后l<=r的时候还会运行一次，会让l-1(如果答案正确的话)，所以应该输出的是r
    return 0;
}
