#include <stdio.h>
int main()
{
   int N,M,K,n,i=1,t;   
       scanf("%d %d %d",&N,&M,&K);
       int x[N];
       for(n=0;n<N;n++) 
       x[n]=0;
       if(N==1)printf("1 ");
       else 
       {
       for(n=0;n<N;n++)
       {  
           if(n%2==0)
           {    t=0; 
                   while(t<M-1)
                   {
                       i--;
                    if(i<0)i=N-1;
                    if(x[i]==0)t++;
                }
                x[i]=1;
                if(i==0)printf("%d ",N);
                else printf("%d ",i);
            }
               if(n%2==1)
           {    t=0;
                   while(t<K-1)
                   {
                       i++;
                    if(i>N-1)i=0;
                    if(x[i]==0)t++;
                }
                x[i]=1;
                if(i==0)printf("%d ",N);
                else printf("%d ",i);
            }
        }
           }
}
