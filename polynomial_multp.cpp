#include <iostream>
#include <vector>
using namespace std;
typedef struct node Node;
struct node
{
    int x, n;
    Node *next;
};
void create_poly(Node *head, int size)
{
    Node *new_node, *temp;
    if (size == 0)
    {
        return;
    }
    cout << "Enter terms (coeff exponent):\n";
    while (size)
    {
        new_node = new Node;
        new_node->next = NULL;
        cin >> new_node->n >> new_node->x;
        if (head->next == NULL)
        {
            head->next = new_node;
            temp = head;
        }
        else
        {
            temp->next->next = new_node;
            temp = temp->next;
        }
        size--;
    }
}
void print_poly(Node *head)
{
    Node *temp;
    temp = head->next;
    while (temp != NULL)
    {
        cout << temp->n << "x^" << temp->x;
        if (temp->next != NULL)
        {
            cout << " + ";
        }
        temp = temp->next;
    }
    
}
void free_poly(Node *head)
{
    Node *temp1, *temp2;
    temp1 = head;

    while (temp1 != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        delete (temp2);
    }
}
void swap_nodes(Node*head1,Node*head2){
    int x,y;
    x=head1->n;
    y=head1->x;
    head1->n=head2->n;
    head2->n=x;
    head1->x=head2->x;
    head2->x=y;
}
void sort_poly(Node*head3,int size){
        Node*temp5;
        int i=size-1;
    while(i>0){
        temp5=head3->next;
        while(temp5!=NULL){
            if(temp5->next!=NULL&&temp5->x<temp5->next->x){
                
                swap_nodes(temp5,temp5->next);
                
            }
            temp5=temp5->next;
        }
        i--;
    }
}
int main()
{
    node *head1, *head2, *temp1, *temp2, *temp3;
    head1 = new Node;
    head2 = new Node;
    head1->next = NULL;
    head2->next = NULL;
    int size1, size2,count=0;
    cout << "polynomial P:\nEnter the number of terms: ";
    cin >> size1;
    create_poly(head1, size1);
    sort_poly(head1,size1);
    cout << "polynomial Q:\nEnter the number of terms: ";
    cin >> size2;
    create_poly(head2, size2);
    sort_poly(head2,size2);
    if (size1 == 0 || size2 == 0)
    {
        cout << "\nOperation is not possinble ";
        return 0;
    }
cout<<"\nP(x) = ";
    print_poly(head1);
    cout<<"\nQ(x) = ";
    print_poly(head2);

    vector<pair<int, int>> v1;
    int n,x,y;
    temp1 = head1->next;
    
    while (temp1 != NULL)
    {   temp2 = head2->next;
        while (temp2 != NULL)
        {x=(temp1->n * temp2->n);
            y=(temp1->x + temp2->x);
            v1.push_back({x,y});
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    int r = 1;
    Node *head3, *new_node;
    head3 = new Node;
    head3->next = NULL;
    Node *temp4;
    
    for (int i = 0; i < (size1 * size2); i++)
    {   temp4 = head3->next;
        r = 1;
        while (temp4 != NULL)
        {
            if (v1[i].second == temp4->x)
            {
                r = 0;
            }
            temp4 = temp4->next;
        }
        if(r==0){
        continue;}

            new_node = new Node;
            new_node->next = NULL;
            count++;
        
        new_node->x = v1[i].second;
        new_node->n = v1[i].first;
        for (int j = 0; j < (size1 * size2); j++)
        {
            if (i != j && v1[i].second == v1[j].second)
            {
                new_node->n = new_node->n + v1[j].first;
            }
        }
        if (head3->next == NULL)
        {
            head3->next = new_node;
            temp3 = head3;
        }
        else
        {
            temp3->next->next = new_node;
            temp3 = temp3->next;
        }
        
    }sort_poly(head3,count);
    cout<<"\n\nResultant Polynomial after multiplication:\n";
    print_poly(head3);
    free_poly(head1);
    free_poly(head2);
    free_poly(head3);
}
