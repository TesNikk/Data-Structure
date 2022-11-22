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
Node* top;
class Stack {
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
	//peek
	char peek();
};
char Stack::peek() {
	return top->data;
}
Stack s;



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
	char x = -1;
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
int isOperand(char x) {
	if (x == '+' || x == '-' || x == '*' || x == '/') {
		return 0;
	}
	else {
		return 1;
	}
}
int pre(char x) {
	if (x == '+' || x == '-') {
		return 1;
	}
	else if (x == '*' || x == '/') {
		return 2;
	}
	else {
		return 0;
	}
}
char* InfixtoPostfix(char* infix) {
	int len = strlen(infix);
	char* postfix = new char[len + 2];
	int i = 0;
	int j = 0;
	while (infix[i] != '\0') {
		if (isOperand(infix[i])) {
			postfix[j++] = infix[i++];
		}
		else {
			if (!s.isEmpty() && pre(infix[i]) <= pre(s.peek())) {
				postfix[j++] = s.pop();

			}
			else {
				s.push(infix[i++]);
			}
		}
	}
	while (top != NULL) {
		postfix[j++] = s.pop();
		postfix[j] = '\0';
	}
	return postfix;
}

int main() {
	char infix[] = "a+b*c-d/e";
	char* postfix = InfixtoPostfix(infix);
	cout << postfix << endl;
	return 0;

}

