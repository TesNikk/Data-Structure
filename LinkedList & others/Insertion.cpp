#include<iostream>
using namespace std;
int main() {
    int a[50];
    int x, m,n;
    cout<<"Enter Array Size- "<<"Index number- "<<"value-"<<endl;
    cin>>n>>m>>x;
    int i;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    i = n - 1;
    if (0 <= m <= (n - 1))
    {
        for (i = (n - 1); i >= m; i--) {
            a[i + 1] = a[i];
        }
        a[m] = x;
        n++;
    }
    else {
        cout << "Enter Valid Index!!!!" << endl;
    }
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}