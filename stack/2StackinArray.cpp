#include<iostream>
using namespace std;
class TwoStack {
private:
	int* arr;
	int size;
	int top1;
	int top2;
public:
	TwoStack(int size) {
		this->size = size;
		arr = new int[size];
		top1 = -1;
		top2 = size;
	}
	//push
	void push1(int element);
	void push2(int element);
	//pop
	int pop1();
	int pop2();
	//peek
	int peek1();
	int peek2();
};
void TwoStack::push1(int element) {
	if (top2 - top1 > 1) {
		top1++;
		arr[top1] = element;
	}
}
void TwoStack::push2(int element) {
	if (top2-top1>1) {
		top2--;
		arr[top2] = element;
	}
}

int TwoStack::pop1() {
	if (top1 >= 0) {
		int ans = arr[top1];
		top1--;
		return ans;
	}
	else {
		cout << "Stack is Empty" << endl;
	}
}
int TwoStack::pop2() {
	if (top2 < size) {
		int ans = arr[top2];
		top2++;
		return ans;
	}
}
int TwoStack::peek1() {
	if (top1 >= 0) {
		return arr[top1];
	}
	else {
		cout << "Stack is Empty" << endl;
	}
}
int TwoStack::peek2() {
	if (top2 < size) {
		return arr[top2];
	}
	else {
		cout << "Stack is Overflowed" << endl;
	}
}
int main() {
	TwoStack s(4);
	s.push1(1);
	s.push1(2);
	s.push2(3);
	s.push2(4);
	cout << s.peek1() << endl;
	cout << s.peek2() << endl;
	cout<<s.pop1()<<endl;
	cout << s.pop2() << endl;

	cout << s.peek1() << endl;
	cout << s.peek2() << endl;

	return 0;


}