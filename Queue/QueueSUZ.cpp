#include<iostream>
using namespace std;
class Queue {
private:
	int size;
	int front;
	int rear;
	int* Q;
public:
	//constructor
	Queue(int size) {
		this->size = size;
		front = -1;
		rear = -1;
		Q = new int[size];
	}
	//insert
	void enqueue();
	//delete
	void  dequeue();
	//display
	void display();
};
void Queue::enqueue() {
	int x;
	cout << "Enter Value " << endl;
	cin >> x;
	if (rear == size - 1) {
		rear = 0;
		if (rear == front) {
			cout << "Queue is Full" << endl;
			rear = size - 1;
		}
		else {
			Q[rear] = x;
		}
	}
	else {
		if (rear + 1 == front) {
			cout << "Queue is Full" << endl;
		}
		else {
		rear++;
		Q[rear] = x;
		}
	}
}
void Queue::dequeue() {
	int x = -1;
	if (front == rear ==-1) {
		cout << "Queue is empty" << endl;
	}
	else {
		if (front == size - 1) {
			front = 0;
		}
		else {
			front++;
		}
		x = Q[front];
		cout << "Dequeued value = " << x << endl;
	}
}
void Queue::display() {
	cout << "Displaying Values: " << endl;
	if (front == rear ==-1) {
		cout << "Queue is empty" << endl;
	}
	for (int i = front+1; i <= rear; i++) {
		cout << Q[i] << " ";
	}
	cout << endl;
}
//MENU
void menu() {
	cout << "*****MENU*****" << endl;
	cout << "Enter Your Option " << endl;
	cout << "1.Enqueue\n2.Dequeue\n3.Display\n4.Exit" << endl;
	cout << endl;
}
int main() {
	cout << "Size of Queue" << endl;
	int s;
	cin >> s;
	Queue q(s);
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
		}
	}
	return 0;
}
