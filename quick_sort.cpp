#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include <algorithm>
template <class T>
class Array
{
private:
    T *array;
    int size;

public:
    Array(int size = 5)
    {
        this->size = size;
        this->array = new T[size];
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            this->array[i] = rand() % 10 + 1;
        }
    }
    ~Array()
    {
        delete[] this->array;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << this->array[i] << " ";
        }
        cout << endl;
    }
    int partition(int st, int end)
    {
        T x = this->array[end];
        int i = st - 1;
        for (int j = st; j <= end; j++)
        {
            if (this->array[j] < x)
            {
                i++;
                mySwap(&this->array[i], &this->array[j]);
            }
        }
        mySwap(&this->array[i + 1], &this->array[end]);
        return i + 1;
    }
    void mySwap(int *a, int *b)
    {
        T tmp = *a;
        *a = *b;
        *b = tmp;
    }
    void quick_sort(int st, int end)
    {
        if (st < end)
        {

            int pivot = partition(st, end);
            quick_sort(st, pivot - 1);
            quick_sort(pivot + 1, end);
        }
    }
    int hoare_partition(int st, int end)
    {
        int x = this->array[st];
        int i = st - 1;
        int j = end + 1;
        while (i < j)
        {

            do
            {
                i++;
            } while (!(this->array[i] >= x));
            do
            {
                j--;
            } while (!(this->array[j] <= x));
            if (i < j)
            {
                mySwap(&this->array[i], &this->array[j]);
            }
        }
        return j;
    }

    void quick_sort_mit_hoare_partition(int st, int end)
    {

        if ((end - st) >= 1)
        {
            int pivot = hoare_partition(st, end);

            quick_sort_mit_hoare_partition(st, pivot);
            quick_sort_mit_hoare_partition(pivot + 1, end);
        }
    }
};

int main()
{
    Array<int> a1(10);
    a1.display();
    // a1.quick_sort(0, 9);
    a1.quick_sort_mit_hoare_partition(0, 10);
    a1.display();
    return 0;
}