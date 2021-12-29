#include<iostream>
using namespace std;

int mp[300][300];
int vs[300];
int s[300];
int link[300];
int front=0,rear=0;
int stage=0;
int n,m,t,k,v;
int is_ok=0;

void BFS(int a, int b){
	int e;
	if(rear == 0){
		link[0]=a;
		rear++;
		vs[a] = 1;
	}
	stage++;
	while(front != rear){
	
		e = link[front];
		link[front] = -1;
		front++;
		if(e == b){
			is_ok = 1;
			return;
		}
		else{
			for(int i=0; i<n; i++){
				if(mp[e][i] == 1 && vs[i] == 0){
					s[i] = stage;
					link[rear] = i;
					rear++;
					vs[i]=1;
				}
			}
			stage++;
		}
	}

	return;
}

int main(){
	
	while(~scanf("%d %d",&n,&m)){
		for(int i=0; i<300; i++){
			for(int j=0; j<300; j++){
				mp[i][j] = 0;
			}
		}
		for(int i=0; i<n; i++){
			cin >> t >> k;
			for(int j=0; j<k; j++){
				cin >> v;
				mp[t][v] = 1;
			}	
		}
		int a,b;
		for(int i=0; i<m; i++){
			cin >> a >> b;
			for(int j=0; j<300; j++){
				s[j]=0;
			}
			for(int j=0; j<300; j++){
				vs[j]=0;
			}
			for(int j=0; j<300; j++){
				link[j]=0;
			}
			front = rear = 0;
			stage = 0;
			is_ok = 0;
			BFS(a,b);
			if(is_ok == 1)
			cout << s[b] << endl;
			else cout << "connection impossible" << endl;
		}
		
		
	}
	
	return 0;
}
