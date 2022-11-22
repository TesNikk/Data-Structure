#include<iostream>
#include<math.h>
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
class Stack {
private:
	Node* top;
public:
	Stack() {
		top = NULL;
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
	//IsBalanced
	bool isBalanced(char* exp);
};
void Stack::push(char x) {
	Node* temp = new Node(x);
	if (temp != NULL) {
		temp->next = top;
		top = temp;
	}
	else {
		cout << "stack is overflowed" << endl;
	}

}
char Stack::pop() {
	char x;
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
bool Stack::isBalanced(char* exp) {
	for (int i = 0; exp[i] != '\0'; i++) {
		if (exp[i] == '('||exp[i]=='{'||exp[i]=='[') {
			push(exp[i]);
		}
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
			if (isEmpty()) {
				return false;
			}
			else {
				char x;
				x = pop();
				if ((abs(x - exp[i])) != 1 && (abs(x - exp[i])) != 2) {
					return false;
				}
			}
		}
	}
	if (isEmpty()) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	char exp[20] = "{([a+b]*[c-d)]/e}";
	Stack s;
	cout << s.isBalanced(exp);

	return 0;

}