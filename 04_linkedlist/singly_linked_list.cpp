#include <iostream>
#include <stack>
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

// Function to delete a node from the beginning
Node *deleteAtBeginning(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;
    head = head->next;

    delete temp;

    return head;
}

// Function to delete a node from the end
Node *deleteAtEnd(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *secondLast = head;
    while (secondLast->next->next != nullptr)
    {
        secondLast = secondLast->next;
    }

    secondLast->next = nullptr;

    return head;
}

// Delete a node at the given position
Node *deleteAtPosition(Node *head, int pos)
{
    Node *temp = head;

    if (pos == 1)
    {
        head = temp->next;
        delete temp;
        return head;
    }

    Node *prev = nullptr;
    for (int i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;

    return head;
}

// Search an element in the linked list (Iterative approach)
// bool searchKey(Node *head, int key)
// {
//     Node *curr = head;

//     while (curr != NULL)
//     {
//         if (curr->data == key)
//         {
//             return true;
//         }
//         curr = curr->next;
//     }

//     return false;
// }

// Search an element in the linked list (Recursive approach)
bool searchKey(Node *head, int key)
{
    if (head == nullptr)
    {
        return false;
    }

    if (head->data == key)
    {
        return true;
    }

    return searchKey(head->next, key);
}

// Reverse list (Iterative approach)
// Node *reverseList(Node *head)
// {
//     Node *curr = head, *prev = nullptr, *next;

//     while(curr != nullptr)
//     {
//         next = curr->next;
//         curr->next = prev;

//         prev = curr;
//         curr = next;
//     }

//     return prev;
// }

// Reverse list (Recursive approach)
// Node *reverseList(Node *head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }

//     Node *rest = reverseList(head->next);

//     head->next->next = head;
//     head->next = NULL;
//     return rest;
// }

// Reverse list (Stack approach)
Node *reverseList(Node *head)
{
    stack<Node *> s;
    Node *temp = head;

    while (temp->next != NULL)
    {
        s.push(temp);
        temp = temp->next;
    }
    
    head = temp;

    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }

    temp->next = NULL;

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

    // Delete at beginning
    // head = deleteAtBeginning(head);

    // Delete at end
    // head = deleteAtEnd(head);

    // Delete at position
    // pos = 2;
    // head = deleteAtPosition(head, pos);

    // Reverse list
    head = reverseList(head);
    printList(head);

    // Search
    int key = 10;
    if (searchKey(head, key))
        cout << "true";
    else
        cout << "false";
    cout << endl;

    cout << "---------------------------------------" << endl;

    return 0;
}