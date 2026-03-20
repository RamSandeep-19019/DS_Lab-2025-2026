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
void create_lnk_list(node**head,int n){
 string name;
 int id;
 float marks;
 node**temp;
 temp=head;
    for(int i=0;i<n;i++){
        cout<<"Roll_No,name,marks: ";
        cin>>id>>name>>marks;
        if(*head==NULL){
            *head=createNode(id,name,marks);
            temp=head;
        }
        else{
            (*temp)->next=createNode(id,name,marks);
            *temp=(*temp)->next;
        }
    }
}
void backward_traversal(int pointer,int v[],int arr_size);
void forward_traversal(int pointer,int v[],int arr_size){
   
    for(int i=0;i<pointer;i++){
        if(v[i]>v[pointer]){
            cout<<"swapping"<<v[i]<<v[pointer]<<endl;
            swap(v[i],v[pointer]);
            pointer=i;
           break;
        }
    }cout<<"going for backward traversal"<<endl;
     backward_traversal(pointer,v,arr_size);
}
void backward_traversal(int pointer,int v[],int arr_size){
    for(int i=arr_size-1;i>pointer;i--){
        if(v[i]>v[pointer]){
            cout<<"swapping"<<v[i]<<v[pointer]<<endl;
            swap(v[i],v[pointer]);
            pointer=i;
            break;
        }
    }cout<<"going for forward traversal"<<endl;
    forward_traversal(pointer,v,arr_size);
}
int search_value(int arr[],int n,int id){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==id){
            return i;
        }
    }
    
}
void quick_sort(node* start,node* last){
    if(start==last||start==NULL){
        return;
    }
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
    cout<<"going for forward traversal"<<endl;
    forward_traversal(pointer,arr,n);
    node *next_start,*next_last;
     x=search_value(arr,n,pointer);
    temp=start;
    for(int i=0;i<n;i++){
        temp->marks=arr[i];
        temp=temp->next;        
    }
    temp=start;
    for (int i = 0; i < x; i++)
    {
        next_last=temp;
        temp=temp->next;
    }
    next_start=temp->next;
    if(next_last!=NULL)
    quick_sort(start,next_last);
    if(next_start!=NULL)
    quick_sort(next_start,last);
    
    
}
void display_lnk_list(node *head){
   node*temp;
   temp=head;
    while(temp!=NULL){
        cout<<temp->roll_No<<" "<<temp->name<<" "<<temp->marks<<endl;
    }
}
void delete_lnk_list(node *head){
    node *temp;
    
    while(head!=NULL){
        temp=head;
        head=head->next;
        delete(temp);
    }
}
int main(){
    node *head,*temp;
    head=NULL;
    int n;
    cin>>n;
    temp=head;
    create_lnk_list(&head,n);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    display_lnk_list(head);
    quick_sort(head,temp);
    display_lnk_list(head);
    delete_lnk_list(head);
}
