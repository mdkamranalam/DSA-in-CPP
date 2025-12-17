#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    explicit Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

/* ---------- Utilities Function ---------- */
void printList(Node *head)
{

    Node *curr = head;
    while (curr)
    {
        cout << curr->data;
        if (curr->next)
            cout << " <-> ";
        curr = curr->next;
    }
    cout << endl;
}

/* ---------- Traversal Operations ---------- */
// Forward Traversal (Iterative Approach)
// void forwardTraversal(Node *head)
// {
//     Node *curr = head;

//     while (curr)
//     {
//         cout << curr->data;
//         if (curr->next)
//             cout << " -> ";
//         curr = curr->next;
//     }
//     cout << endl;
// }

// Forward Traversal (Recursive Approach)
// void forwardTraversal(Node *head)
// {
//     if (!head) return;

//     cout << head->data;
//     if (head->next)
//         cout << " -> ";

//     forwardTraversal(head->next);
// }

// Backward Traversal (Iterative Approach)
// void backwardTraversal(Node *tail)
// {
//     Node *curr = tail;

//     while (curr)
//     {
//         cout << curr->data;
//         if (curr->prev)
//             cout << " <- ";
//         curr = curr->prev;
//     }
//     cout << endl;
// }

// Backward Traversal (Recursive Approach)
// void backwardTraversal(Node *tail)
// {
//     if (!tail) return;

//     cout << tail->data;
//     if (tail->prev)
//         cout << " <- ";

//     backwardTraversal(tail->prev);
// }

/* ---------- Insertion Operations ---------- */
Node *insertAtBeginning(Node *head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;

    if (head)
        head->prev = newNode;

    return newNode;
}

Node *insertAtEnd(Node *head, int value)
{
    Node *newNode = new Node(value);

    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }

        curr->next = newNode;
        newNode->prev = curr;
    }
    return head;
}

Node *insertAtPosition(Node *head, int pos, int value)
{
    Node *newNode = new Node(value);

    if (pos == 1)
    {
        newNode->next = head;

        if (head)
            head->prev = newNode;
        
        head = newNode;
        return head;
    }

    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr; i++)
    {
        curr = curr->next;
    }

    if (!curr)
    {
        delete newNode;
        return head;
    }

    newNode->prev = curr;
    newNode->next = curr->next;
    curr->next = newNode;

    if (!newNode->next)
        newNode->next->prev = newNode;
    
    return head;
}

/* ---------- Main Function ---------- */
int main()
{
    cout << "---------- DOUBLY LINKEDLIST ----------" << endl;

    Node *head = new Node(2);
    head->next = new Node(3);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;

    // Insert a new node at the front of the list
    int value = 1;
    head = insertAtBeginning(head, value);

    value = 10;
    head = insertAtEnd(head, value);

    int pos = 3;
    value = 50;
    head = insertAtPosition(head, pos, value);

    printList(head);

    cout << "---------------------------------------" << endl;

    return 0;
}