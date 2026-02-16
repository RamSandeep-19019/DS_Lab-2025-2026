#include<stack>
#include<iostream>
using namespace std ;
int main(){
	int n;
	cin>>n;
	int arr[20];
	int ans[20];
	stack <int> s;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int p=n-1;
   for(int i=n-1;i>=0;i--){
	if(s.empty()){
	ans[p]=-1;
	s.push(arr[i]);
	}
	else if(s.top()>arr[i]){
	
	ans[p]=s.top();
	s.push(arr[i]);	
	}	
   else{

   	s.pop();
   	if(s.empty()){
	ans[p]=-1;
	
	}
	else{
	ans[p]=s.top();
   
   }s.push(arr[i]);
}
   p=p-1;
   }
   for(int i=0;i<n;i++){
   	cout<<ans[i]<<" ";
   }

}
