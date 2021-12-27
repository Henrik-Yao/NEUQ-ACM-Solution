#include <bits/stdc++.h>
using namespace std;
queue<int>q[100];
int main(){
    int n;
    cin>>n;
    int num=0;
    int a;
    cin>>a;
    q[num].push(a);
    n-=1;num++; 
    while(n--){
        cin>>a;
        bool flag=false;
        for(int i=0;i<num;i++)
            if(q[i].back()>=a)
            {
                q[i].push(a);
                flag=true;
                break;
            }
        if(!flag){
            q[num].push(a);
            num++;
        }
    }
    int i;
    for(i=0;i<num;i++)
            if(q[i].back()==1){
                break;
            }
    int arr[100];
    int k=0;
    memset(arr,0,sizeof(arr));
    while(!q[i].empty()){
        arr[k++]=q[i].front();
        q[i].pop();
    }
    for(int j=0;j<k-1;j++){
        cout<<arr[j]<<" ";
    }
    cout<<arr[k-1]<<endl;
    cout<<num<<endl;
    return 0;
}
