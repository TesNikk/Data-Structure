#include<iostream>
using namespace std;
int main() {
	cout << "Enter array size: " << endl;
	int n;
	cin >> n;
	int a[50];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int temp = 0;
	for (int i = 0; i < n - 1; i++) //n-1 PASS
    {
		int flag = 0;
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
			if (!flag) {
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}