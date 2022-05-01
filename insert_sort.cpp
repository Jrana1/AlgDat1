#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h>
// bool search_ite(int *A, int key, int size)
// {

//   int l = 0, r = size - 1, mid = 0, k = 0;
//   while (l < r)
//   {
//     k = k + 1;
//     mid = (l + r - 1) / 2;
//     if (A[mid] < key)
//     {
//       l = mid + 1;
//     }
//     else
//     {
//       r = mid;
//     }
//   }
// //   cout << A[mid] << " " << A[l] << " " << A[r] << " " << k << endl;
// }
void insert_sort(int *A, int size)
{
  for (int i = 1; i < size; i++)
  {
    int key = A[i];
    int j = i - 1;
    int flag = 0;
    while (j >= 0 && key < A[j])
    {
      A[j + 1] = A[j];
      flag = 1;
      j--;
    }
    if (flag == 1)
    {
      A[j + 1] = key;
    }
  }
}
int main()
{
  int A[4] = {3, 2, 9, 1};
  int size = sizeof(A) / sizeof(A[0]);
  insert_sort(A, size);
  for (auto x : A)
  {
    cout << x << " ";
  }

  return 0;
}