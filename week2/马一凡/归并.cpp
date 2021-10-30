#include<iostream>
using namespace std;

long long line(int rr[],int ss[],int l,int m,int r,long long flag)
{
    int i=l,j=m+1,k=l;
    while((j<=r)&&(i<=m)){
        if(rr[i]<=rr[j])
        {
            ss[k] = rr[i];
            i++;
            k++;
            flag++;
        }
        else
        {
            ss[k]=rr[j];
            j++;
            k++;
            flag++;
        }
	}
	while(i<=m) ss[k++]=rr[i++];
    while(j<=r) ss[k++]=rr[j++];
    return flag;
}


long long fen(int rr[],int ss[],int l,int r,long long flag)
{
    int m=(l+r)/2;
    int tt[20];
    if(l==r)
        ss[l]=rr[r];
    else
    {
        m=(l+r)/2;
        fen(rr,tt,l,m,flag);
        fen(rr,tt,m+1,r,flag);
        flag = line(tt,ss,l,m,r,flag);
    }
    return flag;
}

	
	
int main()
{
    int a[10];
    int i,n;
    long long flag =0;
	cin >> n;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    flag = fen(a,a,0,n-1,flag);

    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    cout << flag;
    return 0;
}

