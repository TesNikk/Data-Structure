#include<iostream>
#include<stack>
#include<string>
using namespace std;
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

void infixToPostfix(string infix) {
    stack <char> s;
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
			while (!s.empty() && precedence(c) <= precedence(s.top())) {
				postfix += s.top();
				s.pop();
			}
			s.push(c);
		}
	}
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    cout << postfix << endl;
}

int main() {
	string infix = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(infix);
    return 0;
}