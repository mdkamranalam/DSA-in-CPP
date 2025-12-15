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
// void traverseList(Node *head)
// {
//     if (head == nullptr)
//     {
//         cout << endl;
//         return;
//     }

//     cout << head->data;

//     if (head->next != nullptr)
//     {
//         cout << " -> ";
//     }

//     traverseList(head->next);
// }

// Function to insert a new node at beginning of the list
Node *insertAtBeginning(Node *head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    return newNode;
}

void printList(Node *head)
{
    Node *curr = head;

    while (curr != nullptr)
    {
        cout << curr->data;
        if (curr->next != nullptr)
        {
            cout << " -> ";
        }
        curr = curr->next;
    }
    cout << endl;
}

// Function to insert a new node at the end of the list
Node *insertAtEnd(Node *head, int value)
{
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
        return newNode;
    }

    Node *last = head;

    while (last->next != nullptr)
    {
        last = last->next;
    }

    last->next = newNode;

    return head;
}

// Function to insert a new node at the given position in the list
Node *insertAtPosition(Node *head, int pos, int value)
{
    if (pos < 1)
    {
        return head;
    }

    if (pos == 1)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        return newNode;
    }

    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr != nullptr; i++)
    {
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        return head;
    }

    Node *newNode = new Node(value);

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

int main()
{
    cout << "---------- SINGLE LINKEDLIST ----------" << endl;
    Node *head = new Node(10);
    // head->next = new Node(20);
    // head->next->next = new Node(30);
    // head->next->next->next = new Node(40);

    // Insert at beginning
    int value = 1;
    head = insertAtBeginning(head, value);

    // Insert at the end
    value = 100;
    head = insertAtEnd(head, value);

    // Insert at the given position
    int pos = 3;
    value = 20;
    head = insertAtPosition(head, pos, value);

    // traverseList(head);
    printList(head);
    cout << "---------------------------------------" << endl;

    return 0;
}