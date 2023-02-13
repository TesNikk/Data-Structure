#include<iostream>
using namespace std;
int Binary_search(int a[], int n, int data) {
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (data == a[mid]) {
			return mid;
		}
		else if (data < a[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;

}
int main() {
	int a[100];
	int n;
	cout << "Enter Array size:" << endl;
	cin >> n;
	cout << "Input Elements: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "Enter data to search" << endl;
	int data;
	cin >> data;
	int result;
	result = Binary_search(a, n, data);
	if (result == -1) {
		cout << "Not found" << endl;
	}
	else {
		cout << "found at " << result << endl;
	}
}