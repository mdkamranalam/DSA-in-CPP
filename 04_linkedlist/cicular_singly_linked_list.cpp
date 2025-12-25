#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    explicit Node(int data) : data(data), next(this) {}
};

/* ---------- Utility Functions ---------- */
void printList(const Node *head)
{
    if (!head)
        return;

    const Node *curr = head;
    do
    {
        cout << curr->data;
        curr = curr->next;
        if (curr != head)
            cout << " -> ";
    } while (curr != head);

    cout << " -> (HEAD)" << endl;
}

int length(const Node *head)
{
    if (!head)
        return 0;

    int len = 0;
    const Node *curr = head;
    do
    {
        len++;
        curr = curr->next;
    } while (curr != head);

    return len;
}

/* ---------- Insertion Operations ---------- */
Node *insertAtBeginning(Node *head, int value)
{
    Node *newNode = new Node(value);

    if (!head)
        return newNode;

    Node *tail = head;
    while (tail->next != head)
        tail = tail->next;

    newNode->next = head;
    tail->next = newNode;

    return newNode;
}

Node *insertAtEnd(Node *head, int value)
{
    Node *newNode = new Node(value);

    if (!head)
        return newNode;

    Node *tail = head;
    while (tail->next != head)
        tail = tail->next;

    tail->next = newNode;
    newNode->next = head;

    return head;
}

Node *insertAtPosition(Node *head, int pos, int value)
{
    if (pos <= 0)
        return head;

    if (pos == 1)
        return insertAtBeginning(head, value);

    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr->next != head; i++)
        curr = curr->next;

    Node *newNode = new Node(value);
    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

/* ---------- Deletion Operations ---------- */
Node *deleteAtBeginning(Node *head)
{
    if (!head)
        return nullptr;

    if (head->next == head)
    {
        delete head;
        return nullptr;
    }

    Node *tail = head;
    while (tail->next != head)
        tail = tail->next;

    Node *temp = head;
    head = head->next;
    tail->next = head;

    delete temp;
    return head;
}

Node *deleteAtEnd(Node *head)
{
    if (!head)
        return nullptr;

    if (head->next == head)
    {
        delete head;
        return nullptr;
    }

    Node *curr = head;
    while (curr->next->next != head)
        curr = curr->next;

    delete curr->next;
    curr->next = head;

    return head;
}

Node *deleteAtPosition(Node *head, int pos)
{
    if (!head || pos <= 0)
        return head;

    if (pos == 1)
        return deleteAtBeginning(head);

    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr->next != head; i++)
        curr = curr->next;

    if (curr->next == head)
        return head;

    Node *temp = curr->next;
    curr->next = temp->next;

    delete temp;
    return head;
}

/* ---------- Search Operation ---------- */

bool searchKey(Node *head, int key)
{
    if (!head)
        return false;

    Node *curr = head;
    do
    {
        if (curr->data == key)
            return true;
        curr = curr->next;
    } while (curr != head);

    return false;
}

/* ---------- Reverse Operation ---------- */

Node *reverseList(Node *head)
{
    if (!head || head->next == head)
        return head;

    Node *prev = head;
    Node *curr = head->next;
    Node *next = nullptr;

    while (curr != head)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head->next = prev;
    head = prev;

    return head;
}

/* ---------- Cleanup ---------- */

void freeList(Node *&head)
{
    if (!head)
        return;

    Node *curr = head->next;
    while (curr != head)
    {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }

    delete head;
    head = nullptr;
}

/* ---------- Main ---------- */
int main()
{
    cout << "---------- CIRCULAR SINGLY LINKED LIST ----------" << endl;

    Node *head = nullptr;

    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 30);
    head = insertAtPosition(head, 2, 20);

    printList(head);

    int key = 10;
    cout << (searchKey(head, key) ? "True" : "False") << endl;

    head = reverseList(head);
    printList(head);

    freeList(head);

    cout << "-----------------------------------------------" << endl;
    return 0;
}