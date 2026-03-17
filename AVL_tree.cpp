#include<iostream>
using namespace std;
struct node{
    int ID;
    int rating;
    char name[50];
    node *left,*right;
};
struct node* createNode(int ID){
    node *new_node;
    new_node= new node;
    new_node->ID=ID;
    cout<<"Enter the name and rating: ";
    cin>>new_node->name>>new_node->rating;
    
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void insert_node(node**root,int ID){
    if(*root==NULL){
     *root=createNode(ID);
     return;
 }  
 if(ID==(*root)->ID){
    return;
 }
 else if(ID<(*root)->ID){
    insert_node(&(*root)->left,ID);
   
 }
  else if(ID>(*root)->ID){
    insert_node(&(*root)->right,ID);
   
 }

}
void display_tree_inorder(node*root){
if(root==NULL){
    return;
}
  display_tree_inorder(root->left);
  cout<<"ID: "<<root->ID<<" Name: "<<root->name<<" Rating: "<<root->rating<<endl;
  display_tree_inorder(root->right);
 
}
void LL_rotation(node **root){
     node *x,*y;
    x=(*root)->left->right;
    y=(*root)->left;
    (*root)->left=x;
   y->right=*root;
    *root=y;
}
void RR_rotation(node **root){
    node *x,*y;
    x=(*root)->right->left;
    y=(*root)->right;
    (*root)->right=x;
   y->left=*root;
    *root=y;
   
}
void LR_rotation(node **root){
    RR_rotation(&(*root)->left);
    LL_rotation(&(*root));
}
void RL_rotation(node **root){
    LL_rotation(&(*root)->right);
    RR_rotation(&(*root));
}
void delete_tree(node **root){
    if(*root==NULL)
    return;
    delete_tree(&(*root)->left);
    delete_tree(&(*root)->right);
    node *temp;
    temp=*root;
    delete(temp);
    *root=NULL;
}
void search_ID(node *root,int ID){
  if (root==NULL){
    cout<<"Not found";
    return;
  }
  else if(root->ID==ID){
    cout<<"ID: "<<root->ID<<" Name: "<<root->name<<" Rating: "<<root->rating;
    return;
  }
  else if(ID>root->ID){
    search_ID(root->right,ID);
  }
  else if(ID<root->ID){
    search_ID(root->left,ID);
  }
}
void update_rating(node **root,int ID,int rating){
  if (root==NULL){
    cout<<"ID Not found";
    return;
  }
  else if((*root)->ID==ID){
    (*root)->rating=rating;
    return;
  }
  else if(ID>(*root)->ID){
    update_rating(&(*root)->right,ID,rating);
  }
  else if(ID<(*root)->ID){
    update_rating(&(*root)->left,ID,rating);
  }
}
int find_height(node *root){
    if(root==NULL){
        return 0;
    }
    int x=find_height(root->left);
    int y=find_height(root->right);
    int z=(x>y)?x:y;
    return z+1;
}
bool check_unbalance(node *root){
   int x=find_height(root->left)-find_height(root->right);
    if(x>1||x<-1){
      return true;
    }
    else{
      return false;
    }
}
void AVL_tree(node **root,int ID){
  if(root==NULL||(*root)->ID==ID){
    return;
  }
 if(ID<(*root)->ID){
 AVL_tree(&(*root)->left,ID);
  if(check_unbalance((*root))){
   if((*root)->left!=NULL&&ID<(*root)->left->ID)
   LL_rotation(root);
   else
   LR_rotation(root);
  }
}
 else if(ID>(*root)->ID)
  AVL_tree(&(*root)->right,ID);
if(check_unbalance(*root)){
   if((*root)->right!=NULL&&ID>(*root)->right->ID)
   RR_rotation(root);
   else
   RL_rotation(root);
  }
 
  
   
}
int main(){
    node *root;
    root=NULL;
    int input,n;
    cout<<"1.Employee Join\n2.Employee Exit\n3.Search Employee\n4.Update Rating\n5.Display Employees\n6.Exit\nEnter your choice: ";
    cin>>input;
    int x,y,z;
while(input!=6){
    switch(input){
        case 1:
        cout<<"enter the ID: ";
        cin>>n;
        insert_node(&root,n);
        AVL_tree(&root,n);
            break;
        case 2:
        
        cout<<"Enter the value: ";
        cin>>x;
       // delete_node2(&root,x);
            break;
        case 3:
        cout<<"Employee ID to search: ";
        cin>>y;
        search_ID(root,y);
        break;
        case 4:
        cout<<"Employee ID and rating: ";
        cin>>y>>z;
        break;
        case 5:
        display_tree_inorder(root);
        break;
}
cout<<"\n\n\n1.Employee Join\n2.Employee Exit\n3.Search Employee\n4.Update Rating\n5.Display Employees\n6.Exit\nEnter your choice: ";
               cin>>input;
}
delete_tree(&root);
}
