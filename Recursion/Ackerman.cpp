#include <iostream>
using namespace std;
long long Ackerman(long long m, long long n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if ((m > 0) && (n == 0))
    {
        return Ackerman(m - 1, 1);
    }
    else if ((m > 0) && (n > 0))
    {
        return Ackerman(m - 1, Ackerman(m, n - 1));
    }
}
int main()
{
    long long m, n;
    cout << "Input M  N" << endl;
    cin >> m >> n;
    cout<<Ackerman(m,n)<<endl;
    return 0;
}