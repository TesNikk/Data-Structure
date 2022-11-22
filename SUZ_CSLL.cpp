#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	//constructor
	Node(int data) {
		this->data = data;
		next = NULL;
	}

	//destructor
	~Node() {
		int value = this->data;
		if (next != NULL) {
			delete next;
			next = NULL;
		}
		cout << "memory is freed for " << value << endl;
	}
};

class LinkedList {
private:
	Node* head;
	Node* tail;
public:

	//constructor
	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	//creating N numbers of linked list
	void create_node();

	//traversing LinkedList
	void display();

	//Insertion
	void insert();

	//delete Node
	void deleteNode();

	//Update Node
	void updateNode();
};

void LinkedList::create_node() {
	cout << "Enter Numbers of Nodes " << endl;
	int n;
	cin >> n;
	cout << "Enter the value of Nodes" << endl;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		Node *temp = new Node(x);
		if (head == NULL) {
			head = temp;
		}
		if (tail == NULL) {
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}
	tail->next = head;
}

void LinkedList::display() {
	Node* temp = head;
	cout << "Display:" << endl;
	if (head == NULL) {
		cout << "Empty List" << endl;
		return;
	}
	do {
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp!= head);
	cout << endl;
}

void LinkedList::insert() {
	Node* curr = head;
	cout << "After what element you wanna insert your node " << endl;
	int y;
	cin >> y;
	int x;
	cout << "Value of new node " << endl;
	cin >> x;
	Node* nodetoInsert = new Node(x);
	int flag = 1; 
	while (!(curr==head && flag==0)) {
		if (curr->data == y) {
			nodetoInsert->next = curr->next;
			curr->next = nodetoInsert;
			break;
		}
		else {
			curr = curr->next;
			flag = 0;
		}
	}
	if (!flag) {
		cout << "Sorry the element you have input is not found in the list" << endl;
	}
}

void LinkedList::deleteNode() {
	Node* prev = head;
	Node* curr = prev->next;
	int y;
	cout << "Enter the element you wanna delete " << endl;
	cin >> y;
	int flag = 0;
	while (curr !=head) {
		if (curr->data == y) {
			prev->next = curr->next;
			curr->next = NULL;
			flag = 1;
			delete curr;
			break;
			}
		else {
			prev = curr;
			curr = curr->next;
			}
	}
	if (!flag) {
		cout << "Sorry the element you have input is not found in the list" << endl;
	}
}

void LinkedList::updateNode() {
	Node* temp = head;
	int x, y;
	cout << "Enter the Node Value to be updated AND the UPDATED value " << endl;
	cin >> x >> y;
	if (temp == NULL) {
		cout << "Empty List" << endl;
	}
	int flag = 0;
	while (temp != head) {
		if (temp->data == x) {
			temp->data = y;
			flag = 1;
			break;
		}
		else {
			temp = temp->next;
		}
	}
	if (!flag) {
		cout << "Sorry the element you have input is not found in the list" << endl;
	}
}

//MENU
void menu() {

	cout << "\n********* MENU *********" << endl;
	cout << "1.Create \n2.Display \n3.Insert \n4.Update \n5.Delete \n6.Exit " << endl;
	cout << "Enter Your Option" << endl;

}

int main() {
	LinkedList L1;
	int option = 1;
	while (option != 6) {
		menu();
		cin >> option;
		switch (option) {
		case 1:
			L1.create_node();
			L1.display();
			break;
		case 2:
			L1.display();
			break;
		case 3:
			L1.insert();
			L1.display();
			break;
		case 4:
			L1.updateNode();
			L1.display();
			break;
		case 5:
			L1.deleteNode();
			L1.display();
			break;
		case 6:
			break;
		default:
			cout << "Invalid Input" << endl;
			break;
		}
	}
	return 0;
}
