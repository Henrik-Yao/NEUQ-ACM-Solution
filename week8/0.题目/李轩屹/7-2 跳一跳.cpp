#include<bits/stdc++.h>
using namespace std;
const int Max = 1e6+10;
int a[Max];
int find(int n, int m){
	int ans = n+1;
	for(int i = n; i <= m; i ++){
		if(a[n] < a[i]){
			a[n] = a[i];
			ans = i;
		}
	}
	return ans;
}
int link(int n, int m){
	int ans = n;
	for(int i = ans; i <= m; i ++){
		if(a[n] < a[i]+(i-n)){
			n = i;
		}
	}
	return n;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	int k = 0, tmp = 1; // ������һ��
	while(k+a[k] < n-1){
        int p = a[k]; // ����ʧ
		int m = find(k,a[k]+k); // Ѱ��k��a[k]+k֮�����ֵ���ڵ�λ��
		k = link(m,p+k); // Ѱ��Ҫ�����λ����
		tmp ++;
	}
	cout << tmp << endl;
}

 



