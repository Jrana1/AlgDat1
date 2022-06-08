#include <iostream>
using namespace std;
#include <stack>
bool isBalanced(const char *str)
{
    stack<char> s;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (!s.empty())
            {
                char x = str[i];
                char top = s.top();
                if ((x == ')' && top == '(') || (x == '}' && top == '{') || (x == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    return s.empty() ? true : false;
}

int main()
{
    char str[] = "[({((a+b))})-{c*(d-3)}]";
    cout << isBalanced(str) << endl;

    return 0;
}