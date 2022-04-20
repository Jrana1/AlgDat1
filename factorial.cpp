#include <iostream>
using namespace std;

int factorial_recursive(int n)
{

    if (n == 0)
        return 1;
    return n * factorial_recursive(n - 1);
}
int main()
{

    int n = 4;
    cout << factorial_recursive(n) << endl;

    return 0;
}