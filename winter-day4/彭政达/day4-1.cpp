/*
7-1 ˫ʮһ
˫ʮһ�ڼ䣬ĳ��������ƽ̨��������ΪӦ�����۸߷壬׼����n��������������һ����Ӫ�ֿ⣬
��Ҫ���Ǹòֿ�����n�������е�ĳ�����У��Ҿ����������г��е���̾���֮����С��
���д����������������ҳ������ֿ�ĵص㡣�ٶ�n�����б��Ϊ0��n-1��
����֮��������һ���������������г��пɼ���
�����ʽ:
��������������ݡ�ÿ�����ݵ�һ��Ϊ����������n��e����������100��n��ʾ��������
������e�б�ʾ�������м�ľ�����Ϣ��ÿ��Ϊ3���Ǹ�����a��b��c��
����a��b��ʾ�������б�ţ�c��ʾ���м�ľ��롣
��ʾ����ʹ��EOF�ж����������
�����ʽ:
���Ϊһ����������ʾ�����ֿ�ĳ��б�ţ�������������Ҫ������������С�ߡ�
��������:
6 5
0 1 1
0 2 1
0 3 1
0 4 1
0 5 1
4 5 
0 1 1        0-1 1 -2 5 -3 5             
0 2 5  1-0 1       -2 2 -3 4             
1 2 2  2-0 5  -1 2      -3 1             
1 3 4  3-0 5  -1 4 -2 1                 
2 3 1                          
�������:
0
1
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("in1.txt","r",stdin);
    int lo,vertex,edge,g[128][128];
    while(cin>>vertex>>edge){
    	if(vertex==EOF) break;
        memset(g,128,sizeof(g));
        for(int i=1;i<=edge;i++){
            int from,to,weight;
            cin>>from>>to>>weight;
            if(++from==++to) g[from][to]=0;
            else{
                g[from][to]=weight;
                g[to][from]=weight;
            }
        }
        for(int i=1;i<=vertex;i++)
            for(int j=1;j<=vertex;j++)
                for(int k=1;k<=vertex;k++)
                    if(g[j][k]>g[j][i]+g[i][k]) g[j][k]=g[j][i]+g[i][k];
        long long dis[128]={0},ans=2147483647;
        for(int i=1;i<=vertex;i++)
            for(int j=1;j<=vertex;j++)
                if(i!=j) dis[i]+=(long long)g[i][j];
        lo=1;
        for(int i=1;i<=vertex;i++)
            if(dis[i]<ans) ans=dis[i],lo=i;
        cout<<lo-1<<endl;
    }
}
