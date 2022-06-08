#include <iostream>
using namespace std;
template <class T>
class Stack
{
private:
    int size;
    int top;
    T *Array;

public:
    Stack()
    {
        this->size = 8;
        this->top = -1;
        this->Array = new T[this->size];
    };
    bool isEmpty()
    {
        return this->top == -1 ? true : false;
    }
    void push(T val)
    {
        if (this->top == this->size)
        {
            cout << "Stack Overflow!!" << endl;
            exit(1);
        }
        this->Array[++this->top] = val;
    }
    T pop()
    {
        if (this->isEmpty())
        {
            cout << "Stack is Empty!!" << endl;
            exit(0);
        }
        T x = this->Array[this->top--];
        return x;
    }
    void display()
    {
        for (int i = 0; i <= this->top; i++)
        {
            cout << this->Array[i] << " ";
        }
        cout << "\n";
    }
    ~Stack()
    {
        delete[] Array;
    }
    bool isFull()
    {
        if (this->top == this->size)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    int arr[] = {3, 9, 1, 3, 2, 8, 6, 4, 2};
    Stack<int> s1;
    for (int i = 0; i < 9; i++)
    {
        s1.push(arr[i]);
    }
    s1.display();
    while (!s1.isEmpty())
    {
        cout << s1.pop() << " ";
    }
    cout << "\n";

    return 0;
}