#include<iostream>
using namespace std;
struct node{
    int ID;
    int rating;
    string name;
    node *left,*right;
};
struct node* createNode(int ID,string& name,int rating){
    node *new_node;
    new_node= new node;
    new_node->ID=ID;
    new_node->name=name;
    new_node->rating=rating;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void insert_node(node**root,int ID,string& name,int rating){
    if(*root==NULL){
     *root=createNode(ID,name,rating);
     return;
 }  
 if(ID==(*root)->ID){
    return;
 }
 else if(ID<(*root)->ID){
    insert_node(&(*root)->left,ID,name,rating);
   
 }
  else if(ID>(*root)->ID){
    insert_node(&(*root)->right,ID,name,rating);
   
 }

}
void display_tree_inorder(node*root){
if(root==NULL){
    return;
}
  display_tree_inorder(root->left);
  cout<<"ID:"<<root->ID<<" Name:"<<root->name<<" Rating:"<<root->rating<<"/10"<<endl;
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
    cout<<"Employee Found -> ID:"<<root->ID<<" Name:"<<root->name<<" Rating:"<<root->rating<<"/10";
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
  if (*root==NULL){
    cout<<"ID Not found";
    return;
  }
  else if(rating>10||rating<0){
    cout<<"Rating must be between 0 and 10";
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
int balance_factor(node*root){
    int x=find_height(root->left)-find_height(root->right);
      return x;
}
void AVL_tree_insertion(node **root,int ID){
  if(*root==NULL||(*root)->ID==ID){
    return;
  }
 if(ID<(*root)->ID){
 AVL_tree_insertion(&(*root)->left,ID);
  if(check_unbalance((*root))){
   if((*root)->left!=NULL&&ID<(*root)->left->ID)
   LL_rotation(root);
   else
   LR_rotation(root);
  }
}
 else if(ID>(*root)->ID)
  AVL_tree_insertion(&(*root)->right,ID);
if(check_unbalance(*root)){
   if((*root)->right!=NULL&&ID>(*root)->right->ID)
   RR_rotation(root);
   else
   RL_rotation(root);
  }
  
}
void AVL_tree_deletion(node **root){
  if(*root==NULL){
    return;
  }

    if(balance_factor(*root)==2){
      if(balance_factor((*root)->left)!=-1){
        LL_rotation(root);
      }
      else{
        LR_rotation(root);
      }
    }
    else if(balance_factor(*root)==-2){
       if(balance_factor((*root)->right)!=1){
        RR_rotation(root);
      }
      else{
        RL_rotation(root);
      }
    }
  
}
void delete_node2(node **root,int x);

int find_min(node* root){
    if(root->left==NULL){
        return root->ID;
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
    (*root)->ID=y;
    delete_node2(root,y);
}
void delete_node2(node **root,int ID){
    if(*root==NULL){
        cout<<"ID not found";
        return;
    }
    else if(ID<(*root)->ID){
        delete_node2(&(*root)->left,ID);
    }
    else if(ID>(*root)->ID){
        delete_node2(&((*root)->right),ID);
    }
    else if(ID==(*root)->ID){
        if((*root)->left==NULL&&(*root)->right==NULL){
            case_1(root);
        }
        else if(((*root)->left!=NULL&&(*root)->right==NULL)||((*root)->left==NULL&&(*root)->right!=NULL)){
            case_2(root);
        }
        else if((*root)->left!=NULL&&(*root)->right!=NULL){
            case_3(root);
        }
    }
}
int main(){
    node *root;
    root=NULL;
    int input,n;
    cout<<"AVL Tree Based Employee Perfomane Management System Menu\n1.Employee Join\n2.Employee Exit\n3.Search Employee\n4.Update Rating\n5.Display Employees\n6.Exit\nEnter your choice: ";
    cin>>input;
    int x,y,z,rating;
    string name;

while(input!=6){
    switch(input){
        case 1:
        cout<<"enter the ID Name Rating(0-10): ";
        cin>>n>>name>>rating;
        insert_node(&root,n,name,rating);
        AVL_tree_insertion(&root,n);
        cout<<"Employee added successfully";
            break;
        case 2:
        
        cout<<"Enter employee leaving company: ";
        cin>>x;
       delete_node2(&root,x);
       AVL_tree_deletion(&root);
       cout<<"Employee record removed";
            break;
        case 3:
        cout<<"Employee ID to search: ";
        cin>>y;
        search_ID(root,y);
        break;
        case 4:
        cout<<"Employee ID and new rating: ";
        cin>>y>>z;
        update_rating(&root,y,z);
        break;
        case 5:
        display_tree_inorder(root);
        break;
}
cout<<"\nAVL Tree Based Employee Perfomane Management System Menu\n1.Employee Join\n2.Employee Exit\n3.Search Employee\n4.Update Rating\n5.Display Employees\n6.Exit\nEnter your choice: ";
               cin>>input;
}
delete_tree(&root);
}
