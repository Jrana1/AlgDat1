
#include <iostream>
using namespace std;
#include <stack>

class Queue
{
private:
    stack<int> s1;
    stack<int> s2;
    int size;

public:
    Queue();
    void enqueue(int val);
    int dequeue();
    void enqueue1(int val);
    int dequeue1();
    bool isEmpty();
};
// enqueue in O(n)
void Queue::enqueue1(int val)
{
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    s1.push(val);
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
}
// dequeue in O(1)
int Queue::dequeue1()
{
    int x = s2.top();
    s2.pop();
    return x;
}
// dequeue in O(n)
int Queue::dequeue()
{

    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    int x = s2.top();
    s2.pop();
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return x;
}
Queue::Queue()
{
}
bool Queue::isEmpty()
{
    if (s1.empty())
        return true;
    return false;
}
// enqueue in O(1)
void Queue::enqueue(int val)
{
    s1.push(val);
}
int main()
{
    Queue q2;

    q2.enqueue1(32);
    q2.enqueue1(3);
    q2.enqueue1(1);
    cout << q2.dequeue1() << endl;

    return 0;
}