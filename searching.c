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
        { // how to improve Linear Search?
            // mySwap(&a[k], &a[0]); //  1.Move to front/head--> rapid improvement
            mySwap(&a[k], &a[k - 1]); // 2. Transposition-->Move to 1 step forward --> slow improvement
            return k;
        }
    }
}
int linear_search_recursive(float *a, int start, int end, float key)
{

    if (a[start] == key)
    {
        mySwap(&a[start], &a[0]);
        return start;
    }
    if (start == end)
    {
        return -1;
    }
    return linear_search_recursive(a, start + 1, end, key);
}
int binary_search_recursive(float *a, int lo, int hi, float key)
{

    int mid = (lo + hi) / 2;
    if (a[mid] == key)
    {
        return mid;
    }
    else if ((hi - lo) < 0)
    {
        return -1;
    }
    else if (key > a[mid])
    {
        binary_search_recursive(a, mid + 1, hi, key);
    }
    else
    {
        binary_search_recursive(a, lo, mid - 1, key);
    }
}
int main()
{
    float a[] = {1.5, 1.7, 2.3, 2.6, 3.3, 3.5};
    int size = sizeof(a) / sizeof(a[0]);
    // int ans = binary_search(a, size, 1.8);
    int index = binary_search_recursive(a, 0, size, 1.7);
    printf("%d\n", index);
    printf("%d\n", binary_search_recursive(a, 0, size, 1.6));
    return 0;
}