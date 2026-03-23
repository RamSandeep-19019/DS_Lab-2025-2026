#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
void radix_sort(int arr[],int n,int j){
    
    stack<int> s0,s1,s2,s3,s4,s5,s6,s7,s8,s9;
    int x=pow(10,j+1);
    int y;
    int z=j;
   for(int i=0;i<n;i++){
    y=arr[i]%x;
    while(j>0){
      y/=10;
      j--;
    }j=z;
   
    switch(y){
        case 0:
          s0.push(arr[i]);
       
        break;
        case 1:
        s1.push(arr[i]);
         
        break;
        case 2:
          s2.push(arr[i]);
        
        break;
        case 3:
          s3.push(arr[i]);
        
        break;
        case 4:
          s4.push(arr[i]);
       
        break;
        case 5:
          s5.push(arr[i]);
        
        break;
        case 6:
          s6.push(arr[i]);
        
        break;
        case 7:
          s7.push(arr[i]);
        
        break;
        case 8:
          s8.push(arr[i]);
        
        break;
        case 9:
          s9.push(arr[i]);
        
        break;
        
    }
   }
   stack<int> s;
 while(s9.size()!=0){
    s.push(s9.top());
    
    s9.pop();
 }
 while(s8.size()!=0){
    s.push(s8.top());
    
    s8.pop();
 }
 while(s7.size()!=0){
    s.push(s7.top());
    
    s7.pop();
 }
 while(s6.size()!=0){
    s.push(s6.top());
    
    s6.pop();
 }
 while(s5.size()!=0){
    s.push(s5.top());
    
    s5.pop();
 }
  while(s4.size()!=0){
    s.push(s4.top());
    
    s4.pop();
 }
  while(s3.size()!=0){
    s.push(s3.top());
    
    s3.pop();
 }
  while(s2.size()!=0){
    s.push(s2.top());
    
    s2.pop();
 }
  while(s1.size()!=0){
    s.push(s1.top());
    
    s1.pop();
 }
  while(s0.size()!=0){
    s.push(s0.top());
    
    s0.pop();
 }
 int i=0;

 
 while(!s.empty()){
  arr[i]=s.top();
  s.pop();
  i++;
 }

}
int main(){
int n;
cout<<"Enter number of pin codes: ";
cin>>n;
int arr[n];
cout<<"Enter PIN codes:\n";
for(int i=0;i<n;i++){
    cin>>arr[i];
    while(arr[i]>999999){
        cout<<"Invalid PIN! Enter a 6-digit PIN code: ";
       cin>>arr[i];
    }
}
for(int i=0;i<6;i++){
  radix_sort(arr,n,i);
}
cout<<"Sorted PIN codes:\n";
for (int i = 0; i < n; i++)
{
  cout<<arr[i]<<" ";
}


}
