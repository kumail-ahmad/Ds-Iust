#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char help, char dest)
{
    if (n == 1)
    {
        cout << "Transfered disk " << n << " from " << src << " to " << dest << endl;
        return;
    }

    towerOfHanoi(n - 1, src, dest, help);
    cout << "Transfered disk " << n << " from " << src << " to " << dest << endl;

    towerOfHanoi(n - 1, help, src, dest);
}

int main()
{
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');
}