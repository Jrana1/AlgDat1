#include <iostream>
using namespace std;
class Queue
{
private:
    int front;
    int rear;
    int size;
    int *Array;

public:
    Queue()
    {
        this->front = this->rear = -1;
        this->size = 10;
        this->Array = new int[this->size];
    }
    void enqueue(int val)
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
    int dequeue()
    {
        return this->Array[++this->front];
    }
};

int main()
{
    int A[] = {2, 3, 5, 8};
    Queue q;
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