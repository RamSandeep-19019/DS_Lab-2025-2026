#include<iostream>
#include<algorithm>
using namespace std;
void insertion_sort(int arr[],int sorted_length,int arr_size){
    if(sorted_length==arr_size){
        return;
    }
    int x=arr[sorted_length];
    for(int i=0;i<sorted_length;i++){
        if(x<arr[i]){
            cout<<"swapping"<<arr[i]<<" "<<x<<endl;
            swap(arr[i],x);
        }
    }
    arr[sorted_length]=x;
    sorted_length++;
    insertion_sort(arr,sorted_length,arr_size);
}
int main(){
    int arr[8]={5,3,2,1,10,8,7,9};
    int x=1;
    insertion_sort(arr,x,8);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
}