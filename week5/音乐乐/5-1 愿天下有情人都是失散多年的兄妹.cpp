#include<bits/stdc++.h>
using namespace std;
int cnt,flag,N,K;
int path1[100];
int path2[100];
int depth1=0, deep1=0;
int depth2=0, deep2=0;
struct person
{
	char sex;
	int id1=-1;
	int id2=-1;
};
person arr[100000];
void bfs(int s,int j)
{
	if(s==-1)
	return;
	if((deep1==5&&j==1)||(deep2==5&&j==2))
	return;
	if (j==1)
    {
        path1[depth1++]=s;
        deep1++;
        bfs(arr[s].id1, 1);
        bfs(arr[s].id2, 1);
        deep1--;
    }
    else
    {
        path2[depth2++] = s;
        deep2++;
        bfs(arr[s].id1, 2);
        bfs(arr[s].id2, 2);
        deep2--;
    }
}
int main()
{
	int i;
	cin>>N;
	for(i=0;i<N;i++)
	{
		int id;
		cin>>id;
		cin>>arr[id].sex>>arr[id].id1>>arr[id].id2;
		if(arr[id].id1!=-1)
		arr[arr[id].id1].sex='M';
		if(arr[id].id2!=-1) 
		arr[arr[id].id2].sex='F';
	}
	cin>>K;
	while(K--)
	{
		depth1=0,depth2=0;
		int a,b;
		cin>>a>>b;
		if(arr[a].sex==arr[b].sex)
		{
			cout << "Never Mind" << endl;
            continue;
		}
		bfs(a,1);
		bfs(b,2);
		deep1=0;
		deep2=0;
		int flag=0;
		for (int k=0;k<depth1;k++)
        {
            for (int l=0;l<depth2;l++)
            {
                if (path1[k]==path2[l])
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
        cout<<"No"<<endl;
        else
        cout<<"Yes"<<endl;
	}
	return 0;
}
