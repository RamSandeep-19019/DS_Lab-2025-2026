#include<iostream>
#include<stack>
using namespace std;
void radix_sort(int arr[],int n){
    int count=0;
    stack<int> s0,s1,s2,s3,s4,s5,s6,s7,s8,s9;
   for(int i=0;i<n;i++){
    switch(arr[i]){
        case 1:
        s1.push(count);
        count++;
        break;
        case 2:
          s2.push(count);
        count++;
        break;
        case 3:
          s3.push(count);
        count++;
        break;
        case 4:
          s4.push(count);
        count++;
        break;
        case 5:
          s5.push(count);
        count++;
        break;
        case 6:
          s6.push(count);
        count++;
        break;
        case 7:
          s7.push(count);
        count++;
        break;
        case 8:
          s8.push(count);
        count++;
        break;
        case 9:
          s9.push(count);
        count++;
        break;
        case 10:
          s0.push(count);
        count++;
        break;
    }
   }
   stack<int> s;
 while(sizeof(s9)!=0){
    s.push(s9.top());
    s9.pop();
 }
 while(sizeof(s8)!=0){
    s.push(s8.top());
    s8.pop();
 }
 while(sizeof(s7)!=0){
    s.push(s7.top());
    s7.pop();
 }
 while(sizeof(s6)!=0){
    s.push(s6.top());
    s6.pop();
 }
 while(sizeof(s5)!=0){
    s.push(s5.top());
    s5.pop();
 }
}
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i]>999999){
        cout<<"Invalid input give again: ";
       cin>>arr[i];
    }
}


}