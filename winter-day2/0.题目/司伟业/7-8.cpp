#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
//����С���ѵ����ȶ���
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
	//ans��Ϊ����������Ȩ·�����Ⱥͣ�Ҳ��������Ӧ�Ĺ���������ĳ���
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
						//�����ַ���������ҵ��˲�����ǰ׺���ͱ��ΪNo��
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

