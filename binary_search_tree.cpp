#include<iostream>
using namespace std;
struct node{
    int key;
    node *left;
    node *right;

};
struct node* createNode(int key){
    node *new_node;
    new_node= new node;
    new_node->key=key;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void insert(struct node* root,int key)
{
 if(root==NULL){
     return ;
 }  
 if(key==root->key){
    return;
 }
 else if(key<root->key){
    insert(root->left,key);
    if(root->left==NULL){
        root->left=createNode(key);
    }
 }
  else if(key>root->key){
    insert(root->right,key);
    root->right=createNode(key);
 }

}
void display_tree_inorder(node*root){
if(root==NULL){
    return;
}
 display_tree_inorder(root->left);
  cout<< root->key<<" ";
  display_tree_inorder(root->right);
 
}
void display_tree_preorder(node*root){
if(root==NULL){
    return;
}
cout<< root->key<<" ";
 display_tree_preorder(root->left);
  
  display_tree_preorder(root->right);
 
}
void display_tree_postorder(node*root){
if(root==NULL){
    return;
}

 display_tree_postorder(root->left);
  
  display_tree_postorder(root->right);
 cout<< root->key<<" ";
}
void delete_node(node*root,int key){
    if(root=NULL){
        cout<<"No match found";
        return;
    }
    else if(root->key>key){
        delete_node(root->left,key);
        if(root->left->key==key){
         if(root->left->left==NULL&&root->left->right!=NULL){
        node *temp;
        temp=root->left->right;
        delete(root->left);
        root->left=temp;
    }
     else if(root->left->right==NULL&&root->left->left!=NULL){
        node *temp;
        temp=root->left->left;
        delete(root->left);
        root->left=temp;
    }
    }
    }
    else if(root->key<key){
        delete_node(root->right,key);
         if(root->right->key==key){
         if(root->right->left==NULL&&root->right->right!=NULL){
        node *temp;
        temp=root->right->right;
        delete(root->right);
        root->right=temp;
    }
     else if(root->right->right==NULL&&root->right->left!=NULL){
        node *temp;
        temp=root->right->left;
        delete(root->right);
        root->right=temp;
    }
    }
    }
    else if(root->key==key){
    if(root->left==NULL&&root->right==NULL){
        delete(root);
    }
    
}
}
int main(){
node *root;
int input,n;
root=new node;
root->key=10000;
int count=1;
root->left=NULL;
root->right=NULL;
cout<<"1.Insert\n2.Delete\n3.Inorder Traversal\n4.preoder Traversal\n5.Postorder traversal\n6.Exit\nEnter your choice: ";
cin>>input;


while(input!=6){
    switch(input){
        case 1:
        cout<<"enter the value";
        if(root->key==10000){
            cin>>root->key;
        }
        else{ 
               cin>>n;
               insert(root,n);
               
            }
            break;
        case 2:
        cout<<"2";
            break;
        case 3:
        display_tree_inorder(root);
        break;
        case 4:
        display_tree_preorder(root);
        break;
        case 5:
        display_tree_postorder(root);
        break;
}

cout<<"\n\n\n1.Insert\n2.Delete\n3.Inorder Traversal\n4.preoder Traversal\n6.Exit\nEnter your choice: ";
               cin>>input;
}

}