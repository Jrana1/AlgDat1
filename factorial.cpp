#include <iostream>
using namespace std;

int factorial_recursive(int n)
{

    if (n == 0)
        return 1;
    return n * factorial_recursive(n - 1);
}
int factorial_iterative(int n)
{

    int ans = 1;
    while (n > 1)
    {
        ans *= n;
        n--;
    }
    return ans;
}
int main()
{

    int n = 4;
    cout << factorial_iterative(n) << endl;

    return 0;
}