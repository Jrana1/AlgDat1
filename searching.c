#include <stdio.h>
#include <stdlib.h>
int binary_search(float *a, int sz, float key)
{

    int lo = 0, hi = sz - 1, mid;
    while (hi - lo >= 0)
    {
        mid = (lo + hi) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (key > a[mid])
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    printf("in f -> %d\n", lo);
    return -1;
}
void mySwap(float *x, float *y)
{
    // *x = *x ^ *y;
    // *y = *x ^ *y;
    // *x = *x ^ *y;
    float temp = *x;
    *x = *y;
    *y = temp;
}
int linear_search(float *a, int size, float key)
{
    for (int k = 0; k < size; k++)
    {
        if (a[k] == key)
        {
            // mySwap(&a[k], &a[0]); // Move to front/head--> rapid improvement
            mySwap(&a[k], &a[k - 1]); // Move to 1 step forward --> slow improvement
            return k;
        }
    }
}
int main()
{
    float a[] = {1.5, 1.7, 2.3, 2.6, 3.3, 3.5};
    int size = sizeof(a) / sizeof(a[0]);
    // int ans = binary_search(a, size, 1.8);
    int index = linear_search(a, size, 3.3);
    printf("%d\n", index);
    printf("%d\n", linear_search(a, size, 3.3));
    return 0;
}