#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	//constructor
	Node(int data) {
		this->data = data;
	}
};
void insertAtHead(Node* &head,int data) {//with reference copy bcz i wanna change in original linked list i.e head will be updated
	//create new node
	Node* temp = new Node(data);
	temp->next = head;
	head = temp;
}
void print(Node * &head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data <<" ";
		temp = temp->next;
	}
	cout << endl;
}
int main() {
	Node* node1 = new Node(10);
	//Head pointed to Node
	Node* head = node1;
	print(head);

	insertAtHead(head, 12);
	print(head);

	insertAtHead(head, 15);
	print(head);
	return 0;
}