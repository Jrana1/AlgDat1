
#include <iostream>
using namespace std;
#include <queue>
class Stack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    Stack();
    void push(int val);
    int pop();
    bool isEmpty();
};
Stack::Stack() {}
void Stack::push(int val)
{
    q2.push(val);
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
}
int Stack::pop()
{
    int x = q1.front();
    q1.pop();
    return x;
}
int main()
{

    Stack s1;
    s1.push(32);
    s1.push(3);
    s1.push(5);
    s1.push(1);
    cout << s1.pop() << endl;

    return 0;
}