#include<iostream>
using namespace std;
class linkedListNode {
public:
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
        if (this->Next != NULL) {
            delete Next;
            this->Next = NULL;
        }
        cout << "Memory is free for node with data" << value << endl;
    }
};
void insertAtHead(linkedListNode* &head, int n) {
    linkedListNode* temp = new linkedListNode(n);
    temp->Next = head;
    head = temp;
}
// linkedListNode* reverseList(linkedListNode* &head) {
//     if (head == NULL || head->Next == NULL) {
//         return head;
//     }
//     linkedListNode* prev = NULL;
//     linkedListNode* curr = head;
//     linkedListNode* forward = NULL;
//     while (curr != NULL) {
//         forward = curr->Next;
//         curr->Next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     return prev;
// }
void reverse(linkedListNode* &head, linkedListNode *curr, linkedListNode *prev) {
    if(curr == NULL) {
        head = prev;
        return ;
    }
    linkedListNode *forward = curr->Next;
    reverse(head, forward, curr);
    curr -> Next = prev;
}
linkedListNode* reverselist(linkedListNode* head) {
    linkedListNode *curr = head;
    linkedListNode *prev = NULL;
    reverse(head, curr, prev);
    return head;
}
void print(linkedListNode* &head) {
    linkedListNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->Next;
    }
    cout << endl;
}
int main() {
    linkedListNode* node1 = new linkedListNode(10);
    linkedListNode* head = node1;
    print(head);
    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 14);
    print(head);
    head = reverselist(head);
    print(head);

    // Delete dynamically allocated memory
    while (head != NULL) {
        linkedListNode* temp = head;
        head = head->Next;
        delete temp;
    }
    return 0;
}
