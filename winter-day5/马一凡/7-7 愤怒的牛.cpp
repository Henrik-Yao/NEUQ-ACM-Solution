#include <bits/stdc++.h>
using namespace std;
int a[100010];
int l, r;
int n,c;
 
int solve(int m)              
{
    int vs=1,last=1;    //��Ϊ��һ��ţһ��Ҫռ�ݵ�һ�����䣨������ʹ����Ĵ����ţ�������vs��ʼ��Ϊ1
    for(int i=2; i <=n; i++){
        if(a[i]-a[last] >= m){
            vs++;           //������������Ҫ��Ļ�����ô�ø���ͷ�ţ   
            last = i;                                               
        }
    }
    if(vs >= c)
		return 1;          //�����ѡȡ�ĸ�������>=c����˵��ö�ٵ����������������ǲ���������return true,����ö�ٸ���ľ���
    return 0;
}
 
int main(){
    cin >> n >> c;
    for(int i=1; i <=n; i++)
		cin >> a[i];
    l = 1; 
	r = a[n]-a[1];           //�ұ߽�Ϊn��������ܳ��ȣ��������һ��С�ڵ��������ֵ
    sort(a+1,a+1+n);
    while(l <= r){
        int mid = (l+r)/2;
        if(solve(mid))
			l = mid+1;       //�����ǰö�ٵ����������ϣ���ô����l=mid,������ľ����Ƿ�Ҳ���ϣ���ΪҪ������������룩
        else
            r = mid-1;
    }
    cout << r << endl;    //�������l<=r��ʱ�򻹻�����һ�Σ�����l-1(�������ȷ�Ļ�)������Ӧ���������r
    return 0;
}
