#include<bits/stdc++.h>
using namespace std;

int fibseries[20];

void makeFib() {
    fibseries[0]=1;
    int fib=1, prev=0;
    for(int i=1;i<20;i++) {
        fib=fib+prev;
        prev=fib-prev;
        fibseries[i]=fib;
}
}

int findMaxFib(int num) {
    for(int i=0;i<20;i++) {
        if(fibseries[i]>num)
        return i;
    }
}

int fibSearch(int arr[], int num, int length, int key) {
    int offset=-1;
    while(fibseries[num]>1) {
        int i=min(offset+fibseries[num-2], length-1);
        if(arr[i]<key) {
            offset=i;
            num--;
        }
        else if(arr[i]>key) {
            num-=2;
        }
        else
        return i;
    }
    return -1;
}
int main() {
    makeFib();
    cout<<"Enter number of elements: ";
    int n;
    cin>>n;
    int fib=findMaxFib(n);
    int arr[n];
    cout<<"Enter sorted elements:\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Enter element to search: ";
    int key;
    cin>>key;
    int result=fibSearch(arr, fib, n, key);
    if(result==-1)
    cout<<"Element not found";
    else
    cout<<"Element found at position: "<<result+1;
}