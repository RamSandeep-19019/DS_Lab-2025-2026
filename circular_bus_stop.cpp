#include <iostream>
using namespace std;
typedef struct node Node;
struct node
{
    int x;
    Node *next;
};

int main()
{
    Node *temp, *temp1, *temp2, *new_node, *head;
    head = new Node;
    head->next = NULL;
    int n, count;
    count = 0;
    cout << "Enter Maximum Passengers at Bus Stop: ";
    cin >> n;
    cout << "1.Insert Passenger\n2.Remove Passenger\n3.Display Passengers\n4.Exit\nEnter choice: ";
    int input;
    cin >> input;
    while (input != 4)
    {
        switch (input)
        {
        case 1:

            if (count < n)
            {
                new_node = new Node;
                cout << "Eneter Passenger Number: ";
                cin >> new_node->x;
                new_node->next = NULL;
                count++;
                temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }

                
                    temp->next = new_node;
                
                cout << "Passenger " << new_node->x << " entered the bus stop.\n";
            }
            else
            {
                cout << "Bus stop is full\n";
            }
            break;

        case 2:
            //--------Deletion-------
            cout << head->next->x << " is boarded the bus\n";
            temp1=head->next;
            head->next=head->next->next;
            delete (temp1);
            count--;
            break;
        case 3:
            //-----Display-----
            temp1 = head->next;
            cout << "Passengers waiting:\n";

            while (temp1 != NULL)
            {
                cout << temp1->x << " ";
                temp1 = temp1->next;
            }

            cout << "\n";
            break;
        }
        cout << "1.Insert Passenger\n2.Remove Passenger\n3.Display Passengers\n4.Exit\nEnter choice: ";

        cin >> input;
    }
    temp1 = head->next;

    while (temp1 != NULL)
    {
        temp2 = temp1;
        delete (temp2);
        temp1 = temp1->next;
    }
}