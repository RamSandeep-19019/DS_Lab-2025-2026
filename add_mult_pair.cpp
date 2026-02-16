#include<stdio.h>
int func(int arr[],int n){ int r=0;
	for(int i=0;i<=n/2;i++){
		for(int j=i;j<n;j++){
		if((arr[i]*arr[j])%2!=0 && i!=j){
			printf("%d %d  ",arr[i],arr[j]);r=1;
		}
		}
	}
	if(r==0){
		printf("No odd product pair found");
	}
}
int main(){
	int arr[100];
	printf("enter the number of elements:");
	int n;
	scanf("%d",&n);
	printf("enter the elements:");	
	for(int i=0;i<n;i++){
	scanf("%d",&arr[i]);
	}
	func(arr,n);
}
