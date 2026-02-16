#include<stdio.h>
int main(){
	int n;
	printf("enter the size:");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements:\n");
	for(int i=0;i<n;i++){
	
	scanf("%d",&arr[i]);
}
	int M[n];

//	for(int i=0;i<n;i++)
	M[0]=1;

	for(int i=1;i<n;i++){
		M[i]=M[i-1]*arr[i-1];
	}
	int p=1;
	for(int i=n-1;i>=0;i--){
		M[i]=M[i]*p;
		p*=M[i];
	}
	for(int i=0;i<n;i++)
	printf("%d ",M[i]);
}
