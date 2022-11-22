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

void insertAtHead(Node*& head, int data) { 
	//create new node
	Node* temp = new Node(data);
	temp->next = head;
	head = temp;
}

void insertAtTail(Node* &tail,int data) {
	//create new node
	Node* temp = new Node(data);
	tail->next = temp;
	tail = temp;
}

void insertAtPosition(Node * &tail,Node * &head,int position,int d) {
	//insert at start
	if (position == 1) {
		insertAtHead(head, d);
		return;
	}

	/*but amra len jani na janle tail update kora jeto
	if (len == position - 1) {
		insertAtTail(tail, d);
	}*/

	Node* temp = head;
	int cnt = 1;

	while (cnt < position - 1) {
		temp = temp->next;
		cnt++;
	}

	//Insert At last
	if (temp->next == NULL) {
		insertAtTail(tail, d);
		return;
	}

	//creating a new node for d
	Node* NodeToInsert = new Node(d);

	NodeToInsert->next = temp->next;
	temp->next = NodeToInsert;
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
	Node* tail = node1;
	print(head);

	insertAtTail(tail, 12);
	print(head);

	insertAtTail(tail, 15);
	print(head);

	insertAtPosition(tail,head, 4, 22);
	print(head);

	cout << "Head = " << head->data << endl;
	cout << "Tail = " << tail->data << endl;

	return 0;
}