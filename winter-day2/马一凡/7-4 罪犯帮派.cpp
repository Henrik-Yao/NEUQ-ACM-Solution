#include<iostream>
using namespace std;

int pre[1100]={0};
int book[1100]={0};
int n,m,q;

void init(int *pre){
	for(int i=1; i<=n; i++){
		pre[i] = i;
	}
}

int find(int x)     				//查找结点 x的根结点 
{
    if(pre[x] == x) return x;		//递归出口：x的上级为 x本身，即 x为根结点        
    return pre[x] = find(pre[x]);	//此代码相当于先找到根结点 rootx，然后pre[x]=rootx 
}


void join(int x,int y)                     
{
    int fx=find(x), fy=find(y); 
    if(fx != fy) 
        pre[fx]=fy;	//fy做fx的前驱结点
}

int main(){

	int sum=0;
	cin >> n >> m >> q;
	
	init(pre);
	
	for(int i=0; i<m; i++){
		int x,y;
		cin >> x >> y;
		join(x,y);
	}
	
	for(int i=0; i<q; i++){
		int x,y;
		cin >> x >> y;
		if(find(x) == find(y)){
			cout << "In the same gang."<< endl;
		}
		else cout << "In different gangs." << endl;
	}
	for(int i=1; i<=n; i++){
		if(pre[i] == i){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
