#include <iostream>
using namespace std;
template <class T>
class Queue
{
private:
    int front;
    int rear;
    int size;
    T *Array;

public:
    Queue()
    {
        this->front = this->rear = -1;
        this->size = 10;
        this->Array = new T[this->size];
    }
    void enqueue(T val)
    {
        if (this->rear == this->size - 1)
        {
            cout << "Queue is Full!!" << endl;
            exit(0);
        }
        this->Array[++this->rear] = val;
    }
    void display() const
    {

        for (int i = this->front + 1; i <= this->rear; i++)
        {
            cout << this->Array[i] << " ";
        }
        cout << "\n";
    }
    ~Queue()
    {
        delete[] this->Array;
    }
    inline bool isEmpty() const
    {
        return this->front == this->rear ? true : false;
    }
    inline bool isFull() const
    {
        return this->rear == (this->size - 1) ? true : false;
    }
    T dequeue()
    {
        return this->Array[++this->front];
    }
};

int main()
{
    float A[] = {2.3, 3.1, 5.0, 8.9};
    Queue<float> q;
    for (int i = 0; i < 4; i++)
    {
        q.enqueue(A[i]);
    }
    q.display();
    for (int i = 0; i < 4; i++)
    {
        cout << q.dequeue() << endl;
    }
    return 0;
}