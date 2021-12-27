#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
//代表小顶堆的优先队列
priority_queue<int ,vector<int>,greater<int> > q;
int main(void){
	int n;
	char s[66];
	int p[66];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		getchar();
		scanf("%c%d",&s[i],&p[i]);
		q.push(p[i]);
	}
	int ans=0;
	//ans即为哈弗曼树带权路径长度和，也就是所对应的哈夫曼编码的长度
	while(q.size()>1){
		int x=q.top();
		q.pop();
		int y=q.top();
		q.pop();
		q.push(x+y);
		ans+=x+y;
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		char ss[66][66];
		int sum=0;
		for(int j=0;j<n;j++){
			getchar();
			char c;
			scanf("%c %s",&c,ss[j]);
			sum+=strlen(ss[j])*p[j];
		}
		if(sum!=ans)printf("No\n");
		else{
			int flag=0;
			for(int j=0;j<n;j++){
				int x=strlen(ss[j]);
				for(int l=0;l<n;l++){
					if(j!=l){
						if(strstr(ss[l],ss[j])==&ss[l][0]){
						//查找字符串，如果找到了并且是前缀，就标记为No了
							flag=1;
							break;
						}
					}
				}
				if(flag==1)break;
			}
			if(flag==1)printf("No\n");
			else printf("Yes\n");
		}
	}
	return 0;
}

