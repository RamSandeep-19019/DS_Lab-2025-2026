#include<bits/stdc++.h>
using namespace std;
int fiboncci_search(int arr[],int n,int key){
    int k=-1,i,f1,f2;
    bool tr=true;
    int count=0;
    int fib[11]={0,1,1,2,3,5,8,13,21,34,55};
    int fibu;
    for (int i = 0; i < 10; i++)
    {
        if(fib[i]>=n){
            if(i>1){
                f1=fib[i-1];
                f2=fib[i-2];
            }
            fibu=fib[i];
            break;
        }
    }
    while (count<100)
    { count++;
        i=min(f2+k,n-1);
        if(arr[i]<key){
            fibu=f2;
            f2=f1-f2;
            f1=fibu;
            k=i;
        }
        else if(arr[i]>key){
            fibu=f2;
            f2=f1-f2;
            f1=fibu;
        }
        else if(arr[i]==key){
           
            return i+1;
        }

    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int fib[11]={0,1,1,2,3,5,8,13,21,34,55};
    int fibu;
    for (int i = 0; i < 10; i++)
    {
        if(fib[i]>=n){
            fibu=fib[i];
            break;
        }
    }
    int key;
    cin>>key;
    int t=fiboncci_search(arr,n,key);
    if(t!=-1)
    cout<<t;
    else
    cout<<"No element";
}