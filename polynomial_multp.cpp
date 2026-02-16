#include<iostream>
#include<vector>
using namespace std;
typedef struct node Node;
struct node{
    int x,n;
    Node *next;
};
void create_poly(Node *head,int size){
    Node *new_node,*temp;
    if(size==0){
        return;
    }
    cout<<"Enter the coefficient and Exponent:";
    while(size){
        new_node=new Node;
        new_node->next=NULL;
        
        cin>>new_node->n>>new_node->x;
        if(head->next==NULL){
            head->next=new_node;
            temp=head;
        }
        else{
            temp->next->next=new_node;
            temp=temp->next;
        }
        size--;
    }
}
void print_poly(Node *head){
    Node *temp;
    temp=head->next;
    while(temp!=NULL){
        cout<<temp->n<<"x^"<<temp->x;
        
        if(temp->next!=NULL){
            cout<<"+";
        }
        temp=temp->next;
    }
cout<<"\n";
}
int main(){
    Node *head1,*head2,*temp1,*temp2,*temp3;
    head1=new Node;
    head2=new Node;
    head1->next=NULL;
    head2->next=NULL;
    int size1,size2;
    cout<<"For first polyomial:\nEnter the number of terms:";
    cin>>size1;
    create_poly(head1,size1);
    
    cout<<"For second polyomial:\nEnter the number of terms:";
    cin>>size2;
    create_poly(head2,size2);
    if(size1==0 || size2==0){
        cout<<"Operation is not possible";
        return 0;
    }print_poly(head1);
    print_poly(head2);

    vector<pair<int,int> > v1;
    int n;
    temp1=head1->next;
    temp2=head2->next;
    while(temp1!=NULL){
        while(temp2!=NULL){
            v1.push_back({(temp1->n*temp2->n),(temp1->x+temp2->x)});
            temp2=temp2->next;
        } 
        temp1=temp1->next;
    }
    int r=1;
    Node *head3,*new_node;
    head3=new Node;
    head3->next=NULL;
    Node *temp4;
    temp4=head3->next;
    for(int i=0;i<(size1*size2);i++){
        while(temp4!=NULL){
            if(v1[i].second==temp4->x){
                r=0;
            }
            temp4=temp4->next;
        }
        if(r){
            new_node=new Node;
            new_node->next=NULL;
        }

        new_node->x=v1[i].second;
        new_node->n=v1[i].first;
        for(int j=0;j<(size1*size2);j++){
        if(i!=j && v1[i].second==v1[j].second){
            new_node->n=new_node->n+v1[j].first;
        }

    }
     if(head3->next==NULL){
            head3->next=new_node;
            temp3=head3;
        }
        else{
            temp3->next->next=new_node;
            temp3=temp3->next;
        }
    r=1;
    }
    print_poly(head3);
}
