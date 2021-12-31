/*
7-7 ������С�ɱ���·
n������֮��Ŀǰ��һЩ��·���ӣ�����·�������ʧ�޵�������
��������׼��������һЩ��������Ϊ��׼��·��ϣ����׼��·�ܹ������г�����ͨ���ܳɱ���С��
��������һ������Ƚ����⣬�ܵ��ε����ƣ����ֻ����������׼��·ͨ������
���д�����ҳ�һ���������������ġ��ܳɱ���С�ĸ��췽�����������ڸ��췽����������ʶ��
�ٶ���·��˫��ġ�
�����ʽ:
��������������ݡ�ÿ�����ݵ�һ����3������n��v��e����������50��nΪ������Ŀ��
������0��n-1��vΪ������������׼��·�ĳ����ţ�eΪ���е���·������
��������e�б�ʾÿ����·��Ϣ��ÿ��Ϊ3���Ǹ�����a��b��c����ʾ����a�ͳ���b������һ����·��
���������Ϊ��׼��·���ɱ�Ϊc��
�����ʽ:
��ÿ���������һ�У�Ϊһ����������ʾ����Ҫ�����С�ɱ����������ڸ��췽���������-1��
��������:
5 0 8
0 1 1
0 2 1
0 3 1
0 4 1
1 4 100
1 2 100
2 3 100
3 4 100
5 0 4
0 1 1
0 2 1
0 3 1
0 4 1
�������:
202
-1
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int from,to,weight;
}s[64];
int father[64];
bool cmp(node a,node b){
    if(a.weight<b.weight) return true;
    else return false;
}
int find(int x){
    int a=x ;
    while(x!=father[x]) x=father[x];
    while(a!=father[a]){
        int z=a;
        a=father[a];
        father[z]=x;
    }
    return x;
}
int main(){
    int n,v,e;
    while(cin>>n>>v>>e){
        int i;
        for(i=0;i<e;i++) cin>>s[i].a>>s[i].b>>s[i].cost;
        sort(s,s+e,cmp);
        for(i=0;i<64;i++) father[i]=i;
        int count=0,num=0,sum=0;
        for(i=0;i<e;i++){
            if(s[i].from==v || s[i].to==v){
                int fa=find(s[i].a),fb=find(s[i].b);
                if(count<2 && fa!=fb){
                    count++;num++;
                    sum+=s[i].weight;
                    father[fa]=fb;
                }
            }
			else if(s[i].from!=v && s[i].to!=v){
                int fa=find(s[i].from);
                int fb=find(s[i].to);
                if(fa!=fb){
                    num++;
                    sum+=s[i].cost;
                    father[fa]=fb;
                }
            }
            if(num==n-1) break;
        }
        if(num==n-1) cout<<sum<<endl;
        else cout<<-1<<endl;
    }
}
