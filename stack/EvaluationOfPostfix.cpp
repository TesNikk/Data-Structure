#include<iostream>
using namespace std;
class Polish{
private:
	int top = -1;
	int stack[20];
public:
	void push(int x) {
		stack[++top] = x;
	}
	int pop() {
		return stack[top--];
	}
	void postfix(char *exp) {
		for (int i = 0; exp[i] != 0; i++) {
			int n, n1, n2, num;
			if (isdigit(exp[i])) {
				num = exp[i] - 48;
				push(num);
			}
			else {
				n2 = pop();
				n1 = pop();
				switch (exp[i]) {
				case '+':n = n1 + n2;
					break;
				case '-':n = n1 - n2;
					break;
				case '*':n = n1 * n2;
					break;
				case '/':n = n1 / n2;
					break;	
				}
				push(n);
			}
		}
		cout<<"Result = "<<pop()<<endl;
	}
};

int main() {
	cout << "Enter Expression " << endl;
	char exp[20];
	cin >> exp;
	Polish p;
	p.postfix(exp);
	return 0;
}