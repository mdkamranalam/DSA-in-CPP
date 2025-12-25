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

void freeList(Node *&head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
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
        return newNode;

    Node *curr = head;
    while (curr->next)
        curr = curr->next;

    curr->next = newNode;
    newNode->prev = curr;

    return head;
}

Node *insertAtPosition(Node *head, int pos, int value)
{
    if (pos <= 0)
        return head;

    if (pos == 1)
        return insertAtBeginning(head, value);

    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr; i++)
        curr = curr->next;

    if (!curr)
        return head;

    Node *newNode = new Node(value);
    newNode->next = curr->next;
    newNode->prev = curr;

    if (curr->next)
        curr->next->prev = newNode;

    curr->next = newNode;

    return head;
}

/* ---------- Deletion Operations ---------- */
Node *deleteAtBeginning(Node *head)
{
    if (!head)
        return nullptr;

    Node *temp = head;
    head = head->next;

    if (head)
        head->prev = nullptr;

    delete temp;
    return head;
}

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
    while (curr->next)
    {
        curr = curr->next;
    }

    curr->prev->next = nullptr;
    delete curr;

    return head;
}

Node *deleteAtPosition(Node *head, int pos)
{
    if (!head || pos <= 1)
        return head;

    if (pos == 1)
        return deleteAtBeginning(head);

    Node *curr = head;
    for (int i = 1; i < pos && curr; i++)
        curr = curr->next;

    if (!curr)
        return head;

    if (curr->prev)
        curr->prev->next = curr->next;

    if (curr->next)
        curr->next->prev = curr->prev;

    delete curr;
    return head;
}

/* ---------- Main Function ---------- */
int main()
{
    cout << "---------- DOUBLY LINKEDLIST ----------" << endl;

    Node *head = nullptr;

    head = insertAtBeginning(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);

    head = insertAtBeginning(head, 1);
    head = insertAtEnd(head, 10);
    head = insertAtPosition(head, 3, 50);

    printList(head);

    head = deleteAtPosition(head, 3);
    printList(head);

    head = deleteAtBeginning(head);
    printList(head);

    head = deleteAtEnd(head);
    printList(head);

    freeList(head);

    cout << "---------------------------------------" << endl;

    return 0;
}