#include <iostream>
using namespace std;
#include <stdlib.h>

int search_iterative(int *a, int key, int sz)
{

    int lo = 0;
    int hi = sz - 1;
    int k = 0;
    int mid = 0;
    while (lo < hi)
    {
        k = k + 1;
        mid = (lo + hi - 1) / 2;
        if (a[mid] < key)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    cout << k << endl;
    return a[lo] == key;
    // return lo;
}
int main()
{

    int a[] = {1, 4, 6, 7, 8, 13, 15, 16, 18, 19, 20, 21, 22, 23, 24, 25};
    int size = sizeof(a) / sizeof(a[0]);

    int key = search_iterative(a, 16, size);
    cout << key << endl;
    return 0;
}