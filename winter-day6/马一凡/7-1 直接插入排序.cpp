#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	while(cin >> n){
	
    int i,j;
    int a[10];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=1; i<n; i++)
    {
    	int flag = 0;
        int t;
        t = a[i];//�����ڱ�
        for(j=i-1; a[j] > t && j >= 0; j--)//Ѱ�Ҳ���λ��
            a[j+1] = a[j];//ǰһ�����ڵ�ǰ����ǰ����ǰһ��
        a[j+1] = t;
        for(int j=0; j<n; j++){
        	if(flag == 1) cout << " ";
        	cout << a[j];
        	flag = 1;
		}	
        cout << endl;
    }
}
    return 0;
}
