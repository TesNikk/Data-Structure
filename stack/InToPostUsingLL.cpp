#include<iostream>
#include<cstring>
using namespace std;
class Node {
public:
	char data;
	Node* next;
	Node(char data) {
		this->data = data;
		next = NULL;
	}

};
Node* topp;
class Stack {
public:
	Stack() {
		topp = NULL;
	}
	//push
	void push(char x);
	//pop
	char pop();
	//display
	void display();
	//empty
	bool isEmpty();
	//Full
	bool isFull();
	//peek
	char top();
};
char Stack::top() {
	return topp->data;
}
Stack s;



void Stack::push(char x) {
	Node* temp = new Node(x);
	if (temp != NULL) {
		temp->next = topp;
		topp = temp;
	}
	else {
		cout << "stack is overflowed" << endl;
	}

}
char Stack::pop() {
	char x = -1;
	if (topp != NULL) {
		Node* temp = topp;
		x = temp->data;
		topp = temp->next;
		delete temp;
		return x;
	}
	else {
		cout << "Stack is empty" << endl;
	}
}
void Stack::display() {
	Node* temp = topp;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
bool Stack::isEmpty() {
	if (topp == NULL) {
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
int isperand(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
		return 1;
	}
	else {
		return 0;
	}
}
int precedence(char c) {
	if (c == '+' || c == '-') {
		return 1;
	}
	else if (c == '*' || c == '/') {
		return 2;
	}
	else if (c == '^') {
		return 3;
	}
	else {
		return 0;
	}
}
void InfixtoPostfix(string infix) {
	string postfix;
	for (int i = 0; infix[i] != '\0'; i++) {
		char c = infix[i];
		if (isperand(c)) {
			postfix += c;
		}
		else if (c == '(') {
			s.push('(');
		}
		else if (c == ')') {
			while (s.top() != '(') {
				postfix += s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			while (!s.isEmpty() && precedence(c) <= precedence(s.top())) {
				postfix += s.top();
				s.pop();
			}
			s.push(c);
		}
	}
	while (!s.isEmpty()) {
		postfix += s.top();
		s.pop();
	}
	cout << postfix << endl;
}

int main() {
	string infix = "a+b*(c^d-e)^(f+g*h)-i" ;
	InfixtoPostfix(infix);
	return 0;
}