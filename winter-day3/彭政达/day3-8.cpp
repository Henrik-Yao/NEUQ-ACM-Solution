/*
7-8 ��������
�������Ϊ1��n��nƪ���ģ��Լ�m������d, u (1��d,u��n,d!=u)�����ù�ϵ��
��ʾ��������d�ж����һ������������u�б����á�����Ҫ����nƪ�����������У�
���з�������������Ҫ��һƪ�������õ����ʱ�����������ǰ��������б��������
���д������Լ��㶼�ж���������Ҫ��ķ��������������Ҫ��ķ��������0��
�����Ψһ���������1������ж��ַ��������2��
�����ʽ:
��������������ݣ�ÿ�����ݵ�һ��Ϊ����������n��m���ֱ��ʾ����ƪ�������ù�ϵ����
��������100��������m�б�ʾ�������ù�ϵ��ÿ��Ϊ�ո�����2��������d��u��
��ʾ��������d�ж����һ������������u�б����á�
�����ʽ:
����ÿ���������һ��������������Ҫ������з��������0�������Ψһ���������1��
����ж��ַ��������2��
��������:
5 4
1 5
5 2
3 2
4 3
5 4
3 1
4 2
1 5
5 4
�������:
2
1
*/
#include <bits/stdc++.h>
using namespace std;
int d,u,n,m,x[128];
vector<int>edge[128],ans;
queue<int>q;
int main(){
	freopen("in8.txt","r",stdin);
    while(cin>>n>>m){
    	if(n==EOF) break;
        int flag=0,cnt=0;
        for(int i=0;i<m;i++){
            cin>>d>>u;
            edge[d].push_back(u);
            x[u]++;
        }
        for(int i=1;i<=n;i++){
            if(!x[i]){
                q.push(i);
                cnt++;
            }
        }
        if(cnt>1) flag=1;
        while(!q.empty()){
            int p=q.front();q.pop();
            ans.push_back(p);
            for(int i=0;i<edge[p].size();i++){
                int y=edge[p][i];
                x[y]--;
                if(!in[y]) q.push(y);
            }
        }
        if(ans.size()==n){
            if(!flag) cout<<"1"<<endl;
            else cout<<"2"<<endl;
        }
        else cout<<"0"<<endl;
        for(int i=0;i<m;i++) edge[i].clear();
        ans.clear();
		while(!q.empty())q.pop();
		memset(x,0,sizeof(x));
    }
}
