#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node(int data) {
		this->data=data;
		next = NULL;
		prev = NULL;
	}
	~Node() {
		int value = data;
		if (next != NULL) {
			delete next;
			next = NULL;
		}
		cout << "Memory freed for " << value << endl;
	}
};
class Linkedlist {
private:
	Node* head;
	Node* tail;
public:
	//constructor
	Linkedlist() {
		head = NULL;
		tail = NULL;
	}

	//create
	void create();
	//insert
	void insert();
	//Traverse
	void display();
	//deleteNode
	void deleteNode();
};
void Linkedlist::create() {
	int n;
	cout << "How many node you want: " << endl;
	cin >> n;
	cout << "Input values " << endl;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (tail == NULL) {
			Node* temp = new Node(x);
			head = temp;
			tail = temp;
			temp->next = temp;
			temp->prev = temp;
		}
		else {
			Node* nodetoInsert = new Node(x);
			nodetoInsert->next = tail->next;
			nodetoInsert->prev = tail;
			tail->next->prev = nodetoInsert;
			tail->next = nodetoInsert;
			tail = nodetoInsert;
		}
	}
}

void Linkedlist::insert() {
	cout << "After what element " << endl;
	int element;
	cin >> element;
	int x;
	cout << "Input Value " << endl;
	cin >> x;
	if (tail == NULL) {
		Node* temp = new Node(x);
		head = temp;
		tail = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else {
		Node* curr = head;
		Node* nodetoInsert = new Node(x);
		while (curr->data != element) {
			curr = curr->next;
		}
		nodetoInsert->next = curr->next;
		nodetoInsert->prev = curr;
		curr->next->prev = nodetoInsert;
		curr->next = nodetoInsert;
	}
}
void Linkedlist::display() {
		Node* temp = head;
		if (head == NULL) {
			cout << "Linked List is empty" << endl;
		}
		else {
			do {
				cout << temp->data << " ";
				temp = temp->next;
			} while (temp != head);
		}
}
void Linkedlist::deleteNode() {
	int element;
	cout << "Which element you wanna delete " << endl;
	cin >> element;
	if (head == NULL) {
		cout << "Linked List is empty" << endl;
	}
	else {
		Node* curr = tail;
		Node* prev = curr->next;
		while (curr->data != element) {
			prev = curr;
			curr = curr->next;
		}
		if (curr == prev) {
			head = NULL;
		}
		else if (head == curr) {
			head = prev;
		}
		prev->next = curr->next;
		curr->next->prev = prev;
		curr->next = NULL;
		curr->prev = NULL;
		delete curr;
	}
}
void menu() {
	cout << "\n*****MENU*****" << endl;
	cout << " 1.Create\n 2.Insert\n 3.Delete\n 4.exit\n" << endl;
	cout << "Enter Your Option" << endl;
}
int main() {
	int opt = 1;
	Linkedlist l;
	while (opt != 4) {
		menu();
		cin >> opt;
		switch (opt) {
		case 1:l.create();
			l.display();
			break;
		case 2:l.insert();
			l.display();
			break;
		case 3:l.deleteNode();
			l.display();
			break;
		case 4:
			break;
		default:
			cout << "Invalid Option " << endl;
		}
	}
	return 0;
}
