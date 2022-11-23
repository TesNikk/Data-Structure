#include<iostream>
using namespace std;
class Node {
private:
	int data;
	Node* next;
public:
	//constructor
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
	//Destructor
	~Node() {
		int value = data;
		if (next != NULL) {
			delete next;
			next = NULL;
		}
		cout << "Dequeued value = " << value << endl;
	}
	//By this i can access Node members fron queue
	friend class Queue;
};
class Queue{
private:
	Node* front;
	Node* rear;
public:
	//constructor
	Queue() {
		front = NULL;
		rear = NULL;
	}
	//Insert
	void enqueue();
	//Delete
	void dequeue();
	//display
	void display();
};
void Queue::enqueue() {
	int x;
	cout << "Enter Value " << endl;
	cin >> x;
	Node* temp = new Node(x);
	if (temp == NULL) {
		cout << "Queue is full" << endl;
	}
	else if (front == NULL) {
		front = temp;
		rear = temp;
	}
	else {
		rear->next = temp;
		rear = temp;
	}
}
void Queue::dequeue() {
	if (front == NULL) {
		cout << "Queue is empty" << endl;
	}
	else {
		Node* temp = front;
		front = front->next;
		temp->next = NULL;
		delete temp;
	}
}
void Queue:: display() {
	Node* temp = front;
	if (front == NULL) {
		cout << "Queue Is Empty" << endl;
		return;
	}
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
void menu() {
	cout << "*****MENU*****" << endl;
	cout << "Enter Your Option " << endl;
	cout << "1.Enqueue\n2.Dequeue\n3.Display\n4.Exit" << endl;
	cout << endl;
}
int main() {
	Queue q;
	int opt = 1;
	while (opt != 4) {
		menu();
		cin >> opt;
		switch (opt) {
		case 1:q.enqueue();
			break;
		case 2:q.dequeue();
			q.display();
			break;
		case 3:q.display();
			break;
		case 4:
			break;
		default:
			cout << "Invalid Option" << endl;
			break;
		}	
	}
	return 0;
}