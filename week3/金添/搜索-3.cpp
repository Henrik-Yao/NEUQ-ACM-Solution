#include <bits/stdc++.h>
using namespace std;
int zone[21][21];//��ͼ��ÿһ���ڵ���Χ�˸���ĵ��׸����������Ҫ�����ֵ 
int mine[21][21];//��ͼ��ÿһ���ڵ�ĵ��׸���
int flag=0;
int n,m,k,l;
void search(int remp1,int remp2)
{
	if(!(remp1>=0&&remp1<n&&remp2>=0&&remp2<m))
	return;//���������߽磬ֹͣ����ʼ�������� 
	zone[remp1][remp2]=0;   
	for(int i1=-1;i1<=1;i1++)
	{
		for(int j1=-1;j1<=1;j1++)
		{
			if(!(i1==0&&j1==0))
			{
				if((remp1+i1>=0&&remp1+i1<n&&remp2+j1>=0&&remp2+j1<m)&&mine[remp1+i1][remp2+j1])
				{
				    zone[remp1][remp2]++;
			    }	 
			}
		}
	}
	if(zone[remp1][remp2])
	return;//���õ㸽���е��ף��򷵻�
	else//���õ���Χ�޵��ף������Ѱ�� 
	{
		for(int i2=-1;i2<=1;i2++)
		{
			for(int j2=-1;j2<=1;j2++)
			{
		     	if(!(i2==0&&j2==0))
				{
					if((remp1+i2>=0&&remp1+i2<n&&remp2+j2>=0&&remp2+j2<m)&&zone[remp1+i2][remp2+j2]==-1)
					{
				    	 search(remp1+i2,remp2+j2);
			   	 	}	 
				}	    	
    		}
    	}
	}
}
int main()
{
	memset(zone,-1,sizeof(zone));
	cin>>n>>m>>k>>l;
	for(int i=0;i<k;i++)
	{
		int remp1,remp2;
		cin>>remp1>>remp2;
		mine[remp1][remp2]=1;  
	}
	for(int h=0;h<l;h++)
	{
		int remp1,remp2;
		cin>>remp1>>remp2;
		if (zone[remp1][remp2] >= 0)continue;//����õ��Ѵ򿪣����Ӹ����� 
		if(mine[remp1][remp2])//���õ�Ϊ���ף���ֱ����Ϸ���� 
	    {
	        cout<<"You lose"<<endl;
	    	break;
		}
		search(remp1,remp2);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<zone[i][j]<<" ";
			} 
			cout<<endl;
		}
	int paichu=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(zone[i][j]==-1)
			paichu++;
		}
    }
	if(paichu==k)
	{
	cout<<"You win"<<endl;
	break;
    }
	
	cout<<endl; 
	
	}
	
	return 0;	
}
