#include <stdio.h>
#define N 4
main(){
    int t[][N]={21,2,13,24,25,16,47,38,29,11,32,54,42,21,3,10};
    int i,j,sum;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
        printf("%4d",t[i][j]);
        printf("\n");
    }
    sum=0;
    for(i=0;i<N;i++)
    sum+=t[i][i];
    for(i=0;i<N;i++)
    sum+=t[i][N-i-1];
    printf("%d\n",sum);
}