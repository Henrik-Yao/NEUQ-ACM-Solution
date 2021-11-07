#include <cstdio>
#include <cstring>
using namespace std;


long long a[100000010], tmp[100000010];
long long answer;


void M(long long l, long long m, long long r)
{
    long long i = l;
    long long j = m + 1;
    long long k = l;
    while(i <= m && j <= r)
    {
        if(a[i] > a[j])
        {
            tmp[k++] = a[j++];
            answer += m - i + 1;
        }
        else
        {
            tmp[k++] = a[i++];
        }
    }
    while(i <= m) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(long long i = l; i <= r; i++)
    {
        a[i] = tmp[i];
    }
}
void sort(long long l,long long r)
{
    if(l < r)
    {
        long long m = (l + r) >> 1;
        sort(l,m);
        sort(m+1,r);
        M(l,m,r);
    }
}
int main()
{

    long long n;
    long long i, j;
    while(scanf("%lld", &n)!=EOF)
    {
        for(i=0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        answer = 0;
        sort(0,n-1);
        printf("%lld\n", answer);
    }
    return 0;
}
