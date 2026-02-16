#include<iostream>

using namespace std;

struct node{
    struct node *prev;
    int x;
    struct node *next;
};

int main(){
    struct node *new_node,*temp,*head;
    head=new struct node;
    head->next=NULL;
    head->prev=NULL;
    int input,input2;
    cout<<"Which one do you want to start:\n1.Insert at Beginning\n2.Insert at End\n3.Insert at position\n4.Delete from Beginning\n5.Delete from End\n6.Delete from position\n7.Display\n8.Exit\n";
    cin>>input;
    

    while(input != 8){
   if( input !=7) {
    new_node=new struct node;
    new_node->next=NULL;
    new_node->prev=NULL;
    cout<<"enter the value";
    cin>>new_node->x;
   }
    if(input==1){
        //---at beginning----
        if(head->next!=NULL){
        new_node->next=head->next;
        head->next->prev=new_node;
        head->next=new_node;
        new_node->prev=head;
        }
        else{
            new_node->prev=head;
            head->next=new_node;
        }
    }

    else if(input==2){
    //----at end----
    if(head->next==NULL){
        head->next=new_node;
        new_node->prev=head;
        temp=head;
        
        
    }
    else{
        temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next->next=new_node;
        new_node->prev=temp->next;
        
    }
   
}

    else if(input==3){
    //-----at a position----
    int n,i=3;
    cout<<"Enter the position:";
    cin>>n;
    temp=head->next;
    while(i<n){
    temp=temp->next;
    i++;
    }
    new_node->next=temp->next;
    temp->next->prev=new_node;
    temp->next=new_node;
    new_node->prev=temp;
    
}

    else if(input==7){
	
    //---Display---
    temp=head;
    while(temp!=NULL){
        if(temp!=head){cout<<temp->x;}
        temp=temp->next;
        if(temp!=NULL ){
           if(temp!=head){cout<<"<->";}
        }
    }
    
	}
    cout<<"\nWhich one do you want to start:\n1.Insert at Beginning\n2.Insert at End\n3.Insert at position\n4.Delete from Beginning\n5.Delete from End\n6.Delete from position\n7.Display\n8.Exit\n";
    cin>>input;
	}
    //----at end---

    
}
