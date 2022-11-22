#include<iostream>
using namespace std;
int main() {
	int a[50];
	cout << "Enter Array Size: " << endl;
	int n;
	cin >> n;
	cout << "Enter the value u want to delete: " << endl;
	int x;
	cin >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			for (int j = i; j < n - 1; j++) {
				a[j] = a[j + 1];
			}
		}
	}
	for (int i = 0; i < n-1; i++) {
		cout << a[i] <<" ";
	}
	return 0;
}