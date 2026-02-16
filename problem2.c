#include<stdio.h>
void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}
void func(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
}
int main(){
    int arr[100];
    int n;
    printf("enter size");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    func(arr,n);
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}