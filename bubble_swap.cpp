#include<stdio.h>
struct rec{
	int id;
	char str[100];
	int age;
};
void func(struct rec arr[],int n){
   struct rec temp[10]; 
   for(int i=0;i<n-1;i++){
        if(arr[i].age>arr[i+1].age){
         printf("%d %s %d \n",arr[i+1].id,arr[i+1].str,arr[i+1].age);
 
        }
    }
printf("%d %s %d \n",arr[n-1].id,arr[n-1].str,arr[n-1].age);
}
int main(){
	int n;
	printf("enter the number of rows");
	scanf("%d",&n);
    struct rec a[10];
    for(int i=0;i<n;i++){
	
    scanf("%d %s %d",&a[i].id,&a[i].str,&a[i].age);
//    printf("%d %s %d",a[1].id,a[1].str,a[1].age);
}

    func(a,n);
    
}
