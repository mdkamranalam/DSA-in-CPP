#include <iostream>
// #include <stack>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    explicit Node(int data) : data(data), next(nullptr) {}
};

// ---------- Utility Functions ----------
void printList(const Node *head)
{
    const Node *curr = head;

    while (curr)
    {
        cout << curr->data;
        if (curr->next)
            cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

int length(const Node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

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

// ---------- Insertion Operations ----------
// Function to insert a new node at beginning of the list
Node *insertAtBeginning(Node *head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    return newNode;
}

// Function to insert a new node at the end of the list
Node *insertAtEnd(Node *head, int value)
{
    Node *newNode = new Node(value);

    if (!head)
        return newNode;

    Node *curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

// Function to insert a new node at the given position in the list
Node *insertAtPosition(Node *head, int pos, int value)
{
    if (pos <= 0)
        return head;

    if (pos == 1)
        return insertAtBeginning(head, value);

    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr; i++)
    {
        curr = curr->next;
    }

    if (!curr)
        return head;

    Node *newNode = new Node(value);
    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

// ---------- Deletion Operations ----------
// Function to delete a node from the beginning
Node *deleteAtBeginning(Node *head)
{
    if (!head)
        return nullptr;

    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Function to delete a node from the end
Node *deleteAtEnd(Node *head)
{
    if (!head)
        return nullptr;

    if (!head->next)
    {
        delete head;
        return nullptr;
    }

    Node *curr = head;
    while (curr->next->next)
    {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = nullptr;
    return head;
}

// Delete a node at the given position
Node *deleteAtPosition(Node *head, int pos)
{
    if (!head || pos <= 0)
        return head;

    if (pos == 1)
        return deleteAtBeginning(head);

    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr->next; i++)
    {
        curr = curr->next;
    }

    if (!curr->next)
        return head;

    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;

    return head;
}

// ---------- Search Operations ----------
// Search an element in the linked list (Iterative approach)
bool searchKey(Node *head, int key)
{
    while (head)
    {
        if (head->data == key)
            return true;
        head = head->next;
    }

    return false;
}

// Search an element in the linked list (Recursive approach)
// bool searchKey(Node *head, int key)
// {
//     if (head == nullptr)
//     {
//         return false;
//     }

//     if (head->data == key)
//     {
//         return true;
//     }

//     return searchKey(head->next, key);
// }

// ---------- Reverse Operations ----------
// Reverse list (Iterative approach)
Node *reverseList(Node *head)
{
    Node *curr = head, *prev = nullptr;

    while (curr != nullptr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

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
// Node *reverseList(Node *head)
// {
//     stack<Node *> s;
//     Node *temp = head;

//     while (temp->next != NULL)
//     {
//         s.push(temp);
//         temp = temp->next;
//     }

//     head = temp;

//     while (!s.empty())
//     {
//         temp->next = s.top();
//         s.pop();
//         temp = temp->next;
//     }

//     temp->next = NULL;

//     return head;
// }

// ---------- Cleanup ----------
void freeList(Node *&head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// ---------- Main Function ----------
int main()
{
    cout << "---------- SINGLE LINKEDLIST ----------" << endl;
    Node *head = nullptr;

    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 30);
    head = insertAtPosition(head, 2, 20);

    printList(head);

    int key = 10;
    cout << (searchKey(head, key) ? "True" : "False") << endl;

    freeList(head);

    cout << "---------------------------------------" << endl;

    return 0;
}