#include <bits/stdc++.h>
using namespace std;
#define N 101
int indegree[N];//indegree�Ǹ��������
int adj[N][N];//�ڽӾ����ʾͼ
int visit[N];//��¼�Ƿ����
int n,m;//n�����㣬m����
int result;//�������
void dfs(int num){
    if(num==n){//��������������������еĵ�Ϊֹ
        result++;//����
        return;
    }
    for(int i=1;i<=n;i++){
        if((!indegree[i])&&(!visit[i])){//���ҵ�û�б����ʹ������Ϊ0�ĵ�
            for(int j=1;j<=n;j++){
                if(adj[i][j]) indegree[j]--;//��������iΪ��β�Ļ�ͷj����ȼ�һ
            }
            visit[i]=1;//��¼���ʱ�־
            dfs(num+1);//��������
            for(int k=1;k<=n;k++){//�����ǻ��ݣ��ָ����
                if(adj[i][k]) indegree[k]++;
            }
            visit[i]=0;//�ָ�δ�����ʱ�־
        }
    }
    return;
}
int main(){
    while(cin>>n>>m){
        result=0;
        memset(indegree,0,sizeof(indegree));
        memset(adj,0,sizeof(adj));
        memset(visit,0,sizeof(visit));
        while(m--){
            int a,b;
            cin>>a>>b;
            indegree[b]++;
            adj[a][b]=1;
        }
        dfs(0);
        if(result<=1) cout<<result<<endl;
        else cout<<"2"<<endl;
    }
}
