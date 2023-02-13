#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* prev;
	Node* next;
	Node(int data) {
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
};
//Traversing Linked List
void print(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
//Get length of Linked List
int getlength(Node* head) {
	Node* temp = head;
	int cnt = 0;
	while (temp != NULL) {
		temp = temp->next;
		cnt++;
	}
	return cnt;
}
int main() {
	Node* node1 = new Node(10);
	Node* head = node1;
	print(head);
	cout << "Length of the linked list = " << getlength(head);
	return 0;
}