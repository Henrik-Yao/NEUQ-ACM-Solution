#include <queue>
#include <cstdio>
#define N 101
using namespace std;

int n,a[N];
priority_queue<int , vector<int> , greater<int> > q;

int main(){
	while(~scanf("%d",&n)){
		for(int i = 1;i <= n;i ++)
			scanf("%d",&a[i]);
		for(int i = 2;i <= n;i ++){
			for(int j = 1;j <= i;j ++) 
				q.push(a[j]);
			int tot = 0;
			while(!q.empty()){
				tot ++;
				printf("%d",q.top());
				if(tot < n) printf(" ");
				q.pop();
			}
			for(int j = i + 1;j <= n;j ++){
				printf("%d",a[j]);
				if(j < n) printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
