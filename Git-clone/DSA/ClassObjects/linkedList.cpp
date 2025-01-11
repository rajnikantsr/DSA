#include<iostream>
using namespace std;
class linkedListNode {
    public :
    int data;
    linkedListNode* Next;
    linkedListNode(int data) {
        //constructor
        this->data = data;
        this->Next = NULL;
    }
    //Destructor
    ~linkedListNode() {
        int value = this->data;
        //Memory free
        if(this->Next!=NULL) {
            delete Next;
            this->Next = NULL;
        }
        cout << "Memory is free for node with data" << value << endl;
    }
};
void insertAtHead(linkedListNode* &Head, int n) {
    //New node create
    linkedListNode* temp = new linkedListNode(n);
    temp -> Next = Head;
    Head = temp;
}
void insertAtTail(linkedListNode* &Tail, int n) {
    linkedListNode* temp = new linkedListNode(n);
    Tail->Next = temp;
    Tail = temp;
}
void insertInMiddle(linkedListNode* &Tail, linkedListNode* &Head, int position, int n) {
    linkedListNode* temp = Head;
    if(position == 1) {
        insertAtHead(Head, n); 
        return;
    }
    int cnt = 1;
    while(cnt < position-1) {
        temp = temp->Next;
        cnt++;
    }
    //Inserting at last position
    if(temp->Next == NULL) {
        insertAtTail(Tail, n);
        return; 
    }
    //Creation a node for n
    linkedListNode* nodeToInsert = new linkedListNode(n);
    nodeToInsert->Next = temp->Next;
    temp->Next = nodeToInsert;
}
void deleteNode(int position, linkedListNode* &head) {
    //Deleting first and start node
    if(position == 1) {
        linkedListNode* temp = head;
        head = head->Next;
        delete temp;
    } else {
        //Deleting any middle node or last node
        linkedListNode* curr = head;
        linkedListNode* prev = NULL;
        int cnt = 1;
        while(cnt <= position) {
            prev = curr;
            curr = curr->Next;
            cnt++;
        }
        prev -> Next = curr -> Next;
        curr->Next = NULL;
        delete curr;
    }
}
void print(linkedListNode* &Head) {
    linkedListNode* temp = Head;
    // cout << "Temp is " << Head << endl;
    // cout << "Temp is " << temp << endl;
    // cout << "Temp is " << temp->Next << endl;
    while(temp != NULL) {
        cout << temp->data << " " << endl;
        cout << temp->Next << endl;
        temp = temp->Next;
    }
    cout << endl;
}
int main() {
    linkedListNode* node1 = new linkedListNode(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> Next << endl;
    //Head pointed to new node
    linkedListNode* head = node1;
    linkedListNode* tail = node1;
    print(head);
    // print(tail);
    // insertAtHead(head, 12);
    // print(head);
    // insertAtHead(head, 17);
    // print(head);
    insertAtTail(tail, 14);
    print(head);
    insertAtTail(tail, 118);
    print(head);
    insertInMiddle(tail, head, 4, 19);
    print(head);
    cout << "Head" << head->data << endl;
    cout << "Tail" << tail->data << endl;
    deleteNode(2, head);
    print(head);
    return 0;
}