#include <iostream>
using namespace std;
int count = 0;
int TOH(int n, char src, char dest, char aux)
{
    if (n > 0)
    {
        count++;
        TOH(n - 1, src, aux, dest);
        cout << "Move from " << src << " to " << dest << endl;
        TOH(n - 1, aux, dest, src);
    }
    return count;
}
int main()
{
    int n;
    cout << "Enter How many Discs" << endl;
    cin >> n;
    int cnt=TOH(n, 'A', 'B', 'C');
    cout << "Steps = " << cnt << endl;
    return 0;
}