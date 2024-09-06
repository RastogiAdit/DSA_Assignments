#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int data)
{
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp; 
}

void insertAtTail(Node* &head, int data)
{
    Node* temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    } 
    Node* toAdd = new Node(data);
    temp -> next = toAdd;
}

void insertAtMid(Node* &head, int data, int pos)
{
    if(pos == 1)
    {
        insertAtHead(head,data);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count != pos-1)
    {
        temp = temp -> next;
        count++;
    }
    Node* toAdd = new Node(data);
    toAdd -> next = temp -> next;
    temp -> next = toAdd;
}


void printLL(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void deleteNode(Node * &head, int pos)
{
    if(pos == 1)
    {
        head = head -> next;
        return;
    }
    int count = 1;
    Node* temp = head;
    while(count != pos-1)
    {
        temp = temp -> next;
        count++;
    }
    temp -> next = (temp -> next) -> next;
}

int main()
{
    
    Node* node1 = new Node(10);
    Node* head = node1;
    // printLL(head);
    insertAtHead(head, 20);
    // printLL(head);
    insertAtTail(head, 30);
    // printLL(head);
    insertAtTail(head, 40);
    printLL(head);
    // 20 10 30 40

    insertAtMid(head, 5, 3);
    printLL(head);
    deleteNode(head, 3);
    printLL(head);

    return 0;
}

