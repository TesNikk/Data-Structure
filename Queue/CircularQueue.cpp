#include <iostream>
using namespace std;
class Queue
{
private:
	int size;
	int front;
	int rear;
	int *Q;

public:
	// constructor
	Queue(int size)
	{
		this->size = size;
		front = -1;
		rear = -1;
		Q = new int[size];
	}
	// insert
	void enqueue();
	// delete
	void dequeue();
	// display
	void display();
};
void Queue::enqueue()
{
	int x;
	cout << "Enter Value " << endl;
	cin >> x;
	if ((rear + 1) % size == front)
	{ // MOD
		cout << "Queue is full" << endl;
	}
	else
	{
		rear = (rear + 1) % size;
		Q[rear] = x;
	}
}
void Queue::dequeue()
{
	int x = -1;
	if (front == rear)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		front = (front + 1) % size;
		x = Q[front];
		cout << "Dequeued value = " << x << endl;
	}
}
void Queue::display()
{
	if (front == -1)
	{
		cout << "Queue Empty" << endl;
		// return;
	}
	else
	{
		int i = (front + 1);
		do
		{
			cout << Q[i] << " ";
			i = (i + 1) % size;
		} while (i != (rear + 1) % size);
		cout << endl;
	}
}
// MENU
void menu()
{
	cout << "*****MENU*****" << endl;
	cout << "Enter Your Option " << endl;
	cout << "1.Enqueue\n2.Dequeue\n3.Display\n4.Exit" << endl;
	cout << endl;
}
int main()
{
	cout << "Size of Queue" << endl;
	int s;
	cin >> s;
	Queue q(s);
	int opt = 1;
	while (opt != 4)
	{
		menu();
		cin >> opt;
		switch (opt)
		{
		case 1:
			q.enqueue();
			break;
		case 2:
			q.dequeue();
			q.display();
			break;
		case 3:
			q.display();
			break;
		case 4:
			break;
		}
	}
	return 0;
}
