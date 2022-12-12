#include <iostream>
using namespace std;
void insertion(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = a[i];
        while (j > -1 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}
void display(const int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter Array size" << endl;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Before Sorting: " << endl;
    display(a, n);
    insertion(a, n);
    cout << "After sorting: " << endl;
    display(a, n);
    return 0;
}