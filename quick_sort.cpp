#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{       
    int roll_No;
    string name;
    float marks;
    node* next;
};
struct node* createNode(int id,string name,float marks){
    node *new_node;
    new_node= new node;
    new_node->marks=marks;
    new_node->roll_No=id;
    new_node->name=name;
    new_node->next=NULL;
    return new_node;
}
void create_lnk_list(node*head,int n){
 string name;
 int id;
 float marks;
 node*temp;
    for(int i=0;i<n;i++){
        cout<<"Roll_No,name,marks: ";
        cin>>id>>name>>marks;
        if(head==NULL){
            head=createNode(id,name,marks);
        }
        else{
            temp->next=createNode(id,name,marks);
            temp=temp->next;
        }
    }
}
void forward_traversal(int pointer,int v[],int arr_size){
   
    for(int i=0;i<pointer;i++){
        if(v[i]>v[pointer]){
            swap(v[i],v[pointer]);
            pointer=i;
           break;
        }
    } backward_traversal(pointer,v,arr_size);
}
void backward_traversal(int pointer,int v[],int arr_size){
    for(int i=arr_size-1;i>pointer;i--){
        if(v[i]>v[pointer]){
            swap(v[i],v[pointer]);
            pointer=i;
            break;
        }
    }forward_traversal(pointer,v,arr_size);
}
void quick_sort(node* start,node* last){
    node*temp;
    temp=start;
    vector<int> v;
    while(temp!=last){
        v.push_back(temp->marks);
    }
    v.push_back(last->marks);
    int n=sizeof(v),x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=v[i];
    }
    int pointer=n-1;
    int pivot=arr[n-1];
    forward_traversal(pointer,arr,n);
    
    
}
int main(){
    node* head;
    head=NULL;
    int n;

}