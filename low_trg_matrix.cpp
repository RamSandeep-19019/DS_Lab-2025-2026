#include<stdio.h>
int main(){
	int n;
	int arr[10][10];
	printf("enter the size:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	printf("Compressed array\n");
	int arr2[20];
	for(int i=0,k=0;i<n;i++){
		for (int j=0;j<=i;j++,k++){
			printf("%d",arr[i][j]);
			arr2[k]=arr[i][j];
		}
	}
	printf("\nenetr the indices i and j:");
	int i,j;
	scanf("%d %d",&i,&j);
	printf("%d",arr2[(i*(i+1))/2+j]);
	
	
}
