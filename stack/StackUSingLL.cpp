#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		next = NULL;
	}

};
class Stack {
private:
	Node* top;
public:
	Stack() {
		top = NULL;
	}
	//push
	void push(int x);
	//pop
	int pop();
	//display
	void display();
	//empty
	bool isEmpty();
	//Full
	bool isFull();
};
void Stack::push(int x) {
	Node* temp = new Node(x);
	if (temp != NULL) {
		temp->next = top;
		top = temp;
	}
	else {
		cout << "stack is overflowed" << endl;
	}

}
int Stack::pop() {
	int x = -1;
	if (top != NULL) {
		Node* temp = top;
		x = temp->data;
		top = temp->next;
		delete temp;
		return x;
	}
	else {
		cout << "Stack is empty" << endl;
	}
}
void Stack::display() {
	Node* temp = top;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
bool Stack::isEmpty() {
	if (top == NULL) {
		return true;
	}
	else {
		return false;
	}
}
bool Stack::isFull() {
	Node* temp = new Node(1);
	if (temp == NULL) {
		return true;
	}
	else {
		delete temp;
		return false;
	}
}
int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.display();
	cout<<s.pop()<<endl;
	s.display();
	cout << s.pop() << endl;

	cout << s.pop() << endl;

	if (s.isEmpty()) {
		cout << "Stack is Empty" << endl;
	}
	else {
		cout << "stack is not empty " << endl;
	}
	if (s.isFull()) {
		cout << "Stack is FULL!" << endl;
	}
	else {
		cout << "Stack is not FULLED" << endl;
	}

	return 0;

}