#include<stdio.h>
#define max 1000
#define n 100
void DIJ(float C[n][n],int v,int q)
{
    float D[n];
    int P[n],S[n];
    int i,j,k,v1,pre;
    float min,inf=200;
    v1=v-1;
    for(i=0;i<n;i++)
    {
        D[i]=C[v1][i];
        if(D[i]!=max)
            P[i]=v;
        else P[i]=0;
    }
    for(i=0;i<n;i++)
        S[i]=0; 
    S[v1]=1;
    D[v1]=0;
    for(i=0;i<n-1;i++)
    {
        min=inf;
        for(j=0;j<n;j++)
            if((!S[j])&&(D[j]<min))
            {
                min=D[j];
                k=j;
            }
            S[k]=1;
            for(j=0;j<n;j++)
                if((!S[j])&&(D[j]>D[k]+C[k][j]))
                {
                    D[j]=D[k]+C[k][j];
                    P[j]=k+1;
                }
    }
        i=q-1;
        pre=P[i];
        j=0;
        int b[n];
        while(pre!=0)
        {
            b[j]=pre;
            j++;
            pre=P[pre-1];
        }
        printf("%d-->",v-1);
        for(k=j-2;k>=0;k--)
        {
            printf("%d-->",b[k]-1);
        }
        if(D[i]!=max)
        printf("%d:%.0f",i,D[i]);
}
main()
{
    int i,j,k,e,r;
    float z;
    float a[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j]=max;
    scanf("%d%d",&r,&e);
    for(k=0;k<e/2;k++)
    {
        scanf("%d%d%f",&i,&j,&z);
        a[i][j]=z;
        a[j][i]=z;
    }
    scanf("%d",&i);
    scanf("%d",&j);
    DIJ(a,i+1,j+1);
}


