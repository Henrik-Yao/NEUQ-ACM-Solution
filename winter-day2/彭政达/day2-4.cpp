/*
7-4 �ﷸ����
Tabu�еľ���־����������ң����Ҫ��ȡ�ж����������еļ�����ɡ�
Ŀǰ�������ǣ����������ﷸ������������ͬһ����ô��������һ���ж��ٸ����ɣ�
������Tabu������n���ﷸ�����Ϊ1��n������m����Ϣ��ʾ����ͬһ���ɵ������ﷸ��š�
�������Щ����ȫ����Ϣ�������������������Ҫ����Ϣ��
�����ʽ:
�����һ��Ϊ������������n��m��q��nΪ�ﷸ����mΪ��������֪��Ϣ������qΪ��ѯ����
������m�У�ÿ��2��������a��b����ʾ�ﷸa���ﷸb����ͬһ���ɡ�������q�У�ÿ��2��������c��d��
����ѯ�ﷸc��d�Ƿ�����ͬһ���ɡ�ÿ������������Կո�����n��m��q��������1000��
�����ʽ:
���Ϊq+1�У�ǰq�ж�Ӧ�������q����ѯ�Ľ�����������ͬһ���ɣ��������In the same gang.����
���������In different gangs.�������һ��Ϊһ����������ʾ������Ŀ��
��������:
3 2 1
1 2
2 3
1 3
�������:
In the same gang.
1
*/
#include <bits/stdc++.h>
using namespace std;
set<int> s[1005];
int v=0,n,m,q;
int main(){
	ios::sync_with_stdio(false);
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(!s[v].count(a) && !s[v].count(b)){
        	v++;
        	s[v].insert(a);s[v].insert(b); 
        }
        else if(!s[v].count(a)) s[v].insert(a);
        else if(!s[v].count(b)) s[v].insert(b);
    }
    for(int i=0;i<q;i++){
        int c,d;
        cin>>c>>d;
        bool flag=0;
        for(int i=1;i<=v;i++)
            if(s[i].count(c) && s[i].count(d)){
                flag=1;
                break;
            }
        if(flag) cout<<"In the same gang."<<endl;
        else cout<<"In different gangs."<<endl;
    }
    cout<<v<<endl;
    return 0;
}
