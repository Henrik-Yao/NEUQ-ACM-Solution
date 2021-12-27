#include<bits/stdc++.h>
using namespace std;
struct sss
{
   int data;
   struct sss* next;
};
struct sss *head,*p,*q,*r,*ohead,*jhead;
int a[1005];
void ssort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            swap(a[i],a[j]);
        }
    }
}
void creat(int a[],int n)
{
    head=(struct sss*)malloc(sizeof(struct sss));
    head->next=NULL;
    p=head;
    for(int i=0;i<n;i++)
    {
        r=(struct sss*)malloc(sizeof(struct sss));
        r->next=NULL;
        r->data=a[i];
        p->next=r;
        p=p->next;
    }
}
void ocreat(int a[],int n)
{
    ohead=(struct sss*)malloc(sizeof(struct sss));
    ohead->next=NULL;
    p=ohead;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            r=(struct sss*)malloc(sizeof(struct sss));
            r->next=NULL;
            r->data=a[i];
            p->next=r;
            p=p->next;
        }
        
    }
}
void jcreat(int a[],int n)
{
    jhead=(struct sss*)malloc(sizeof(struct sss));
    jhead->next=NULL;
    p=jhead;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2!=0)
        {
            r=(struct sss*)malloc(sizeof(struct sss));
            r->next=NULL;
            r->data=a[i];
            p->next=r;
            p=p->next;
        }
    }
}
int main()
{
    int f=1,n=0;
    while(cin>>a[n])
    {
        n++;
    }
    ssort(a,n);
    creat(a,n);
    ocreat(a,n);
    jcreat(a,n);
    p=head->next;
    while(p!=NULL)
    {
        q=p;
        if(f)
        {
            cout<<p->data;
            f=0;
        }
        else 
        {
            cout<<"->"<<p->data;
        }
        p=p->next;
    }
    puts("");
    p=jhead->next;
    f=1;
    while(p!=NULL)
    {
        q=p;
        if(f)
        {
            cout<<p->data;
            f=0;
        }
        else 
        {
            cout<<"->"<<p->data;
        }
        p=p->next;
    }
    puts("");
    p=ohead->next;
    f=1;
      while(p!=NULL)
    {
        q=p;
        if(f)
        {
            cout<<p->data;
            f=0;
        }
        else 
        {
            cout<<"->"<<p->data;
        }
        p=p->next;
    }
    return 0;
}