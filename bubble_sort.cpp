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
    Array(int size = 3)
    {
        this->size = size;
        this->array = new int[size];
        this->result = new int[size];
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            this->array[i] = rand() % 20 + 1;
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << this->array[i] << " ";
        }
        cout << endl;
    }
    void bubble_sort()
    {
        for (int i = 0; i < this->size - 1; i++)
        {
            for (int j = 0; j < this->size - i; j++)
            {
                if (this->array[j] >= this->array[j + 1])
                {
                    int temp = this->array[j];
                    this->array[j] = this->array[j + 1];
                    this->array[j + 1] = temp;
                }
            }
        }
    }
};
int main()
{
    Array a1(12);
    a1.display();
    a1.bubble_sort();
    a1.display();
    return 0;
}