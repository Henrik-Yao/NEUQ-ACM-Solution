#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000010];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int pos=lower_bound(a+1,a+n+1,k)-a;//��һ�����ڵ���k������λ�ã�ָ�룩����Ҫ��ȥ������ 
	if(pos==-1)cout<<n+1;
	else cout<<pos;
	return 0;
}
