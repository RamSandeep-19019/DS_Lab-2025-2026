#include<iostream>
#include<algorithm>
using namespace std;
void selection_sort(int arr[],int n,int sorted_length){
    if(sorted_length==n-1){
        return;
    }
    int min=sorted_length;
    for(int i=sorted_length+1;i<n;i++){
        if(arr[min]>arr[i]){
            min=i;
        }
    }
    cout<<sorted_length<<" ";
    
    if(min!=sorted_length){cout<<"swapping"<<arr[min]<<" "<<arr[sorted_length]<<endl;
    swap(arr[min],arr[sorted_length]);}
    sorted_length++;
    selection_sort(arr,n,sorted_length);
}
int main(){
    int arr[8]={5,3,2,1,10,8,7,9};
    int x=0;
    selection_sort(arr,8,x);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
}