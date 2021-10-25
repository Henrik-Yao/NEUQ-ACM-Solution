 #include <bits/stdc++.h>
 using namespace std;

const int max_N =  1e5 + 5;
void print(int arr[],int n){
    int i;
    for(i = 0;i < n;i++)
    cout<<arr[i]<<' ';
}

void merge(int arr[],int temparr[],int left,int mid,int right){
    int l_pos = left;
    int r_pos = mid + 1;
    int pos = left;
    while(l_pos <= mid && r_pos <= right){
        if(arr[l_pos] < arr[r_pos])
        temparr[pos++] = arr[l_pos++];
        else
        temparr[pos++] = arr[r_pos++];
    }
    while(l_pos <= mid) 
    temparr[pos++] = arr[l_pos++];
    while(r_pos <= right)
    temparr[pos++] = arr[r_pos++];
    while(left <= right){
        arr[left] = temparr[left];
        left++;
    }
}

void msort(int arr[],int temparr[],int left,int right){
    if(left < right){
        int mid = (left + right) / 2;
        msort(arr,temparr,left,mid);
        msort(arr,temparr,mid + 1,right);
        merge(arr,temparr,left,mid,right);
    }

}

void merge_sort(int arr[],int n){
    int temparr[max_N] = {};
        msort(arr,temparr,0,n - 1);
}

int main(int argc, char const * argv[]){
    int arr[max_N] = {0};
    int n;cin>>n;
    for(int i = 0;i < n;i++)cin>>arr[i];
    merge_sort(arr,n);
    print(arr,n);
    return 0;
 }