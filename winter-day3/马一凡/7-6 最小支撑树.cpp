#include<bits/stdc++.h>
using namespace std;

int f[210]={0};

struct tree{
	int x,y,vec;
};

int cmp(struct tree node1,struct tree node2){	//将边值按照递增顺序排序
	return node1.vec < node2.vec;
}

int find(int x){	//查
	if(f[x] == x)
		return x;
	else return f[x] = find(f[x]);
}

void merge(int x,int y){	//并
	int a = find(x);
	int b = find(y);
	if(a!=b)
		f[a] = b;
}

int main(){
	int n,e;
	while(cin >> n >> e){
		tree node[100100];	
		int flag[210] = {0};	//flag数组：生成树时，若该点被选过了就令它的值为1
		int a,b,c;
		for(int i=0; i<n; i++){	//初始并查集数组       
			f[i] = i;
		}
		for(int i=0; i<e; i++){
			cin >> a >> b >> c;
			node[i].x = a;
			node[i].y = b;
			node[i].vec = c;
			merge(a,b);	//将有边的两点并起来
		}
		int num = 0;
		for(int i = 0;i < n;i++){	//判断图的连通子块个数，如果为1，才能找到最小支撑树
			if(f[i] == i)
				num++;
		}
		
		if(num == 1){
			sort(node,node+e,cmp);
			
			int sum = 0;
			for(int i=0; i<e; i++){
				if(flag[node[i].x] == 1 && flag[node[i].y] == 1){	//若两个点都已经被选入了，则跳过这条边否则会出现回路
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

