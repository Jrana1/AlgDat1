#include <iostream>
using namespace std;
#include <algorithm>
class Heap
{

private:
    int size;
    int length;
    int *Array;

public:
    Heap();
    Heap(int size, int length);
    void insert(int key);
    void display();
    int laenge();
    int loeschen();
    // ~Heap();
};
int Heap::loeschen()
{
    int root = this->Array[1];
    int last = this->Array[this->length - 1];
    this->Array[1] = last;
    int i = 1;

    while (i < this->length)
    {

        if (last > this->Array[2 * i] && last > this->Array[2 * i + 1])
        {
            break;
        }
        else
        {
            if (this->Array[2 * i] > this->Array[2 * i + 1])
            {
                swap(this->Array[i], this->Array[2 * i]);
                i = i * 2;
            }
            else
            {
                swap(this->Array[i], this->Array[2 * i + 1]);
                i = i * 2 + 1;
            }
        }
    }
    this->Array[i] = root;
}
int Heap::laenge()
{
    return this->length;
}
Heap::Heap()
{
    this->size = 0;
    this->length = 1;
}
Heap::Heap(int size, int length)
{
    this->length = length;
    this->size = size;
    this->Array = new int[this->size];
}

void Heap::insert(int key)
{
    if (this->length == 1)
    {
        this->Array[length++] = key;
        return;
    }
    int i = this->length;
    while (i > 1 && key > this->Array[i / 2])
    {
        this->Array[i] = this->Array[i / 2];
        i = i / 2;
    }
    this->Array[i] = key;
    this->length++;
}
void Heap::display()
{
    for (int i = 1; i < this->length; i++)
    {
        cout << this->Array[i] << " ";
    }
    cout << "\n";
}
int main()
{

    Heap h1(34, 1);
    h1.insert(32);
    h1.insert(3);
    h1.insert(54);
    h1.insert(77);
    h1.insert(21);
    h1.insert(64);
    h1.insert(88);
    h1.insert(99);
    // h1.insert(55);
    // h1.insert(4);
    // h1.insert(21);
    // h1.insert(42);
    // h1.insert(45);
    // h1.insert(2);
    // h1.insert(78);
    h1.display();
    for (int i = 0; i < h1.laenge() - 1; i++)
        h1.loeschen();
    h1.display();

    return 0;
}