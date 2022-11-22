#include<iostream>
using namespace std;
class stack {
private:
	int* arr;
	int size;
	int top;
public:
	stack(int size) {
		this->size = size;
		arr = new int[size];
		top = -1;
	}
	//push
	void push(int element);
	//peek
	int peek();
	//delete
	void pop();
	//IsEmpty
	bool empty();
};
void stack::push(int element) {
	if (top < size - 1) {
		top++;
		arr[top] = element;
	}
	else {
		cout << "Stack is overflowed" << endl;
	}
}
int stack::peek() {
	if (top >= 0) {
		return arr[top];
	}
	else {
		cout << "Stack is empty" << endl;
	}
}
void stack::pop() {
	if (top >= 0) {
		top--;
	}
	else {
		cout << "Stack is Underflowed" << endl;
	}
}
bool stack::empty() {
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	stack s(5);
	s.push(1);
	s.push(2);

	cout << s.peek() << endl;
	s.pop();

	cout << s.peek() << endl;
	s.pop();

	if (s.empty()) {
		cout << "stack is empty" << endl;
	}
	else {
		cout << "Not empty" << endl;
	}
}