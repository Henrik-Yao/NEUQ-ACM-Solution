#include<bits/stdc++.h>
using namespace std;
const int M=100000;
int a[M];
void PaiXuDiGui(int a[],int b,int c);
void PaiXuAndDiGui(int a[],int b,int c);
void xiaopaixu(int a[],int b,int c,int middle);
int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	PaiXuDiGui(a,0,n);//进行排序 
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
void PaiXuDiGui(int a[],int b,int c)
{
	PaiXuAndDiGui(a,b,c-1); //逐步缩小范围 
}
void PaiXuAndDiGui(int a[],int b,int c)
{
    if(b>=c) 
    { 
	return ;
	} 
	int middle=(b+c)/2;	//分隔成一些小的区间 
	PaiXuAndDiGui(a,b,middle);
	PaiXuAndDiGui(a,middle+1,c);
	xiaopaixu(a,b,c,middle);	
}
void xiaopaixu(int a[],int b,int c,int middle)//对小区间进行排序 
{
  int xiaoshuzu[c-b+1],i,j,k;
  for(k=b;k<=c;k++)
  {
  xiaoshuzu[k-b]=a[k];
  }
  i=b;
  j=middle+1;
  for(k=b;k<=c;k++)
  {
  	if(i>middle)
  	{
  		a[k]=xiaoshuzu[j-b];
  		j++;
	  }
	else if(j>c)
	{
		a[k]=xiaoshuzu[i-b];
		i++;
	  }
	else if(xiaoshuzu[i-b]>xiaoshuzu[j-b])
	{
		a[k]=xiaoshuzu[j-b];
		j++;
		}
	else
	{
		a[k]=xiaoshuzu[i-b];
		i++;
	}
   }	
	
}
