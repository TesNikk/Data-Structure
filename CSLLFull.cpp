#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    //constructor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
    //destructor
    ~Node() {
        int val = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << val << endl;
    }
};

void insertNode(Node*& tail, int element, int data) {
    //assuming that element is present in the list

    //empty list
    if (tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        //Non Empty list
        //assuming that element is present in the list

        Node* curr = tail;
        while (curr->data != element) {
            curr = curr->next;
        }
        //element found -> curr is representing element of current node

        Node* temp = new Node(data);
        temp->next = curr->next;
        curr -> next = temp;
    }
}
//Traversing
void print(Node *tail) {
    Node* temp = tail;
    if (tail == NULL) {
        cout << "Linked list is empty" << endl;
    }
    do {
        cout << tail->data<<" ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

//Deletion
void deleteNode(Node* &tail,int value) {
    //empty list
    if (tail == NULL) {
        cout << "Linked list is empty" << endl;
    }
    else {
        //Non empty list
        //assuming value is present in the LL

        Node* prev = tail;
        Node* curr = prev->next;//cause curr prev er next e thake
        while (curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        //1 Node linked list
        if (curr == prev) {
            tail = NULL;
        }                       //>=2 Node linked list
        else if (tail == curr) {//taill = curr holei bujhbo 1st element delete hosse
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main() {
    Node* tail = NULL;

    //insert in empty list
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);
    
    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    return 0;
}