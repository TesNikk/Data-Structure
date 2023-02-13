#include<iostream>
using namespace std;
int main() {
    int a[5][6] = { {0,0,0,0,9,0},
                {0,8,0,0,0,0},
                {4,0,0,2,0,0},
                {0,0,0,0,0,5},
                {0,0,2,0,0,0} };
    int s[100][3];
    int n = 5, m = 6;
    int k = 0;
    s[0][0] = n;
    s[0][1] = m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0) {

                k++;
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];

            }
        }
    }
    s[0][2] = k;//we didnt knew at first how many values were there thats y its written in last
    cout << "Rows Columns Value"<<endl;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < 3; j++) {
            cout << s[i][j] << "      ";
        }
        cout << endl;
    }


    return 0;
}