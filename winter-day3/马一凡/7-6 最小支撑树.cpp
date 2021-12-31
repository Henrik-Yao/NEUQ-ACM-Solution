#include<bits/stdc++.h>
using namespace std;

int f[210]={0};

struct tree{
	int x,y,vec;
};

int cmp(struct tree node1,struct tree node2){	//����ֵ���յ���˳������
	return node1.vec < node2.vec;
}

int find(int x){	//��
	if(f[x] == x)
		return x;
	else return f[x] = find(f[x]);
}

void merge(int x,int y){	//��
	int a = find(x);
	int b = find(y);
	if(a!=b)
		f[a] = b;
}

int main(){
	int n,e;
	while(cin >> n >> e){
		tree node[100100];	
		int flag[210] = {0};	//flag���飺������ʱ�����õ㱻ѡ���˾�������ֵΪ1
		int a,b,c;
		for(int i=0; i<n; i++){	//��ʼ���鼯����       
			f[i] = i;
		}
		for(int i=0; i<e; i++){
			cin >> a >> b >> c;
			node[i].x = a;
			node[i].y = b;
			node[i].vec = c;
			merge(a,b);	//���бߵ����㲢����
		}
		int num = 0;
		for(int i = 0;i < n;i++){	//�ж�ͼ����ͨ�ӿ���������Ϊ1�������ҵ���С֧����
			if(f[i] == i)
				num++;
		}
		
		if(num == 1){
			sort(node,node+e,cmp);
			
			int sum = 0;
			for(int i=0; i<e; i++){
				if(flag[node[i].x] == 1 && flag[node[i].y] == 1){	//�������㶼�Ѿ���ѡ���ˣ������������߷������ֻ�·
					continue;
				}
				else{
					flag[node[i].x] = 1;
					flag[node[i].y] = 1;
					sum = sum+node[i].vec;
				}
			}
			cout << sum << endl;
		}
		else{
			cout << "There is no minimum spanning tree." << endl;
		}
	}
	
	return 0;
} 

