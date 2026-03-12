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
void insert(struct node **root,int key)
{
 if(*root==NULL){
     *root=createNode(key);
     return;
 }  
 if(key==(*root)->key){
    return;
 }
 else if(key<(*root)->key){
    insert(&(*root)->left,key);
   
 }
  else if(key>(*root)->key){
    insert(&(*root)->right,key);
   
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
void delete_node_my_firt_one(node*root,int key){
    if(root=NULL){
        cout<<"No match found";
        return;
    }
    else if(root->key>key){
        delete_node_my_firt_one(root->left,key);
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
        delete_node_my_firt_one(root->right,key);
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
void delete_node2(node **root,int x);

int find_min(node* root){
    if(root->left==NULL){
        return root->key;
    }
    else{
       return find_min(root->left);
    }

}
void case_1(node **root){
    node *temp;
    temp=*root;
    *root=NULL;
    delete temp;
}
void case_2(node **root){
    node *temp;
    temp=*root;
    if((*root)->left!=NULL)
    *root=(*root)->left;
    else
     *root=(*root)->right;
     delete(temp);
}
void case_3(node **root){
    int y=find_min((*root)->right);
    (*root)->key=y;
    delete_node2(root,y);
}
void delete_node2(node **root,int key){
    if(*root==NULL){
        cout<<"No value is there";
        return;
    }
    else if(key<(*root)->key){
        delete_node2(&(*root)->left,key);
    }
    else if(key>(*root)->key){
        delete_node2(&((*root)->right),key);
    }
    else if(key==(*root)->key){
        if((*root)->left==NULL&&(*root)->right==NULL){
            case_1(root);
        }
        if(((*root)->left!=NULL&&(*root)->right==NULL)||((*root)->left==NULL&&(*root)->right!=NULL)){
            case_2(root);
        }
        if((*root)->left!=NULL&&(*root)->right!=NULL){
            case_3(root);
        }
    }
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
int main(){
node *root;
int input,n;
cout<<"1.Insert\n2.Delete\n3.Inorder Traversal\n4.preorder Traversal\n5.postorder Traversal\n6.Exit\nEnter your choice: ";
cin>>input;

int x;
while(input!=6){
    switch(input){
        case 1:
        cout<<"enter the value";
        cin>>n;
        insert(&root,n);
            break;
        case 2:
        
        cout<<"Enter the value: ";
        cin>>x;
        delete_node2(&root,x);
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

cout<<"\n\n\n1.Insert\n2.Delete\n3.Inorder Traversal\n4.preorder Traversal\n5.postorder Traversal\n6.Exit\nEnter your choice: ";
               cin>>input;
}
delete_tree(&root);
}
