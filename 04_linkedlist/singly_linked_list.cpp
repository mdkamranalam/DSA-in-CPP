#include <iostream>
using namespace std;

class Node
{

public:
    int data;

    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to traverse and print the linked list (iterative approach)
// void traverseList(Node *head)
// {
//     while (head != nullptr)
//     {
//         cout << head->data;
//         if (head->next != nullptr)
//         {
//             cout << " -> ";
//         }
//         head = head->next;
//     }
//     cout << endl;
// }

// Function to traverse and print the linked list (recursive approach)
void traverseList(Node *head)
{
    if (head == nullptr)
    {
        cout << endl;
        return;
    }

    cout << head->data;

    if (head->next != nullptr)
    {
        cout << " -> ";
    }

    traverseList(head->next);
}

int main()
{
    cout << "---------- SINGLE LINKEDLIST ----------" << endl;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    traverseList(head);
    cout << "---------------------------------------" << endl;

    return 0;
}