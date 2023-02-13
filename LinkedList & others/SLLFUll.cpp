#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;			//pointer to other node
	//constructor
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
	~Node() {
		int value = this->data;
		//memory free
		if (this->next != NULL) {
			delete next;
			this->next = NULL;
		}
		cout << "Memory is freed for node with data " << value << endl;
	}
};

void insertAtHead(Node*& head, int data) {
	//create new node 
	Node* temp = new Node(data);
	temp->next = head;
	head = temp;
}

void insertAtTail(Node*& tail, int data) {
	//create new node
	Node* temp = new Node(data);
	tail->next = temp;
	tail = temp;
}

void insertAtPosition(Node*& tail, Node*& head, int position, int d) {
	//insert at start
	if (position == 1) {
		insertAtHead(head, d);
		return;
	}

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
void deleteNode(Node *&tail,Node* &head, int position) {
	//deleting first or start node

	if (position == 1) {
		Node *temp = head;
		head = head->next;
		//memory free start node
		temp->next = NULL;
		delete temp;
	  }
	else {
		//deleteing any middle or last node
		Node* curr = head;
		Node* prev = NULL;
		int cnt = 1;
		while (cnt < position) {
			prev = curr;
			curr = curr->next;
			cnt++;
		}

		prev->next = curr->next;
		if (prev->next == NULL) {//tail updatation for last Node
			tail = prev;
		}
		curr->next = NULL;
		delete curr;
	}
}
void print(Node*& head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
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

	insertAtPosition(tail, head, 4, 22);
	print(head);

	cout << "Head = " << head->data << endl;
	cout << "Tail = " << tail->data << endl;

	deleteNode(tail,head, 4);
	print(head);
	cout << "Head = " << head->data << endl;
	cout << "Tail = " << tail->data << endl;
	return 0;
}