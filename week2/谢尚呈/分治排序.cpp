#include<cstdio>
#include<iostream>
using namespace std;

const int max_arr_len=100000;

int n_all[max_arr_len];

void solve(int left, int right)
{
	//cout<<"将solve自n_all["<<left<<"]="<<n_all[left]<<"至n_all["<<right<<"]="<<n_all[right]<<endl;
	if(left>=right)	return;
	if(left==right-1)
		if(n_all[left]<=n_all[right]);
		else
		{
			int t=n_all[left];
			n_all[left]=n_all[right];
			n_all[right]=t;
		}
	int middle=(left+right)/2;
	//cout<<"将开始solve自n_all["<<left<<"]="<<n_all[left]<<"至n_all["<<middle<<"]="<<n_all[middle]<<endl;
	solve(left, middle);
	//cout<<"将开始solve自n_all["<<middle+1<<"]="<<n_all[middle+1]<<"至n_all["<<right<<"]="<<n_all[right]<<endl;
	solve(middle+1, right);
	int *in;
	in=new int[right-left+1];
	int l_s=left, r_s=middle+1, i_s=0;
	while(l_s!=middle+1||r_s!=right+1)
	{
		//cout<<"正比较n_all["<<l_s<<"]="<<n_all[l_s]<<"和n_all["<<r_s<<"]="<<n_all[r_s]<<endl;
		if(l_s==middle+1)
		{
			in[i_s]=n_all[r_s];
			r_s++;
			i_s++;
			continue;
		}
		if(r_s==right+1)
		{
			in[i_s]=n_all[l_s];
			l_s++;
			i_s++;
			continue;
		}
		if(n_all[l_s]<=n_all[r_s])
		{
			in[i_s]=n_all[l_s];
			l_s++;
		}
		else
		{
			in[i_s]=n_all[r_s];
			r_s++;
		}
		i_s++;
	}
	for(int i=left; i<=right; i++)	n_all[i]=in[i-left];
	//cout<<"排列好的序列为：";
	//for(int i=left; i<=right; i++)	cout<<n_all[i]<<" ";
	//cout<<endl;
	delete in;
	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)	scanf("%d", &n_all[i]);
	solve(0,n-1);
	for(int i=0; i<n; i++)
	printf("%d ", n_all[i]);
	return 0;
}
