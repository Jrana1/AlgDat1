#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

class Array
{
private:
    int *array, *result;
    int size;

public:
    Array(int size)
    {
        this->array = new int[size];
        this->size = size;
    }
    Array()
    {
        this->size = 10;
        this->array = new int[size];
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            this->array[i] = rand() % 20;
        }
    }
    void display()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << this->array[i] << " ";
        }
        cout << endl;
    }
    int max()
    {
        int max = this->array[0];
        for (int i = 0; i < size; i++)
        {
            if (this->array[i] >= max)
            {
                max = this->array[i];
            }
        }
        return max;
    }
    void count_sort()
    {
        int max = this->max();
        Array a2(max + 1);
        for (int i = 0; i < max + 1; i++)
        {
            a2.array[i] = 0;
        }
        for (int i = 0; i < this->size; i++)
        {
            a2.array[this->array[i]]++;
        }
        int j = 0;
        for (int i = 0; i < max + 1; i++)
        {
            while (a2.array[i] > 0)
            {
                this->array[j++] = i;
                a2.array[i]--;
            }
        }
    }
};
int main()
{
    Array a1;
    a1.display();
    a1.count_sort();
    a1.display();
    return 0;
}