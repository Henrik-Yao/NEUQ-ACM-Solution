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

int find(int x)     				//���ҽ�� x�ĸ���� 
{
    if(pre[x] == x) return x;		//�ݹ���ڣ�x���ϼ�Ϊ x������ xΪ�����        
    return pre[x] = find(pre[x]);	//�˴����൱�����ҵ������ rootx��Ȼ��pre[x]=rootx 
}


void join(int x,int y)                     
{
    int fx=find(x), fy=find(y); 
    if(fx != fy) 
        pre[fx]=fy;	//fy��fx��ǰ�����
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
