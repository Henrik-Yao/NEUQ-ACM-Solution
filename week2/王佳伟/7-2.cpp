#include<bits/stdc++.h>
using namespace std;

struct connect{ //���� 
	int city1;
	int city2;
}con[10001];;


int main() {
	int n, m; 
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> con[i].city1 >> con[i].city2;
	}
	int t;//������ 
	int k; 
	int c;//��ȥ���Ϊc�ĳ��� 
	int insist[10001] = {0};//��i��ŵĳ����Ƿ���� ,0������ڣ�1�������� 
	cin >> t;
	for(int i = 0; i < t; i++){
		memset(insist, 0, sizeof(insist));
		cin >> k;
		for(int i = 0; i < k; i++){
			cin >> c;
			insist[c] = 1;
		}
		//�ж��Ƿ����
		bool judge = true;
		for(int j = 0; j < m; j++){ //�������ĸ����Ӳ�����Ҫ�� 
			if(!insist[con[j].city1] && !insist[con[j].city2]) {//������ 
				judge = false;
			}
		} 
		if(judge){
			cout << "YES" << endl; 
		}
		else cout << "NO" << endl;
	}
	

	
}
