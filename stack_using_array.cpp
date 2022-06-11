#include <iostream>
using namespace std;
#include <stack>
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
        this->size = 34;
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

    return 0;
}